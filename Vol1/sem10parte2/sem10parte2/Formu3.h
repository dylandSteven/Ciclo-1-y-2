#pragma once

namespace sem10parte2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formu3
	/// </summary>
	public ref class Formu3 : public System::Windows::Forms::Form
	{
	public:
		Formu3(void)
		{
			InitializeComponent();
			gr = panel1->CreateGraphics();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formu3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lbly2;

	private: System::Windows::Forms::Label^ lblx2;

	private: System::Windows::Forms::Label^ lbly1;

	private: System::Windows::Forms::Label^ lblx1;
	private: System::Windows::Forms::Button^ btneliminar;
	private: System::Windows::Forms::Button^ btndibuja;
	private: System::Windows::Forms::TextBox^ txtboY2;
	private: System::Windows::Forms::TextBox^ txtboX2;
	private: System::Windows::Forms::TextBox^ txtboY1;
	private: System::Windows::Forms::TextBox^ txtboX1;


	private:
		Graphics^ gr;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btneliminar = (gcnew System::Windows::Forms::Button());
			this->btndibuja = (gcnew System::Windows::Forms::Button());
			this->txtboY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtboX2 = (gcnew System::Windows::Forms::TextBox());
			this->txtboY1 = (gcnew System::Windows::Forms::TextBox());
			this->txtboX1 = (gcnew System::Windows::Forms::TextBox());
			this->lbly2 = (gcnew System::Windows::Forms::Label());
			this->lblx2 = (gcnew System::Windows::Forms::Label());
			this->lbly1 = (gcnew System::Windows::Forms::Label());
			this->lblx1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(297, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(574, 549);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Formu3::panel1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btneliminar);
			this->groupBox1->Controls->Add(this->btndibuja);
			this->groupBox1->Controls->Add(this->txtboY2);
			this->groupBox1->Controls->Add(this->txtboX2);
			this->groupBox1->Controls->Add(this->txtboY1);
			this->groupBox1->Controls->Add(this->txtboX1);
			this->groupBox1->Controls->Add(this->lbly2);
			this->groupBox1->Controls->Add(this->lblx2);
			this->groupBox1->Controls->Add(this->lbly1);
			this->groupBox1->Controls->Add(this->lblx1);
			this->groupBox1->Location = System::Drawing::Point(13, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(248, 488);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Dibujar Linea";
			// 
			// btneliminar
			// 
			this->btneliminar->Location = System::Drawing::Point(146, 275);
			this->btneliminar->Name = L"btneliminar";
			this->btneliminar->Size = System::Drawing::Size(75, 23);
			this->btneliminar->TabIndex = 9;
			this->btneliminar->Text = L"Eliminar";
			this->btneliminar->UseVisualStyleBackColor = true;
			this->btneliminar->Click += gcnew System::EventHandler(this, &Formu3::btneliminar_Click);
			// 
			// btndibuja
			// 
			this->btndibuja->Location = System::Drawing::Point(30, 275);
			this->btndibuja->Name = L"btndibuja";
			this->btndibuja->Size = System::Drawing::Size(75, 23);
			this->btndibuja->TabIndex = 8;
			this->btndibuja->Text = L"Dibujar";
			this->btndibuja->UseVisualStyleBackColor = true;
			this->btndibuja->Click += gcnew System::EventHandler(this, &Formu3::btndibuja_Click);
			// 
			// txtboY2
			// 
			this->txtboY2->Location = System::Drawing::Point(101, 218);
			this->txtboY2->Name = L"txtboY2";
			this->txtboY2->Size = System::Drawing::Size(47, 22);
			this->txtboY2->TabIndex = 7;
			// 
			// txtboX2
			// 
			this->txtboX2->Location = System::Drawing::Point(101, 168);
			this->txtboX2->Name = L"txtboX2";
			this->txtboX2->Size = System::Drawing::Size(47, 22);
			this->txtboX2->TabIndex = 6;
			// 
			// txtboY1
			// 
			this->txtboY1->Location = System::Drawing::Point(101, 117);
			this->txtboY1->Name = L"txtboY1";
			this->txtboY1->Size = System::Drawing::Size(47, 22);
			this->txtboY1->TabIndex = 5;
			// 
			// txtboX1
			// 
			this->txtboX1->Location = System::Drawing::Point(101, 68);
			this->txtboX1->Name = L"txtboX1";
			this->txtboX1->Size = System::Drawing::Size(47, 22);
			this->txtboX1->TabIndex = 4;
			// 
			// lbly2
			// 
			this->lbly2->AutoSize = true;
			this->lbly2->Location = System::Drawing::Point(27, 218);
			this->lbly2->Name = L"lbly2";
			this->lbly2->Size = System::Drawing::Size(25, 17);
			this->lbly2->TabIndex = 3;
			this->lbly2->Text = L"Y2";
			this->lbly2->Click += gcnew System::EventHandler(this, &Formu3::label4_Click);
			// 
			// lblx2
			// 
			this->lblx2->AutoSize = true;
			this->lblx2->Location = System::Drawing::Point(27, 174);
			this->lblx2->Name = L"lblx2";
			this->lblx2->Size = System::Drawing::Size(25, 17);
			this->lblx2->TabIndex = 2;
			this->lblx2->Text = L"X2";
			// 
			// lbly1
			// 
			this->lbly1->AutoSize = true;
			this->lbly1->Location = System::Drawing::Point(27, 117);
			this->lbly1->Name = L"lbly1";
			this->lbly1->Size = System::Drawing::Size(25, 17);
			this->lbly1->TabIndex = 1;
			this->lbly1->Text = L"Y1";
			// 
			// lblx1
			// 
			this->lblx1->AutoSize = true;
			this->lblx1->Location = System::Drawing::Point(27, 68);
			this->lblx1->Name = L"lblx1";
			this->lblx1->Size = System::Drawing::Size(25, 17);
			this->lblx1->TabIndex = 0;
			this->lblx1->Text = L"X1";
			// 
			// Formu3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(883, 613);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"Formu3";
			this->Text = L"Formu3";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btndibuja_Click(System::Object^ sender, System::EventArgs^ e) {

		Int16 x1, x2, y1, y2;
		x1 = Convert::ToInt16(txtboX1->Text);
		x2 = Convert::ToInt16(txtboX2->Text);
		y1 = Convert::ToInt16(txtboY1->Text);
		y2 = Convert::ToInt16(txtboY2->Text);
		//Graphics^ gr = panel1->CreateGraphics();
		if (x1 >= 0 && y1 >= 0 && y2 >= 0)

		gr->DrawLine(gcnew Pen(Color::Blue, 4), x1, y1, x2, y2);
		gr->DrawEllipse(gcnew Pen(Color::Green, 3), 20, 20, 60, 60);
		gr->DrawRectangle(gcnew Pen(Color::Yellow, 2), 70, 70, 50, 50);
		gr->FillEllipse(Brushes::Beige, 20, 20, 60, 60);
		//demo->Insert(0,gcnew String("demo"));

	}
private: System::Void btneliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	gr->Clear(Color::White);
}
private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	e->X;
	e->Y;
	//MessageBox::Show("la coordenada en X es: " + e->X + "La coordenada Y es " + e->Y);
}
};
}
