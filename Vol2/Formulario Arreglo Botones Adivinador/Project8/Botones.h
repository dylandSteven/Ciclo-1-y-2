#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class CBotones
{
public:
	CBotones(){
		botones = gcnew array<Button^>(max);
	}
	~CBotones(){}
	void crearBotones(Panel^p,String^ nombre, String ^ imagen ,Int64 x , Int64 y) {
		
			botones[i] = gcnew Button();
			botones[i]->Text = "";
			botones[i]->Name = nombre;
			botones[i]->Image = gcnew Bitmap(imagen);
			botones[i]->Location = Point(x, y);
			botones[i]->Size = Size(100,100);
			botones[i]->BackColor = Color::Green;
			p->Controls->Add(botones[i]);
			
			i += 1;
	}

	Button^ getBoton(int pos) {

		return botones[pos];
	}
	Void setBotonImagen(int pos, String^nombre) {
		botones[pos]->Image = gcnew Bitmap(nombre);
	}


	void crearEtiqueta(Panel^ p, Int64 x, Int64 y) {
		etiqueta = gcnew Label();
		etiqueta->ForeColor = Color::Black;
		etiqueta->Text = "Select Cats";
		etiqueta->Name = "lbl1";
		etiqueta->Location = Point(x, y);
		etiqueta->Size = Size(100, 30);
		etiqueta->BackColor = Color::Red;
		p->Controls->Add(etiqueta);
		
	}


private:
	array<Button^>^botones;
	Label^ etiqueta;
	short max = 16;
	int i=0;
};

