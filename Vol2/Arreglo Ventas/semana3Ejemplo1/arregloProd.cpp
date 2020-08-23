
#include "arregloPro.h"

void arregloProductos::insertar(Producto* p) {
	lista.push_back(p);
}
Producto* arregloProductos::recuperar(short pos) {
	return lista.at(pos);
}
void arregloProductos::eliminarPosicion(short pos) {

	lista.erase(lista.begin() + pos);
}

arregloProductos::arregloProductos()
{
}

arregloProductos::~arregloProductos()
{
}
