#pragma once
#include"MyForm.h"
namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ Music;
	public:
		MenuPrincipal(void)
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
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Button^ btnInstruccionesDesaparecer;
	private: System::Windows::Forms::Button^ btnInstruccionesAparecer;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblabajo;
	private: System::Windows::Forms::Label^ lblIzquierda;
	private: System::Windows::Forms::Label^ lblDerecha;
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->btnInstruccionesDesaparecer = (gcnew System::Windows::Forms::Button());
			this->btnInstruccionesAparecer = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblabajo = (gcnew System::Windows::Forms::Label());
			this->lblIzquierda = (gcnew System::Windows::Forms::Label());
			this->lblDerecha = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(511, 751);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// btnInstruccionesDesaparecer
			// 
			this->btnInstruccionesDesaparecer->Location = System::Drawing::Point(372, 615);
			this->btnInstruccionesDesaparecer->Name = L"btnInstruccionesDesaparecer";
			this->btnInstruccionesDesaparecer->Size = System::Drawing::Size(104, 23);
			this->btnInstruccionesDesaparecer->TabIndex = 1;
			this->btnInstruccionesDesaparecer->Text = L"Instrucciones";
			this->btnInstruccionesDesaparecer->UseVisualStyleBackColor = true;
			this->btnInstruccionesDesaparecer->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstruccionesDesaparecer_Click);
			// 
			// btnInstruccionesAparecer
			// 
			this->btnInstruccionesAparecer->Location = System::Drawing::Point(372, 615);
			this->btnInstruccionesAparecer->Name = L"btnInstruccionesAparecer";
			this->btnInstruccionesAparecer->Size = System::Drawing::Size(100, 24);
			this->btnInstruccionesAparecer->TabIndex = 2;
			this->btnInstruccionesAparecer->Text = L"Instrucciones";
			this->btnInstruccionesAparecer->UseVisualStyleBackColor = true;
			this->btnInstruccionesAparecer->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstruccionesAparecer_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(553, 92);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(153, 334);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(534, 485);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(237, 153);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(712, 212);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 32);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Arriba";
			// 
			// lblabajo
			// 
			this->lblabajo->AutoSize = true;
			this->lblabajo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblabajo->Location = System::Drawing::Point(712, 261);
			this->lblabajo->Name = L"lblabajo";
			this->lblabajo->Size = System::Drawing::Size(94, 32);
			this->lblabajo->TabIndex = 6;
			this->lblabajo->Text = L"Abajo";
			// 
			// lblIzquierda
			// 
			this->lblIzquierda->AutoSize = true;
			this->lblIzquierda->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIzquierda->Location = System::Drawing::Point(712, 319);
			this->lblIzquierda->Name = L"lblIzquierda";
			this->lblIzquierda->Size = System::Drawing::Size(141, 32);
			this->lblIzquierda->TabIndex = 7;
			this->lblIzquierda->Text = L"Izquierda";
			// 
			// lblDerecha
			// 
			this->lblDerecha->AutoSize = true;
			this->lblDerecha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDerecha->Location = System::Drawing::Point(712, 368);
			this->lblDerecha->Name = L"lblDerecha";
			this->lblDerecha->Size = System::Drawing::Size(129, 32);
			this->lblDerecha->TabIndex = 8;
			this->lblDerecha->Text = L"Derecha";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(607, 664);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 726);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnInstruccionesAparecer);
			this->Controls->Add(this->lblDerecha);
			this->Controls->Add(this->lblIzquierda);
			this->Controls->Add(this->lblabajo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnInstruccionesDesaparecer);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void musica()
		{
			Music = gcnew SoundPlayer("Bomberman\\ModoSolitario.wav");
			Music->PlayLooping();
		}
	private: System::Void btnInstruccionesDesaparecer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 572;
		btnInstruccionesDesaparecer->Visible = false;
		btnInstruccionesAparecer->Visible = true;
	}
private: System::Void btnInstruccionesAparecer_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Width = 980;
	btnInstruccionesDesaparecer->Visible = true;
	btnInstruccionesAparecer->Visible = false;

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm^ frm = gcnew MyForm();
	this->Visible = true;
	frm->Show();
	Music->Stop();

}
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	musica();
}
};
}
