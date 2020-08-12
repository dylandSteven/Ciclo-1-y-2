#pragma once

#include<cstdlib>
#include<ctime>
#include"Personajeadm.h"
//ref class  ControlJuego
//{
//public:
//	ControlJuego(Graphics ^canvas) {
//		personajes = gcnew array<PersonajeADM^>(5);
//		for (int i = 0; i < 5; ++i) {
//			personajes[i] = gcnew PersonajeADM(canvas, rand() % 300, rand() % 300);
//		}
//	}
//
//	void graficar() 
//	{
//		for (int i = 0; i < 5; ++i) {
//			personajes[i]->dibujar();
//		}
//	
//	}
//
//	void mover() {
//		for (int i = 0; i < 5; i++)
//		{
//			personajes[i]->moverAutomatico();
//		
//		}
//	
//	}
//	
//private:
//	cli::array<PersonajeADM^>^ personajes;
//	
//};

ref class Controladora 
{
	array<PersonajeADM^>^ coleccion;
	PersonajeADM^ jugador;
	int tam;
public:

	Controladora(Graphics^ canvas, int  nro)
	{
		tam = nro;
		coleccion = gcnew array<PersonajeADM^>(nro);
		jugador = gcnew PersonajeADM(canvas,50,50,1);
		for (int i = 0; i < nro; ++i)
		{
			coleccion[i] = gcnew PersonajeADM(canvas, rand() % 400, rand() % 400,i+1);
		}
	}
		void graficar()
		{
			jugador->dibujar();
			for (int i = 0; i < tam; ++i)
			{
				coleccion[i]->dibujar();
			}
		}

		void moverNPC() {

			for (int i = 0; i < tam; i++)
			{
				coleccion[i]->moverAutomatico();
			}
		}
		void mover(System::Windows::Forms::KeyEventArgs^ e) {

			jugador->mover(e);
		}

	/*	void determinarColision() {
			for (int i = 0; i < tam; i++)
			{
				coleccion[i]->colision();
			}
		}*/
};