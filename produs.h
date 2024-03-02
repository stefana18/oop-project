#pragma once
#include<iostream>
using namespace std;

class Produs {
private:
	int cod;
	string nume;
	int pret;
	int noProdus;
public:
	Produs();
	Produs(int, string, int, int);
	Produs(const Produs&);
	Produs& operator=(const Produs&);
	bool operator == (const Produs&);
	~Produs();
	int getCod();
	int getPret();
	int getNoProdus();
	string getNume();
	void setCod(int);
	void setPret(int);
	void setNume(string);
	void setNoProdus(int);
};