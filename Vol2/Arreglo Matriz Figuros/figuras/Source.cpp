#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include<conio.h>
#include"Avion.h"
#include"Moto.h"
#include"Vehiculo.h"
#include"VehiculoAereo.h"
#include"VehiculoTerrestre.h"
#include"Persona.h"
using namespace std;
using namespace System;


int main() {
	Console::CursorVisible = false;

	char opcion;

	do{

		cout << "Eliga una opcion: "<<endl;
		cout << "[C]Coche" << endl;
		cout << "[H]Helicoptero" << endl;
		cout << "[A]Avion" << endl;
		cout << "[M]Moto: " << endl;
		cout << "[S]Salir: " << endl;
		cin >> opcion;

	}while (!(opcion=='C'||opcion=='M'|| opcion == 'A'|| opcion == 'S'|| opcion == 'H'));
	if (opcion != 'S') {

		switch (opcion)
		{
		//case 'C':    break;
		case 'M':  
			
			Moto* objMoto;

			objMoto = new Moto(4, 15);
			objMoto->AsignarCoordenadaXY();
			Console::Clear();
			while (!_kbhit()) {
				objMoto->Borrar();
				objMoto->MoverFigura();
				objMoto->mostrarFigura();
				Sleep(50);
			}
			delete objMoto;
			
			break;
		//case 'H':    break;
		case 'A':    
			

			Avion* objAvion;

			objAvion = new Avion(6, 19);
			objAvion->AsignarCoordenadaXY();
			Console::Clear();
			while (!_kbhit()) {
				objAvion->Borrar();
				objAvion->MoverFigura();
				objAvion->mostrarFigura();
				Sleep(50);
			}
			delete objAvion;

			break;
		case 'C':
			Persona* nuePersona;
			nuePersona = new Persona(3, 3);
			nuePersona->AsignarCoordenadaXY();
			Console::Clear();

			while (!_kbhit())
			{
				nuePersona->Borrar();
				nuePersona->MoverFigura();
				nuePersona->mostrarFigura();
				Sleep(50);

			}

			
			
			break;
		default:cout << "Opcion no valida";
			break;
		}


	}
	else {
		exit(0);
	}


	return 0;
}