#include "repoFile.h"
#include <fstream>
#include<algorithm>
#include<sstream>
#include<string>
#include "produs.h"
#include<iostream>
using namespace std;

void RepoFile::load_from_file()
{
	ifstream in(fileName);
	while (!in.eof())
	{
		string cod;
		string nume;
		string pret;
		string noProduse;
		getline(in, cod);
		getline(in, nume);
		getline(in, pret);
		getline(in, noProduse);

		try {
			int cod1 = stoi(cod);
			int pret1 = stoi(pret);
			int noProduse1 = stoi(noProduse);

			Produs produs(cod1, nume, pret1, noProduse1);
			if (nume != "")
				Repo<Produs>::addElement(produs);
		}
		catch (const std::invalid_argument& e) {
			cout << "Invalid argument exception: " << e.what() << endl;
		}
	}
}

void RepoFile::write_to_file()
{
	ofstream out(fileName);
	for (auto& produs : Repo<Produs>::getAll())
	{
		out << produs.getCod() << endl;
		out << produs.getNume() << endl;
		out << produs.getPret() << endl;
		out << produs.getNoProdus() << endl;
	}
	out.close();
}
