#pragma once
#include"Sucursal.h"

using namespace std;

class Sucursales{

private:
	Sucursal** a;
	int cant;
	string empresa;

public:
	Sucursales(string em="www") {
		empresa = em;
		cant = 0;
		a = new Sucursal * [cant];
	}

	void setEmpresa(string e) { empresa = e; }
	string getEmpresa() { return empresa; }
	
	
	void agregarSucursal(Sucursal *s) {
		Sucursal** aux = new Sucursal * [cant + 1];

		for (int i = 0; i < cant; i++) {
			aux[i] = a[i];
		}
		aux[cant] = s;
		cant++;
		a=aux;

	}
	void mostrarVentassucursales() 
	{
		for (int i = 0; i < cant; i++)
		{
			a[i]->mostrarVentasSucursales();
			cout << "****************************************" << endl;
		}
	}

	void agregarVentaXSucursal(string s, Venta* v)
	{
		for (int i = 0; i < cant; i++)
		{
			if (a[i]->getLugar() == s) {
				a[i]->agregarVenta(v);
			}
		}
	}

	void ventasDias(short dia, short mes, int anho)
	{
		int c =0;
		for (int i = 0; i < cant; i++) {
			c += a[i]->cantVentasDias(dia, mes, anho);
			}
		cout << endl << "La venta de todas las sucursaldes del dia " << dia << "son: " << c;
		}

};