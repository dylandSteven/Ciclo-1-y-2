#pragma once
#include"Usuario.h"
class Cola
{
public:
	Cola();
	~Cola();
	void atender();
	void atender(char tipo);
	bool insertarFinal(Usuario *n);
	Usuario* recuperar(short p);
	short getcDocentes();
	short getcPadres() ;
	short getcAlumnos();
	short longitud();


private:

	Usuario** colaA;
	short indice;
	short capacidad;
	short cDocentes;
	short cPadres;
	short cAlumnos;

};


