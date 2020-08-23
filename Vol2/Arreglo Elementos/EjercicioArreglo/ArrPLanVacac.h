#pragma once
#pragma once
#include<string>
#include<iostream>
#include"Fecha.h"
#include"Hotel.h"
#include"Boleto.h"
#include"PlanVac.h"
class arrPlanVac {

private:
	vector<PlanVac*>arreglo;

public:

	arrPlanVac() {}
	~arrPlanVac() {}

	void agregar() {
		PlanVac* arr = new PlanVac();
		arreglo.push_back(arr);
	}
	void eliminar()
	{
		arreglo.pop_back();
	}

	void ListarProFecha(int banio, int aanio)
	{
		for (int i = 0; i < arreglo.size(); i++) {

			if (arreglo[i]->getanho() > banio && arreglo[i]->getanho() < aanio) {

				arreglo[i]->getInfoPlanVacac();
			}

		}
	}
	void ListarPlanVacacMismoHotel(string nombre) {
		for(int i = 0; i < arreglo.size();i++)
		{
			if (arreglo[i]->getNombre() == nombre) {

				arreglo[i]->getInfoPlanVacac();
		}
		
		}
		}

	void ListarBoletosPlanVacac()
	{
		for (int i = 0; i < arreglo.size(); i++)
		{
			arreglo[i]->getInfoBoleto();
		}
	}

	void ListarTodo()
	{
		for (int i = 0; i < arreglo.size(); i++)
		{
			arreglo[i]->getInfoPlanVacac();
		}
	}

};