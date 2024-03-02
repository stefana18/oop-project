#include "money.h"

Money::Money() {
	this->value = -1;
	this->noMoney = 0;
}

Money::Money(int mValue, int noMoney) {
	this->value = mValue;
	this->noMoney = noMoney;
}

Money::Money(const Money& money)
{
	this->value = money.value;
	this->noMoney = money.noMoney;
}

int Money::getValue() const
{
	return this->value;
}
void Money::setValue(int mValue) {
	this->value = mValue;
}

int Money::getNoMoney() const
{
	return this->noMoney;
}

void Money::setNoMoney(int noMoney)
{
	this->noMoney = noMoney;
}


Money& Money::operator=(const Money& money)
{
	if (this != &money)
	{
		this->value = money.value;
		this->noMoney = money.noMoney;
	}
	return*this;
}

bool Money::operator==(const Money& money)
{
	return money.value == this->value && money.noMoney == this->noMoney;
}

bool Money::operator<(const Money& money) const {
	return this->value < money.value && this->noMoney < money.noMoney;

}

Money::~Money() = default;