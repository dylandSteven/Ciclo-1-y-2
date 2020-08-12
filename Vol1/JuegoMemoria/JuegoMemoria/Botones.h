 #pragma once
#define MAX 16
using namespace System::Windows::Forms;
using namespace System;
using namespace System::Drawing;


ref class Botones
{


	array<Button^>^ botones;
	short j; short indice = 0;
public:
	Botones() {
		botones = gcnew array<Button^>(16);
	}

	void poblar(Panel^ p) {

		Random r;
		int x;
		int y;

		for (short i = 0; i < MAX; i++)
		{

			if (i == 4) { i = 0; j++; }
			if (j == 4) { break; }//listaBotones->poblar(panel1);
			boton(p, i, j);
		}
	}

	void boton(Panel^ p, short i, short j) {
		botones[indice] = gcnew Button();
		botones[indice]->Location = Point(20 + 100 * i, 20 + 100 * j);
		botones[indice]->Size = Size(100, 100);
		botones[indice]->Name = "Boton" + indice;
		p->Controls->Add(botones[indice]);
		indice++;
	}



	Button^ recuperar(int pos) {
		if (pos >= 0 && pos < MAX) {
			return botones[pos];
		}
	}

	int cantidad() {
		return MAX;
	}

};