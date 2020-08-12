#pragma once
#include"Numeros.h"
namespace claseProfe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formclase
	/// </summary>
	public ref class Formclase : public System::Windows::Forms::Form
	{
	public:
		Formclase(void)
		{
			InitializeComponent();
			arreglo = new Numeros();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formclase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbxNumeros;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btninsertar;

	private: System::Windows::Forms::TextBox^ tbxinsertar;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ tbxeliminar;
	private: System::Windows::Forms::Button^ btneliminar;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ tbxcontar;
	private: System::Windows::Forms::Button^ btnContar;




	private: System::Windows::Forms::GroupBox^ grpbx1;

		   Numeros* arreglo;
	private: System::Windows::Forms::Label^ lblcont;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ btnordenar;


	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ txbxpos;

	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::TextBox^ tbxnume;

	private: System::Windows::Forms::Label^ lblNumero;
	private: System::Windows::Forms::Label^ Posicion;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbxNumeros = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->btnordenar = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->lblNumero = (gcnew System::Windows::Forms::Label());
			this->Posicion = (gcnew System::Windows::Forms::Label());
			this->tbxnume = (gcnew System::Windows::Forms::TextBox());
			this->txbxpos = (gcnew System::Windows::Forms::TextBox());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tbxeliminar = (gcnew System::Windows::Forms::TextBox());
			this->btneliminar = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblcont = (gcnew System::Windows::Forms::Label());
			this->tbxcontar = (gcnew System::Windows::Forms::TextBox());
			this->btnContar = (gcnew System::Windows::Forms::Button());
			this->grpbx1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbxinsertar = (gcnew System::Windows::Forms::TextBox());
			this->btninsertar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->grpbx1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbxNumeros
			// 
			this->lbxNumeros->FormattingEnabled = true;
			this->lbxNumeros->ItemHeight = 16;
			this->lbxNumeros->Location = System::Drawing::Point(15, 21);
			this->lbxNumeros->Name = L"lbxNumeros";
			this->lbxNumeros->Size = System::Drawing::Size(137, 404);
			this->lbxNumeros->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->grpbx1);
			this->groupBox1->Controls->Add(this->lbxNumeros);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(855, 467);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mantenimiento de Numeros";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Formclase::groupBox1_Enter);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->btnordenar);
			this->groupBox5->Location = System::Drawing::Point(519, 219);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(256, 106);
			this->groupBox5->TabIndex = 8;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Ordenar";
			// 
			// btnordenar
			// 
			this->btnordenar->Location = System::Drawing::Point(73, 46);
			this->btnordenar->Name = L"btnordenar";
			this->btnordenar->Size = System::Drawing::Size(75, 23);
			this->btnordenar->TabIndex = 3;
			this->btnordenar->Text = L"Ordenar";
			this->btnordenar->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->lblNumero);
			this->groupBox4->Controls->Add(this->Posicion);
			this->groupBox4->Controls->Add(this->tbxnume);
			this->groupBox4->Controls->Add(this->txbxpos);
			this->groupBox4->Controls->Add(this->btnModificar);
			this->groupBox4->Location = System::Drawing::Point(513, 98);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(256, 106);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Modificar";
			this->groupBox4->Enter += gcnew System::EventHandler(this, &Formclase::groupBox4_Enter);
			// 
			// lblNumero
			// 
			this->lblNumero->AutoSize = true;
			this->lblNumero->Location = System::Drawing::Point(79, 27);
			this->lblNumero->Name = L"lblNumero";
			this->lblNumero->Size = System::Drawing::Size(58, 17);
			this->lblNumero->TabIndex = 6;
			this->lblNumero->Text = L"Numero";
			// 
			// Posicion
			// 
			this->Posicion->AutoSize = true;
			this->Posicion->Location = System::Drawing::Point(5, 27);
			this->Posicion->Name = L"Posicion";
			this->Posicion->Size = System::Drawing::Size(61, 17);
			this->Posicion->TabIndex = 5;
			this->Posicion->Text = L"Posicion";
			// 
			// tbxnume
			// 
			this->tbxnume->Location = System::Drawing::Point(82, 48);
			this->tbxnume->Name = L"tbxnume";
			this->tbxnume->Size = System::Drawing::Size(58, 22);
			this->tbxnume->TabIndex = 4;
			// 
			// txbxpos
			// 
			this->txbxpos->Location = System::Drawing::Point(6, 50);
			this->txbxpos->Name = L"txbxpos";
			this->txbxpos->Size = System::Drawing::Size(60, 22);
			this->txbxpos->TabIndex = 1;
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(159, 48);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(75, 23);
			this->btnModificar->TabIndex = 3;
			this->btnModificar->Text = L"Cambiar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &Formclase::btnModificar_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tbxeliminar);
			this->groupBox3->Controls->Add(this->btneliminar);
			this->groupBox3->Location = System::Drawing::Point(182, 239);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(256, 106);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Eliminar";
			// 
			// tbxeliminar
			// 
			this->tbxeliminar->Location = System::Drawing::Point(6, 49);
			this->tbxeliminar->Name = L"tbxeliminar";
			this->tbxeliminar->Size = System::Drawing::Size(129, 22);
			this->tbxeliminar->TabIndex = 1;
			this->tbxeliminar->TextChanged += gcnew System::EventHandler(this, &Formclase::tbxeliminar_TextChanged);
			// 
			// btneliminar
			// 
			this->btneliminar->Location = System::Drawing::Point(175, 49);
			this->btneliminar->Name = L"btneliminar";
			this->btneliminar->Size = System::Drawing::Size(75, 23);
			this->btneliminar->TabIndex = 3;
			this->btneliminar->Text = L"Eliminar";
			this->btneliminar->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->lblcont);
			this->groupBox2->Controls->Add(this->tbxcontar);
			this->groupBox2->Controls->Add(this->btnContar);
			this->groupBox2->Location = System::Drawing::Point(182, 133);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 106);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L" Contar";
			// 
			// lblcont
			// 
			this->lblcont->AutoSize = true;
			this->lblcont->Location = System::Drawing::Point(28, 86);
			this->lblcont->Name = L"lblcont";
			this->lblcont->Size = System::Drawing::Size(36, 17);
			this->lblcont->TabIndex = 4;
			this->lblcont->Text = L"       ";
			// 
			// tbxcontar
			// 
			this->tbxcontar->Location = System::Drawing::Point(6, 49);
			this->tbxcontar->Name = L"tbxcontar";
			this->tbxcontar->Size = System::Drawing::Size(129, 22);
			this->tbxcontar->TabIndex = 1;
			// 
			// btnContar
			// 
			this->btnContar->Location = System::Drawing::Point(175, 49);
			this->btnContar->Name = L"btnContar";
			this->btnContar->Size = System::Drawing::Size(75, 23);
			this->btnContar->TabIndex = 3;
			this->btnContar->Text = L"Contar";
			this->btnContar->UseVisualStyleBackColor = true;
			this->btnContar->Click += gcnew System::EventHandler(this, &Formclase::btnContar_Click);
			// 
			// grpbx1
			// 
			this->grpbx1->Controls->Add(this->tbxinsertar);
			this->grpbx1->Controls->Add(this->btninsertar);
			this->grpbx1->Location = System::Drawing::Point(182, 21);
			this->grpbx1->Name = L"grpbx1";
			this->grpbx1->Size = System::Drawing::Size(256, 106);
			this->grpbx1->TabIndex = 4;
			this->grpbx1->TabStop = false;
			this->grpbx1->Text = L"Insertar";
			// 
			// tbxinsertar
			// 
			this->tbxinsertar->Location = System::Drawing::Point(6, 49);
			this->tbxinsertar->Name = L"tbxinsertar";
			this->tbxinsertar->Size = System::Drawing::Size(129, 22);
			this->tbxinsertar->TabIndex = 1;
			// 
			// btninsertar
			// 
			this->btninsertar->Location = System::Drawing::Point(175, 49);
			this->btninsertar->Name = L"btninsertar";
			this->btninsertar->Size = System::Drawing::Size(75, 23);
			this->btninsertar->TabIndex = 3;
			this->btninsertar->Text = L"Insertar";
			this->btninsertar->UseVisualStyleBackColor = true;
			this->btninsertar->Click += gcnew System::EventHandler(this, &Formclase::button1_Click);
			// 
			// Formclase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(913, 489);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Formclase";
			this->Text = L"Formclase";
			this->groupBox1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->grpbx1->ResumeLayout(false);
			this->grpbx1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Int16 n = Convert::ToInt16(tbxinsertar->Text);
		lbxNumeros->Items->Add(n);
		arreglo->insertar(n);
		poblarListBox();
		tbxinsertar->Text = "";
		tbxinsertar->Focus();
	}
		   void poblarListBox()
		   {
			   lbxNumeros->Items->Clear();
			   for (int i = 0; i < arreglo->cantidad(); ++i)
			   {   Int16 v = arreglo->recuperar(i);
				   lbxNumeros->Items->Add(v);
			   }
		   }
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnContar_Click(System::Object^ sender, System::EventArgs^ e) {
	Int16 n = Convert::ToInt16(tbxcontar->Text);
	n=arreglo->contar(n); 
	lblcont->Text = n + " ";
	}
private: System::Void tbxeliminar_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Int16 elim = Convert::ToInt16(tbxeliminar->Text);
	arreglo->eliminar(elim);
	poblarListBox();
	
}
private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {

	Int16 num1 = Convert::ToInt16(txbxpos->Text);
	Int16 num2 = Convert::ToInt16(tbxnume->Text);
	arreglo->modificar(num1, num2);
	poblarListBox();

}
};
}
