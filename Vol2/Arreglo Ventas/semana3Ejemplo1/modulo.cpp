#include"comprobante.h"
#include"arregloPro.h"
#include"Header.h"

#include<iostream>
using namespace std;
int main() {
	char* nombre=new char[10];
	float precio;
	short cantidad;
	char* nombre2=new char[10];
	float precio2;
	short cantidad2;

	comprobante* boleta1;
	
	cout << "Modulo de ventas 1"<<endl;
	cout << "==================="<<endl;
	cout << "Ingrese Producto 1";
	cin >> nombre;
	cout << "Ingrese Precio 1";
	cin >> precio;
	cout << "Ingrese Cantidad 1";
	cin >> cantidad;

	Producto* productoA = new Producto(nombre, precio, cantidad);
	cout << "Modulo de ventas 2"<<endl;
	cout << "==================="<<endl;
	cout << "Ingrese Producto 2";
	cin >> nombre2;
	cout << "Ingrese Precio 2";
	cin >> precio2;
	cout << "Ingrese Cantidad 2";
	cin >> cantidad2;
	Producto* productoB = new Producto (nombre2, precio2, cantidad2);

	arregloProductos* detalle = new arregloProductos();

	detalle->insertar(productoA);
	detalle->insertar(productoB);
	boleta1 = new comprobante((char*)("09/09/2017"), detalle);
	


	cout<<"Fecha"<<boleta1->getFecha()<<endl;
	cout<<"detalle"<<endl;
	cout << "Producto 1" << endl;
	cout << boleta1->getDetalle()->recuperar(0)->getnombre() << endl;
	cout << boleta1->getDetalle()->recuperar(0)->getcantidad() << endl;
	cout << boleta1->getDetalle()->recuperar(0)->getprecio() << endl;
	cout << endl;

	cout << "Producto 2" << endl;
	cout << boleta1->getDetalle()->recuperar(1)->getnombre() << endl;
	cout << boleta1->getDetalle()->recuperar(1)->getcantidad() << endl;
	cout << boleta1->getDetalle()->recuperar(1)->getprecio() << endl;
	cout << endl;

	system("pause");
}