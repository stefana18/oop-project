#pragma once
#include "invalidCodeException.h"
#include "invalidNumeException.h"
#include "invalidPretException.h"

class ProdusValidator {
private:
    int validCode;
    int pretValid;
public:
    ProdusValidator(int code, int pret) : validCode(code), pretValid(pret){
    }

    void validate(int code, string nume, int pret) {
            if (code < validCode)
                throw InvalidCodeException("Codul trebuie sa fie numar natural!");
            if (nume =="")
                throw InvalidNumeException("Numele nu poate fi gol!");
            if (pret < pretValid)
                throw InvalidPretException("Pretul trebuie sa fie numar natural!");
        }
};