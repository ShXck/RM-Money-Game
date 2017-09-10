#ifndef BUYER_H_
#define BUYER_H_
#include "util.h"
#include <iostream>
#include <string>

class Buyer {
public:
	Buyer();
	void bet( int money );
	void withdraw();
	int funds();
	std::string name();
	int bid();
	virtual ~Buyer();
private:
	void set_name();
private:
	int _wallet;
	bool is_active;
	std::string _name;
	int _bid;
};

#endif /* BUYER_H_ */
