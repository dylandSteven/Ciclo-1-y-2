#pragma once
#include"Control.h"
namespace sprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FRMAminaciones3
	/// </summary>
	public ref class FRMAminaciones3 : public System::Windows::Forms::Form
	{
	private:
		Controladora^ juego;
		BufferedGraphicsContext^ espacioBuffer;
		BufferedGraphics^ bg;
		Graphics^ gr;
	public:
		FRMAminaciones3(void)
		{
			InitializeComponent();
			 espacioBuffer=BufferedGraphicsManager::Current;
			 gr = panel1->CreateGraphics();
			bg=espacioBuffer->Allocate(gr, this->ClientRectangle);
			juego = gcnew Controladora(bg->Graphics, 12);

			
			//personaje = gcnew PersonajeADM(bg->Graphics,10,10);
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FRMAminaciones3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(3, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(814, 610);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FRMAminaciones3::panel1_MouseClick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FRMAminaciones3::timer1_Tick);
			// 
			// FRMAminaciones3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 623);
			this->Controls->Add(this->panel1);
			this->Name = L"FRMAminaciones3";
			this->Text = L"FRMAminaciones3";
			this->Load += gcnew System::EventHandler(this, &FRMAminaciones3::FRMAminaciones3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FRMAminaciones3::FRMAminaciones3_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	    bg->Graphics->Clear(SystemColors::Control);
		juego->graficar();
		juego->moverNPC();
		bg->Render(gr);
	
	}
	private: System::Void FRMAminaciones3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->mover(e);
	
	}
	private: System::Void FRMAminaciones3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	
	}
	};
}
