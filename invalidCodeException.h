#pragma once
#include <stdexcept>

class InvalidCodeException :
    public std::invalid_argument {
private:
    const char* message;
public:
    InvalidCodeException(const char* msg) :
        std::invalid_argument(msg), message(msg) {
    }
    const char* what() const noexcept{
        return message;
    }

};