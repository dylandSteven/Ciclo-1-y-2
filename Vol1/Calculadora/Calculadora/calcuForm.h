#pragma once
#include<vector>
#include<string>
using namespace std;
namespace Calculadora {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de calcuForm
	/// </summary>
	public ref class calcuForm : public System::Windows::Forms::Form
	{
	public:
	
			String ^muestraTodo="";
			int resultado; 
			int aux;
	private: System::Windows::Forms::Label^ lblResultado;
	public:
		int contador = 0;
		calcuForm(void)
		{
			int numero;
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}


		void getresultaod() {
			if (contador == 1) {
				resultado = aux;

			}
			else if (contador > 1) {
				resultado *= 10;
				resultado += aux;
			}
		}
		

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~calcuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn8;







	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btnresta;
	private: System::Windows::Forms::Button^ btnmulti;
	private: System::Windows::Forms::Button^ btndiv;
	private: System::Windows::Forms::Button^ btnigual;





	private: System::Windows::Forms::Button^ btnsuma;
	private: System::Windows::Forms::TextBox^ txtResultado;

	private: System::Windows::Forms::Button^ btn0;
	private: System::Windows::Forms::Button^ btn9;
		
	

	protected:

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->txtResultado = (gcnew System::Windows::Forms::TextBox());
			this->btnresta = (gcnew System::Windows::Forms::Button());
			this->btnmulti = (gcnew System::Windows::Forms::Button());
			this->btndiv = (gcnew System::Windows::Forms::Button());
			this->btnigual = (gcnew System::Windows::Forms::Button());
			this->btnsuma = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblResultado);
			this->groupBox1->Controls->Add(this->btn9);
			this->groupBox1->Controls->Add(this->btn0);
			this->groupBox1->Controls->Add(this->txtResultado);
			this->groupBox1->Controls->Add(this->btnresta);
			this->groupBox1->Controls->Add(this->btnmulti);
			this->groupBox1->Controls->Add(this->btndiv);
			this->groupBox1->Controls->Add(this->btnigual);
			this->groupBox1->Controls->Add(this->btnsuma);
			this->groupBox1->Controls->Add(this->btn2);
			this->groupBox1->Controls->Add(this->btn3);
			this->groupBox1->Controls->Add(this->btn4);
			this->groupBox1->Controls->Add(this->btn5);
			this->groupBox1->Controls->Add(this->btn6);
			this->groupBox1->Controls->Add(this->btn7);
			this->groupBox1->Controls->Add(this->btn8);
			this->groupBox1->Controls->Add(this->btn1);
			this->groupBox1->Location = System::Drawing::Point(47, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(259, 437);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &calcuForm::groupBox1_Enter);
			// 
			// btn9
			// 
			this->btn9->Location = System::Drawing::Point(84, 280);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(28, 31);
			this->btn9->TabIndex = 16;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &calcuForm::btn9_Click);
			// 
			// btn0
			// 
			this->btn0->Location = System::Drawing::Point(50, 317);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(28, 31);
			this->btn0->TabIndex = 15;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &calcuForm::btn0_Click);
			// 
			// txtResultado
			// 
			this->txtResultado->Enabled = false;
			this->txtResultado->Location = System::Drawing::Point(18, 154);
			this->txtResultado->Name = L"txtResultado";
			this->txtResultado->Size = System::Drawing::Size(204, 22);
			this->txtResultado->TabIndex = 14;
			this->txtResultado->TextChanged += gcnew System::EventHandler(this, &calcuForm::txtResultado_TextChanged);
			// 
			// btnresta
			// 
			this->btnresta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnresta->Location = System::Drawing::Point(179, 205);
			this->btnresta->Name = L"btnresta";
			this->btnresta->Size = System::Drawing::Size(27, 31);
			this->btnresta->TabIndex = 13;
			this->btnresta->Text = L"-";
			this->btnresta->UseVisualStyleBackColor = true;
			this->btnresta->Click += gcnew System::EventHandler(this, &calcuForm::btnresta_Click);
			// 
			// btnmulti
			// 
			this->btnmulti->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnmulti->Location = System::Drawing::Point(146, 243);
			this->btnmulti->Name = L"btnmulti";
			this->btnmulti->Size = System::Drawing::Size(27, 31);
			this->btnmulti->TabIndex = 12;
			this->btnmulti->Text = L"*";
			this->btnmulti->UseVisualStyleBackColor = true;
			this->btnmulti->Click += gcnew System::EventHandler(this, &calcuForm::button13_Click);
			// 
			// btndiv
			// 
			this->btndiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btndiv->Location = System::Drawing::Point(179, 243);
			this->btndiv->Name = L"btndiv";
			this->btndiv->Size = System::Drawing::Size(27, 31);
			this->btndiv->TabIndex = 11;
			this->btndiv->Text = L"/";
			this->btndiv->UseVisualStyleBackColor = true;
			this->btndiv->Click += gcnew System::EventHandler(this, &calcuForm::btndiv_Click);
			// 
			// btnigual
			// 
			this->btnigual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnigual->Location = System::Drawing::Point(146, 280);
			this->btnigual->Name = L"btnigual";
			this->btnigual->Size = System::Drawing::Size(60, 31);
			this->btnigual->TabIndex = 10;
			this->btnigual->Text = L"=";
			this->btnigual->UseVisualStyleBackColor = true;
			this->btnigual->Click += gcnew System::EventHandler(this, &calcuForm::btnigual_Click);
			// 
			// btnsuma
			// 
			this->btnsuma->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnsuma->Location = System::Drawing::Point(146, 205);
			this->btnsuma->Name = L"btnsuma";
			this->btnsuma->Size = System::Drawing::Size(27, 31);
			this->btnsuma->TabIndex = 9;
			this->btnsuma->Text = L"+";
			this->btnsuma->UseVisualStyleBackColor = true;
			this->btnsuma->Click += gcnew System::EventHandler(this, &calcuForm::btnsuma_Click);
			// 
			// btn2
			// 
			this->btn2->Location = System::Drawing::Point(50, 205);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(28, 31);
			this->btn2->TabIndex = 7;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &calcuForm::button8_Click);
			// 
			// btn3
			// 
			this->btn3->Location = System::Drawing::Point(84, 205);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(24, 31);
			this->btn3->TabIndex = 6;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &calcuForm::btn3_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(18, 242);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(26, 32);
			this->btn4->TabIndex = 5;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &calcuForm::btn4_Click);
			// 
			// btn5
			// 
			this->btn5->Location = System::Drawing::Point(50, 242);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(28, 32);
			this->btn5->TabIndex = 4;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &calcuForm::btn5_Click);
			// 
			// btn6
			// 
			this->btn6->Location = System::Drawing::Point(84, 243);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(24, 31);
			this->btn6->TabIndex = 3;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &calcuForm::btn6_Click);
			// 
			// btn7
			// 
			this->btn7->Location = System::Drawing::Point(18, 280);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(26, 31);
			this->btn7->TabIndex = 2;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &calcuForm::button3_Click);
			// 
			// btn8
			// 
			this->btn8->Location = System::Drawing::Point(50, 280);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(28, 31);
			this->btn8->TabIndex = 1;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &calcuForm::btn8_Click);
			// 
			// btn1
			// 
			this->btn1->Location = System::Drawing::Point(18, 205);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(26, 31);
			this->btn1->TabIndex = 0;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &calcuForm::btn1_Click);
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->Location = System::Drawing::Point(98, 381);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(0, 17);
			this->lblResultado->TabIndex = 17;
			this->lblResultado->Click += gcnew System::EventHandler(this, &calcuForm::lblResultado_Click);
			// 
			// calcuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 505);
			this->Controls->Add(this->groupBox1);
			this->Name = L"calcuForm";
			this->Text = L"calcuForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ numero2 = "2";
		aux = 2;
		txtResultado->Text += numero2;
		contador++;
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero7 = "7";
	txtResultado->Text += numero7;
	aux = 7;
	contador++;
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero9 = "*";
	txtResultado->Text += numero9;

}
private: System::Void btn1_Click(System::Object^ sender, System::EventArgs^ e) {
	String ^numero1="1";

	txtResultado->Text+=numero1;
	aux = 1; contador++;
	

}
private: System::Void btn3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero3 = "3";
	txtResultado->Text += numero3;
	aux = 3;
	contador++;
}

private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero4 = "4";
	txtResultado->Text += numero4;
	aux = 4;
	contador++;
}
private: System::Void btn5_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero5 = "5";
	txtResultado->Text += numero5;
	aux = 5;

}
private: System::Void btn6_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero6 = "6";
	txtResultado->Text += numero6;
	aux = 6;
}
private: System::Void btn8_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero8 = "8";
	txtResultado->Text += numero8;
	aux = 8;
}
private: System::Void btn0_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero0 = "0";
	txtResultado->Text += numero0;
	aux = 0;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn9_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero9 = "9";
	txtResultado->Text += numero9;
	aux = 9;
}
private: System::Void btnsuma_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero9 = "+";
	txtResultado->Text += numero9;
}
private: System::Void btnresta_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ numero9 = "-";
	txtResultado->Text += numero9;


}
private: System::Void btndiv_Click(System::Object^ sender, System::EventArgs^ e) {
	//String^ numero9 = "/";
	txtResultado->Text = "0";
}
private: System::Void txtResultado_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	

}
private: System::Void btnigual_Click(System::Object^ sender, System::EventArgs^ e) {
	
Double s;
	s=Convert::ToDouble(txtResultado->Text);

	lblResultado->Text =s+"" ;
}
private: System::Void lblResultado_Click(System::Object^ sender, System::EventArgs^ e) {


}
};
}
