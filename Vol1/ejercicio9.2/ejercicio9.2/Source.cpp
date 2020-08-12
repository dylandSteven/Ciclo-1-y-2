#include"Circulo.h"
#include<iostream>
#include"ClaseControlador.h"
#include"Triangulo.h"
using namespace std;
int main() {
		Circulo nuevoCirculo(3, 3, 5, 1, 1, true, 5, 5);
		Triangulo nuevoTria(3, 6, 5, 1, 1, true, 3, 5);
	Controladora nuevocontrol(nuevoCirculo,nuevoTria);
	while (true) {
		nuevoCirculo.eliminar();
		nuevoCirculo.mover();
		nuevoCirculo.dibujar();
		//nuevoCirculo.eliminar();
		nuevoTria.eliminar();
		nuevoTria.mover();
		nuevoTria.dibujar();


		nuevocontrol.colision();
		_sleep(50);
		cout << endl;
	}
	cin.ignore();
	cin.get();

}