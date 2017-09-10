#include "Game.h"

Game::Game() : _round( 1 ) {
	if( !_font.loadFromFile( "assets/DroidSerif-Regular.ttf" ) ) {
		std::cout << "COULDNT NOT OPEN FONT" << std::endl;
	}
	bet_button.setPosition( sf::Vector2f( 120, 500 ) );
	bet_button.setSize( sf::Vector2f( 250, 50 ) );
	bet_button.setFillColor( sf::Color::Green );

	withdraw_button.setPosition( sf::Vector2f( 400, 500 ) );
	withdraw_button.setSize( sf::Vector2f( 250, 50 ) );
	withdraw_button.setFillColor( sf::Color::Red );
}

void Game::handle_input( sf::Event e, sf::RenderWindow& window ) {

	switch( e.key.code ) {
		case sf::Mouse::Left: {
			sf::Vector2i mouse_pos = sf::Mouse::getPosition( window );
			sf::Vector2f mouse_pos_f( static_cast<float>( mouse_pos.x ), static_cast<float>( mouse_pos.y ) );
			check_button_clicked( mouse_pos_f );
			break;
		}
	}

}

void Game::check_button_clicked( sf::Vector2f mouse_pos ) {
	if( bet_button.getGlobalBounds().contains( mouse_pos ) ) {
		game_handler.update_player_funds( game_handler.player_funds() - DEFAULT_BET_MONEY );
		game_handler.bet( DEFAULT_BET_MONEY );
		_text[ 4 ].setString( "Your wallet: $" + std::to_string( game_handler.player_funds() ) );
		_text[ 8 ].setString( "BID: $" + std::to_string( game_handler.get_current_bid() ) );
	} else if( withdraw_button.getGlobalBounds().contains( mouse_pos ) ) {
		//Witdraw
	}
}

void Game::draw( sf::RenderWindow& window ) {
	window.draw( bet_button );
	window.draw( withdraw_button );
	for( int i = 0; i < TEXT_ITEMS; i++ ) {
		window.draw( _text[i] );
	}
}

void Game::start() {


	game_handler.set_data();

	set_text();

	sf::RenderWindow _window( sf::VideoMode( 800,600 ), "Here comes the money" );

	while( _window.isOpen() ) {
		sf::Event e;
		while( _window.pollEvent( e ) ) {
			switch( e.type ) {
				case sf::Event::MouseButtonReleased:
				case sf::Event::KeyReleased: {
					handle_input( e, _window );
					break;
				}
				case sf::Event::Closed: {
					_window.close();
					break;
				}

			}
		}
		_window.clear();
		draw( _window );
		_window.display();
	}
}

void Game::set_text() {

	_text[ 0 ].setFont( _font );
	_text[ 0 ].setString( game_handler.get_buyer_info( 0 ).name() + ": $" + std::to_string( game_handler.get_buyer_info( 0 ).bid() ) );
	_text[ 0 ].setFillColor( sf::Color::Blue );
	_text[ 0 ].setPosition( 50, 50 );
	_text[ 0 ].setCharacterSize( 24 );

	_text[ 1 ].setFont( _font );
	_text[ 1 ].setString( game_handler.get_buyer_info( 1 ).name() + ": $" + std::to_string( game_handler.get_buyer_info( 1 ).bid() ) );
	_text[ 1 ].setFillColor( sf::Color::Blue );
	_text[ 1 ].setPosition( 50, 100 );
	_text[ 1 ].setCharacterSize( 24 );

	_text[ 2 ].setFont( _font );
	_text[ 2 ].setString( game_handler.get_buyer_info( 2 ).name() + ": $" + std::to_string( game_handler.get_buyer_info( 2 ).bid() ) );
	_text[ 2 ].setFillColor( sf::Color::Blue );
	_text[ 2 ].setPosition( 50, 150 );
	_text[ 2 ].setCharacterSize( 24 );

	_text[ 3 ].setFont( _font );
	_text[ 3 ].setString( game_handler.get_buyer_info( 3 ).name() + ": $" + std::to_string( game_handler.get_buyer_info( 3 ).bid() ));
	_text[ 3 ].setFillColor( sf::Color::Blue );
	_text[ 3 ].setPosition( 50, 200 );
	_text[ 3 ].setCharacterSize( 24 );

	_text[ 4 ].setFont( _font );
	_text[ 4 ].setString( "Your wallet: $" + std::to_string( game_handler.player_funds() ) );
	_text[ 4 ].setFillColor( sf::Color::White );
	_text[ 4 ].setPosition( 50, 350 );
	_text[ 4 ].setCharacterSize( 28 );

	_text[ 5 ].setFont( _font );
	_text[ 5 ].setString( "BET" );
	_text[ 5 ].setFillColor( sf::Color::Black );
	_text[ 5 ].setPosition( 210, 505 );
	_text[ 5 ].setCharacterSize( 28 );

	_text[ 6 ].setFont( _font );
	_text[ 6 ].setString( "WITHDRAW" );
	_text[ 6 ].setFillColor( sf::Color::Black );
	_text[ 6 ].setPosition( 440, 505 );
	_text[ 6 ].setCharacterSize( 28 );

	_text[ 7 ].setFont( _font );
	_text[ 7 ].setString( "Item: " + game_handler.get_item( _round - 1 ) );
	_text[ 7 ].setFillColor( sf::Color::Yellow );
	_text[ 7 ].setPosition( 500, 120 );
	_text[ 7 ].setCharacterSize( 30 );

	_text[ 8 ].setFont( _font );
	_text[ 8 ].setString( "BID: $" + std::to_string( game_handler.get_current_bid() ) );
	_text[ 8 ].setFillColor( sf::Color::Magenta );
	_text[ 8 ].setPosition( 500, 160 );
	_text[ 8 ].setCharacterSize( 30 );
}

Game::~Game() { }

