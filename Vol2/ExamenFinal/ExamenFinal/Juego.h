#pragma once
#include "jugadorAmbulancia.h"
#include"PersonasCorren.h"
#include"PersonasJuegan.h"
#include<fstream>
using namespace std;
class Juego {

private:

	jugadorAmbulancia* objAmbulancia;
	PersoCorrenS* objCorren;
	PersoJueganS* objJuegan;
	int tiempo;
	clock_t start;
public:


	Juego() {
	
		objAmbulancia = new jugadorAmbulancia();
		objCorren = new PersoCorrenS();
		objJuegan = new PersoJueganS();

		tiempo = 60;
		start = clock();
	};



	void dibujar(Graphics ^g , Bitmap ^bmpJugador, Bitmap ^corren, Bitmap ^juegan)
	{
		g->DrawString("Tiempo: " + tiempo.ToString(), gcnew Font("Arial ", 12), Brushes::Black, 0, 20);
		g->DrawString("Puntos: " + objAmbulancia->getPuntos().ToString(), gcnew Font("Arial", 12), Brushes::Black,0,0);
		objAmbulancia->dibujar(g , bmpJugador);
		objCorren->Mostrar(g, corren);
		objJuegan->Mostrar(g, juegan);
	}


	void mover(Graphics^ g) {
	
		objAmbulancia -> mover(g);
		objCorren->mover(g);
		objJuegan->mover(g);

		

		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			tiempo--;
			start = clock();
		}
		if (tiempo%5 ==0) {
			if(rand()%50==0)
			objCorren->agregarEnemigo(new PersonasCorren());
			objJuegan->agregarEnemigo(new PersonasJuegan());
		
		}
	}



	void colisionEnemigoCorren() {
	
		for (int j = 0; j < objCorren->getCantidad(); j++) {
			PersonasCorren* enm = objCorren->getPersonanCorren(j);
			if (enm->Zoom().IntersectsWith(objAmbulancia->Zoom()));
			objAmbulancia->setPuntos(objAmbulancia->getPuntos()+50);
			//objCorren->EliminarEnemigo(j--);
			break;
	}
	
	}



	void colisionEnemigoJuega() {

		for (int i = 0; i < objJuegan->getCantidad(); i++) {
			PersonasJuegan* enm = objJuegan->getPersonaJuegan(i);

			if (enm->Zoom().IntersectsWith(objAmbulancia->Zoom()));
			objAmbulancia->setPuntos(objAmbulancia->getPuntos() + 50);
			//objCorren->EliminarEnemigo(i--);
			break;
		}
	  }

	
		
	
	void setTiempo(int valor) { tiempo = valor; }
	int getTiempo() { return tiempo; }



	void guardar() {
		ofstream file("configuracion.txt");

		file << objAmbulancia->getPuntos();
		file << tiempo;

		file.close();
	}
	jugadorAmbulancia* getJUgador() { return objAmbulancia; }
};