#pragma once
#include<string>
#include<iostream>
#include"Fecha.h"
#include"Hotel.h"
#include"Boleto.h"
using namespace std;

class PlanVac :public Hotel, public Boleto
{
private:
	int duracion;
	int presupuesto;

public:
	PlanVac()
	{
		duracion = rand() % 11;
		presupuesto = rand() % 20000;
	}
	~PlanVac() {}

	void getInfoPlanVacac()
	{
		cout << "Duracion: " << duracion << endl;
		cout << "Presupuesto: " << presupuesto << endl;
		getInfoBoleto();
		getInfoHotel();
	}

};