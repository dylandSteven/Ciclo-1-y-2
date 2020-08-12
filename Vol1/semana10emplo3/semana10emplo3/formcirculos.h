#pragma once
#include"arrCirculo.h"
namespace semana10emplo3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de formcirculos
	/// </summary>
	public ref class formcirculos : public System::Windows::Forms::Form
	{
	public:
		formcirculos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~formcirculos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^ timer1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		ArrCirculo* oVecCirculo;
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
			this->timer1->Tick += gcnew System::EventHandler(this, &formcirculos::timer1_Tick);
			// 
			// formcirculos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1410, 1055);
			this->Name = L"formcirculos";
			this->Text = L"formcirculos";
			this->Load += gcnew System::EventHandler(this, &formcirculos::formcirculos_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &formcirculos::formcirculos_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void formcirculos_Load(System::Object^ sender, System::EventArgs^ e) {

		oVecCirculo = new ArrCirculo();

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	 
		Graphics^ canvas = this->CreateGraphics();
		canvas->Clear(Color::Blue);
		oVecCirculo->Mover(canvas);

		delete canvas;
	}
	private: System::Void formcirculos_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		oVecCirculo->Agregar(e->X, e->Y);
	}
	};
}
