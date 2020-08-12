#pragma once

namespace sprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Animaciofrm
	/// </summary>
	public ref class Animaciofrm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ personaje;
		int anchoSprite;
		int altoSprite;
		int anchoImagen, altoImagen;
		Graphics^ lienzo;
		int dx, dy;
		int filas, columnas;
		bool pulsado;
		
	private: System::Windows::Forms::Timer^ timer1;

	public:
		Animaciofrm(void)
		{
			InitializeComponent();
			personaje = gcnew Bitmap("Personaje1.png");
			anchoSprite = personaje->Width;
			altoSprite = personaje->Height;
			anchoImagen = anchoSprite / 4;
			altoImagen = altoSprite / 4;
			lienzo = panel1->CreateGraphics();
			dx = dy = filas = columnas = 0;
			pulsado = false;
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Animaciofrm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(804, 522);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Animaciofrm::timer1_Tick);
			// 
			// Animaciofrm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 587);
			this->Controls->Add(this->panel1);
			this->Name = L"Animaciofrm";
			this->Text = L"Animaciofrm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Animaciofrm::Animaciofrm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Animaciofrm::Animaciofrm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		lienzo->Clear(Color::White);
		//if (columnas > 3) { columnas = 0;}
		//if (filas > 3)filas = 0;
		Rectangle areaVisible = Rectangle(anchoImagen * columnas, altoImagen * filas, anchoImagen, altoImagen);
		lienzo->DrawImage(personaje, dx, dy, areaVisible, GraphicsUnit::Pixel);
		//if(pulsado)	++columnas;
		++columnas;
		if (columnas > 3) { columnas = 0; };
		//if (++dx > 50 || ++dy > 50) {
			//dx = 0;
			//dy = 0;
		//}

	}
	private: System::Void Animaciofrm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down) { dy++; filas = 0; }
		if (e->KeyCode == Keys::Up) { dy++; filas = 3; }
		if (e->KeyCode == Keys::Left) { dx--; filas = 1; }
		if (e->KeyCode == Keys::Right) { dx++; filas = 2; }
	    timer1->Enabled = true;
		pulsado = true;
		switch (e->KeyCode)
		{
		//case Keys::Down: {if(dy<(panel1->Height-altoImagen))dy+=velocidady; filas = 0; }; break;
		//case Keys::Right: {if(dx<panel1->Width-anchoImagen)dx+=velocidadx; filas = 2; }; break;
		case Keys::Left: {if(dx>0)dx--; filas = 1; }; break;
		case Keys::Up: {if(dy>0)dy--; filas = 3; }; break;
		//case Keys::A:velocidadx += 2; break;
		//case Keys::D:velocidadx -= 2; break;
		
		default:
			break;
		}
		//dx += velocidadx;
		
	}
	private: System::Void Animaciofrm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		timer1->Enabled = false;
		//columnas = 0;
		pulsado = false;
	
	}
};
	}
