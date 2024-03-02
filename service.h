#pragma once
#include "repo.h"
#include "repoFile.h"
#include "money.h"
#include<vector>
#include "produs.h"
class Service {
private:
	RepoFile produsRepo;
	Repo <Money> moneyRepo;
public:
	Service();
	Service(const Service& service1);
	Service(RepoFile produsRepo, Repo<Money>& moneyRepo);

	void addProdus(int, string, int, int);
	void addMoney(int, int);

	//void cantitateProdus(Produs&, int);
	//void cantitateMoney(Money&, int);

	int removeProdus(int, string, int, int);
	int removeMoney(int, int);

	int updateProdus(int, string, int, int, int, string, int, int);
	int updateMoney(int, int, int, int);

	int findProdus(int, string, int, int);
	int findMoney(int, int);

	int sumaClient();
	int sumaBancnote();
	int achizitieProdus(int, int);

	vector<Produs> getAllProduse();
	vector<Money> getAllMoney();
	~Service();
	int sizeProduse();
	int sizeMoney();

};