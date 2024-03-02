#include "ui.h"
#include<iostream>
#include<vector>
using namespace std;

void UI::adaugareProdus()
{
	int cod;
	cout << "Introduceti codul produsului: " << endl;
	cin >> cod;

	string nume;
	cout << "Introduceti numele produsului: " << endl;
	cin >> nume;
	/*cin.get();
	cin.getline(nume, 20);*/

	int pret;
	cout << "Introduceti pretul produsului: " << endl;
	cin >> pret;

	int noProdus;
	cout << "Introduceti numarul de produse: " << endl;
	cin >> noProdus;
	this->service.addProdus(cod, nume, pret, noProdus);
}



void UI::cautareProdus()
{
	int cod;
	cout << "Introduceti codul produsului: " << endl;
	cin >> cod;

	string nume;
	cout << "Introduceti numele produsului: " << endl;
	cin >> nume;

	int pret;
	cout << "Introduceti pretul produsului: " << endl;
	cin >> pret;

	int noProdus;
	cout << "Introduceti numarul de produse: " << endl;
	cin >> noProdus; 

	int rez = this->service.findProdus(cod, nume, pret, noProdus);
	if (rez != 0)
	{
		cout << "Produsul exista!" << endl;
	}
	
}

void UI::stergereProdus()
{
	int cod;
	cout << "Introduceti codul produsului: " << endl;
	cin >> cod;

	string nume;
	cout << "Introduceti numele produsului: " << endl;
	cin >> nume;
	/*cin.get();
	cin.getline(nume, 20);*/

	int pret;
	cout << "Introduceti pretul produsului: " << endl;
	cin >> pret;

	int noProdus;
	cout << "Introduceti numarul de produse:  " << endl;
	cin >> noProdus;

	int rez = this->service.removeProdus(cod, nume, pret, noProdus);
	if (rez != 0) 
	{
		cout << "Produsul a fost sters cu succes!" << endl;
	}
}

void UI::actualizareProdus()
{
	int codVechi;
	cout << "Introduceti codul produsului care trebuie modificat: " << endl;
	cin >> codVechi;

	string numeVechi;
	cout << "Introduceti numele produsului care trebuie modificat: " << endl;
	cin >> numeVechi;
	/*cin.get();
	cin.getline(numeVechi, 20);*/

	int pretVechi;
	cout << "Introduceti pretul produsului care trebuie modificat: " << endl;
	cin >> pretVechi;

	int noProdusVechi;
	cout << "Introduceti numarul de produse care trebuie modificat: " << endl;
	cin >> noProdusVechi;

	int cod;
	cout << "Introduceti noul cod al produsului: " << endl;
	cin >> cod;

	string nume;
	cout << "Introduceti noul nume al produsului: " << endl;
	cin >> nume;
	/*cin.get();
	cin.getline(nume, 20);*/

	int pret;
	cout << "Introduceti noul pret al produsului: " << endl;
	cin >> pret;

	int noProdus;
	cout << "Introduceti noul numar de produse: " << endl;
	cin >> noProdus;

	int rez = this->service.updateProdus(codVechi, numeVechi, pretVechi, noProdusVechi, cod, nume, pret, noProdus);
	if (rez != 0)
	{
		cout << "Produsul a fost actualizat cu succes!" << endl;
	}
}


void UI::afisareProduse()
{
	vector<Produs> v = this->service.getAllProduse();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).getCod() << endl;
		cout << v.at(i).getNume() << endl;
		cout << v.at(i).getPret() << endl;
		cout << v.at(i).getNoProdus() << endl;
	}
}


void UI::cautareBani()
{
	int value;
	cout << "Introduceti valoarea bancnotei cautata: " << endl;
	cin >> value;

	int noMoney;
	cout << "Introduceti numarul de bancnote cautate: " << endl;
	cin >> noMoney;

	int rez = this->service.findMoney(value, noMoney);
	if (rez != 0)
	{
		cout << "Bancnota exista!" << endl;
	}
}

void UI::stergereBani()
{
	int value;
	cout << "Introduceti valoarea bancnotei: " << endl;
	cin >> value;

	int noMoney;
	cout << "Introduceti numarul de bancnote: " << endl;
	cin >> noMoney;
	int rez = this->service.removeMoney(value, noMoney);
	if (rez != 0) 
	{
		cout << "Bancnota a fost stearsa cu succes!" << endl;
	}
}

void UI::actualizareBani()
{
	int oldValue, newValue, oldNoMoney, newNoMoney;
	cout << "Introduceti valoarea bancnotei care trebuie modificata: " << endl;
	cin >> oldValue;
	cout << "Introduceti numarul de bancnote care trebuie modificate: " << endl;
	cin >> oldNoMoney;
	cout << "Introduceti noua valoare a bancnotei: " << endl;
	cin >> newValue;
	cout << "Introduceti noul numar de bancnote: " << endl;
	cin >> newNoMoney;

	int rez = this->service.updateMoney(oldValue, oldNoMoney, newValue, newNoMoney);
	if (rez != 0)
	{
		cout << "Bancnota fost actualizata cu succes!" << endl;
	}
}

void UI::afisareBani()
{
	vector<Money> v = this->service.getAllMoney();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).getValue() << endl;
		cout << v.at(i).getNoMoney() << endl;
	}
}

void UI::achizitieProdusClient()
{
	int value, noMoney;
	cout << "Introduceti valoarea bancnotei: " << endl;
	cin >> value;
	cout << "Introduceti numarul de bancnote: " << endl;
	cin >> noMoney;
	this->service.addMoney(value, noMoney);

	int sumaClient1 = service.sumaClient();
	int cod;
	cout << "Dati codul produsului pe care il doriti:  " << endl;
	cin >> cod;
	int rez = this->service.achizitieProdus(cod, sumaClient1);
	if (rez == 0)
		cout << "Produsul nu exista!" << endl;
	if (rez == 1)
		cout << "Achizitia a fost efectuata cu succes!" << endl;
	if (rez == 2)
		cout << "Tonomatul nu va poate oferi rest!" << endl;
	if (rez == 3)
		cout << "Tonomatul va poate oferi rest!" << endl;
	if (rez == 4)
		cout << "Nu aveti suficienti bani!" << endl;


}



void UI::afisareMeniu(int optiune)
{
	cout << "1. Adauga un produs: " << endl;
	cout << "2. Cauta un produs: " << endl;
	cout << "3. Sterge un produs: " << endl;
	cout << "4. Actualizeaza un produs: " << endl;
	cout << "5. Afiseaza lista de produse: " << endl;
	cout << endl;
	cout << "6. Cauta o bancnota: " << endl;
	cout << "7. Sterge o bancnota: " << endl;
	cout << "8. Actualizeaza o bancnota: " << endl;
	cout << "9. Afiseaza lista de bancnote: " << endl;
	cout << "10. Achizitioneaza un produs: " << endl;
	cout << "0. Iesire din meniu." << endl;
	cout << "Alegeti o optiune: " << endl;
	cin >> optiune;
	do {
		switch (optiune)
		{
		case 1:
			adaugareProdus();
			break;
		case 2:
			cautareProdus();
			break;
		case 3:
			stergereProdus();
			break;
		case 4:
			actualizareProdus();
			break;
		case 5:
			afisareProduse();
			break;
		case 6:
			cautareBani();
			break;
		case 7:
			stergereBani();
			break;
		case 8:
			actualizareBani();
			break;
		case 9:
			afisareBani();
			break;
		case 10:
			achizitieProdusClient();
			break;
		case 0:
			optiune = 0;
			break;
		default:
			cout << "Tasta gresita. Reincercati!";
			cin >> optiune;
		}
		cout << "Alegeti o optiune: ";
		cin >> optiune;
	} while (optiune != 0);
	cout << "Programul s-a incheiat!";
}

UI::UI(Service& service1):service(service1)
{
}

UI::~UI()
{
}