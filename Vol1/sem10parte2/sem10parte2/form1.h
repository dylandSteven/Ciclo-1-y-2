#pragma once

namespace sem10parte2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de form1
	/// </summary>
	public ref class form1 : public System::Windows::Forms::Form
	{
	public:
		form1(void)
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
		~form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(249, 212);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &form1::panel1_Paint);
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 514);
			this->Controls->Add(this->panel1);
			this->Name = L"form1";
			this->Text = L"form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		Pen^ pincel = gcnew Pen(Color::Blue, 4);
		gr->DrawLine(pincel, 10, 10, 10, 100);
		gr->DrawLine(pincel, 10, 100, 80, 100);
		gr->DrawLine(pincel, 80, 100, 80, 10);

		gr->DrawLine(pincel, 100, 10, 100, 100);
		gr->DrawLine(pincel, 100, 10, 180, 10);
		gr->DrawLine(pincel, 100, 55, 180, 55);
		gr->DrawLine(pincel, 180, 10, 180, 55);

		gr->DrawLine(pincel, 200, 10, 200, 100);
		gr->DrawLine(pincel, 200, 10, 280, 10);
		gr->DrawLine(pincel, 200, 100, 280, 100);
	}
	};
}
