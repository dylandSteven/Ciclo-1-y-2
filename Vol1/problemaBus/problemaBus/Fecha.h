#pragma once
class Fecha {

private:

	int dia, mes, anho;
	int hora, minuto;

public:

	Fecha(int dia, int mes, int anho, int hora, int minuto)
	{
		this->dia = dia;
		this->mes = mes;
		this->anho = anho;
		this->hora = hora,
			this->minuto = minuto;
	}

	int getdia() { return dia; }
	int getmes() { return mes; }
	int getanho() { return anho; }
	int gethora() { return hora; }
	int getminuto() { return minuto; }


};