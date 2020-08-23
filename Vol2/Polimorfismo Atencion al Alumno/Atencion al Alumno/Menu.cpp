#include"Cola.h"
#include"Usuario.h"
#include<iostream>
using namespace std;

short nroTicket=1;

int main() {

	short opcion;
	char* nombre;
	char* apellido;
	long codigo;
	short nroTicket;
	char tipoUsuario;
	Cola* atencion=new Cola();
	do {
		system("cls");
		cout<<"Menu Opciones"<<endl;
		cout << "=============" <<endl;
		cout<<"1.Insertar"<<endl;
		cout<<"2.Atender "<<endl;
		cout<<"3.Atender por tipo"<<endl;
		cout<<"4.Numero de atenciones por Tipo"<<endl;
		cout<<"5.Mostrar Cola"<<endl;
		cout <<"6.Salir" << endl;
		do {
		cout << "Ingrese una opcion:";
			cin >> opcion;
		} while (opcion < 0 || opcion>6);


		switch (opcion)
		{
		case 1: {
			char* nombre = new char[10];
			char* apellido = new char[10];

			cout << "Ingrese nombre:"; cin >> nombre;
			cout << "Ingrese apellido:"; cin >> apellido;
			cout << "Ingrese codigo:"; cin >> codigo;
			cout << "Ingrese tipo de usuario:"; cin >> tipoUsuario;
			atencion->insertarFinal(new Usuario(nombre, apellido, codigo, nroTicket++, tipoUsuario));
			break;
		}
		case 2:
			atencion->atender();
			break;
		case 3:
			cout << "Ingrese tipo de usuario:";
			cin >> tipoUsuario;
			atencion->atender(tipoUsuario);
			break;
		case 4:
			cout << "Cantidad de atenciones por tipo de usuario:" << endl;
			cout << "Alumnos" << atencion->getcAlumnos()<<endl;
			cout << "Docentes" << atencion->getcDocentes()<<endl;
			cout << "Padres" << atencion->getcPadres() << endl;
			system("pause");
		break;
    case 5:
		cout << "MOstrar cola de usuarios:";
		for (int i = 0; i < atencion->longitud(); i++) {
			cout<<atencion->recuperar(i)->getNombre() << "  " << atencion->recuperar(i)->getTipoUsuario();
		}
		atencion->atender(tipoUsuario);
		
		break;

	default:cout << "Opcion incorrecta" << endl; break;
  
	}
	} while (opcion!=6);

	return 0;
}