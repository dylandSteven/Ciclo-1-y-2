#pragma once

namespace sprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de formSprite
	/// </summary>
	public ref class formSprite : public System::Windows::Forms::Form
	{
	private:
		Bitmap ^personaje;
		int anchoSprite;
		int altoSprite;
		int anchoImagen;
		Graphics^ lienzo;
		Int16 x, y;
		int filas, columnas;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ nmny;

	private: System::Windows::Forms::NumericUpDown^ nmnx;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
		   int altoImagen;

	public:
		formSprite(void)
		{
			InitializeComponent();
			personaje = gcnew Bitmap("Personaje1.png");
			anchoSprite = personaje->Width;
			altoSprite = personaje->Height;
			anchoImagen = anchoSprite / 4;
			altoImagen = altoSprite / 4;
			lienzo = panel1->CreateGraphics();
			filas = 0;
			columnas = 0;
		
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~formSprite()
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


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nmny = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmnx = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmny))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmnx))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nmny);
			this->groupBox1->Controls->Add(this->nmnx);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(27, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(243, 311);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &formSprite::groupBox1_Enter);
			// 
			// nmny
			// 
			this->nmny->Location = System::Drawing::Point(97, 146);
			this->nmny->Name = L"nmny";
			this->nmny->Size = System::Drawing::Size(120, 22);
			this->nmny->TabIndex = 4;
			// 
			// nmnx
			// 
			this->nmnx->Location = System::Drawing::Point(97, 111);
			this->nmnx->Name = L"nmnx";
			this->nmnx->Size = System::Drawing::Size(120, 22);
			this->nmnx->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Recortar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &formSprite::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(311, 52);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(253, 302);
			this->panel1->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &formSprite::timer1_Tick);
			// 
			// formSprite
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 516);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"formSprite";
			this->Text = L"formSprite";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmny))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmnx))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		filas = Convert::ToInt16(nmnx->Text);
		columnas = Convert :: ToInt16(nmnx->Text);
		lienzo->Clear(SystemColors::Control);
		Rectangle areaVisible = Rectangle(anchoImagen * x, altoImagen * y, anchoImagen, altoImagen);
		lienzo->DrawImage(personaje,0,0,areaVisible,GraphicsUnit::Pixel);
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	lienzo->Clear(SystemColors::Control);
	if (columnas > 3) { columnas = 0;filas++; }
	if (filas > 3)filas = 0;
	Rectangle areaVisible = Rectangle(anchoImagen * columnas, altoImagen * filas, anchoImagen, altoImagen);
	lienzo->DrawImage(personaje, 0, 0, areaVisible, GraphicsUnit::Pixel);
	columnas++;
}
};
}
