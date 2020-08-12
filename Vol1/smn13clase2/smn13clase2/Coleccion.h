#pragma once
#include<fstream>
#include"Header.h"
ref class Imagenes {
	cli::array<Imagen^>^arreglo;
	int contador;
	Imagenes() {
		contador = 0;
		arreglo = gcnew array<Imagen^>(100);
	
	}

	void insertar(int x, int y)
	{
		if(contador<arreglo->Length)
		arreglo[contador] = gcnew Imagen(x, y);
		contador++;
	}


	void graficar(Graphics ^gr)
	{

		for (int i = 0; i < arreglo->Length; ++i) {
			arreglo[i]->graficar(gr);
		}
	}

	void mover(Graphics^ gr)
	{
		for (int i = 0; i < arreglo->Length; ++i)
		{
			arreglo[i]->mover(gr);

		}
	}

	void guardarTodo()
	{
		std::ofstream archivo("juego.txt");
		for (short i = 0; i < arreglo->Length; ++i)
		{
			archivo << arreglo[i]->getX() << "  " << arreglo[i]->getY() << std::endl;
		}
		archivo.close();
	}


};