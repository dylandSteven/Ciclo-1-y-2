#pragma once
#include<iostream>
#include"Botones.h"
namespace JuegoMemoria {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormMemoria
	/// </summary>
	public ref class FormMemoria : public System::Windows::Forms::Form
	{
	public:

		FormMemoria(void)
		{
			listaBotones = gcnew Botones();
			InitializeComponent();
			i = j = 0;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormMemoria()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:

		Botones ^listaBotones;
		int i;
		int j;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
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
			this->panel1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel1->Location = System::Drawing::Point(101, 33);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1033, 625);
			this->panel1->TabIndex = 0;
			// 
			// FormMemoria
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1214, 720);
			this->Controls->Add(this->panel1);
			this->Name = L"FormMemoria";
			this->Text = L"FormMemoria";
			this->Load += gcnew System::EventHandler(this, &FormMemoria::FormMemoria_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormMemoria_Load(System::Object^ sender, System::EventArgs^ e) {

			
					listaBotones->poblar(panel1);
		listaBotones->recuperar(2)->Click += gcnew EventHandler(this, &FormMemoria::Mensaje);
		

	}
	private:System::Void Mensaje(System::Object^ sneder, System::EventArgs^ e) {
		MessageBox::Show("UPECINO");
		listaBotones->recuperar(2);
		cout << "jnjdnf";
	}
	
	};
}
