#include<iostream>
#include"arrAuto.h"

using namespace std;

int main() {
	int x;
	char* modelo;
	char* color;
	double precio;
	int anho;
	double Ps;
	bool lunasPolarizadas;
	ArregloAuto* bjarr = new ArregloAuto();
	Carro* nuevoRegistro;
	do {
		cout << "1.Registrar" << endl;
		cout << "2.Eliminar" << endl;
		cout << "3.Mostrar" << endl;
		cout << "4.Eliminar por año" << endl;
		cout << "9.Salir" << endl;
		cin >> x;
		switch (x)
		{

		case 1:

			modelo = new char[10];
			color = new  char[10];
			cout << "Ingrese un modelo: " << endl;
			cin >> modelo;
			cout << "ingrese un color: "<<endl;
			cin >> color;
			cout << "Ingrse un precio: " << endl;
			cin >> precio;
			cout << "Ingrese un año: " << endl;
			cin >> anho;
			cout << "INgrese una prima de seguro: " << endl;
			cin >> Ps;
			cout << "Tiene lunas polarizadas: " << endl;
			cin >> lunasPolarizadas;
			nuevoRegistro = new Carro(modelo,color
			,precio,anho,Ps,lunasPolarizadas);

			bjarr->registrar(nuevoRegistro);

			break;

		case 2:
			bjarr->elimnar();
			
			
			break;
		case 3: 
			cout << "Modelo\t CCOlor\t Precio\t Año\t Ps\t Lunas "<<endl;
			for (int i = 0; i <= bjarr->longitud(); i++) {
			cout<<	bjarr->devolver(i)->getmodelo() <<"\t"<<bjarr->devolver(i)->getcolor() << "\t" << bjarr->devolver(i)->getprecio()<< "\t" <<
					bjarr->devolver(i)->getanho() << "\t" << bjarr->devolver(i)->getPs()<< "\t" << bjarr->devolver(i)->getlunasPolarizadas();
											 
			}			
			break;
		case 4:

			int anhio;
			cout << "INgrese un año: ";
			cin >> anhio;
			bjarr->eliminarPorAnhio(anhio);
			; break;
		case 5:
					cout << endl;
			cout << "Carros del 2020 ";

			for (int i = 0; i < bjarr->longitud(); i++) {
				if (bjarr->devolver(i)->getanho() == 2020)
				{
					cout << bjarr->devolver(i)->getmodelo() << "\t" << bjarr->devolver(i)->getcolor() << "\t" << bjarr->devolver(i)->getprecio() << "\t" <<
						bjarr->devolver(i)->getanho() << "\t" << bjarr->devolver(i)->getPs() << "\t" << bjarr->devolver(i)->getlunasPolarizadas();

				}
			}
			cout << endl;
			cout << "Carros de mas de 5000 ";
			for (int i = 0; i < bjarr->longitud(); i++) {
				if (bjarr->devolver(i)->getPs() == 5000)
				{
					cout << bjarr->devolver(i)->getmodelo() << "\t" << bjarr->devolver(i)->getcolor() << "\t" << bjarr->devolver(i)->getprecio() << "\t" <<
						bjarr->devolver(i)->getanho() << "\t" << bjarr->devolver(i)->getPs() << "\t" << bjarr->devolver(i)->getlunasPolarizadas();

				}
			}
			cout << endl;
			cout << "Carros de Lunas Polarizadas ";
			for (int i = 0; i < bjarr->longitud(); i++) {
				if (bjarr->devolver(i)->getlunasPolarizadas() ==true)
				{
					cout << bjarr->devolver(i)->getmodelo() << "\t" << bjarr->devolver(i)->getcolor() << "\t" << bjarr->devolver(i)->getprecio() << "\t" <<
						bjarr->devolver(i)->getanho() << "\t" << bjarr->devolver(i)->getPs() << "\t" << bjarr->devolver(i)->getlunasPolarizadas();

				}
			}

			cout << endl;
			cout << "Carros en donde Precio es mayor al promedio ";
			for (int i = 0; i < bjarr->longitud(); i++) {
				if (bjarr->promedio() < bjarr->devolver(i)->getprecio() )
				{
					cout << bjarr->devolver(i)->getmodelo() << "\t" << bjarr->devolver(i)->getcolor() << "\t" << bjarr->devolver(i)->getprecio() << "\t" <<
						bjarr->devolver(i)->getanho() << "\t" << bjarr->devolver(i)->getPs() << "\t" << bjarr->devolver(i)->getlunasPolarizadas();

				}
			}




			break;
		}
	} while (!(x == 9));
	cin.ignore();
	cin.get();
}