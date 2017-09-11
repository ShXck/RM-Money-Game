#include "Buyer.h"

Buyer::Buyer( int initial_funds ) : _wallet( initial_funds ), is_active( true ), _bid( 0 ) { set_name(); }

void Buyer::bet( int money, int current_bid ) {
	if( ( _wallet - ( money + current_bid) ) < 0 ) {
		_bid += _wallet;
		_wallet = 0;
		withdraw();
	} else {
		_wallet -= money + current_bid;
		_bid += money + current_bid;
	}
}

void Buyer::withdraw() {
	is_active = false;
}

void Buyer::set_name() {

	std::string _names[ 10 ] = { "John", "Tex", "Dan", "Locke", "Bjourne", "Vanessa", "Emma", "Natalya", "Jackson", "Jim" };
	_name = _names[ util::random_number( 0, 9 ) ];
}

int Buyer::funds() { return _wallet; }

std::string Buyer::name() { return _name; }

int Buyer::bid() { return _bid; }

const bool& Buyer::is_playing() const {
	return is_active;
}

Buyer::~Buyer() { }

