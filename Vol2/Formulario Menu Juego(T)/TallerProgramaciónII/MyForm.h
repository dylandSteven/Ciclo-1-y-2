#pragma once
#include "Juego.h"
namespace TallerProgramaciónII {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum Pantalla { Titulo, IJuego, Instrucciones, Ganaste, Perdiste };

	public ref class MyForm : public System::Windows::Forms::Form
	{
		Juego* juego;  
		int nivel;
	private: System::Windows::Forms::Panel^  pnlTitulo;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  pnlInstrucciones;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  sss;
	private: System::Windows::Forms::Panel^  pnlGanaste;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  pnlPerdiste;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label4;
			 Bitmap^ jugador;
	public:
		MyForm(void)
		{
			nivel = 1;
			InitializeComponent();
			
			jugador = gcnew Bitmap("Imagenes\\jugador.png");

			MostrarPantalla(Titulo);
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
			 /// <summary>
			 /// Método necesario para admitir el Diseñador. No se puede modificar
			 /// el contenido de este método con el editor de código.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->clock = (gcnew System::Windows::Forms::Timer(this->components));
				 this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->pnlInstrucciones = (gcnew System::Windows::Forms::Panel());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->sss = (gcnew System::Windows::Forms::Label());
				 this->pnlGanaste = (gcnew System::Windows::Forms::Panel());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->pnlPerdiste = (gcnew System::Windows::Forms::Panel());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->pnlTitulo->SuspendLayout();
				 this->pnlInstrucciones->SuspendLayout();
				 this->pnlGanaste->SuspendLayout();
				 this->pnlPerdiste->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // clock
				 // 
				 this->clock->Tick += gcnew System::EventHandler(this, &MyForm::clock_Tick);
				 // 
				 // pnlTitulo
				 // 
				 this->pnlTitulo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pnlTitulo->Controls->Add(this->button2);
				 this->pnlTitulo->Controls->Add(this->button1);
				 this->pnlTitulo->Controls->Add(this->label1);
				 this->pnlTitulo->Location = System::Drawing::Point(258, 167);
				 this->pnlTitulo->Margin = System::Windows::Forms::Padding(4);
				 this->pnlTitulo->Name = L"pnlTitulo";
				 this->pnlTitulo->Size = System::Drawing::Size(25, 25);
				 this->pnlTitulo->TabIndex = 0;
				 // 
				 // button2
				 // 
				 this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button2->ForeColor = System::Drawing::Color::White;
				 this->button2->Location = System::Drawing::Point(367, 329);
				 this->button2->Margin = System::Windows::Forms::Padding(4);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(319, 74);
				 this->button2->TabIndex = 2;
				 this->button2->Text = L"Instrucciones";
				 this->button2->UseVisualStyleBackColor = false;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				 // 
				 // button1
				 // 
				 this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button1->ForeColor = System::Drawing::Color::White;
				 this->button1->Location = System::Drawing::Point(40, 329);
				 this->button1->Margin = System::Windows::Forms::Padding(4);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(319, 74);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Jugar";
				 this->button1->UseVisualStyleBackColor = false;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // label1
				 // 
				 this->label1->Dock = System::Windows::Forms::DockStyle::Top;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(0, 0);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(23, 124);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Mi Juego";
				 this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pnlInstrucciones
				 // 
				 this->pnlInstrucciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pnlInstrucciones->Controls->Add(this->label2);
				 this->pnlInstrucciones->Controls->Add(this->button3);
				 this->pnlInstrucciones->Controls->Add(this->sss);
				 this->pnlInstrucciones->Location = System::Drawing::Point(299, 56);
				 this->pnlInstrucciones->Margin = System::Windows::Forms::Padding(4);
				 this->pnlInstrucciones->Name = L"pnlInstrucciones";
				 this->pnlInstrucciones->Size = System::Drawing::Size(10, 10);
				 this->pnlInstrucciones->TabIndex = 3;
				 // 
				 // label2
				 // 
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(80, 137);
				 this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(612, 199);
				 this->label2->TabIndex = 3;
				 this->label2->Text = resources->GetString(L"label2.Text");
				 this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // button3
				 // 
				 this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button3->ForeColor = System::Drawing::Color::White;
				 this->button3->Location = System::Drawing::Point(437, 358);
				 this->button3->Margin = System::Windows::Forms::Padding(4);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(319, 74);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"Regresar";
				 this->button3->UseVisualStyleBackColor = false;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
				 // 
				 // sss
				 // 
				 this->sss->Dock = System::Windows::Forms::DockStyle::Top;
				 this->sss->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->sss->Location = System::Drawing::Point(0, 0);
				 this->sss->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->sss->Name = L"sss";
				 this->sss->Size = System::Drawing::Size(8, 15);
				 this->sss->TabIndex = 0;
				 this->sss->Text = L"Instrucciones";
				 this->sss->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pnlGanaste
				 // 
				 this->pnlGanaste->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pnlGanaste->Controls->Add(this->button4);
				 this->pnlGanaste->Controls->Add(this->label3);
				 this->pnlGanaste->Location = System::Drawing::Point(99, 39);
				 this->pnlGanaste->Margin = System::Windows::Forms::Padding(4);
				 this->pnlGanaste->Name = L"pnlGanaste";
				 this->pnlGanaste->Size = System::Drawing::Size(23, 21);
				 this->pnlGanaste->TabIndex = 4;
				 // 
				 // button4
				 // 
				 this->button4->BackColor = System::Drawing::Color::Yellow;
				 this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button4->Location = System::Drawing::Point(231, 346);
				 this->button4->Margin = System::Windows::Forms::Padding(4);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(313, 63);
				 this->button4->TabIndex = 1;
				 this->button4->Text = L"Menu";
				 this->button4->UseVisualStyleBackColor = false;
				 this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
				 // 
				 // label3
				 // 
				 this->label3->Dock = System::Windows::Forms::DockStyle::Top;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(0, 0);
				 this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(21, 247);
				 this->label3->TabIndex = 0;
				 this->label3->Text = L"Ganaste";
				 this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pnlPerdiste
				 // 
				 this->pnlPerdiste->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pnlPerdiste->Controls->Add(this->button5);
				 this->pnlPerdiste->Controls->Add(this->label4);
				 this->pnlPerdiste->Location = System::Drawing::Point(490, 168);
				 this->pnlPerdiste->Margin = System::Windows::Forms::Padding(4);
				 this->pnlPerdiste->Name = L"pnlPerdiste";
				 this->pnlPerdiste->Size = System::Drawing::Size(20, 24);
				 this->pnlPerdiste->TabIndex = 5;
				 // 
				 // button5
				 // 
				 this->button5->BackColor = System::Drawing::Color::Yellow;
				 this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button5->Location = System::Drawing::Point(240, 346);
				 this->button5->Margin = System::Windows::Forms::Padding(4);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(313, 63);
				 this->button5->TabIndex = 1;
				 this->button5->Text = L"Menu";
				 this->button5->UseVisualStyleBackColor = false;
				 this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
				 // 
				 // label4
				 // 
				 this->label4->Dock = System::Windows::Forms::DockStyle::Top;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(0, 0);
				 this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(18, 409);
				 this->label4->TabIndex = 0;
				 this->label4->Text = L"Perdiste";
				 this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(974, 448);
				 this->Controls->Add(this->pnlPerdiste);
				 this->Controls->Add(this->pnlGanaste);
				 this->Controls->Add(this->pnlInstrucciones);
				 this->Controls->Add(this->pnlTitulo);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->Name = L"MyForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"MyForm";
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
				 this->pnlTitulo->ResumeLayout(false);
				 this->pnlInstrucciones->ResumeLayout(false);
				 this->pnlGanaste->ResumeLayout(false);
				 this->pnlPerdiste->ResumeLayout(false);
				 this->ResumeLayout(false);

			 }
#pragma endregion

			 void MostrarPantalla(Pantalla pantalla)
			 {
				 pnlPerdiste->Visible = false;
				 pnlTitulo->Visible = false;
				 pnlInstrucciones->Visible = false;
				 pnlGanaste->Visible = false;
				 pnlPerdiste->Dock = System::Windows::Forms::DockStyle::None;
				 pnlTitulo->Dock = System::Windows::Forms::DockStyle::None;
				 pnlInstrucciones->Dock = System::Windows::Forms::DockStyle::None;
				 pnlGanaste->Dock = System::Windows::Forms::DockStyle::None;

				 if (pantalla == Titulo)
				 {
					 pnlTitulo->Visible = true;
					 pnlTitulo->Dock = System::Windows::Forms::DockStyle::Fill;
					 pnlTitulo->Focus();
				 }
				 else if (pantalla == IJuego)
				 {
					 if (this->Focused == false)
						 this->Focus();

				 }
				 else if (pantalla == Instrucciones)
				 {
					 pnlInstrucciones->Visible = true;

					 pnlInstrucciones->Dock = System::Windows::Forms::DockStyle::Fill;

					 pnlInstrucciones->Focus();
				 }
				 else if (pantalla == Ganaste)
				 {
					 pnlGanaste->Visible = true;

					 pnlGanaste->Dock = System::Windows::Forms::DockStyle::Fill;

					 pnlGanaste->Focus();
				 }
				 else if (pantalla == Perdiste)
				 {
					 pnlPerdiste->Visible = true;

					 pnlPerdiste->Dock = System::Windows::Forms::DockStyle::Fill;

					 pnlPerdiste->Focus();
				 }

			 }




			 Void clock_Tick(Object^  sender, EventArgs^  e)
			 {
				 Graphics^ g = this->CreateGraphics();

				 g->Clear(Color::Green);
				 juego->Mover(g);
				 juego->Mostrar(g, jugador);


				 if (juego->CantEnemigos() == 0)
				 {
					 nivel++;

					 if (nivel < 8)
					 {
						 delete juego;
						 juego = new Juego(nivel);
					 }
					 else
					 {
						 MostrarPantalla(Ganaste);
						 clock->Enabled = false;
						 delete juego;
						 nivel = 1;
					 }
				 }

				 if (juego->Tiempo() <= 0 && juego->CantEnemigos() > 0)
				 {
					 MostrarPantalla(Perdiste);
					 clock->Enabled = false;
					delete juego;
					nivel = 1;
				 }


			 }

	Void MyForm_KeyDown(Object^  sender, KeyEventArgs^  e)
			 {
				 if (e->KeyCode == Keys::Up)
				 {
					 juego->SetJugadorDY(-10);
					 juego->SetJugadorAccion(Arriba);
				 }
				 else if (e->KeyCode == Keys::Down)
				 {
					 juego->SetJugadorDY(10);
					 juego->SetJugadorAccion(Abajo);
				 }
				 else if (e->KeyCode == Keys::Left)
				 {
					 juego->SetJugadorDX(-10);
					 juego->SetJugadorAccion(Izquierda);
				 }
				 else if (e->KeyCode == Keys::Right)
				 {
					 juego->SetJugadorDX(10);
					 juego->SetJugadorAccion(Derecha);
				 }
				 else if (e->KeyCode == Keys::B)
				 {
					 clock->Enabled = false;
					 MostrarPantalla(Titulo);
					 nivel = 1;
				 }
			 }
	Void MyForm_KeyUp(Object^  sender, KeyEventArgs^  e)
			 {
				 if (e->KeyCode == Keys::Up)
				 {
					 juego->SetJugadorDY(0);
				 }
				 else if (e->KeyCode == Keys::Down)
				 {
					 juego->SetJugadorDY(0);
				 }
				 else if (e->KeyCode == Keys::Left)
				 {
					 juego->SetJugadorDX(0);
				 }
				 else if (e->KeyCode == Keys::Right)
				 {
					 juego->SetJugadorDX(0);
				 }
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		MostrarPantalla(Titulo);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		MostrarPantalla(Instrucciones);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		MostrarPantalla(IJuego);
		clock->Enabled = true;
		juego = new Juego(nivel);

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		MostrarPantalla(Titulo);
	}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	MostrarPantalla(Titulo);
}
};
}