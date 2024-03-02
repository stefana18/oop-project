#pragma once
#include <stdexcept>

class InvalidNumeException :
	public std::invalid_argument {
private:
	const char* message;
public:
	InvalidNumeException(const char* msg):
		std::invalid_argument(msg), message(msg) {
	}
	const char* what() const noexcept {
		return message;
	}
};