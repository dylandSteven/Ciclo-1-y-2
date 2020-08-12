#include<iostream>
#include<fstream>
#include<string>
#include"MyForm.h"
using namespace smn13clase2;
using namespace std;

int main()
{
	Application::Run(gcnew MyForm());
	//string mensaje;
	
	//ofstream archivoEsc("demo.txt");
	//archivoEsc<< "Si se puede !!!" << endl;
	//archivoEsc.close();

	//ifstream archivoLec("demo.txt");
	//getline(archivoLec, mensaje);
	////archivoLec>> mensaje;
	//cout << mensaje;
	//archivoLec.get();
	//cin.get();

	/*fstream archivo1("demo.txt",ios::out);
	archivo1 << "Si se puede !!!" << endl;
	archivo1.close();*/
	//fstream archivo1("demo.txt", ios::app);
	//archivo1 << "Si se puede !!!" << endl;
	//archivo1.close();
	//fstream archivo2("demo.txt", ios::in);
	//getline(archivo2, mensaje);
	//cout << mensaje;
	//archivo2.close();
	//cin.get();

	return 0;
}