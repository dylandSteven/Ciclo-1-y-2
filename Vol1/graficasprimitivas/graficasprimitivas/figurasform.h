#pragma once

namespace graficasprimitivas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de figurasform
	/// </summary>
	public ref class figurasform : public System::Windows::Forms::Form
	{
	public:
		figurasform(void)
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
		~figurasform()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// figurasform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 281);
			this->Name = L"figurasform";
			this->Text = L"figurasform";
			this->Load += gcnew System::EventHandler(this, &figurasform::figurasform_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &figurasform::figurasform_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void figurasform_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	

	private: System::Void figurasform_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		Pen^ pincel = gcnew Pen(Color::Blue, 4);
		gr->DrawLine(pincel, 10, 10, 10, 100);
		gr->DrawLine(pincel, 10, 100, 80, 100);
		gr->DrawLine(pincel, 80, 100, 80, 10);

		gr->DrawLine(pincel, 100, 10, 100, 100);
		gr->DrawLine(pincel, 100, 10, 180, 10);
		gr->DrawLine(pincel, 100, 55, 180, 55);
		gr->DrawLine(pincel, 180, 10, 180, 55);
		
		gr->DrawLine(pincel, 200, 10, 200, 100);
		gr->DrawLine(pincel, 200, 10, 280, 10);
		gr->DrawLine(pincel, 200, 100, 280, 100);
		}
	};
}
