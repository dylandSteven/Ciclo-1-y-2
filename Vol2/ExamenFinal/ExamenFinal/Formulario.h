#pragma once
#include"Juego.h"
#include<fstream>
namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario
	/// </summary>
	public ref class Formulario : public System::Windows::Forms::Form
	{

		Bitmap^ bmpJugador = gcnew Bitmap("spriteAmbulancia.png");
		Bitmap^ bmpCorren = gcnew Bitmap("spriteCorre.png");
		Bitmap^ bmpJuegan = gcnew Bitmap("spriteCamina.png");
		Juego* objJuego;
	public:
		Formulario(void)
		{
			InitializeComponent();
			objJuego = new Juego();
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpJuegan->MakeTransparent(bmpJuegan->GetPixel(0, 0));
			bmpCorren->MakeTransparent(bmpCorren->GetPixel(0, 0));

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 681);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::Formulario_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::Formulario_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->Clear(Color::AliceBlue);
		objJuego->mover(bf->Graphics);
		objJuego->dibujar(bf->Graphics, bmpJugador, bmpCorren, bmpJuegan);
		objJuego->colisionEnemigoCorren();
		objJuego->colisionEnemigoJuega();
		objJuego->guardar();
		bf->Render();
	}


		 
	private: System::Void Formulario_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{

		case Keys::Up:
			objJuego->getJUgador()->moverJUgadorDY(-10);
			objJuego->getJUgador()->setDireccion(Arriba);
			break;


		case Keys::Down:

			objJuego->getJUgador()->moverJUgadorDY(+10);
			objJuego->getJUgador()->setDireccion(Abajo);
			break;

		case Keys::Left:

			objJuego->getJUgador()->moverJUgadorDX(-10);
			objJuego->getJUgador()->setDireccion(Izquierda);
			break;

		case Keys::Right:

			objJuego->getJUgador()->moverJUgadorDX(+10);
			objJuego->getJUgador()->setDireccion(Derecha);
			break;
		}
	
	
	
	}
	private: System::Void Formulario_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		switch (e->KeyCode)
		{

		case Keys::Up:

			objJuego->getJUgador()->moverJUgadorDY(0);
			break;


		case Keys::Down:


			objJuego->getJUgador()->moverJUgadorDY(0);
			break;

		case Keys::Left:


			objJuego->getJUgador()->moverJUgadorDX(0);
			break;

		case Keys::Right:


			objJuego->getJUgador()->moverJUgadorDX(0);
			break;
		}
	
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
