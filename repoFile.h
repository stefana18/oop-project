#pragma once
#include "produs.h"
#include<fstream>
#include<string>
#include <vector>
#include "repo.h"

using namespace std;

class RepoFile: public Repo<Produs>{
private:
	string fileName;
	void load_from_file();
	void write_to_file();
	void clear_file() {
		ofstream filestream(fileName, ios::trunc);
		filestream.close();
	}
public:
	RepoFile(string fileName) : Repo(), fileName{ fileName } {
		load_from_file();
	}
	void addElement(Produs p) override {
		Repo<Produs>::addElement(p);
		write_to_file();
	}
	bool removeElement(const Produs& p) override {
		return Repo<Produs>::removeElement(p);
		write_to_file();
	}
	bool updateElement(const Produs& p1, const Produs& p2) override {
		return Repo<Produs>::updateElement(p1, p2);
		write_to_file();
	}
	bool findElement(const Produs& p) override {
		return Repo<Produs>::findElement(p);
		write_to_file();
	}
	
};