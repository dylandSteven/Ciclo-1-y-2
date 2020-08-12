#pragma once}

#include<vector>
typedef double D;
using namespace std;
#include<cmath>
using namespace ::System::Drawing;
class Balas
{
	class Bala {
		D x, y;
		D dx;
		int alto;
		int ancho;
		D destX;
		D destY;
		D angulo;

	public:
		Bala(D x = 0, D y = 0, D dx = 5, int w = 30, int h = 30) :
	x(x),y(y),dx(dx), alto(h),ancho(w)
		{
			this->destX = destX;
			this->destY = destY;
			angulo = atan((destY - y) / (destX - x));
		}
		void graficar(Graphics^ canvas)
		{
			canvas->FillEllipse(Brushes::Green, Rectangle(x, y, 30, 30));

		}
		void dibujarmover()
		{
			x += dx;
			y = x * tan(angulo);
		}


	};
	
	vector<Bala>arrBalas;

public :

	Balas()
	{
		arrBalas = vector<Bala>();

	}
	void graficarTodo(Graphics ^g)
	{
		
		for (auto iterador : arrBalas)
		{
			iterador.graficar(g);
		}
	}
	void moverTodo()
	{
		vector<Bala>::iterator iterador = arrBalas.begin();
		for (; iterador != arrBalas.end(); ++iterador)
		{
		iterador->dibujarmover();
		}
	}

	void apuntar(double destX, double destY)
	{
		arrBalas.push_back(Bala( destX, destY));

	}


	
};