#include <iostream>
#include <cstdlib>
#include <ctime>

#include "arregloContrasena.h"

using namespace std;

int main() {
	srand(time(NULL));
	arregloContra* p = new arregloContra();
	p->generarInfo();
	p->vof();
}
