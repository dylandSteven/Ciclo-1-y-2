#pragma once
#include "Juego.h"
#include <fstream>
namespace TallerProgramaciónII {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{

		Bitmap^ j;
		Bitmap^ en;
	private: System::Windows::Forms::Timer^  clock;

			 Juego* juego;

	public:
		MyForm(void)
		{

			InitializeComponent();

			int t;
			std::ifstream file("time.txt");
			file >> t;
			file.close();

			juego = new Juego(t);
			j = gcnew Bitmap("Imagenes\\jugador.png");
			en = gcnew Bitmap("Imagenes\\enemigo.png");


		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:



	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
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
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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
		juego->Mostrar(bf->Graphics, j, en);
		
		bf->Render(g);

		if (juego->Tiempo() == 0)
		{
			this->Close();
		}
	}
	Void MyForm_KeyDown(Object^  sender, KeyEventArgs^  e)
	{
		int v = 10;
		if (e->KeyCode == Keys::Up)
		{
			juego->JugadorDY(-v);
			juego->JugadorAccion(Arriba);
		}
		else if (e->KeyCode == Keys::Down)
		{
			juego->JugadorDY(v);
			juego->JugadorAccion(Abajo);
		}
		else if (e->KeyCode == Keys::Left)
		{
			juego->JugadorDX(-v);
			juego->JugadorAccion(Izquierda);
		}
		else if (e->KeyCode == Keys::Right)
		{
			juego->JugadorDX(v);
			juego->JugadorAccion(Derecha);
		}
	}
	Void MyForm_KeyUp(Object^  sender, KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::Up)
		{
			juego->JugadorDY(0);
		}
		else if (e->KeyCode == Keys::Down)
		{
			juego->JugadorDY(0);
		}
		else if (e->KeyCode == Keys::Left)
		{
			juego->JugadorDX(0);
		}
		else if (e->KeyCode == Keys::Right)
		{
			juego->JugadorDX(0);
		}
	}
};
}
