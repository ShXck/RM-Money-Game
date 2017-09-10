#include "GameDataHandler.h"

Game_Data_Handler::Game_Data_Handler() : last_response( 1500 ) {
	rm_lib.rm_init( 0,0,0,0 );
}

void Game_Data_Handler::set_data() {
	send_player_data();

	for( int i = 0; i < AI_PLAYERS_NUM; i++ ) {
		players_ai.push_back( Buyer() );
	}

	load_items();

}

void Game_Data_Handler::send_player_data() {
	int initial_funds = 1500;
	int matches_won = 0;
	int pl_score = 0;
	int people_beaten = 0;
	int current_bid = 0;

	for( int i = 0; i < 5; i++ ) {
		data_keys.push_back( util::create_random_key( 4 ) );
	}

	for( int i = 0; i < 10; i++ ) {
		items_keys.push_back( util::create_random_key( 4 ) );
	}

	rm_lib.rm_new( data_keys[ 0 ].c_str(), std::to_string( initial_funds ), sizeof( int ) );
	rm_lib.rm_new( data_keys[ 1 ].c_str(), std::to_string( matches_won ), sizeof( int ) );
	rm_lib.rm_new( data_keys[ 2 ].c_str(), std::to_string( pl_score ), sizeof( int ) );
	rm_lib.rm_new( data_keys[ 3 ].c_str(), std::to_string( people_beaten ), sizeof( int ) );
	rm_lib.rm_new( data_keys[ 4 ].c_str(), std::to_string( current_bid ), sizeof( int ) );
}

void Game_Data_Handler::load_items() {
	std::string _line;
	std::ifstream items_file("assets/items.txt");
	if( items_file.is_open() ) {
		unsigned int _index = 0;
		while( std::getline( items_file, _line) && _index < items_keys.size() ) {
			if( _line != "" ) {
				rm_lib.rm_new( items_keys[_index].c_str(), _line, sizeof( char* ) );
			}
			_index++;
		}
		items_file.close();
	} else {
		std::cout << "FILE NOT OPENENED" << std::endl;
	}
}

void Game_Data_Handler::update_player_funds( int new_val ) {
	std::string str_val = std::to_string( new_val );
	rm_lib.rm_replace( data_keys[0].c_str(), &str_val );
	char* _response = rm_lib.rm_get( data_keys[0].c_str() )->_value;
	last_response = std::atoi( _response );
}

void Game_Data_Handler::bet( int money ) {
	char* current_bid = rm_lib.rm_get( data_keys[4].c_str() )->_value;
	std::cout << "CB:" << current_bid << std::endl;
	int current_bid_int = std::atoi( current_bid ) + money;
	std::cout << "CB_INT: " << current_bid_int << std::endl;
	std::string str_bid = std::to_string( current_bid_int );
	rm_lib.rm_replace( data_keys[4].c_str(), &str_bid );
}

Buyer& Game_Data_Handler::get_buyer_info( int index ) {
	if( index < players_ai.size() ) {
		return players_ai.at( index );
	}
	return players_ai.at( 0 );
}

std::string Game_Data_Handler::get_item( int index ) {
	char* _response = rm_lib.rm_get( items_keys[ index ].c_str() )->_value;
	std::string str_response( _response );
	return str_response;
}

int Game_Data_Handler::get_current_bid() {
	char* current_bid = rm_lib.rm_get( data_keys[4].c_str() )->_value;
	return std::atoi( current_bid );
}

const int& Game_Data_Handler::player_funds() const { return last_response; }

Game_Data_Handler::~Game_Data_Handler() { }

