#pragma once
#include "produs.h"
#include<vector>
using namespace std;

template<class obiect>class Repo {
private:
	vector<obiect> elem;
public:
	int length;
	Repo();
	virtual void addElement(obiect element);
	virtual bool removeElement(const obiect& element);
	virtual bool updateElement(const obiect& element, const obiect& elementNou);
	virtual bool findElement(const obiect& element);
	vector<obiect>& getAll();
	obiect getElem(int poz);
	int size();
	~Repo();

};

template<class obiect>
inline Repo<obiect>::Repo()
{
	this->length = 0;
}

template<class obiect>
inline void Repo<obiect>::addElement(obiect element)
{
	this->elem.push_back(element);
	this->length++;
}

//template<class obiect>
//inline void Repo<obiect>::cantitateElement(obiect& element, int cantitate)
//{
//	int v[20] = { 0 }, i = 0;
//	while (i < length)
//	{
//		if (findElement(element))
//			v[i] = cantitate;
//	}
//
//}

template<class obiect>
inline bool Repo<obiect>::removeElement(const obiect& element)
{
	if (findElement(element)) {
		int poz = 0;
		while (poz < length && !(elem.at(poz) == element))
			poz++;
		for (int i = poz; i < length - 1; i++)
			this->elem.at(i) = this->elem.at(i + 1);
		this->elem.pop_back();
		this->length--;
		return true;
	}
	return false;
}

template<class obiect>
inline bool Repo<obiect>::updateElement(const obiect& element, const obiect& elementNou)
{
	if (findElement(element)) {
		int i = 0;
		while (i < length && !(this->elem.at(i)== element))
			i++;
		this->elem.at(i) = elementNou;
		return true;
	}
	return false;
}

template<class obiect>
inline bool Repo<obiect>::findElement(const obiect& element)
{
	int i = 0;
	while (i < this->length) {
		if (this->elem.at(i) == element)
			return true;
		i++;
	}
	return false;
}

template<class obiect>
inline vector<obiect>& Repo<obiect>::getAll()
{
	return this->elem;
}

template<class obiect>
inline obiect Repo<obiect>::getElem(int poz)
{
	return this->elem[poz];
}

template<class obiect>
inline int Repo<obiect>::size()
{
	return this->length;
}

template<class obiect>
inline Repo<obiect>::~Repo()
{
	this->length = 0;
}
