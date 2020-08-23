#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Prenda {
    string codigo;
    string tipo;
    short talla;
    float stock;
public:
    Prenda() {
        bool validador = false;
        //codigo
        cout << "Informacion necesaria para la creacion de la prenda: " << endl << "Ingrese codigo de la prenda de 4 digitos: ";
        do {
            cin >> codigo;
            if (codigo.length() == 4) {
                validador = true;
            }
            else { cout << "Codigo incorrecto ingrese nuevamente: " << endl; }
        } while (validador == false);
        //tipo
        cout << "Ingrese el tipo de prenda:";

        do {
            validador = false;
            cin >> tipo;
            if (tipo == "polo" || tipo == "camisa" || tipo == "polera") {
                validador = true;
            }
            else { cout << "No valido ingrese denuevo porfavor" << endl; }
        } while (validador == false);
        //talla
        cout << "Ingrese talla: de 10 a 15: ";
        do {
            validador = false;
            cin >> talla;
            if (talla > 10 && talla < 15) {
                validador = true;
            }
            else {
                cout << endl << "No valido ingrese denuevo porfavor";

            }
        } while (validador == false);
        //stock
        cout << "Ingrese stock: ";
        do {
            validador = false;
            cin >> stock;
            if (stock > 0) {
                validador = true;
            }
            else {
                cout << endl << "No valido ingrese denuevo porfavor";

            }
        } while (validador == false);
    };

    void setCodigo(string codigo) { this->codigo = codigo; }
    void setTipo(string tipo) { this->tipo = tipo; }
    void setTalla(short talla) { this->talla = talla; }
    void setStock(float stock) { this->stock = stock; }
    string getCodigo() { return codigo; }
    string getTipo() { return tipo; }
    short getTalla() { return talla; }
    float getStock() { return stock; }
    void reportePrenda() {
        cout << endl << "-----------------" << "Codigo : " << codigo << endl << "Tipo: " << tipo << endl << "Talla: " << talla << endl << "Stock: " << stock << endl;

    }

};






class Almacen {
    Prenda* arrPrenda;
    short n;
    short numero;
    string descripcion;
    string ubicacion;
public:
    Almacen() {
        cout << "Ingresa la cantidad de prendas que se encontraran en este almacen al empezar: ";
        cin >> n;
        arrPrenda = new Prenda[n];
    }
    ~Almacen() {};
    short getN() { return n; }
    void prendasRegistradas() {
        cout << "Prendas registradas en este almacen: " << endl;
        for (short i; i < n; i++) {
            cout << "Prenda nro: " << i << endl;
            arrPrenda[i].reportePrenda();
        }
    }
    void eliminarPrenda(short pos) {
        Prenda* arrTemp;
        arrTemp = new Prenda[n - 1];
        short j = 0;
        for (short i = 0; i < n; i++) {
            if (i != pos) {
                arrTemp[j] = arrPrenda[i];
                j++;
            }
        }
        delete arrPrenda;
        arrPrenda = arrTemp;
        n--;
    }
    /////////////////////////////////////
    bool modificarPrenda(string codigo) {
        bool valxd = false;
        bool tmre;
        string auxTC;
        short auxtalla;
        float auxStock;
        string modificacion;
        for (short i = 0; i < n; i++) {
            if (arrPrenda[i].getCodigo() == codigo) {
                do {
                    cout << "Que desea modificar? de esta prenda?: (codigo,tipo,tallas,stock), si ingresa mal tendra q reingresar el dato";
                    cin >> modificacion;
                } while (modificacion != "codigo" || modificacion != "tipo" || modificacion != "talla" || modificacion != "stock");
                //if anidado ya q no puedo usar switch
                if (modificacion == "codigo") {
                    do {
                        cout << "Ingrese nuevo dato: ";
                        cin >> auxTC;
                        if (auxTC.length() == 4) {
                            valxd = true;
                        }
                        else { cout << "Codigo incorrecto ingrese nuevamente: " << endl; }
                    } while (valxd == false);

                    arrPrenda[i].setCodigo(auxTC);

                }
                else if (modificacion == "tipo") {
                    do {
                        valxd = false;
                        cout << "Ingrese el tipo de prenda:";
                        cin >> auxTC;
                        if (auxTC == "polo" || auxTC == "polo" || auxTC == "polera") {
                            valxd = true;
                        }
                        else { cout << "No valido ingrese denuevo porfavor" << endl; }
                    } while (valxd == false);

                    arrPrenda[i].setTipo(auxTC);

                }
                else if (modificacion == "talla") {
                    do {
                        cout << "Ingrese talla: de 10 a 15: ";
                        valxd = false;
                        cin >> auxtalla;
                        if (auxtalla > 10 && auxtalla < 15) {
                            valxd = true;
                        }
                        else {
                            cout << endl << "No valido ingrese denuevo porfavor";

                        }
                    } while (valxd == false);

                    arrPrenda[i].setTalla(auxtalla);

                }
                else if (modificacion == "stock") {
                    do {
                        valxd = false;
                        cout << "Ingrese stock: ";
                        cin >> auxStock;
                        if (auxStock > 0) {
                            valxd = true;
                        }
                        else {
                            cout << endl << "No valido ingrese denuevo porfavor";

                        }
                    } while (auxStock == false);
                    arrPrenda[i].setStock(auxStock);

                }
                tmre = true;
            }
            else {
                tmre = false;
            }
        }
        return tmre;
    }
    void reporteAlmacen() {}
    void reportStock(float stk) {
        for (short i = 0; i < n; i++) {
            if (arrPrenda[i].getStock() < stk) {
                arrPrenda[i].reportePrenda();
                cout << endl;
            }
        }
    }
    float reportTipoPolo() {
        float suma = 0, promedio, contador;
        for (short i = 0; i < n; i++) {
            if (arrPrenda[i].getTipo() == "polo") {
                suma = suma + arrPrenda[i].getStock();
                contador++;
            }
        }
        promedio = suma / contador;
        return promedio;
    }
    float reportTipoCamisa() {
        float suma = 0, promedio, contador;
        for (short i = 0; i < n; i++) {
            if (arrPrenda[i].getTipo() == "camisa") {
                suma = suma + arrPrenda[i].getStock();
                contador++;
            }
        }
        promedio = suma / contador;
        return promedio;
    }
    float reportTipoPolera() {
        float suma = 0, promedio, contador;
        for (short i = 0; i < n; i++) {
            if (arrPrenda[i].getTipo() == "polera") {
                suma = suma + arrPrenda[i].getStock();
                contador++;
            }
        }
        promedio = suma / contador;
        return promedio;
    }
};
class ArregloAlmacen {
    Almacen* arrAl;
    short n;
public:
    ArregloAlmacen() {
        cout << "Cuantos almacenes desea registrar?: ";
        cin >> n;
        arrAl = new Almacen[n];

    }
    void aEliminarPrenda() {
        cout << "--------------" << endl;
        short pos;
        short al;
        do {
            cout << "De que almacen desea eliminar la prenda?: " << endl;
            cin >> al;
        } while (al > n || al < 0);
        do {
            cout << "Ingresar posicion de la prenda a eliminar en el arreglo: ";
            cin >> pos;
        } while (pos<0 || pos>arrAl[al].getN());

        arrAl[al].eliminarPrenda(pos);
        cout << "Eliminado con exito" << endl;

    }
    void aModificarPrenda() {
        string codigo;
        cout << "Ingrese codigo de la prenda: (codigo de 4 digitos, si se ingresa mal tendra q volver a ingresar el codigo)";
        do {
            cin >> codigo;
        } while (codigo.length() != 4);

        bool val = false, noEncontrado = false;
        short contador = 0;
        do {
            val = arrAl[contador].modificarPrenda(codigo);
            if (val == true) {
                contador = 0;
            }
            if (contador == n) {
                noEncontrado = true;
                cout << "Codigo no encontrado en ninguna prenda" << endl;
            }
            contador++;
        } while (val == false || noEncontrado == false);
    }
    void reporteAlmacenes() {
        cout << "-------------------------" << endl << "Reporte de prendas en todos los almacenes: ";
        for (short i = 0; i < n; i++) {
            cout << "Almacen nro: " << i;
            arrAl[i].prendasRegistradas();
        }
    }
    void aReportStock() {
        cout << "------------------" << endl;
        float stk;
        cout << "Colocar el stock requerido para el reporte: (numero mayor a 0) " << endl;
        cin >> stk;
        for (short i = 0; i < n; i++) {
            arrAl[i].reportStock(stk);
        }
    }
    void aReportTipo() {
        cout << "-------------------" << endl;
        float contxd = 0;
        float polos = 0, camisas = 0, poleras = 0;
        for (short i = 0; i < n; i++) {
            polos = polos + arrAl[i].reportTipoPolo();
            camisas = camisas + arrAl[i].reportTipoCamisa();
            poleras = poleras + arrAl[i].reportTipoPolera();
            contxd++;
        }
        polos = polos / contxd;
        camisas = camisas / contxd;
        poleras = poleras / contxd;
        cout << "Reporte promedio stock de polos: " << polos << endl << "Reporte promedio stock de camisas:" << camisas << endl << "Reporte promedio stock de poleras" << poleras << endl;




    }
};

int main() {
    short n;
    cout << "Youkoso ";
    ArregloAlmacen* uwu;
    uwu = new ArregloAlmacen();

    short opcion;
    do {
        cout << endl << "-###################-" << endl << "Que desea realizar?: (1:Eliminar una prenda , 2:Modificar una prenda buscada por codigo, 3: Reporte entero , 4: Reportar prendas que tienen stock debajo del registrado, 5: Reporte del promedio stock por cada tipo de prenda, 0: salir del programa)" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:uwu->aEliminarPrenda(); break;
        case 2:uwu->aModificarPrenda(); break;
        case 3:uwu->reporteAlmacenes(); break;
        case 4:uwu->aReportStock(); break;
        case 5:uwu->aReportTipo(); break;
        case 0:cout << "Hasta la proxima.mp4"; break;
        default: cout << "Codigo ingresado incorrecto :v"; break;
        }
    } while (opcion != 0);



}