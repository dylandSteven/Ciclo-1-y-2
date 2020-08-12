#pragma once

namespace miniPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de formPaint
	/// </summary>
	public ref class formPaint : public System::Windows::Forms::Form
	{
	public:
		formPaint(void)
		{
			InitializeComponent();
			gr = panel1->CreateGraphics();
			lr = panel1->CreateGraphics();
			valor = 0;
			pintura = false;
			color = 0;
			e1 = e2 = false;
			x1 = y1 = x2 = y2 = 0;

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~formPaint()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ btnRectan;
	private: System::Windows::Forms::Button^ btnCuadr;
	private: System::Windows::Forms::Button^ btnCircu;

	private:
		Graphics^ gr;

		Graphics^ lr;
		Int16 valor;
		Int16 color;
		bool e1, e2;
		bool pintura;
		Int16 x1, y1, x2, y2;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		Int16 x, y;
	private: System::Windows::Forms::Button^ btnpintar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ btnlinea;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnRectan = (gcnew System::Windows::Forms::Button());
			this->btnCuadr = (gcnew System::Windows::Forms::Button());
			this->btnCircu = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnpintar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->btnlinea = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(791, 477);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &formPaint::panel1_Click);
			this->panel1->DoubleClick += gcnew System::EventHandler(this, &formPaint::panel1_DoubleClick);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &formPaint::panel1_MouseClick);
			this->panel1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &formPaint::panel1_MouseDoubleClick);
			// 
			// btnRectan
			// 
			this->btnRectan->Location = System::Drawing::Point(843, 45);
			this->btnRectan->Name = L"btnRectan";
			this->btnRectan->Size = System::Drawing::Size(89, 29);
			this->btnRectan->TabIndex = 1;
			this->btnRectan->Text = L"Rectangulo";
			this->btnRectan->UseVisualStyleBackColor = true;
			this->btnRectan->Click += gcnew System::EventHandler(this, &formPaint::btnRectan_Click);
			// 
			// btnCuadr
			// 
			this->btnCuadr->Location = System::Drawing::Point(843, 90);
			this->btnCuadr->Name = L"btnCuadr";
			this->btnCuadr->Size = System::Drawing::Size(89, 23);
			this->btnCuadr->TabIndex = 2;
			this->btnCuadr->Text = L"Cuadrado";
			this->btnCuadr->UseVisualStyleBackColor = true;
			this->btnCuadr->Click += gcnew System::EventHandler(this, &formPaint::btnCuadr_Click);
			// 
			// btnCircu
			// 
			this->btnCircu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCircu->Location = System::Drawing::Point(843, 134);
			this->btnCircu->Name = L"btnCircu";
			this->btnCircu->Size = System::Drawing::Size(89, 23);
			this->btnCircu->TabIndex = 3;
			this->btnCircu->Text = L"Circulo";
			this->btnCircu->UseVisualStyleBackColor = true;
			this->btnCircu->Click += gcnew System::EventHandler(this, &formPaint::btnCircu_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(949, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 51);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Eliminar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &formPaint::button1_Click);
			// 
			// btnpintar
			// 
			this->btnpintar->Location = System::Drawing::Point(949, 102);
			this->btnpintar->Name = L"btnpintar";
			this->btnpintar->Size = System::Drawing::Size(75, 44);
			this->btnpintar->TabIndex = 5;
			this->btnpintar->Text = L"Pintar";
			this->btnpintar->UseVisualStyleBackColor = true;
			this->btnpintar->Click += gcnew System::EventHandler(this, &formPaint::btnpintar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(843, 240);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Colores";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(846, 275);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Rojo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &formPaint::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(846, 304);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Amarillo";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &formPaint::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(846, 333);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Negro";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &formPaint::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(846, 362);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Azul";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &formPaint::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(846, 391);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Verde";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &formPaint::button6_Click);
			// 
			// btnlinea
			// 
			this->btnlinea->Location = System::Drawing::Point(843, 178);
			this->btnlinea->Name = L"btnlinea";
			this->btnlinea->Size = System::Drawing::Size(89, 23);
			this->btnlinea->TabIndex = 12;
			this->btnlinea->Text = L"Linea";
			this->btnlinea->UseVisualStyleBackColor = true;
			this->btnlinea->Click += gcnew System::EventHandler(this, &formPaint::btnlinea_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(982, 73);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(8, 8);
			this->button7->TabIndex = 13;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// formPaint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 501);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->btnlinea);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnpintar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnCircu);
			this->Controls->Add(this->btnCuadr);
			this->Controls->Add(this->btnRectan);
			this->Controls->Add(this->panel1);
			this->Name = L"formPaint";
			this->Text = L"formPaint";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRectan_Click(System::Object^ sender, System::EventArgs^ e) {
		valor = 1;
	
	}
private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	

	if (valor == 1) {
		x = e->X;
		y = e->Y;
		gr->DrawRectangle(gcnew Pen(Color::Yellow, 3), x, y, 80, 30);
		if (color == 1) {
			gr->DrawRectangle(gcnew Pen(Color::Red, 3), x, y, 80, 30); color = 0;
			if (pintura == true) {
				gr->FillRectangle(Brushes::Red, x, y, 80, 30);   color = 0;
				pintura = false;
			}
		}
		if (color == 2) {
			gr->DrawRectangle(gcnew Pen(Color::Yellow, 3), x, y, 80, 30); color = 0;
			if (pintura == true) {
				gr->FillRectangle(Brushes::Yellow, x, y, 80, 30);   color = 0;
				pintura = false;
			}
		}
		if (color == 3) {
			gr->DrawRectangle(gcnew Pen(Color::Black, 3), x, y, 80, 30); color = 0;

			if (pintura == true) {
				gr->FillRectangle(Brushes::Black, x, y, 80, 30);   color = 0;
				pintura = false;
			}
		}
		if (color == 4) {
			gr->DrawRectangle(gcnew Pen(Color::Blue, 3), x, y, 80, 30); color = 0;
			if (pintura == true) {
				gr->FillRectangle(Brushes::Blue, x, y, 80, 30);   color = 0;
				pintura = false;
			}
		}
		if (color == 5) {
			gr->DrawRectangle(gcnew Pen(Color::Green, 3), x, y, 80, 30); color = 0;
			if (pintura == true) {
				gr->FillRectangle(Brushes::Green, x, y, 80, 30);   color = 0;
				pintura = false;
			}

		}

	}





		if (valor == 2) {
			x = e->X;
			y = e->Y;
			gr->DrawRectangle(gcnew Pen(Color::Blue, 3), x, y, 50, 50);
			if (color == 1) {
				gr->DrawRectangle(gcnew Pen(Color::Red, 3), x, y, 50, 50); color = 0;
				if (pintura == true) {
					gr->FillRectangle(Brushes::Red, x, y, 50, 50);   color = 0;
					pintura = false;
				}
			}
			if (color == 2) {
				gr->DrawRectangle(gcnew Pen(Color::Yellow, 3), x, y, 50, 50); color = 0;
				if (pintura == true) {
					gr->FillRectangle(Brushes::Yellow, x, y, 50, 50);   color = 0;
					pintura = false;
				}
			}
			if (color == 3) {
				gr->DrawRectangle(gcnew Pen(Color::Black, 3), x, y, 50, 50); color = 0;

				if (pintura == true) {
					gr->FillRectangle(Brushes::Black, x, y, 50, 50);   color = 0;
					pintura = false;
				}
			}
			if (color == 4) {
				gr->DrawRectangle(gcnew Pen(Color::Blue, 3), x, y, 50, 50); color = 0;
				if (pintura == true) {
					gr->FillRectangle(Brushes::Blue, x, y, 50, 50);   color = 0;
					pintura = false;
				}
			}
			if (color == 5) {
				gr->DrawRectangle(gcnew Pen(Color::Green, 3), x, y, 50, 50); color = 0;
				if (pintura == true) {
					gr->FillRectangle(Brushes::Green, x, y, 50, 50);   color = 0;
					pintura = false;
				}

			}
		


		}

		if (valor == 3) {
			x = e->X;
			y = e->Y;
			gr->DrawEllipse(gcnew Pen(Color::Green, 3), x, y, 60, 60);
			if (color == 1) {
				gr->DrawEllipse(gcnew Pen(Color::Red, 3), x, y, 60, 60); color = 0;
				if (pintura == true) {
					gr->FillEllipse(Brushes::Red, x, y, 60, 60);   color = 0;
					pintura = false;
				}
			}
			if (color == 2) {
				gr->DrawEllipse(gcnew Pen(Color::Yellow, 3), x, y, 60, 60); color = 0;
				if (pintura == true) {
					gr->FillEllipse(Brushes::Yellow, x, y, 60, 60);   color = 0;
					pintura = false;
				}
			}
			if (color == 3) {
				gr->DrawEllipse(gcnew Pen(Color::Black, 3), x, y, 60, 60); color = 0;

				if (pintura == true) {
					gr->FillEllipse(Brushes::Black, x, y, 60, 60);   color = 0;
					pintura = false;
				}
			}
			if (color == 4) {
				gr->DrawEllipse(gcnew Pen(Color::Blue, 3), x, y, 60, 60); color = 0;
				if (pintura == true) {
					gr->FillEllipse(Brushes::Blue, x, y, 60, 60);   color = 0;
					pintura = false;
				}
			}
			if (color == 5) {
				gr->DrawEllipse(gcnew Pen(Color::Green, 3), x, y, 60, 60); color = 0;
				if (pintura == true) {
					gr->FillEllipse(Brushes::Green, x, y, 60, 60);   color = 0;
					pintura = false;
				}

			}
			
		}

		if (valor == 4) {



			if (e1 == false && e2 == false)
			{
				e1 = true;
				x1 = e->X;
				y1 = e->Y;
			}
			else  if (e1 == true && e2 == false)
			{
				
				x2 = e->X;
				y2 = e->Y;
				e1 = false;
				lr->DrawLine(gcnew Pen(Color::Green, 3), x1, y1, x2, y2);
				
			}
			else {
				lr->Clear(Color::White);
				e1 = e2 = false;
			}

		//	if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0) {
			//}
		
		}

	
	
}
private: System::Void btnCuadr_Click(System::Object^ sender, System::EventArgs^ e) {
	valor = 2;
	
	
}
private: System::Void btnCircu_Click(System::Object^ sender, System::EventArgs^ e) {
	valor = 3;

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	gr->Clear(Color::White);
}
private: System::Void btnpintar_Click(System::Object^ sender, System::EventArgs^ e) {
	pintura = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	color = 1;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	color = 2;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	color = 3;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	color = 4;
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	color = 5;
}
private: System::Void btnlinea_Click(System::Object^ sender, System::EventArgs^ e) {
	valor = 4;

}


private: System::Void panel1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {


	

}
private: System::Void panel1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


}
};
}
