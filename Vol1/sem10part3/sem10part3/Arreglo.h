#pragma once
#define MAXI 20
using namespace System::Windows::Forms;
using namespace System;
using namespace System :: Drawing;

ref class Coleccion
{
	array<Button^>^ botones;
public:
	Coleccion() {
		botones = gcnew array<Button^>(20);

	}

	Void poblar(Panel^ p)
	{
		Random r;
		for (int i = 0; i < MAXI; ++i)
		{
			botones[i] = gcnew Button();
			botones[i]->Location = Point(i * 50, 50);
			botones[i]->Size = Size(50, 50);
			botones[i]->BackColor = seleccionarColor(r.Next(1, 6));
			botones[i]->Name = "Boton" + i;
			botones[i]->Text = (i + 1) + "";
			p->Controls->Add(botones[i]);
			//Rectangle r = Rectangle(Point(50, 50), Size(50, 100));
			//Rectangle r1 = Rectangle(50, 50, 50, 100);


		}

	}
	Color seleccionarColor(int i) {
		Color c;
		switch (i)
		{
		case 1:c = Color::AliceBlue; break;
		case 2:c = Color::AntiqueWhite; break;
		case 3:c = Color::ForestGreen; break;
		case 4:c = Color::LightGoldenrodYellow; break;
		case 5:c = Color::PaleVioletRed; break;
		case 6:c = Color::OrangeRed; break;


		default:
			break;
		}
		return c;

	}

	Button^ obtenerBoton(int pos)
	{
		if (pos >= 0 && pos < MAXI)return botones[pos];
	}

	int cantidad() {
		return MAXI;
	}

};