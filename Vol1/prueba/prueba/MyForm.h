#pragma once

#include<iostream>

namespace prueba {
using namespace std;

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
		Bitmap^ personaje;
		int anchoSprite;
		int altoSprite;
		int anchoImagen;
		int altoImagen;
		Graphics^ lienzo;
		Int16 x, y;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			personaje = gcnew Bitmap("where.png");
			anchoSprite = personaje->Width;
			altoSprite = personaje->Height;
			anchoImagen = anchoSprite / 10;
			altoImagen = altoSprite / 10;
			lienzo = panel1->CreateGraphics();
			x = 0; 
			y = 0;
			personaje->MakeTransparent(personaje->GetPixel(0, 0));
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
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Location = System::Drawing::Point(42, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(803, 432);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(989, 558);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
	
	
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::R)
		{
			lienzo->Clear(SystemColors::Control);
			if (x > 9) { x = 0; y++; }
			
			Rectangle areaVisible = Rectangle(anchoImagen * x, altoImagen * y, anchoImagen, altoImagen);
			Rectangle Aumento = Rectangle(x, y, anchoImagen * 3, altoImagen * 3);
			lienzo->DrawImage(personaje,Aumento, areaVisible, GraphicsUnit::Pixel);
			x++;
			
		}

		if (e->KeyCode == Keys::C)
		{
			if (y > 9)y = 0;

			Rectangle areaVisible = Rectangle(anchoImagen * x, altoImagen * y, anchoImagen, altoImagen);
			lienzo->DrawImage(personaje, 250, 250, areaVisible, GraphicsUnit::Pixel);
			x++;
		}

	} 
};
}
