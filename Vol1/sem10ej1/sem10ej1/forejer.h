#pragma once
#include"Circulo.h"
#include"Cuadrado.h"
namespace sem10ej1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de forejer
	/// </summary>
	public ref class forejer : public System::Windows::Forms::Form
	{
	public:
		forejer(void)
		{
			InitializeComponent();
			timer1->Enabled = true;
			objcirculo = new Circulo(10, 10, 60);
			objcuadrado = new Cuadrado(100, 30, 60);


			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~forejer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private: System::Windows::Forms::Timer^ timer1;
		   Circulo* objcirculo;
		   Cuadrado* objcuadrado;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &forejer::timer1_Tick);
			   // 
			   // forejer
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(463, 465);
			   this->Name = L"forejer";
			   this->Text = L"forejer";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &forejer::forejer_Paint);
			   this->ResumeLayout(false);

		   }

#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		objcuadrado->mover(this->CreateGraphics());
		objcirculo->mover(this->CreateGraphics());
	}
	private: System::Void forejer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {


		System::Drawing::Graphics^ gr = this->CreateGraphics();
		gr->FillRectangle(System::Drawing::Brushes::Red, 0, 0,(int)gr->VisibleClipBounds.Width, (int)gr->VisibleClipBounds.Height);
	}
    };
}
