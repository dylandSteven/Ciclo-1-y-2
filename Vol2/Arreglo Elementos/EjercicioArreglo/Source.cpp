#include <ctime>
#include <iostream>
#include <conio.h>

#include "ArrPlanVacac.h"

using namespace std;

int main()
{
	srand(time(NULL));
	arrPlanVac* arreglo = new arrPlanVac();

	arreglo->agregar();
	arreglo->agregar();
	arreglo->agregar();
	arreglo->agregar();
	arreglo->agregar();
	arreglo->agregar();
	arreglo->agregar();

	arreglo->ListarTodo();
	_getch();
	system("cls");
	arreglo->ListarPlanVacacMismoHotel("Marriot");
	_getch();
	system("cls");
	arreglo->ListarProFecha(1990, 2010);
	_getch();
	system("cls");
	arreglo->ListarBoletosPlanVacac();

	_getch();
	return 0;
}