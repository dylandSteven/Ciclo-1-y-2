#pragma once

namespace Semana11Ejemplo1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormVisor
	/// </summary>
	public ref class FormVisor : public System::Windows::Forms::Form
	{
	private:
		array<Bitmap^>^ imagenes;
		Int16 contador;
	private: System::Windows::Forms::PictureBox^ pbxVisor;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnINiciar;
		   Graphics^ lienzo;
	public:
		FormVisor(void)
		{
			InitializeComponent();
			imagenes= gcnew array<Bitmap^>(10);
			imagenes[0] = gcnew Bitmap("Acuna.jpg");
			imagenes[1] = gcnew Bitmap("Aguilar.jpg");
			imagenes[2] = gcnew Bitmap("Albrech.jpg");
			imagenes[3] = gcnew Bitmap("Alcala.jpg");
			imagenes[4] = gcnew Bitmap("Alcorta.jpg");
			imagenes[5] = gcnew Bitmap("Ananculi.jpg");
			imagenes[6] = gcnew Bitmap("Andrade.jpg");
			imagenes[7] = gcnew Bitmap("Apaza.jpg");
			imagenes[8] = gcnew Bitmap("Aramayo.jpg");
			imagenes[9] = gcnew Bitmap("Arana.jpg");
			contador = 0;
			lienzo = pnlVisor->CreateGraphics();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormVisor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ btnMostrar;
	private: System::Windows::Forms::NumericUpDown^ MUneros;
	private: System::Windows::Forms::Panel^ pnlVisor;
	private: System::ComponentModel::IContainer^ components;


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
			this->btnINiciar = (gcnew System::Windows::Forms::Button());
			this->btnMostrar = (gcnew System::Windows::Forms::Button());
			this->MUneros = (gcnew System::Windows::Forms::NumericUpDown());
			this->pnlVisor = (gcnew System::Windows::Forms::Panel());
			this->pbxVisor = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MUneros))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxVisor))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnINiciar);
			this->groupBox1->Controls->Add(this->btnMostrar);
			this->groupBox1->Controls->Add(this->MUneros);
			this->groupBox1->Location = System::Drawing::Point(28, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 284);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Visor de Imagenes";
			// 
			// btnINiciar
			// 
			this->btnINiciar->Location = System::Drawing::Point(24, 139);
			this->btnINiciar->Name = L"btnINiciar";
			this->btnINiciar->Size = System::Drawing::Size(75, 23);
			this->btnINiciar->TabIndex = 4;
			this->btnINiciar->Text = L"Iniciar";
			this->btnINiciar->UseVisualStyleBackColor = true;
			this->btnINiciar->Click += gcnew System::EventHandler(this, &FormVisor::btnINiciar_Click);
			// 
			// btnMostrar
			// 
			this->btnMostrar->Location = System::Drawing::Point(24, 51);
			this->btnMostrar->Name = L"btnMostrar";
			this->btnMostrar->Size = System::Drawing::Size(75, 23);
			this->btnMostrar->TabIndex = 3;
			this->btnMostrar->Text = L"Mostrar";
			this->btnMostrar->UseVisualStyleBackColor = true;
			this->btnMostrar->Click += gcnew System::EventHandler(this, &FormVisor::btnMostrar_Click);
			// 
			// MUneros
			// 
			this->MUneros->Location = System::Drawing::Point(6, 99);
			this->MUneros->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MUneros->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MUneros->Name = L"MUneros";
			this->MUneros->Size = System::Drawing::Size(120, 22);
			this->MUneros->TabIndex = 2;
			this->MUneros->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// pnlVisor
			// 
			this->pnlVisor->Location = System::Drawing::Point(278, 23);
			this->pnlVisor->Name = L"pnlVisor";
			this->pnlVisor->Size = System::Drawing::Size(352, 285);
			this->pnlVisor->TabIndex = 1;
			this->pnlVisor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormVisor::pnlVisor_Paint);
			// 
			// pbxVisor
			// 
			this->pbxVisor->Location = System::Drawing::Point(278, 335);
			this->pbxVisor->Name = L"pbxVisor";
			this->pbxVisor->Size = System::Drawing::Size(352, 229);
			this->pbxVisor->TabIndex = 2;
			this->pbxVisor->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 800;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormVisor::timer1_Tick);
			// 
			// FormVisor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 732);
			this->Controls->Add(this->pbxVisor);
			this->Controls->Add(this->pnlVisor);
			this->Controls->Add(this->groupBox1);
			this->Name = L"FormVisor";
			this->Text = L"FormVisor";
			this->Load += gcnew System::EventHandler(this, &FormVisor::FormVisor_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MUneros))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxVisor))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormVisor_Load(System::Object^ sender, System::EventArgs^ e) {
		//lienzo->DrawImage(imagen, 0, 0);
	}
private: System::Void pnlVisor_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	//lienzo->DrawImage(imagen, 0, 0);
}
private: System::Void btnMostrar_Click(System::Object^ sender, System::EventArgs^ e) {
	Int16 i = Convert::ToInt16(MUneros->Text);
	lienzo->DrawImage(imagenes[i - 1],10,10,Rectangle(10,10,20,20),GraphicsUnit::Pixel);
	pbxVisor->Image = imagenes[i - 1];

}
private: System::Void btnINiciar_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = true;
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (contador > 9)
	contador = 0;
	lienzo->DrawImage(imagenes[contador], 10, 10);
	contador++;


}
};
}
