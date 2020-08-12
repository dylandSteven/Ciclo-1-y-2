#pragma once
#include"ArregloGoku.h"
namespace gokuSprite {

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
		//CJugador* jugador = new CJugador(50, 50);
		Graphics^ g;
		Bitmap^ bmpJugador = gcnew Bitmap("SpriteGoku.png");
		CArregloGoku* objarreglo;
		BufferedGraphicsContext^ espacio ;
		BufferedGraphics^ buffer ;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(g, this->ClientRectangle);
			objarreglo = new CArregloGoku();
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(776, 475);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionartecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltartecla);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		
	
		
		
	
	}
	private: System::Void soltartecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//jugador->direccion = Direcciones::Ninguna;
	
	}
	private: System::Void presionartecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		/*switch (e->KeyCode)
		{
		case Keys::Left:
			jugador->direccion = Direcciones::Izquierda;

			break;

		case Keys::Right:
			jugador->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			jugador->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			jugador->direccion = Direcciones::Abajo;
			break;


		default:
			break;
		}*/
	
	
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


		buffer->Graphics->Clear(Color::White);
		objarreglo->dibujar(buffer, bmpJugador,e->X,e->Y);

		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
};
}
