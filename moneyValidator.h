#pragma once

#include "invalidMoneyValueException.h"
class MoneyValidator {
private:
	int firstValidValue;
	int secondValidValue;
	int thirdValidValue;
public:
	MoneyValidator(int firstValue, int secondValue, int thirdValue) : firstValidValue(firstValue), secondValidValue(secondValue), thirdValidValue(thirdValue) {
	} 

	void validate(int value) {
		if (value != firstValidValue && value != secondValidValue && value != thirdValidValue)
			throw InvalidMoneyValueException("Valoarea trebuie sa fie 1, 5 sau 10!");
	}

};