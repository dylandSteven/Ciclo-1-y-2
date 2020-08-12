#pragma once
#include<cmath>
#include"Header.h";
namespace Afianzamiento {

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
		Graphics^ gr;
		Balas* balas;
	private: System::Windows::Forms::Timer^ timer1;
		   BufferedGraphicsContext^ espacio;
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = panel1->CreateGraphics();
			balas = new Balas();
			x = 0;
			y = 0;
			dx = dy =5;
			
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
		   BufferedGraphics^ bg;
			double angulo; 
		   int x, y, dx, dy;
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
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(798, 709);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 733);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion5
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//MessageBox::Show(e->X+" "+e->Y);
		//dx = tan(ang) * dy;
		
		angulo = atan((e->Y-y)/(e->X-x));
		//Console::WriteLine(ang);
	//	dy = tan(ang)*dx;
		balas->apuntar(e->X, e->Y);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	//	x += dx;
		//y =x* tan(angulo);
		gr->Clear(SystemColors::Control);
		gr->FillEllipse(Brushes::ForestGreen, Rectangle(x, y, 10, 10));
		balas->graficarTodo(gr);
		balas->moverTodo();

	}
	};
}
