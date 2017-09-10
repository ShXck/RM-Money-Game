#ifndef GAMEDATAHANDLER_H_
#define GAMEDATAHANDLER_H_
#define AI_PLAYERS_NUM 4
#include "lib_ops/RMlib.h"
#include <iostream>
#include <vector>
#include "Buyer.h"
#include <sstream>
#include <fstream>

class Game_Data_Handler {
public:
	Game_Data_Handler();
	void set_data();
	void update_player_funds( int new_val );
	const int& player_funds() const;
	Buyer& get_buyer_info( int index );
	std::string get_item( int index );
	void bet( int money );
	void withdraw();
	int get_current_bid();
	virtual ~Game_Data_Handler();
private:
	void send_player_data();
	void load_items();
private:
	std::vector< Buyer > players_ai;
	std::vector< std::string > data_keys;  // funds,matches,score,beaten,bid
	std::vector< std::string > items_keys;
 	rm::RM_lib rm_lib;
 	int last_response;
};

#endif /* GAMEDATAHANDLER_H_ */
