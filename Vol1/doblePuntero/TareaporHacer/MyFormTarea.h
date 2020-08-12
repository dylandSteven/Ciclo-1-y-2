#pragma once

namespace TareaporHacer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyFormTarea
	/// </summary>
	public ref class MyFormTarea : public System::Windows::Forms::Form
	{
	public:
		MyFormTarea(void)
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
		~MyFormTarea()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ txtEscribir;
	private: System::Windows::Forms::TextBox^ txtContar;
	protected:


	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ lblEscribir;

	private: System::Windows::Forms::Label^ lblContar;


	private: System::Windows::Forms::Label^ lbleliminar;


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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->txtEscribir = (gcnew System::Windows::Forms::TextBox());
			this->txtContar = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->lblEscribir = (gcnew System::Windows::Forms::Label());
			this->lblContar = (gcnew System::Windows::Forms::Label());
			this->lbleliminar = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(38, 48);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(166, 420);
			this->listBox1->TabIndex = 0;
			// 
			// txtEscribir
			// 
			this->txtEscribir->Location = System::Drawing::Point(313, 95);
			this->txtEscribir->Name = L"txtEscribir";
			this->txtEscribir->Size = System::Drawing::Size(128, 22);
			this->txtEscribir->TabIndex = 1;
			// 
			// txtContar
			// 
			this->txtContar->Location = System::Drawing::Point(313, 221);
			this->txtContar->Name = L"txtContar";
			this->txtContar->Size = System::Drawing::Size(128, 22);
			this->txtContar->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(313, 322);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(128, 22);
			this->textBox3->TabIndex = 3;
			// 
			// lblEscribir
			// 
			this->lblEscribir->AutoSize = true;
			this->lblEscribir->Location = System::Drawing::Point(313, 72);
			this->lblEscribir->Name = L"lblEscribir";
			this->lblEscribir->Size = System::Drawing::Size(55, 17);
			this->lblEscribir->TabIndex = 4;
			this->lblEscribir->Text = L"Escribir";
			this->lblEscribir->Click += gcnew System::EventHandler(this, &MyFormTarea::label1_Click);
			// 
			// lblContar
			// 
			this->lblContar->AutoSize = true;
			this->lblContar->Location = System::Drawing::Point(313, 201);
			this->lblContar->Name = L"lblContar";
			this->lblContar->Size = System::Drawing::Size(50, 17);
			this->lblContar->TabIndex = 6;
			this->lblContar->Text = L"Contar";
			// 
			// lbleliminar
			// 
			this->lbleliminar->AutoSize = true;
			this->lbleliminar->Location = System::Drawing::Point(310, 302);
			this->lbleliminar->Name = L"lbleliminar";
			this->lbleliminar->Size = System::Drawing::Size(58, 17);
			this->lbleliminar->TabIndex = 7;
			this->lbleliminar->Text = L"Eliminar";
			// 
			// MyFormTarea
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(556, 515);
			this->Controls->Add(this->lbleliminar);
			this->Controls->Add(this->lblContar);
			this->Controls->Add(this->lblEscribir);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->txtContar);
			this->Controls->Add(this->txtEscribir);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyFormTarea";
			this->Text = L"MyFormTarea";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
