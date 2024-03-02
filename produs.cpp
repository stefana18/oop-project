#include "produs.h"

Produs::Produs()
{
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
	this->noProdus = 0;
}

Produs::Produs(int c, string n, int p, int np)
{
	this->cod = c;
	this->nume = n;
	this->pret = p;
	this->noProdus = np;
}

Produs::Produs(const Produs& produs)
{
	this->cod = produs.cod;
	this->pret = produs.pret;
	this->nume = produs.nume;
	this->noProdus = produs.noProdus;
}

Produs& Produs::operator=(const Produs& produs)
{
	if (this != &produs)
	{
		if (produs.nume != "") {
			this->nume = produs.nume;
		}
		this->cod = produs.cod;
		this->pret = produs.pret;
		this->noProdus = produs.noProdus;
	}
	return *this;
	
}

bool Produs::operator==(const Produs& produs)
{
	return this->nume == produs.nume && produs.cod == this->cod && produs.pret == this->pret && produs.noProdus == this->noProdus;

}

Produs::~Produs()
{
	this->nume = "";
	this->cod = 0;
	this->pret = 0;
	this->noProdus = 0;
}

int Produs::getCod()
{
	return this->cod;
}

int Produs::getPret()
{
	return this->pret;
}

int Produs::getNoProdus()
{
	return this->noProdus;
}

string Produs::getNume()
{
	return this->nume;
}

void Produs::setCod(int c)
{
	this->cod = c;
}

void Produs::setPret(int p)
{
	this->pret = p;
}

void Produs::setNume(string n)
{
	this->nume = n;

}

void Produs::setNoProdus(int np)
{
	this->noProdus = np;
}
