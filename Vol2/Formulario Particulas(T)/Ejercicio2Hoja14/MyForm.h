#pragma once
#include "LargeHadronCollider.h"
namespace Ejercicio2Hoja14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		LHC* lhc;
	public:
		MyForm(void)
		{
			InitializeComponent();
			lhc = new LHC();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete lhc;
			}
		}
	private: System::Windows::Forms::Timer^  clock;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Tick += gcnew System::EventHandler(this, &MyForm::clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 411);
			this->MinimumSize = System::Drawing::Size(246, 185);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	Void clock_Tick(Object^  sender, EventArgs^  e)
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::White);
		lhc->Mover(bf->Graphics);
		lhc->Mostrar(bf->Graphics);
		this->Text = "N:" + lhc->GetNeutrones().ToString() + " P:" + lhc->GetProtones().ToString();


		bf->Render(g);
	}
	};
}
