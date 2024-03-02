#include "produs.h"
#include "repo.h"
#include "service.h"
#include<vector>
#include<cassert>
#include<string.h>
#include "repoFile.h"
#include "produsValidator.h"
#include "moneyValidator.h"
#include "invalidCodeException.h"
#include "invalidNumeException.h"
#include "invalidPretException.h"
#include "invalidMoneyValueException.h"
#include "notFoundElementException.h"

using namespace std;

void testeProdus() {
	Produs p1;
	assert(p1.getCod() == 0);
	assert(p1.getNume() == "");
	assert(p1.getPret() == 0);

	Produs p2(1, "Cola", 10, 10);
	assert(p2.getCod() == 1);
	assert(p2.getNume()=="Cola");
	assert(p2.getPret() == 10);

	p1 = p2;
	assert(p1.getCod() == 1);
	assert(p1.getNume()== "Cola");

	p2.setPret(20);
	assert(p2.getPret() == 20);
}

void testeMoney() {
	Money m1;
	assert(m1.getValue() == -1);

	Money m2(10, 2);
	assert(m2.getValue() == 10);
	m1 = m2;
	assert(m1.getValue() == 10);

}
void testeRepo() {

	RepoFile repo("C:\\Users\\Stefana\\source\\repos\\lab9OOP\\produsTest.txt");
	Produs p(1, "Cola", 10, 70);
	repo.addElement(p);
	assert(repo.size() == 1);
	Produs p1 = repo.getElem(0);

	Produs p2(2, "Bounty", 10, 30);
	repo.addElement(p2);
	assert(repo.size() == 2);

	repo.removeElement(p2);
	assert(repo.size() == 1);

	assert(repo.findElement(p1) == 1);

	Produs p3(1, "Raffaello", 10, 40);
	repo.updateElement(p, p3);
	assert(repo.getElem(0).getCod() == 1);
	assert(repo.getElem(0).getPret() == 10);
	assert(repo.getElem(0).getNume()=="Raffaello");

}

void testeService() {
	RepoFile produsRepo("C:\\Users\\Stefana\\source\\repos\\lab9OOP\\produsTest.txt");
	Repo<Money> moneyRepo;
	Service service(produsRepo, moneyRepo);
	Produs p1(10, "Bueno", 15, 10);
	service.addProdus(10, "Bueno", 15, 10);
	assert(service.sizeProduse() == 2);

	Produs p2(20, "Kinder", 15, 50);
	service.updateProdus(10, "Bueno", 15, 10, 20, "Kinder", 15, 50);
	

	Produs p3(30, "Milka", 20, 10);
	service.addProdus(30, "Milka", 20, 10);
	service.removeProdus(30, "Milka", 20, 10);
	assert(service.sizeProduse() == 2);
	
	service.addMoney(10, 5);
	assert(service.sizeMoney() == 1);

	service.addMoney(10, 5);
	service.removeMoney(10, 5);
	assert(service.sizeMoney() == 1);

	int s = service.sumaClient();
	assert(s == 50);
	assert(service.achizitieProdus(20, s) == 3);

	assert(service.achizitieProdus(25, s) == 0);

	service.removeMoney(10, 5);
	service.addProdus(1, "suc", 5, 2);
	service.addMoney(1, 1);
	int s1 = service.sumaClient();
	assert(service.achizitieProdus(1, s1) == 4);

	service.removeMoney(1, 1);
	service.addMoney(5, 1);
	int s2 = service.sumaClient();
	assert(service.achizitieProdus(1, s2) == 1);

}

void testeProdusValidator(){
	ProdusValidator val(0, 0);
	Produs p(-5, "apa", 5, 5);
	try {
		val.validate(p.getCod(), p.getNume(), p.getPret());
		assert(false);
	}
	catch(InvalidCodeException&){
		assert(true);
	}

	Produs p2(5, "suc", -5, 10);
	try {
		val.validate(p2.getCod(), p2.getNume(), p2.getPret());
		assert(false);
	}
	catch (InvalidPretException&) {
		assert(true);
	}

	RepoFile produsRepo("C:\\Users\\Stefana\\source\\repos\\lab9OOP\\produsTest.txt");
	Produs p3(5, "suc", 10, 10);
	try {
		produsRepo.findElement(p3);
		assert(true);
	}
	catch (ElementNotFoundException&) {
		assert(true);
	}	
}

void testeMoneyValidator(){
	MoneyValidator val(1, 5, 10);
	Money m(7, 2);
	try {
		val.validate(m.getValue());
		assert(false);
	}
	catch (InvalidMoneyValueException&) {
		assert(true);
	}
}
