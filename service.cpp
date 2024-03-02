#include "service.h"
#include<string.h>
#include "produs.h"
#include "money.h"
#include "invalidMoneyValueException.h"
#include "invalidCodeException.h"
#include "notFoundElementException.h"
#include "moneyValidator.h"
#include "produsValidator.h"


Service::Service(const Service& service1): produsRepo(service1.produsRepo), moneyRepo(service1.moneyRepo)
{
	
}

Service::Service(RepoFile produsRepo, Repo<Money>& moneyRepo) :
	produsRepo(produsRepo), moneyRepo(moneyRepo)
{
	this->produsRepo = produsRepo;
	this->moneyRepo = moneyRepo;
}


void Service::addProdus(int cod, string nume, int pret, int noProdus)
{
	ProdusValidator val(0, 0);
	Produs p(cod, nume, pret, noProdus);
	try {
		val.validate(p.getCod(), p.getNume(), p.getPret());
		produsRepo.addElement(p);
	}
	catch (InvalidCodeException& ex) {
		cout << ex.what() << endl;
	}
	catch (InvalidNumeException& ex1) {
		cout << ex1.what() << endl;
	}
	catch (InvalidPretException& ex2) {
		cout << ex2.what() << endl;
	}
}

void Service::addMoney(int money, int noMoney)
{
	MoneyValidator val(1, 5, 10);
	Money mon(money, noMoney);
	try {
		val.validate(money);
		moneyRepo.addElement(mon);
	}
	catch (InvalidMoneyValueException& ex) {
		cout << ex.what() << endl;
		return;
	}
}

//void Service::cantitateProdus(Produs& produs, int cantitate)
//{
//	produsRepo.cantitateElement(produs, cantitate);
//}
//
//void Service::cantitateMoney(Money& money, int cantitate)
//{
//	moneyRepo.cantitateElement(money, cantitate);
//}

int Service::removeProdus(int cod, string nume, int pret, int noProdus)
{
	Produs p(cod, nume, pret, noProdus);
	try {
		if (!produsRepo.findElement(p))
			throw ElementNotFoundException("Produsul nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	return produsRepo.removeElement(p);
}

int Service::removeMoney(int value, int noMoney)
{
	Money m(value, noMoney);
	try {
		if (!moneyRepo.findElement(m))
			throw ElementNotFoundException("Bancnota nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	return moneyRepo.removeElement(m);
}

int Service::updateProdus(int codVechi, string numeVechi, int pretVechi, int noVechi, int codNou, string numeNou, int pretNou, int noNou)
{
	Produs produsVechi(codVechi, numeVechi, pretVechi, noVechi);
	try {
		if (!produsRepo.findElement(produsVechi))
			throw ElementNotFoundException("Produsul nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	Produs produsNou(codNou, numeNou, pretNou, noNou);
	return produsRepo.updateElement(produsVechi, produsNou);

}

int Service::updateMoney(int oldValue, int oldNo, int newValue, int newNo)
{
	Money oldMoney(oldValue, oldNo);
	try {
		if (!moneyRepo.findElement(oldMoney))
			throw ElementNotFoundException("Bancnota nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	Money newMoney(newValue, newNo);
	return moneyRepo.updateElement(oldMoney, newMoney);

}


int Service::findProdus(int cod, string nume, int pret, int noProdus)
{
	Produs p(cod, nume, pret, noProdus);
	try {
		if (!produsRepo.findElement(p))
			throw ElementNotFoundException("Produsul nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	return produsRepo.findElement(p);
}

int Service::findMoney(int value, int noMoney)
{
	Money m(value, noMoney);
	try {
		if (!moneyRepo.findElement(m))
			throw ElementNotFoundException("Bancnota nu exista!");
	}
	catch (ElementNotFoundException& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	return moneyRepo.findElement(m);
}

int Service::sumaClient()
{
	int sumaClient = 0;
	vector<Money> v = moneyRepo.getAll();
	for (int i = 0; i<v.size(); i++)
		sumaClient = sumaClient + v.at(i).getValue() * v.at(i).getNoMoney();
	return sumaClient;

}

int Service::sumaBancnote()
{
	int suma = 200;
	return suma;
}

int Service::achizitieProdus(int cod, int sumaClient1)
{
	sumaClient1 = sumaClient();
	int sumaBancnote1 = sumaBancnote();
	vector<Money> m = moneyRepo.getAll();
	vector<Produs> p = produsRepo.getAll();
	for(int i=0;i< p.size();i++)
		if (produsRepo.getElem(i).getCod() == cod && produsRepo.getElem(i).getNoProdus()>0)
		{
			if (sumaClient1 - produsRepo.getElem(i).getPret() == 0)
			{
				sumaClient1 = sumaClient1 - produsRepo.getElem(i).getPret();
				sumaBancnote1 = sumaBancnote1 + produsRepo.getElem(i).getPret();
				Produs p1(produsRepo.getElem(i).getCod(), produsRepo.getElem(i).getNume(), produsRepo.getElem(i).getPret(), produsRepo.getElem(i).getNoProdus());
				Produs p2(produsRepo.getElem(i).getCod(), produsRepo.getElem(i).getNume(), produsRepo.getElem(i).getPret(), produsRepo.getElem(i).getNoProdus() - 1);
				produsRepo.updateElement(p1, p2); // scade numarul de produse din tonomat
				return 1; // clientul are suma de bani egala cu pretul produsului)		
			}
			if (sumaClient1 - produsRepo.getElem(i).getPret() > 0)
			{
				sumaClient1 = sumaClient1 - produsRepo.getElem(i).getPret();
				int rest = sumaClient1 - produsRepo.getElem(i).getPret();
				if (rest >= sumaBancnote1)
				{
					return 2; // tonomatul nu are rest
				}
				else

				{
					sumaBancnote1 = sumaBancnote1 - rest + produsRepo.getElem(i).getPret();
					Produs p1(produsRepo.getElem(i).getCod(), produsRepo.getElem(i).getNume(), produsRepo.getElem(i).getPret(), produsRepo.getElem(i).getNoProdus());
					Produs p2(produsRepo.getElem(i).getCod(), produsRepo.getElem(i).getNume(), produsRepo.getElem(i).getPret(), produsRepo.getElem(i).getNoProdus() - 1);
					produsRepo.updateElement(p1, p2);
					return 3; // tonomatul poate oferi rest
				}
			}
			 else if (sumaClient1 < produsRepo.getElem(i).getPret())
			 {
				 return 4; // clientul nu are suficienti bani pentru produs
			 }
		}
		
	return 0; // produsul cautat nu exista
}


vector<Produs> Service::getAllProduse()
{
	return produsRepo.getAll();
}

vector<Money> Service::getAllMoney()
{
	return moneyRepo.getAll();
}


Service::~Service()
{
}

int Service::sizeProduse()
{
	return produsRepo.size();
}

int Service::sizeMoney()
{
	return moneyRepo.size();
}

