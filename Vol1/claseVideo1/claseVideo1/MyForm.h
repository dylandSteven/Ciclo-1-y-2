#pragma once
#include"Runner.h"
namespace claseVideo1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		Runner* kandy;
		Random r;
		Bitmap^ bmp2 = gcnew Bitmap("where.png");

		int aux;
		int auxX;

		double pos1 = 130 ;
		double pos2 = 360 ;
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(0, 360);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(982, 100);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(982, 455);
			this->Controls->Add(this->pictureBox1);
			this->Location = System::Drawing::Point(0, 360);
			this->Name = L"MyForm";
			this->Text = L"Kandy Runner";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode ==Keys:: R)
		{
			if (timer1->Enabled == false)
				timer1->Enabled = true;
			timer1->Enabled = false;
		}

		if (e->KeyCode == Keys::C)
		{
			aux = r.Next(0, 2);
			auxX = r.Next(10, 120);
			kandy = new Runner(auxX, pos2, aux);
			buffer->Render(g);
			timer1->Enabled = false;
		
		}
	}
	
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		g = this->CreateGraphics();
		espacio = BufferedGraphicsManager::Current;
		buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::AliceBlue);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		kandy->mover(buffer, bmp2);
		buffer->Render(g);
		buffer->Graphics->Clear(Color::AliceBlue);
	}
	};
}
