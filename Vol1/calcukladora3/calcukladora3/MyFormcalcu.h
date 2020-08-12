#pragma once

namespace calcukladora3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyFormcalcu
	/// </summary>
	public ref class MyFormcalcu : public System::Windows::Forms::Form
	{
	public:

		MyFormcalcu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Double resultado;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyFormcalcu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnigual;
	private: System::Windows::Forms::Button^ btndivi;
	private: System::Windows::Forms::Button^ btnmulti;
	private: System::Windows::Forms::Button^ btnrestar;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnigual = (gcnew System::Windows::Forms::Button());
			this->btndivi = (gcnew System::Windows::Forms::Button());
			this->btnmulti = (gcnew System::Windows::Forms::Button());
			this->btnrestar = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0), true));
			this->label3->Location = System::Drawing::Point(32, 235);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 29);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Respuesta";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Segundo Numero";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 17);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Primer Numero";
			// 
			// btnigual
			// 
			this->btnigual->Location = System::Drawing::Point(362, 87);
			this->btnigual->Name = L"btnigual";
			this->btnigual->Size = System::Drawing::Size(86, 109);
			this->btnigual->TabIndex = 16;
			this->btnigual->Text = L"=";
			this->btnigual->UseVisualStyleBackColor = true;
			this->btnigual->Click += gcnew System::EventHandler(this, &MyFormcalcu::btnigual_Click);
			// 
			// btndivi
			// 
			this->btndivi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btndivi->Location = System::Drawing::Point(290, 144);
			this->btndivi->Name = L"btndivi";
			this->btndivi->Size = System::Drawing::Size(52, 52);
			this->btndivi->TabIndex = 15;
			this->btndivi->Text = L"/";
			this->btndivi->UseVisualStyleBackColor = true;
			this->btndivi->Click += gcnew System::EventHandler(this, &MyFormcalcu::btndivi_Click);
			// 
			// btnmulti
			// 
			this->btnmulti->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnmulti->Location = System::Drawing::Point(237, 144);
			this->btnmulti->Name = L"btnmulti";
			this->btnmulti->Size = System::Drawing::Size(47, 52);
			this->btnmulti->TabIndex = 14;
			this->btnmulti->Text = L"*";
			this->btnmulti->UseVisualStyleBackColor = true;
			this->btnmulti->Click += gcnew System::EventHandler(this, &MyFormcalcu::btnmulti_Click);
			// 
			// btnrestar
			// 
			this->btnrestar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnrestar->Location = System::Drawing::Point(290, 87);
			this->btnrestar->Name = L"btnrestar";
			this->btnrestar->Size = System::Drawing::Size(52, 51);
			this->btnrestar->TabIndex = 13;
			this->btnrestar->Text = L"-";
			this->btnrestar->UseVisualStyleBackColor = true;
			this->btnrestar->Click += gcnew System::EventHandler(this, &MyFormcalcu::btnrestar_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button1->Location = System::Drawing::Point(237, 87);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(47, 51);
			this->button1->TabIndex = 12;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyFormcalcu::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 174);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyFormcalcu::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 101);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 10;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyFormcalcu::textBox1_TextChanged);
			// 
			// MyFormcalcu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(515, 409);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnigual);
			this->Controls->Add(this->btndivi);
			this->Controls->Add(this->btnmulti);
			this->Controls->Add(this->btnrestar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyFormcalcu";
			this->Text = L"MyFormcalcu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			Double n1;
			n1 = Convert::ToDouble(textBox1->Text);
			Double n2;
			n2 = Convert::ToDouble(textBox2->Text);
			double n3;
			n3 = n1 + n2;
			resultado = n3;
			

	}
private: System::Void btnrestar_Click(System::Object^ sender, System::EventArgs^ e) {
	Double n1;
	n1 = Convert::ToDouble(textBox1->Text);
	Double n2;
	n2 = Convert::ToDouble(textBox2->Text);
	double n3;
	n3 = n1 - n2;
	resultado = n3;



}
private: System::Void btnmulti_Click(System::Object^ sender, System::EventArgs^ e) {
	Double n1;
	n1 = Convert::ToDouble(textBox1->Text);
	Double n2;
	n2 = Convert::ToDouble(textBox2->Text);
	double n3;
	n3 = n1 * n2;
	resultado = n3;

}
private: System::Void btndivi_Click(System::Object^ sender, System::EventArgs^ e) {
	Double n1;
	n1 = Convert::ToDouble(textBox1->Text);
	Double n2;
	n2 = Convert::ToDouble(textBox2->Text);
	double n3;
	n3 = n1 / n2;
	resultado = n3;

}
private: System::Void btnigual_Click(System::Object^ sender, System::EventArgs^ e) {
	label3->Text = resultado + " ";
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
