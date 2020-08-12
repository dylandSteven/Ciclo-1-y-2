#pragma once
#include<iostream>
#include"Bola.h"
#include"Coleccion.h"
using namespace System::Drawing;

class CControlador {
public:
	CControlador(Bitmap^ imagen, Graphics^ lienzo) {
		coleccion = new CColeccion();
		bola = new CBola();
		coleccion->generar();
		bola->inicializar(imagen, lienzo);
	}

	void dibujarTodo(Bitmap^ imagen, Graphics^ lienzo)
	{
		lienzo->Clear();
		if (coleccion->colisiona(Rectangle(bola->getX(), bola->getY(), bola->getAncho(), bola->getAlto())))
			bola->disminuye();
		coleccion->dibujarPrimitivas(lienzo);

		bola->dibujar(imagen, lienzo);
	}
	void actualizarDir(int x, int y)
	{
		bola->setAngulo(x, y);
	}
	void moverTodo()
	{
		bola->mover();
		bola->animar();
	}
private:
	CColeccion* coleccion;
	CBola* bola;
};