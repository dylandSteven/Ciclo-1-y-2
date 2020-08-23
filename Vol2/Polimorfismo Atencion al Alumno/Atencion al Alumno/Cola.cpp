#include"Cola.h"

bool Cola::insertarFinal(Usuario* n) {
	if (indice++ < capacidad) {

		colaA[indice] = n;
		return true;
	}
	else {
		return false;
	}

}
Usuario* Cola::recuperar(short p)
{
	if (p <= indice) {
		return colaA[p];
	}
	else
	{
		return nullptr;
	}
}
void Cola::atender() {
	Usuario* temporal;
	if (indice > 0) {
		temporal = colaA[0];
		switch (temporal->getTipoUsuario()) {

		case 'A':cAlumnos++; break;
		case'P':cPadres++; break;
		case'D':cDocentes++; break;
		}
		
		

		for (int i = 0; i < indice; i++) {
			colaA[indice] = colaA[i + 1];
		}
		delete temporal;
		indice--;
	}
}
void Cola::atender(char tipo) {
	Usuario* temporal;

	short pos = -1;
	if (indice > 0) {
		for (int i = 0; i < indice; i++) {
			if (colaA[i]->getTipoUsuario() == tipo)
			{
				pos = i;
				goto sigue;
			}
		}
	sigue:
		temporal = colaA[pos];
		switch (temporal->getTipoUsuario()) {

		case 'A':cAlumnos++; break;
		case'P':cPadres++; break;
		case'D':cDocentes++; break;
		}
		for (int i = pos; i < indice; i++) {

			colaA[indice] = colaA[i + 1];
		}
		indice--;
		delete temporal;
	}
}

short Cola::getcDocentes() { return cDocentes; }
short Cola::getcPadres() { return cPadres; }
short Cola::getcAlumnos() { return cAlumnos; }

short Cola::longitud()
{
	return indice+1;
}



Cola::Cola()
{
	colaA = new Usuario * [100];
	indice = -1;
	capacidad = 100;

}

Cola::~Cola()
{
}