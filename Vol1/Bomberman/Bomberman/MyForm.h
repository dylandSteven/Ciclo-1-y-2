#pragma once
#include "Controladora.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		SoundPlayer^ musicadeNivel;
		CControladora* objControlador = new CControladora();
		Bitmap^ bmpSolido = gcnew Bitmap("Bomberman\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Bomberman\\bmpDestruible.png");
		Bitmap^ bmpSuelo= gcnew Bitmap("Bomberman\\bmpSuelo.png");
		Bitmap ^bmpJugador=gcnew Bitmap("Bomberman\\Jugador.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Bomberman\\explosion.png");
	    Bitmap^ bmpBomba = gcnew Bitmap("Bomberman\\bomba.png");
		Bitmap^ bmpMejoras = gcnew Bitmap("Bomberman\\bmpMejoras.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("Bomberman\\bmpEnemigo.png");

	public:
		MyForm(void)
		{
			InitializeComponent();
			objControlador = new CControladora();
			//
			//TODO: agregar código de constructor aquí
			//
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
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
	private: System::Windows::Forms::Label^ lblNivel;
	private: System::Windows::Forms::ProgressBar^ pbCarga;
	private: System::Windows::Forms::Timer^ trCarga;
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
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->pbCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblNivel
			// 
			this->lblNivel->AutoSize = true;
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Algerian", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNivel->ForeColor = System::Drawing::Color::White;
			this->lblNivel->Location = System::Drawing::Point(212, 237);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(82, 26);
			this->lblNivel->TabIndex = 0;
			this->lblNivel->Text = L"Nivel:";
			// 
			// pbCarga
			// 
			this->pbCarga->Location = System::Drawing::Point(191, 279);
			this->pbCarga->Name = L"pbCarga";
			this->pbCarga->Size = System::Drawing::Size(161, 23);
			this->pbCarga->TabIndex = 1;
			// 
			// trCarga
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 2500;
			this->trCarga->Tick += gcnew System::EventHandler(this, &MyForm::trCarga_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlText;
			this->ClientSize = System::Drawing::Size(846, 728);
			this->Controls->Add(this->pbCarga);
			this->Controls->Add(this->lblNivel);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::LevantarTecla);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void musicanivel() {
			musicadeNivel = gcnew SoundPlayer("Bomberman\\MusicaIntro.wav");
			musicadeNivel->PlayLooping();
		}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		
		objControlador->dibujar(buffer->Graphics, bmpSuelo, bmpSolido,bmpBomba,bmpExplosion, bmpDestruible,bmpJugador, bmpMejoras,bmpEnemigo);
		this->Text = " " + objControlador->GetJugador()->getVidas();
		buffer->Render(g);
		delete buffer, espacio, g;
		
		
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		lblNivel->Text = "Nivel: " + objControlador->getNivael();
		objControlador->CambiarNivel();

	}
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			objControlador->GetJugador()->setDireccion(Direcciones::Arriba);

			break;
		
		
		
		case Keys::Down:
			objControlador->GetJugador()->setDireccion(Direcciones::Abajo);
			break;
		
		case Keys::Right:
			objControlador->GetJugador()->setDireccion(Direcciones::Derecha);
			break;
		
		case Keys::Left:
			objControlador->GetJugador()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::Space:

			objControlador->agregarBomba();
					default:
			break;
		}
	
	}
	private: System::Void LevantarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		switch (e->KeyCode)
		{

			case Keys::Space:
				objControlador->agregarBomba();
			break;
			

		default:
			objControlador->GetJugador()->setDireccion(Direcciones::Ninguna);
			break;
		}
	
	}
private: System::Void trCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	
	pbCarga->Increment(10);
	if (trCarga->Interval == 2500 &&objControlador->getArrEnemigos()->getenemigo().size()<objControlador->getNivael())
	{
		objControlador->crearEnemigosYMejoras();
	
	}
	else {
		trCarga->Enabled = false;
		timer1->Enabled = true;
		lblNivel->Visible = false;
		musicanivel();
		lblNivel->Enabled = false;
		pbCarga->Visible = false;
		pbCarga->Enabled = false;
	}

}
};
}
