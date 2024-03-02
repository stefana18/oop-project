#pragma once
#include <stdexcept>

class InvalidPretException :
	public std::invalid_argument {
private:
	const char* message;
public:
	InvalidPretException(const char* msg):
		std::invalid_argument(msg), message(msg) {
	}
	const char* what() const noexcept {
		return message;
	}
};