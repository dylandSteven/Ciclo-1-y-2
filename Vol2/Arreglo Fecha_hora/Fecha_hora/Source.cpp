#include<iostream>
#include<conio.h>
using namespace std;
#include"Eclipse.h"
#include"Fecha.h"
#include"ArrEcliplse.h"
void Menu()
{
	cout << "1. Agregar Eclipse" << endl;
	cout << "2. Insertar Eclipse" << endl;
	cout << "3. Modificar tipo de eclipse" << endl;
	cout << "4. Eliminar Eclipse" << endl;
	cout << "5. Mostrar lista de eclipses" << endl;
	cout << "6. Reporte de eclipses vistos en Europa" << endl;
	cout << "7. Reporte de eclipses que ocasionaron sismos" << endl;
	cout << "8. Reporte de eclipses que se ocasionaron en la noche" << endl << endl;
}



int main() {


	int opcion,posicion;
	arrfecha *nuevoEclipse;
	nuevoEclipse = new arrfecha;
	string tipo;
	while (1) {

		do {
			
			Menu();
			cout << "\nEliga una opcion: ";
			cin >> opcion;
		} while (!(opcion > 0 && opcion < 9));

		switch (opcion) {

		case 1:nuevoEclipse->AgregarEclipse();break;
		case 2: 
			cout << "Ingrese la opcion: "; cin >> opcion;
			nuevoEclipse->InsertarEclipse(opcion);
			; break;
		case 3:
			cout << "Ingrese la posicion: "; cin >> posicion;
			cout << "Ingrese el nuevo valor: "; cin >> tipo;
			nuevoEclipse->Modificar(posicion, tipo);
			cout << "Se modifico eclipse" << endl;
			;break;
		case 4:

			cout << "Ingrese la posicion: "; cin >> posicion;
			nuevoEclipse->Elimimnar(posicion);
			;break;
		case 5:
			nuevoEclipse->MostrarEclipse();
			;break;
		case 6:
			nuevoEclipse->EclipseEuropeo();
			
			;break;
		case 7:
			nuevoEclipse->eclipseSismo(); break;
			;break;
		case 8:nuevoEclipse->EclipseENNoche(); break;
		
		
		
		}
		_getch();
		/*cin.ignore();
		cin.get();*/
		system("cls");
	
	
	
	
	
	
	
	}
	return 0;
}