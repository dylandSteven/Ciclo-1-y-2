#pragma once
#include"Tragamonedas.h"
#include"JUgadores.h"
namespace PC2 {

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

		Juagdor* ju1;
		Juagdor* ju2;
		Bitmap^ objTragamoneda = gcnew Bitmap("figuras.png");
		Tragamonedas* figura1;
		Tragamonedas* figura2;
		Graphics^ g;
		   Tragamonedas* figura3;
		   BufferedGraphicsContext^ spacio;
		   BufferedGraphics^ buffer;

		   Bitmap^ objFondo;

		   bool jugador1;
			   bool jugador2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;






	private: System::Windows::Forms::Panel^ panel1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			Random r;
			jugador1 = false;
			jugador2 = false;
			srand(time(NULL));
			g = panel1->CreateGraphics();
			spacio = BufferedGraphicsManager::Current;
			buffer = spacio->Allocate(g, panel1->ClientRectangle);
			figura1 = new Tragamonedas(25, 70,  r.Next(0,2), r.Next(0, 2));
			figura2 = new Tragamonedas(245, 70, r.Next(0, 2), r.Next(0, 2));
			figura3 = new Tragamonedas(475, 70, r.Next(0, 2), r.Next(0, 2));

			objFondo = gcnew Bitmap("2310.png");
			ju1 = new Juagdor(1000);
			ju2 = new Juagdor(1000);




			if (jugador1 == false) {

				jugador1 = true;

				if ((figura1->getindiceX() && figura1->getIndiceY()) == (figura2->getindiceX() && figura2->getIndiceY())
					|| (figura2->getindiceX() && figura2->getIndiceY()) == (figura3->getindiceX() && figura3->getIndiceY())
					|| (figura3->getindiceX() && figura3->getIndiceY()) == (figura1->getindiceX() && figura1->getIndiceY()))
				{
					ju1->setValor(ju1->gatValor() + 200);
					

				}


				if ((figura1->getindiceX() && figura1->getIndiceY()) == (figura2->getindiceX() && figura2->getIndiceY())
					&& (figura2->getindiceX() && figura2->getIndiceY()) == (figura3->getindiceX() && figura3->getIndiceY())
					&& (figura3->getindiceX() && figura3->getIndiceY()) == (figura1->getindiceX() && figura1->getIndiceY()))
				{
					ju1->setValor(ju1->gatValor() + 1000);
					

				}



				if ((figura1->getindiceX() && figura1->getIndiceY()) != (figura2->getindiceX() && figura2->getIndiceY())
					&& (figura2->getindiceX() && figura2->getIndiceY()) != (figura3->getindiceX() && figura3->getIndiceY())
					&& (figura3->getindiceX() && figura3->getIndiceY()) != (figura1->getindiceX() && figura1->getIndiceY()))
				{
					ju1->setValor(ju1->gatValor() - 200);

				}


				jugador2 = true;

				if (jugador2 == true) {
					if ((figura1->getindiceX() && figura1->getIndiceY()) == (figura2->getindiceX() && figura2->getIndiceY())
						|| (figura2->getindiceX() && figura2->getIndiceY()) == (figura3->getindiceX() && figura3->getIndiceY())
						|| (figura3->getindiceX() && figura3->getIndiceY()) == (figura1->getindiceX() && figura1->getIndiceY()))
					{
						ju2->setValor(ju2->gatValor() + 200);


					}


					if ((figura1->getindiceX() && figura1->getIndiceY()) == (figura2->getindiceX() && figura2->getIndiceY())
						&& (figura2->getindiceX() && figura2->getIndiceY()) == (figura3->getindiceX() && figura3->getIndiceY())
						&& (figura3->getindiceX() && figura3->getIndiceY()) == (figura1->getindiceX() && figura1->getIndiceY()))
					{
						ju2->setValor(ju2->gatValor() + 1000);


					}



					if ((figura1->getindiceX() && figura1->getIndiceY()) != (figura2->getindiceX() && figura2->getIndiceY())
						&& (figura2->getindiceX() && figura2->getIndiceY()) != (figura3->getindiceX() && figura3->getIndiceY())
						&& (figura3->getindiceX() && figura3->getIndiceY()) != (figura1->getindiceX() && figura1->getIndiceY()))
					{
						ju2->setValor(ju2->gatValor() - 200);

					}


				}
			}



















		







			//
			//TODO: agregar código de constructor aquí
			//
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1135, 528);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(1191, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Jugador 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1194, 250);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Jugador 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1199, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1202, 357);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1408, 563);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(objFondo, 0, 0, objFondo->Width, objFondo->Height);
		figura1->dibujar(buffer->Graphics, objTragamoneda);
		figura2->dibujar(buffer->Graphics, objTragamoneda);
		figura3->dibujar(buffer->Graphics, objTragamoneda);
		figura1->Mover(g);
		figura2->Mover(g);
		figura3->Mover(g);
		buffer->Render(g);

		


	}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{

	case Keys::E:
		timer1->Enabled = false;
		label3->Text =" " +ju1->gatValor();
		label4->Text = "" + ju2->gatValor();
		break;

	default:
		break;
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	/*radioButton1->Enabled = false;
	radioButton2->Enabled = false;
	textBox1->Enabled = false;
	textBox2->Enabled = false;*/


}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {


}
};
}
