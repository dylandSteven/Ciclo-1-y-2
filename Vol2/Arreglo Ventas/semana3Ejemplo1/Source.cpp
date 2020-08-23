#include"Header.h"


void  Producto::setnombre(char* nombre) { this->nombre = nombre; }
void  Producto::setprecio(float precio) { this->precio = precio; }
void  Producto::setcantidad(short cantidad) { this->cantidad = cantidad; }
char* Producto::getnombre() { return nombre; }
float Producto::getprecio() { return precio; }
short Producto::getcantidad() { return cantidad; }

Producto::Producto(char* nombre, float precio, short cantidad)
{
	this->nombre = nombre;
	this->precio = precio;
	this->cantidad = cantidad;
}
Producto::Producto()
{
	this->nombre = new char[10];
	this->precio = 0;
	this->cantidad = 0;
}

Producto::~Producto()
{

}
