#include <iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;
typedef unsigned short us;
class Fecha {
private:
    us dia;
    us mes;
    us anho;
public:
    Fecha() {
        dia = 1;
        mes = 4;
        anho = 2020;
    }
    Fecha(us d, us m, us a) :dia(d), mes(m), anho(a) {}
    void setDia(us d) { dia = d; }
    void setMes(us m) { mes = m; }
    void setAnho(us a) { anho = a; }
    us getDia() { return dia; }
    us getMes() { return mes; }
    us getAnho() { return anho; }
    string toString() {
        string cadena;
        cadena.append(to_string(dia));
        cadena.append("/");
        cadena.append(to_string(mes));
        cadena.append("/");
        cadena.append(to_string(anho));
        return cadena;
    }
};
class Arreglo {
private:
    vector<Fecha> fechasvec;
public:
 

    void ingresarDatos() {
        us opcion;
        us d, m, a;
        while (1) {
            cout << "Eliga una opcion: " << endl;
            cout << "1.Insertar " << endl;
            cout << "2.Identificar " << endl;
            cout << "3.Modificar " << endl;
            cout << "4.Borrar " << endl;
            cout << "5.Mostrar " << endl;
            cin >> opcion;
            if (opcion == 1) {
                insertar(d, m, a);
            };
            if (opcion == 2) {
                buscar();
            };
            if (opcion == 3)
            {
                modificar();
            };
            if (opcion == 4)
            {
                eliminar();
            };
            if (opcion == 5) {
                mostrar();
            }
            cin.ignore();
            cin.get();
        }
    }
    void insertar(us d, us m, us a) {
        cout << "Establesca el dia: ";
        cin >> d;
        cout << endl;
        cout << "Establesca el mes: ";
        cin >> m;
        cout << endl;
        cout << "Establesca el año: ";
        cin >> a;
        cout << endl;
        fechasvec.push_back(Fecha(d, m, a));
    }
    void buscar()
    {
        int ubicacion;
        cout << "Que ubicacion desea encontrar: " << endl;
        cin >> ubicacion;
        for (short i = 0; i < fechasvec.size(); i++) {
            if (i == ubicacion) {
                cout << "la fecha guardada en la posicion " << ubicacion << " es " << fechasvec[i].toString() << endl;
            }
        }
    }
    void eliminar() {
        int ubicacion;
        cout << "Escriba direccion a eliminar :" << endl;
        cin >> ubicacion;
        for (int i = 0; i < fechasvec.size(); i++) {
            if (i == ubicacion) {
                fechasvec.erase(fechasvec.begin() + ubicacion);
            }
        }
    }
    void modificar() {
        short diaux, mesaux, anhoaux;
        int ubicacion;
        cout << "Escribir la ubicacion que quiere cambiar : ";
        cin >> ubicacion;
        cout << endl;
        cout << "Establesca el dia: ";
        cin >> diaux;
        cout << endl;
        cout << "Establesca el mes: ";
        cin >> mesaux;
        cout << endl;
        cout << "Establesca el año: ";
        cin >> anhoaux;
        cout << endl;
        for (int i = 0; i < fechasvec.size(); i++) {
            if (i == ubicacion) {
                fechasvec[i].setDia(diaux);
                fechasvec[i].setMes(diaux);
                fechasvec[i].setAnho(anhoaux);
            }
        }
    }
    void mostrar() {
        for (us i = 0; i < fechasvec.size(); i++) {
            cout << fechasvec[i].toString() << endl;
        }
    }
};
int main() {
    Arreglo* tarea = new Arreglo;
    tarea->ingresarDatos();
}