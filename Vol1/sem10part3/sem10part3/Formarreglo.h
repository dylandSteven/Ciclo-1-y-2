#pragma once
#include"Arreglo.h"
namespace sem10part3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formarreglo
	/// </summary>
	public ref class Formarreglo : public System::Windows::Forms::Form
	{
	public:
		Formarreglo(void)
		{
			listaBotones = gcnew Coleccion();
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formarreglo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnprueba;
	private: System::Windows::Forms::Panel^ panelPrueba;
	protected:

	protected:

	private:
		Coleccion^ listaBotones;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnprueba = (gcnew System::Windows::Forms::Button());
			this->panelPrueba = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btnprueba
			// 
			this->btnprueba->Location = System::Drawing::Point(40, 44);
			this->btnprueba->Name = L"btnprueba";
			this->btnprueba->Size = System::Drawing::Size(75, 23);
			this->btnprueba->TabIndex = 0;
			this->btnprueba->Text = L"Prueba";
			this->btnprueba->UseVisualStyleBackColor = true;
			// 
			// panelPrueba
			// 
			this->panelPrueba->Location = System::Drawing::Point(40, 74);
			this->panelPrueba->Name = L"panelPrueba";
			this->panelPrueba->Size = System::Drawing::Size(1127, 365);
			this->panelPrueba->TabIndex = 1;
			// 
			// Formarreglo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1290, 555);
			this->Controls->Add(this->panelPrueba);
			this->Controls->Add(this->btnprueba);
			this->Name = L"Formarreglo";
			this->Text = L"Formarreglo";
			this->Load += gcnew System::EventHandler(this, &Formarreglo::Formarreglo_Load);
			this->ResumeLayout(false);
		
		}
#pragma endregion

	private: System::Void Formarreglo_Load(System::Object^ sender, System::EventArgs^ e) {
		//Graphics^ lienzo = this->CreateGraphics();
		listaBotones->poblar(panelPrueba);
		listaBotones->obtenerBoton(1)->Click += gcnew System::EventHandler(this, &Formarreglo::Mensaje);

		//for (int i = 0; i  < listaBotones->cantidad(); ++i)
		//{
		//	listaBotones->obtenerBoton(i)->Click += gcnew System::EventHandler(this, &Formarreglo::Mensaje);
		//}

		}
	private:System::Void Mensaje(System::Object^ sneder, System ::EventArgs^ e) {  
			   MessageBox::Show("UPECINO");
		   }
	};
}
