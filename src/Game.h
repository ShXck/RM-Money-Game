#ifndef GAME_H_
#define GAME_H_
#define TEXT_ITEMS 10
#define DEFAULT_BET_MONEY 100
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Buyer.h"
#include "GameDataHandler.h"
#include "util.h"

class Game {
public:
	Game();
	void start();
	virtual ~Game();
private:
	void handle_input( sf::Event e, sf::RenderWindow& window );
	void draw( sf::RenderWindow& window );
	void set_text();
	void check_button_clicked( sf::Vector2f mouse_pos );
	void continue_bidding();
	void start_bidding();
	void get_next_round();
private:
	std::vector < Buyer > player_ai;
	Game_Data_Handler game_handler;
	int _round;
	sf::Text _text[ TEXT_ITEMS ];
	sf::Font _font;
	sf::RectangleShape bet_button;
	sf::RectangleShape withdraw_button;
};

#endif /* GAME_H_ */
