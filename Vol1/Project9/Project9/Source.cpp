#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::to_string;

typedef unsigned short us;

class FECHA
{
public:
    FECHA();
    FECHA(us d, us m, us a) :dia(d), mes(m), anio(a) {}
    ~FECHA();

    us getDia() { return dia; }
    us getMes() { return mes; }
    us getAnio() { return anio; }
    void setDia(us d) { dia = d; }
    void setMes(us m) { mes = m; }
    void setAnio(us a) { anio = a; }

    string tostring() {
        string cadena;
        cadena.append(to_string(dia));
        cadena.append("/");
        cadena.append(to_string(mes));
        cadena.append("/");
        cadena.append(to_string(anio));
        return cadena;
    }

private:
    us dia;
    us mes;
    us anio;

};

FECHA::FECHA()
{
    dia = 1;
    mes = 4;
    anio = 2020;
}

FECHA::~FECHA()
{
}


class COLECCION
{
public:
    COLECCION() {}
    ~COLECCION() {}

    void insertar(short d, short m, short a) {
        fechas.push_back(FECHA(d, m, a));
    }
    void buscar() {
        int pos;
        cout << "que posicion desea buscar" << endl;
        cin >> pos;

        for (int i = 0; i < fechas.size(); i++) {
            if (i == pos) {
                cout << "la fecha guardada en la posicion " << pos << " es" << fechas[i].tostring() << endl;
            }
        }
    }
    void eliminar() {
        int pos;
        cout << "que posicion desea eliminar" << endl;
        cin >> pos;

        for (int i = 0; i < fechas.size(); i++) {
            if (i == pos) {
                fechas.erase(fechas.begin() + pos);
            }
        }

    }
    void obtener() {

        int pos;
        cout << "que posicion desea obetener" << endl;
        cin >> pos;

        for (int i = 0; i < fechas.size(); i++) {
            if (i == pos) {
                cout << "la fecha es " << fechas[i].tostring() << endl;;
            }
        }

    }
    void modificar() {
        short dd, mm, aa;
        int pos;
        cout << "que posicion desea modificar" << endl;
        cin >> pos;
        cout << "introduzca nuevo dia" << endl;
        cin >> dd;
        cout << "introduzca nuevo mes" << endl;
        cin >> mm;
        cout << "introduzca nuevo anio" << endl;
        cin >> aa;

        for (int i = 0; i < fechas.size(); i++) {
            if (i == pos) {
                fechas[i].setDia(dd);
                fechas[i].setMes(mm);
                fechas[i].setAnio(aa);

            }
        }


    }

private:
    vector<FECHA> fechas;
};

int main() {
    srand(time(NULL));
    /*vector<int> enteros;
    vector<char> caracteres;
    //vector<registro> registros;
    vector<FECHA> fechas;

    //////////////////////////////////
    /*enteros.push_back(12);
    enteros.push_back(15);
    enteros.push_back(18);*/
    /*caracteres.push_back('U');
    caracteres.push_back('P');
    caracteres.push_back('C');

    for (int i = 0; i < caracteres.size(); i++) {

        cout << caracteres[i] << " ";
    }
    cout << endl;
    fechas.push_back(FECHA(8, 4, 2020));
    fechas.push_back(FECHA(18, 5, 2020));
    fechas.push_back(FECHA(28, 6, 2020));

    /*for (int i = 0; i < fechas.size(); i++) {

        //cout << fechas[i].getDia() << "/" << fechas[i].getMes()<< "/" << fechas[i].getAnio() << endl;
        cout << fechas.at(i).tostring() << endl;
    }*/

    /*cout << fechas.front().tostring();
    cout << endl;
    fechas.erase(fechas.begin());
    cout << fechas.front().tostring();

    fechas[2] = FECHA(30, 12, 2021);

    for (int i = 0; i < fechas.size(); i++) {
        cout << fechas[i].getDia() << "/" << fechas[i].getMes()<< fechas[i].getAnio()<< endl;
    }*/

    COLECCION* eventos = new    COLECCION;
    short opcion;
    do {
        cout << endl;
        cout << "1-insertar fecha" << endl;
        cout << "2-eliminar fecha" << endl;
        cout << "3-buscar fecha" << endl;
        cout << "4-obtener fecha" << endl;
        cout << "5-modificar fecha" << endl;
        cout << "6-salir" << endl;
        cout << "cual es su opcion" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            short D, M, A;
            cout << "insertar dia" << endl;
            cin >> D;
            cout << "insertar mes" << endl;
            cin >> M;
            cout << "insertar anio" << endl;
            cin >> A;
            eventos->insertar(D, M, A); break;
        case 2:
            eventos->eliminar(); break;
        case 3:
            eventos->buscar(); break;
        case 4:
            eventos->obtener(); break;
        case 5:
            eventos->modificar(); break;
        default: "opcion desconocida \n";
            break;
        }

    } while (opcion != 6);

    cout << endl;
    system("pause");
    return 0;
}