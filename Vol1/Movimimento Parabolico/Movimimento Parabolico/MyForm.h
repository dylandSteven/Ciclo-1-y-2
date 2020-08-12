#pragma once
#include <cmath>
namespace MovimimentoParabolico {

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
	public:
		MyForm(void)
		{
			InitializeComponent();

			gr = this->CreateGraphics();
			inicializa();
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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private:
		Graphics^ gr;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^bg ;
		double i;
		double x;
		double y;
		double angulo;
		double t;
		double vel0;
		double g;
	private:	
		
	private: System::Windows::Forms::Timer^ timer1;

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
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 708);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		void inicializa() {
			vel0 = 80;
			angulo = 45;
			g = 9.81;
			t = 2 * (vel0 * sin(angulo));


		}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	
	}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (i <= t) 
		{
			x = vel0 * cos(angulo)*i;
			y = vel0 * sin(angulo) * i-0.5*g*i*i;
			//gr->Clear(Color::White);
			if ((int)y > 0) {
				gr->DrawEllipse(gcnew Pen(Color::Red), x, 300 - (int)y, 20, 20);
			}
		i = i+1;
		}

	}

	
	};
}
