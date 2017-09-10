#include "Buyer.h"

Buyer::Buyer() : _wallet( util::random_number( 1000, 1500 ) ), is_active( true ), _bid( 0 ) { set_name(); }

void Buyer::bet( int money ) {
	if( ( _wallet - money ) < 0 ) {
		_wallet = 0;
	} else {
		_wallet -= money;
	}
}

void Buyer::withdraw() {
	is_active = false;
}

void Buyer::set_name() {

	std::string _names[ 10 ] = { "John", "Tex", "Dan", "Locke", "Bjourne", "Vanessa", "Emma", "Natalya", "Jackson", "Jim" };
	_name = _names[ util::random_number( 0, 10 ) ];
}

int Buyer::funds() { return _wallet; }

std::string Buyer::name() { return _name; }

int Buyer::bid() { return _bid; }

Buyer::~Buyer() { }

