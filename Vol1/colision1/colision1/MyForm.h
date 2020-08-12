#pragma once
#include"Circulo.h"
#include"Cuadrado.h"
namespace colision1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		Circulo*  objcirculo1;
		Circulo*  objcirculo2;
		Cuadrado* objCuadrado1;
	private: System::Windows::Forms::Timer^ timer1;
		   Cuadrado* objCuadrado2;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			objcirculo1 = new Circulo(200, 50, 4, 4, 1, 1);
			objcirculo2 = new Circulo(300, 100, 4, 4, 1, 2);
			objCuadrado1 = new Cuadrado(50, 30,4, 4, 1, 3);
			objCuadrado2 = new Cuadrado(120, 30,4, 4, 1, 4);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1122, 678);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		g->Clear(Color::YellowGreen);

		objcirculo1->moverCirculo(g);
		objcirculo1->dibujarCirculo(g);

		objcirculo2->moverCirculo(g);
		objcirculo2->dibujarCirculo(g);

		objCuadrado1->moverCuadrado(g);
		objCuadrado1->dinujarCuadrado(g);

		objCuadrado2->moverCuadrado(g);
		objCuadrado2->dinujarCuadrado(g);
	
		if (objCuadrado1->esColison(objcirculo1) == true)
		{
			objcirculo1->setDesX(objcirculo1->getdesXCirculo() * (-1));
			objcirculo1->setDesY(objcirculo1->getdesYCirculo() * (-1));

			objCuadrado1->Setdesy_cuadrado(objCuadrado1->getdesy() * (-1));

			objCuadrado1->setColor(objCuadrado1->getColor() * (-1));
			objcirculo1->setColorCirculo(objcirculo1->getColorCirculo() * -1);
		}
		if (objCuadrado2->esColison(objcirculo1) == true)
		{
			objcirculo1->setDesX(objcirculo1->getdesXCirculo() * (-1));
			objcirculo1->setDesY(objcirculo1->getdesYCirculo() * (-1));

			objCuadrado2->Setdesy_cuadrado(objCuadrado2->getdesy() * (-1));

			objCuadrado2->setColor(objCuadrado2->getColor() * (-1));
			objcirculo1->setColorCirculo(objcirculo1->getColorCirculo() * -1);
		}
		if (objCuadrado1->esColison(objcirculo2) == true)
		{
			objcirculo2->setDesX(objcirculo2->getdesXCirculo() * (-1));
			objcirculo2->setDesY(objcirculo2->getdesYCirculo() * (-1));

			objCuadrado1->Setdesy_cuadrado(objCuadrado1->getdesy() * (-1));

			objCuadrado1->setColor(objCuadrado2->getColor() * (-1));
			objcirculo2->setColorCirculo(objcirculo2->getColorCirculo() * -1);
		}
		if (objCuadrado2->esColison(objcirculo2) == true)
		{
			objcirculo2->setDesX(objcirculo2->getdesXCirculo()* (-1));
			objcirculo2->setDesY(objcirculo2->getdesYCirculo() * (-1));

			objCuadrado2->Setdesy_cuadrado(objCuadrado2->getdesy() * (-1));

			objCuadrado2->setColor(objCuadrado2->getColor() * (-1));
			objcirculo2->setColorCirculo(objcirculo2->getColorCirculo() * -1);
		}

	
	}
	};
}
