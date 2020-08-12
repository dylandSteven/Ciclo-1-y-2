#pragma once

namespace graficasprimitivas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Resumen de frmcanvas1
	/// </summary>
	public ref class frmcanvas1 : public System::Windows::Forms::Form
	{
	public:
		frmcanvas1(void)
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
		~frmcanvas1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ btndibuj;

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
			this->btndibuj = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(299, 370);
			this->panel1->TabIndex = 0;
			// 
			// btndibuj
			// 
			this->btndibuj->Location = System::Drawing::Point(328, 43);
			this->btndibuj->Name = L"btndibuj";
			this->btndibuj->Size = System::Drawing::Size(107, 64);
			this->btndibuj->TabIndex = 1;
			this->btndibuj->Text = L"Dibujar";
			this->btndibuj->UseVisualStyleBackColor = true;
			this->btndibuj->Click += gcnew System::EventHandler(this, &frmcanvas1::btndibuj_Click);
			// 
			// frmcanvas1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 394);
			this->Controls->Add(this->btndibuj);
			this->Controls->Add(this->panel1);
			this->Name = L"frmcanvas1";
			this->Text = L"frmcanvas1";
			this->Load += gcnew System::EventHandler(this, &frmcanvas1::frmcanvas1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmcanvas1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btndibuj_Click(System::Object^ sender, System::EventArgs^ e) {

		Pen^ pincel = gcnew Pen(Color::Green, 4);
		pincel->DashStyle = DashStyle::DashDotDot;
		Graphics ^gr =panel1->CreateGraphics();
		gr->DrawLine(pincel, 20, 20, 150, 150);
		}
	};
}
