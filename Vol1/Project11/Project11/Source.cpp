#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
using namespace std;
using namespace System;
class Combustible {
private:
	string nombre_c;
	int precio;

public:

	Combustible(string nombre_c) {
		this->nombre_c = nombre_c;
		/*this->precio = precio;*/
	}
	Combustible() {
		nombre_c = "";
		/*precio = 0;*/
	}
	int GETprecio() { return precio; }
	void setPrecio(int precio) { this->precio = precio; }
	string getNombre_c() { return nombre_c; }
	void setNombre_c(string nombre_c) { this->nombre_c = nombre_c; }
	/*int getPrecio() { return precio; }
	void setPrecio(int precio) { this->precio = precio; }*/

	string toString() {
		string s(nombre_c); return s;
	}



};
//////////////////////////////////////////////
class Surtidor {
private:
	Combustible* c;
	int c_surtidor;

public:
	~Surtidor() {}

	Surtidor(int c_surtidor) {
		c = nullptr;
		this->c_surtidor = c_surtidor;
	}
	Surtidor() {
		c_surtidor = 0;
	}

	int getCantidad() { return c_surtidor; }
	void setPrecio(int c) { this->c_surtidor = c; }

	string toString() {
		string s(to_string(c_surtidor)); return s;
	}

};
////////////////////////////////////////////////
//class Surtidores {
//private:
//	vector<Surtidor*>arr;
//public:
//	void addSucursal(Surtidor*s) {
//		arr.push_back(s);
//	}
//	void deleteSucursal(int pos) {
//		if (pos > 0 && pos < arr.size())
//		arr.erase(arr.begin()+pos);
//	}
//	void show() {
//		for (int i = 0; i < arr.size(); ++i) {
//			arr[i]->toString();
//		}
//	}
//};
//////////////////////////////////////////////
class Sucursal {
private:
	string distrito;
	//Surtidor* aso;
public:
	Sucursal() {}
	Sucursal(string distrito) {
		this->distrito = distrito;
		/*this->aso = nullptr;*/
	}
	string getSucursal() { return distrito; }

	string toString() {
		string s(/*aso->toString()+" "+*/distrito); return s;
	}
};
//////////////////////////////////////////////
class Sucursales {
private:
	vector<Sucursal*>arr;
public:
	void addCliente(Sucursal* c) {
		arr.push_back(c);
	}
	void eliminar_pos(int pos) {
		if (pos > 0 && pos < arr.size())
			arr.erase(arr.begin() + pos);
	}
	void showCliente() {
		for (int i = 0; i < arr.size(); ++i) {
			arr[i]->toString();
		}
	}

};
//////////////////////////////////////////////


////////////////////////////////////////////// 
class Cliente {
private:
	string n;
	string a;
public:
	Cliente(string n, string a) {
		this->n = n;
		this->a = a;
	}
	Cliente() {
		n = "";
		a = "";
	}
	string getN() { return n; }
	void setN(string n) { this->n = n; }
	string getA() { return a; }
	void setA(string a) { this->a = a; }

	string toString() {
		string s(n + "-" + a); return s;


	}
};
//////////////////////////////////////////////
class Clientes {
private:
	vector<Cliente*>arr;
public:
	void addCliente(Cliente* c) {
		arr.push_back(c);
	}
	void eliminar_pos(int pos) {
		if (pos > 0 && pos < arr.size())
			arr.erase(arr.begin() + pos);
	}
	void showCliente() {
		for (int i = 0; i < arr.size(); ++i) {
			arr[i]->toString();
		}
	}

};
//////////////////////////////////////////////
class Vehiculo {
private:
	string placa_v;
	int c_galon;
public:
	Vehiculo() {}
	Vehiculo(string placa_v, int c_galon) {
		this->placa_v = placa_v;
		this->c_galon = c_galon;
	}
	int getGalon() { return c_galon; }
	void setCanti_Galon(int c_galon) { this->c_galon = c_galon; }
	string getPlaca() { return placa_v; }
	void setPlaca(string placa_v) { this->placa_v = placa_v; }
	string toString() {
		string s(placa_v + "-" + to_string(c_galon)); return s;
	}
};
//////////////////////////////////////////////
struct Fecha {
private:
	int d, m;
public:
	Fecha() {}
	Fecha(int d, int m) {
		this->d = d;
		this->m = m;

	}
	int getDia() { return d; }
	void setDia1(int d) { this->d = d; }
	int getMes() { return m; }
	void setMes(int m) { this->m = m; }
	string toString() {
		string s(to_string(d) + "-" + to_string(m)); return s;
	}
};
//////////////////////////////////////////////
class Venta {
	Combustible c1;
	Fecha f;
	Vehiculo v;
	Sucursal s;
	//Surtidor surti;
	Cliente* c;
	Surtidor surti;
	int precio;

public:
	Venta(Fecha f, Combustible c1, Vehiculo v, Sucursal s, Surtidor surti, Cliente* c) {
		this->f = f;
		this->v = v;
		this->s = s;
		this->c = c;
		this->c1 = c1;
		this->surti = surti;
	}


	int getCantidad_galones() { return v.getGalon(); }
	string getGaso() { return c1.getNombre_c(); }
	int getDia1() { return f.getDia(); }
	int getMes1() { return f.getMes(); }

	string toString() {
		/*cout << "fecha,combustible, vehiculo,sucursal,surtidor,cliente" << endl;*/
		string s(f.toString() + "\n" + c1.toString() + "\n" + v.toString() + "\n" + s.toString() + "\n" + surti.toString() + "\n" + c->toString()); return s;
	}

};
class Ventas {
private:
	vector<Venta*>arr;
	int indice;

public:
	void addAgregar(Venta* v) {
		indice++;
		arr.push_back(v);
	}

	void mostrar() {
		for (int i = 0; i < arr.size(); ++i) {
			cout << "Mostrando datos de cliente" << i + 1 << endl;
			cout << arr.at(i)->toString();
		}
	}

	int longitud() { return indice; }

	/*void por_mes(int mes) {
	for (int i = 0; i < arr.size(); ++i) {
	if (arr.at(i)->getMes1()==mes  && arr.at(i)->getMes1()==mes ) {
	cout << "Mes " << mes << endl;

	cout << "La ganacia fue " << suma() << endl;
	}
	}

	}*/
};

void menu() {
	cout << "1. Agregar informacion" << endl;
	cout << "2. Mostrar todo " << endl;
	cout << "3. Venta consolidada por dia." << endl;
	cout << "4. Venta por mes." << endl;
	cout << "5. Venta por tipo en un mes. " << endl;
	cout << "6. Consumo total de combustible por tipo. " << endl;

}
int main() {
	Fecha f1;
	Combustible combus;
	Vehiculo v1;
	Sucursal s1;
	Surtidor sur;
	Cliente* c1;

	string combustible;

	int c_surti;
	string comprobante;
	int opcion;
	string placa_v;
	int c_galon;
	int d1, _d1, m1;
	string n1;
	string a1;
	Venta* v;
	Ventas venta = Ventas();
	string distrito;
	int dia;
	/*Venta(Fecha f, Combustible c1, Surtidor surti, Vehiculo v, Sucursal s, Cliente * c) {*/
	do {
		//system("cls");
		float precio = 0;
		float p2 = 0;
		float p3 = 0;
		float p4 = 0;
		float p5 = 0;
		float p6 = 0;
		float cont1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
		float suma_mes = 0;
		menu();
		cout << "Ingrese la opcion:"; cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Ingrese el dia: "; cin >> d1;
			cout << "Ingrese el mes: "; cin >> m1;
			f1 = Fecha(d1, m1);
			cout << "Ingrese el nomnre del comustible: "; cin >> combustible;
			combus = Combustible(combustible);
			cout << "Ingrese la placa del vehiculo: "; cin >> placa_v;
			cout << "Ingrese cantidad de galones: "; cin >> c_galon;
			v1 = Vehiculo(placa_v, c_galon);

			cout << "Ingrese el distrito de la sucursal: "; cin >> distrito;
			s1 = Sucursal(distrito);
			cout << "Ingrese la cantidad de surtidores:"; cin >> c_surti;
			sur = Surtidor(c_surti);
			cout << "Ingrese el nombre del cleinte: "; cin >> n1;
			cout << "Ingrese apellido del cliente: "; cin >> a1;
			c1 = new Cliente(n1, a1);
			v = new Venta(f1, combus, v1, s1, sur, c1);
			venta.addAgregar(v);
			break;
		case 2:

			venta.mostrar(); break;

		case 3:
			cout << "Ingrese el dia: "; cin >> _d1;
			cout << "Dia" << _d1 << ":" << endl;
			/*for (int i = 0; i < venta.longitud(); ++i) {*/
			if (combus.getNombre_c() == "Gasohol90" && f1.getDia() == _d1) {
				f1.setDia1(_d1);
				cont1 = v1.getGalon();
				v1.setCanti_Galon(cont1);
				precio += (cont1 * 9.82);
				/*combus.setPrecio(precio);*/
				cout << "Venta de Gasohol90: " << precio << endl;

			}


			if (combus.getNombre_c() == "Gasohol95" && f1.getDia() == d1) {
				f1.setDia1(d1);
				c2 = v1.getGalon();
				v1.setCanti_Galon(d1);
				p2 += (c2 * 11.29);
				/*combus.setPrecio(p2);*/
				cout << "Venta de Gasohol95:  " << p2 << endl;

			}

			if (combus.getNombre_c() == "Gasohol97" && f1.getDia() == d1) {
				f1.setDia1(d1);
				c3 = v1.getGalon();
				v1.setCanti_Galon(c3);
				p3 += c3 * 12.89;
				cout << "Venta de Gasohol97: " << p3 << endl;

			}
			if (combus.getNombre_c() == "DieselUltra" && f1.getDia() == d1) {
				f1.setDia1(d1);
				c4 = v1.getGalon();
				v1.setCanti_Galon(c4);
				p4 += c4 * 9.36;
				cout << "Venta de DieselUltra: " << p4 << endl;

			}
			if (combus.getNombre_c() == "GLS" && f1.getDia() == d1) {
				f1.setDia1(d1);
				c5 = v1.getGalon();
				v1.setCanti_Galon(c5);
				p5 += c5 * 1.54;
				cout << "Venta de GLS: " << p5 << endl;
			}
			if (combus.getNombre_c() == "GNV" && f1.getDia() == d1) {
				f1.setDia1(d1);
				c6 = v1.getGalon();
				v1.setCanti_Galon(c6);
				p6 += c6 * 1.57;
				cout << "Venta de GNV: " << p6 << endl;
			}

			break;

		case 4:
			cout << "Ingrese el mes: "; cin >> m1;
			if (f1.getMes() > 0 && f1.getMes() <= 12) {
				if (f1.getMes() == m1) {
					suma_mes = precio + p2 + p3 + p4 + p5 + p6;
					cout << "La Venta en el mes: " << m1 << " : " << suma_mes << endl;
				}
			}
			break;

		case 5:
			cout << "Ingrese el nombre de la sucursal: "; cin >> distrito;
			if (s1.getSucursal() == distrito) {
				suma_mes = precio + p2 + p3 + p4 + p5 + p6;
				cout << "La suma de : " << distrito << "es: " << suma_mes << endl;
			}
		}

		system("pause>0");
	} while (opcion != 6);

	return 0;
}

