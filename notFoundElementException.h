#pragma once
#include <stdexcept>


class ElementNotFoundException :
    public std::runtime_error {
private:
    const char* message;
public:
    ElementNotFoundException(const char* msg) :
        std::runtime_error(msg), message(msg) {
    }
    const char* what() const noexcept {
        return message;
    }

};