#ifdef   __ARREGLOCONTRASEnA_H__
#define  __ARREGLOCONTRASEnA_H__

#include "contrasena.h"

using namespace std;

class arregloContra {

private:

	int n; 
	contrasena *arr;
	contrasena *p;

public:

	arregloContra() {
		n = 5 + rand() % 11 - 5;
		arr = new contrasena[n];
	}

	void generarInfo() {
		for (int i = 0; i < n; i++) {
			p = new contrasena();
			arr[i] = *p;
		}
	}

	void vof() {
		for (int i = 0; i < n; i++) {
			if (arr[i].isSafe == true) { cout << arr[i].getContrasena() << " es V"; }
			else{ cout << arr[i].getContrasena() << " es F"; }
			cout << endl;
		}
	}
};

#endif // 
