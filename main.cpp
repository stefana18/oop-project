#include "teste.h"
#include "repo.h"
#include "service.h"
#include "money.h"
#include "ui.h"
#include "repoFile.h"
#include <iostream>
using namespace std;
int main()
{
	testeProdus();
	testeRepo();
	//testeService();
	testeMoney();
	testeProdusValidator();
	testeMoneyValidator();
	RepoFile produsRepo("C:\\Users\\Stefana\\source\\repos\\lab9OOP\\produs.txt");
	Repo<Money> moneyRepo;
	Service service(produsRepo, moneyRepo);
	UI ui(service);
	int optiune = 0;
	ui.afisareMeniu(optiune);
	return 0;
}
