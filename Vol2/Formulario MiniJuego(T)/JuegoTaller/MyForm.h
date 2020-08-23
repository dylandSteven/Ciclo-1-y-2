#pragma once
#include "Juego.h"
namespace JuegoTaller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		Juego* juego;
		Bitmap^ jugador;
		Bitmap^ esqueleto;
	public:
		MyForm(void)
		{
			InitializeComponent();
			juego = new Juego();
			jugador = gcnew Bitmap("jugador.png");
			esqueleto = gcnew Bitmap("esqueleto.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  clock;
	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Tick += gcnew System::EventHandler(this, &MyForm::clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 331);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	Void clock_Tick(Object^  sender, EventArgs^  e)
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::Green);
		juego->Mover(bf->Graphics);
		juego->Mostrar(bf->Graphics, jugador, esqueleto);

		if (juego->Tiempo() == 0 ||juego->VidasJugador() == 0)
			this->Close();

		bf->Render(g);
	}
	Void MyForm_KeyDown(Object^  sender, KeyEventArgs^  e)
	{
		int V = 10;

		if (juego->JugadorGetAccion() >= 4 && juego->JugadorGetAccion() <= 7)
		{
			if (e->KeyCode == Keys::Up)
			{
				juego->JugadorSetDY(-V);
				juego->JugadorSetAccion(CaminarArriba);
			}
			else if (e->KeyCode == Keys::Down)
			{
				juego->JugadorSetDY(V);
				juego->JugadorSetAccion(CaminarAbajo);
			}
			else if (e->KeyCode == Keys::Left)
			{
				juego->JugadorSetDX(-V);
				juego->JugadorSetAccion(CaminarIzquierda);
			}
			else if (e->KeyCode == Keys::Right)
			{
				juego->JugadorSetDX(V);
				juego->JugadorSetAccion(CaminarDerecha);
			}
		}
		if (e->Control == false && e->KeyCode == Keys::Space)
		{
			if (juego->JugadorGetAccion() == CaminarArriba)
				juego->JugadorSetAccion(DispararArriba);
			else if (juego->JugadorGetAccion() == CaminarAbajo)
				juego->JugadorSetAccion(DispararAbajo);
			else if (juego->JugadorGetAccion() == CaminarIzquierda)
				juego->JugadorSetAccion(DispararIzquierda);
			else if (juego->JugadorGetAccion() == CaminarDerecha)
				juego->JugadorSetAccion(DispararDerecha);
		}
		else if (e->Control == true && e->KeyCode == Keys::Space)
		{
			if (juego->JugadorGetAccion() == CaminarArriba)
				juego->JugadorSetAccion(CampoArriba);
			else if (juego->JugadorGetAccion() == CaminarAbajo)
				juego->JugadorSetAccion(CampoAbajo);
			else if (juego->JugadorGetAccion() == CaminarIzquierda)
				juego->JugadorSetAccion(CampoIzquierda);
			else if (juego->JugadorGetAccion() == CaminarDerecha)
				juego->JugadorSetAccion(CampoDerecha);
		}

		if (e->KeyCode == Keys::S)
			juego->Guardar();
	}
	Void MyForm_KeyUp(Object^  sender, KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::Up)
			juego->JugadorSetDY(0);
		else if (e->KeyCode == Keys::Down)
			juego->JugadorSetDY(0);
		else if (e->KeyCode == Keys::Left)
			juego->JugadorSetDX(0);
		else if (e->KeyCode == Keys::Right)
			juego->JugadorSetDX(0);
	}
	};
}
