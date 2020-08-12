#pragma once
#include"form1.h"
namespace sem10parte2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de formudos
	/// </summary>
	public ref class formudos : public System::Windows::Forms::Form
	{
	public:
		formudos(void)
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
		~formudos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ formulariosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ formulario1;
	private: System::Windows::Forms::ToolStripMenuItem^ formulario2;
	private: System::Windows::Forms::ToolStripMenuItem^ formulario3;



	private: System::Windows::Forms::BindingSource^ bindingSource1;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->formulariosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formulario1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formulario2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formulario3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->formulariosToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(636, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// formulariosToolStripMenuItem
			// 
			this->formulariosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->formulario1,
					this->formulario2, this->formulario3
			});
			this->formulariosToolStripMenuItem->Name = L"formulariosToolStripMenuItem";
			this->formulariosToolStripMenuItem->Size = System::Drawing::Size(101, 24);
			this->formulariosToolStripMenuItem->Text = L"Formularios";
			// 
			// formulario1
			// 
			this->formulario1->Name = L"formulario1";
			this->formulario1->Size = System::Drawing::Size(224, 26);
			this->formulario1->Text = L"Formulario 1";
			this->formulario1->Click += gcnew System::EventHandler(this, &formudos::formulario1_Click);
			// 
			// formulario2
			// 
			this->formulario2->Name = L"formulario2";
			this->formulario2->Size = System::Drawing::Size(224, 26);
			this->formulario2->Text = L"Formulario 2";
			// 
			// formulario3
			// 
			this->formulario3->Name = L"formulario3";
			this->formulario3->Size = System::Drawing::Size(224, 26);
			this->formulario3->Text = L"Formulario 1 y 2";
			this->formulario3->Click += gcnew System::EventHandler(this, &formudos::formulario1Y2ToolStripMenuItem_Click);
			// 
			// formudos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 417);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"formudos";
			this->Text = L"formudos";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void formulario1Y2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void formulario1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	form1^ obj = gcnew form1();
	obj->ShowDialog();

}
};
}
