#pragma once
#include "service.h"

class UI {
private:
	Service& service;
public:
	UI() = default;
	UI(Service& service1);
	~UI();
	void afisareMeniu(int optiune);

	void adaugareProdus();
	void cautareProdus();
	void stergereProdus();
	void actualizareProdus();
	void afisareProduse();

	void cautareBani();
	void stergereBani();
	void actualizareBani();
	void afisareBani();
	void achizitieProdusClient();
};