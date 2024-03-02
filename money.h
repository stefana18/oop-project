#pragma once

#include<iostream>
using namespace std;

class Money {
private:
	int value;
	int noMoney;
public:
	Money();
	Money(int, int);
	Money(const Money& money);
	int getValue() const;
	void setValue(int);
	int getNoMoney() const;
	void setNoMoney(int);
	Money& operator=(const Money&);
	bool operator==(const Money&);
	bool operator<(const Money& money) const;
	~Money();
	
};