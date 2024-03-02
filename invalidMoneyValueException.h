#pragma once
#include <stdexcept>

class InvalidMoneyValueException : public std::invalid_argument {
private:
   const char* msg;
public:
    InvalidMoneyValueException(const char* message) :
        std::invalid_argument(message), msg(message) {

    }
    const char* what() const noexcept {
        return msg;
    }

};