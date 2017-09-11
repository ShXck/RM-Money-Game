#include "GameDataHandler.h"

Game_Data_Handler::Game_Data_Handler() {
	rm_lib.rm_init( 0,0,0,0 );
}

void Game_Data_Handler::set_data() {
	send_player_data();

	for( int i = 0; i < AI_PLAYERS_NUM; i++ ) {
		players_ai.push_back( Buyer( util::random_number( 5000,10000 ) ) );
	}

	load_items();
}

void Game_Data_Handler::reset( int round ) {
	players_ai.clear();
	for( int i = 0; i < AI_PLAYERS_NUM; i++ ) {
		players_ai.push_back( Buyer( util::random_number( 5000,10000 ) * round ) );
	}
	std::string _bid = std::to_string( 0 );
	rm_lib.rm_replace( data_keys[4].c_str(), &_bid );
	std::string player_funds = std::to_string( util::random_number( 5000,10000 ) * round );
	rm_lib.rm_replace( data_keys[0].c_str(), &player_funds );
}

void Game_Data_Handler::send_player_data() {
	int initial_funds = util::random_number( 5000,10000 );
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
}

void Game_Data_Handler::bet( int money ) {
	char* current_bid = rm_lib.rm_get( data_keys[4].c_str() )->_value;
	int current_bid_int = std::atoi( current_bid ) + money;
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

std::string Game_Data_Handler::get_winner() {
	char* _response = rm_lib.rm_get( data_keys[0].c_str() )->_value;
	int player_bid = std::atoi( _response );
	Buyer& b_win = players_ai[0];
	for( unsigned int i = 1; i < players_ai.size(); i++ ) {
		Buyer& curr_buyer = players_ai[i];
		if( curr_buyer.bid() > b_win.bid() ) b_win = curr_buyer;
	}
	if( b_win.bid() > player_bid ) return b_win.name();
	return "Player";
}

int Game_Data_Handler::player_funds() {
	char* r = rm_lib.rm_get( data_keys[0].c_str() )->_value;
	return std::atoi( r );
}

Game_Data_Handler::~Game_Data_Handler() { }

