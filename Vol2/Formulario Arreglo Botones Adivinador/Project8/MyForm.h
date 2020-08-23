#pragma once
#include "Botones.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			b = gcnew CBotones();
			timer1->Enabled = true;
			//b->crearEtiqueta(panel1, 500, 60);
			auxBoton0 = 20; auxBoton6 = 21; auxBoton10 = 22; auxBoton13 = 23; auxBoton7 = 24; auxBoton9 = 25; auxBoton12 = 26;
			auxBoton1 = 27; auxBoton2 = 28; auxBoton5 = 29; auxBoton15 = 30; auxBoton8 = 31; auxBoton3 = 32;
			auxBoton4 = 33; auxBoton11 = 34; auxBoton14 = 35;
			b->crearBotones(panel1, "btn1", "1.jpg", 50, 60);
			b->crearBotones(panel1, "btn2", "2.jpg", 150, 60);
			b->crearBotones(panel1, "btn3", "3.jpg", 250, 60);
			b->crearBotones(panel1, "btn4", "4.jpg", 350, 60);
			b->crearBotones(panel1, "btn5", "4.jpg", 50, 160);
			b->crearBotones(panel1, "btn6", "3.jpg", 150, 160);
			b->crearBotones(panel1, "btn7", "1.jpg", 250, 160);
			b->crearBotones(panel1, "btn8", "2.jpg", 350, 160);
			b->crearBotones(panel1, "btn9", "3.jpg", 50, 260);
			b->crearBotones(panel1, "btn10", "2.jpg", 150, 260);
			b->crearBotones(panel1, "btn11", "1.jpg", 250, 260);
			b->crearBotones(panel1, "btn12", "4.jpg", 350, 260);
			b->crearBotones(panel1, "btn13", "2.jpg", 50, 360);
			b->crearBotones(panel1, "btn14", "1.jpg", 150, 360);
			b->crearBotones(panel1, "btn15", "4.jpg", 250, 360);
			b->crearBotones(panel1, "btn16", "3.jpg", 350, 360);

		 
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:
		short auxBoton0, auxBoton6, auxBoton10, auxBoton13, auxBoton7, auxBoton9, auxBoton12, auxBoton1,
			 auxBoton2, auxBoton5, auxBoton15, auxBoton8, auxBoton3, auxBoton4, auxBoton11, auxBoton14;
		CBotones^ b;
		short SumaIntentos=0;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnJugar;




	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->btnJugar);
			this->panel1->Location = System::Drawing::Point(14, 15);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1027, 658);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::Red;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->btnJugar->ForeColor = System::Drawing::Color::White;
			this->btnJugar->Location = System::Drawing::Point(644, 42);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(354, 61);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"COMENZAR JUEGO V:";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MyForm::btnJugar_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1077, 752);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		void OcultarDeNuevo() {
			b->setBotonImagen(0, "color.jpg");
			b->setBotonImagen(1, "color1.jpg");
			b->setBotonImagen(2, "color2.jpg");
			b->setBotonImagen(3, "color3.jpg");
			b->setBotonImagen(4, "color4.jpg");
			b->setBotonImagen(5, "color5.jpg");
			b->setBotonImagen(6, "color6.jpg");
			b->setBotonImagen(7, "color7.jpg");
			b->setBotonImagen(8, "color8.jpg");
			b->setBotonImagen(9, "color9.jpg");
			b->setBotonImagen(10, "color10.jpg");
			b->setBotonImagen(11, "color11.jpg");
			b->setBotonImagen(12, "color12.jpg");
			b->setBotonImagen(13, "color13.jpg");
			b->setBotonImagen(14, "color14.jpg");
			b->setBotonImagen(15, "color15.jpg");
		}
		void restaurar() {
			auxBoton0 = 20; auxBoton6 = 21; auxBoton10 = 22; auxBoton13 = 23; auxBoton7 = 24; auxBoton9 = 25; auxBoton12 = 26;
			auxBoton1 = 27; auxBoton2 = 28; auxBoton5 = 29; auxBoton15 = 30; auxBoton8 = 31; auxBoton3 = 32;
			auxBoton4 = 33; auxBoton11 = 34; auxBoton14 = 35;
		}
		void Deshabilitar(short a, short c) {
			b->getBoton(a)->Enabled = false;
			b->getBoton(c)->Enabled = false;
			
		}
		void voltear() {
			b->getBoton(0)->Click += gcnew EventHandler(this, &MyForm::voltear0);
			b->getBoton(1)->Click += gcnew EventHandler(this, &MyForm::voltear1);
			b->getBoton(2)->Click += gcnew EventHandler(this, &MyForm::voltear2);
			b->getBoton(3)->Click += gcnew EventHandler(this, &MyForm::voltear3);
			b->getBoton(4)->Click += gcnew EventHandler(this, &MyForm::voltear4);
			b->getBoton(5)->Click += gcnew EventHandler(this, &MyForm::voltear5);
			b->getBoton(6)->Click += gcnew EventHandler(this, &MyForm::voltear6);
			b->getBoton(7)->Click += gcnew EventHandler(this, &MyForm::voltear7);
			b->getBoton(8)->Click += gcnew EventHandler(this, &MyForm::voltear8);
			b->getBoton(9)->Click += gcnew EventHandler(this, &MyForm::voltear9);
			b->getBoton(10)->Click += gcnew EventHandler(this, &MyForm::voltear10);
			b->getBoton(11)->Click += gcnew EventHandler(this, &MyForm::voltear11);
			b->getBoton(12)->Click += gcnew EventHandler(this, &MyForm::voltear12);
			b->getBoton(13)->Click += gcnew EventHandler(this, &MyForm::voltear13);
			b->getBoton(14)->Click += gcnew EventHandler(this, &MyForm::voltear14);
			b->getBoton(15)->Click += gcnew EventHandler(this, &MyForm::voltear15);

		}
		void DeshabilitarImagenes1() {
			if (auxBoton0 == auxBoton6) {
				Deshabilitar(0, 6); 
			}
			else if (auxBoton10 == auxBoton13) {
				Deshabilitar(10, 13); 
			}
			else if (auxBoton10 == auxBoton6) {
				Deshabilitar(10, 6); 
			}
			else if (auxBoton6 == auxBoton13) {
				Deshabilitar(0, 10); 
			}
			else if (auxBoton0 == auxBoton10) {
				Deshabilitar(0, 10); 
			}
			else if (auxBoton0 == auxBoton13) {
				Deshabilitar(0, 13); 
			}

		}
		void DeshabilitarImagenes2(){
			if (auxBoton1 == auxBoton7) {
				Deshabilitar(1, 7);
			}
			else if (auxBoton1 == auxBoton9) {
				Deshabilitar(1, 9);
			}
			else if (auxBoton1 == auxBoton12) {
				Deshabilitar(1, 12);
			}
			else if (auxBoton7 == auxBoton9) {
				Deshabilitar(7, 9);
			}
			else if (auxBoton7 == auxBoton12) {
				Deshabilitar(7, 12);
			}
			else if (auxBoton9 == auxBoton12) {
				Deshabilitar(9, 12);
			}
		}
		void DeshabilitarImagenes3(){
			if (auxBoton2 == auxBoton5) {
				Deshabilitar(2, 5);
			}
			else if (auxBoton2 == auxBoton8) {
				Deshabilitar(2, 8);
			}
			else if (auxBoton2 == auxBoton15) {
				Deshabilitar(2, 15);
			}
			else if (auxBoton5 == auxBoton8) {
				Deshabilitar(5, 8);
			}
			else if (auxBoton8 == auxBoton15) {
				Deshabilitar(8, 15);
			}
			else if (auxBoton5 == auxBoton15) {
				Deshabilitar(5, 15);
			}
		}
		void DeshabilitarImagenes4(){
			if (auxBoton3 == auxBoton4) {
				Deshabilitar(3, 4);
			}
			else if (auxBoton3 == auxBoton11) {
				Deshabilitar(3, 11);
			}
			else if (auxBoton3 == auxBoton14) {
				Deshabilitar(3, 14);
			}
			else if (auxBoton4 == auxBoton11) {
				Deshabilitar(4, 11);
			}
			else if (auxBoton4 == auxBoton14) {
				Deshabilitar(4, 14);
			}
			else if (auxBoton11 == auxBoton14) {
				Deshabilitar(11, 14);
			}
		}
		void PseudoIntentoErrores() {
			if (SumaIntentos == 2 ) {
				restaurar();
				OcultarDeNuevo();
				SumaIntentos = 0;
			}

		}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void voltear0(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(0)->Image = gcnew Bitmap("1.jpg");
		auxBoton0 = 0; SumaIntentos++;
	}
	private: System::Void voltear1(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(1)->Image = gcnew Bitmap("2.jpg"); auxBoton1 = 4; SumaIntentos++;
	}
	private: System::Void voltear2(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(2)->Image = gcnew Bitmap("3.jpg"); auxBoton2 = 8; SumaIntentos++;
	}
	private: System::Void voltear3(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(3)->Image = gcnew Bitmap("4.jpg"); auxBoton3 = 12; SumaIntentos++;
	}
	private: System::Void voltear4(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(4)->Image = gcnew Bitmap("4.jpg"); auxBoton4 = 12; SumaIntentos++;
	}
	private: System::Void voltear5(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(5)->Image = gcnew Bitmap("3.jpg"); auxBoton5 = 8; SumaIntentos++;
	}
	private: System::Void voltear6(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(6)->Image = gcnew Bitmap("1.jpg");
		auxBoton6 = 0; SumaIntentos++;
	}
	private: System::Void voltear7(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(7)->Image = gcnew Bitmap("2.jpg"); auxBoton7 = 4; SumaIntentos++;
	}
	private: System::Void voltear8(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(8)->Image = gcnew Bitmap("3.jpg"); auxBoton8 = 8; SumaIntentos++;
	}
	private: System::Void voltear9(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(9)->Image = gcnew Bitmap("2.jpg"); auxBoton9 = 4; SumaIntentos++;
	}
	private: System::Void voltear10(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(10)->Image = gcnew Bitmap("1.jpg"); auxBoton10 = 0; SumaIntentos++;
	}
	private: System::Void voltear11(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(11)->Image = gcnew Bitmap("4.jpg"); auxBoton11 = 12; SumaIntentos++;
	}
	private: System::Void voltear12(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(12)->Image = gcnew Bitmap("2.jpg"); auxBoton12 = 4; SumaIntentos++;
	}
 	private: System::Void voltear13(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(13)->Image = gcnew Bitmap("1.jpg"); auxBoton13 = 0; SumaIntentos++;
	}
	private: System::Void voltear14(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(14)->Image = gcnew Bitmap("4.jpg"); auxBoton14 = 12; SumaIntentos++;
	}
	private: System::Void voltear15(System::Object^ sender, System::EventArgs^ e) {
		b->getBoton(15)->Image = gcnew Bitmap("3.jpg"); auxBoton15 = 8; SumaIntentos++;
	}

	
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	DeshabilitarImagenes1();
	DeshabilitarImagenes2();
	DeshabilitarImagenes3();
	DeshabilitarImagenes4();
	PseudoIntentoErrores();

}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	voltear();
}
private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
	OcultarDeNuevo();
}
};
}
