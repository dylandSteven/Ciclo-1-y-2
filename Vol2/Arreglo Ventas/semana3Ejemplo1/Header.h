#pragma once
class Producto {
public:
	Producto();
	Producto(char* nombre, float precio, short cantidad);
	~Producto();
	char* getnombre();
	float getprecio();
	short getcantidad();

	void setnombre(  char * nombre);
	void setprecio(  float precio);
	void setcantidad(short cantidad);

private:
	char* nombre;
	float precio;
	short cantidad;

};