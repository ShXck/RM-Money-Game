#ifndef GAMEDATAHANDLER_H_
#define GAMEDATAHANDLER_H_
#define AI_PLAYERS_NUM 4
#include "lib_ops/RMlib.h"
#include <iostream>
#include <vector>
#include "Buyer.h"
#include <sstream>
#include <fstream>
#include <thread>
#include "util.h"
#include <chrono>

class Game_Data_Handler {
public:
	Game_Data_Handler();
	void set_data();
	void update_player_funds( int new_val );
	int player_funds();
	Buyer& get_buyer_info( int index );
	std::string get_item( int index );
	void bet( int money );
	void withdraw();
	std::string get_winner();
	int get_current_bid();
	void reset( int round );
	virtual ~Game_Data_Handler();
private:
	void send_player_data();
	void load_items();
private:
	std::vector< Buyer > players_ai;
	std::vector< std::string > data_keys;  // funds,matches,score,beaten,bid
	std::vector< std::string > items_keys;
 	rm::RM_lib rm_lib;
};

#endif /* GAMEDATAHANDLER_H_ */
