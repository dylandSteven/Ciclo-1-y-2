#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Persona
{
protected:
	string nombre;
	string apellido;
	short edad;
public:
	~Persona() {}
	Persona(string n = "", string a = "") :nombre(n), apellido(a) {};
	void setNombre(string n) { n = nombre; }
	void setApellido(string a) { a = apellido; }
	void setEdad(short x) { edad = x; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	short  getEdad() { return edad; }

	string toString() { string s(nombre + " " + apellido + " "); return s; }

};

class Empleado :public Persona {
protected:
	string grupoSanguineo;
	int sueldo;

	void setSueldo(int x) { sueldo = x; }
	int  getSueldo() { return sueldo; }
	Empleado() {}
	~Empleado() {}
	Empleado(string nombre, string apellido, string grupo) : Persona(nombre, apellido) { grupoSanguineo = grupo; }
	string toString() {
		string s(Persona::toString() + " " + grupoSanguineo + " "); return s;
	}

};


class Conductor :public Empleado {

private:

	int nroPapeletas;

public:

	Conductor(string nombre, string apellido, string grupo, int nroPapeletas) : Empleado(nombre, apellido, grupo) { this->nroPapeletas = nroPapeletas; }
	Conductor() {
		grupoSanguineo = "O";
		nroPapeletas = 0;
		nombre = "";
	}
	~Conductor() {}

	void setNroPapeletas(int nroPapeletas) {
		this->nroPapeletas = nroPapeletas;
	}
	int getNroPapeletas() { return nroPapeletas; }
	string toString() {
		string aux(Empleado::toString() + " " + to_string(nroPapeletas) + "\n");
		return aux;
	}
};


class Estudiante : public Persona {
private:

	string codigo;

public:
	Estudiante(string n, string a, string cod) {
		Persona::nombre = n;
		Persona::apellido = a;
		codigo = cod;
	}

	~Estudiante() {}
	void setCodigo(string g) { codigo = g; }
	string getCodigo() { return codigo; }

	string getEstudiante() {
		string e(Persona::toString() + " " + codigo + "\n");

		return e;
	}
};

class Administrativo : public Empleado
{
private:
	string tipo;
public:
	Administrativo(string nombre, string apellido, short edad, int sueldo, string tipo) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->sueldo = sueldo;
		this->tipo = tipo;
	}
	~Administrativo() {}

	void setTipo(string x) { tipo = x; }
	string  getTipo() { return tipo; }

	string toString() {
		string s(Empleado::toString() + " " + tipo); return s;
	}

};
class Agente_Seguridad : public Empleado
{
private:
	string licencia;
public:
	Agente_Seguridad(string nombre, string apellido, short edad, int sueldo, string licencia) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->sueldo = sueldo;
		this->licencia = licencia;
	}
	~Agente_Seguridad() {}

	void setLicencia(string x) { licencia = x; }
	string  getLicencia() { return licencia; }

	string toString() {
		string s(Empleado::toString() + " " + licencia); return s;
	}

};

class Profesor :public Empleado {
private:
	string especialidad;
public:
	Profesor(string n, string a, string g, string e) :Empleado(n, a, g) {
		especialidad = e;
	}

	~Profesor() {}
	void setEspecialidad(string e) { especialidad = e; }
	string getEspecialidad() { return especialidad; }

	string toString() {
		string s(Empleado::toString() + " " + especialidad + "-"); return s;
	}
};



class Campus
{


public:
	Campus() {}
	Campus(string nombre, string distrito, string cod) {
		this->nombre = nombre;
		this->distrito = distrito;
		this->cod = cod;
	}
	~Campus() {}

	string getNombre() { return nombre; }
	string getDistrito() { return distrito; }
	string getCod() { return cod; }

	void setNombre(string nombre) { this->nombre = nombre; }
	void setDistrito(string distrito) { this->distrito = distrito; }
	void setCod(string cod) { this->cod = cod; }
	string toString() {
		string s(nombre + " " + distrito + " " + cod); return s;
	}

private:
	string nombre;
	string distrito;
	string cod;
};


class Bus {
private:
	string placa;

	short npasajeros;
	float kilometraje;
	Conductor* conductor;
public:
	Bus(string p = " ", short na = 0, float k = 0) {
		placa = p;
		conductor = nullptr;
		npasajeros = na;
		kilometraje = k;

	}


	~Bus() {}

	void setPlaca(string pl) { placa = pl; }
	void setNpasajeros(float na) { npasajeros = na; }
	void setKilometraje(short k) { kilometraje = k; }

	string getPlaca() { return placa; }

	float getNpasajeros() { return npasajeros; }
	short getKilometraje() { return kilometraje; }
	string getConducotr() { return conductor->getNombre(); }

	string toString() {
		string s(placa + " " + conductor->getNombre() + " " + to_string(npasajeros) + " " + to_string(kilometraje));
		return s;
	}

};


//......................Colecciones(vector)-----------
class Personas
{
private:
	vector<Persona> arreglo;

public:
	void agregar(Persona tipo) {

		arreglo.push_back(tipo);
	}

	void eliminar_en_posicion(int pos) {
		if (pos >= 0 && pos < arreglo.size())
			arreglo.erase(arreglo.begin() + pos);

	}
	void obtener_por_posicion(int pos) {
		if (pos >= 0 && pos < arreglo.size())
			arreglo.at(pos).toString();
	}
	void modificar_por_posicion(int pos, Persona persona) {
		if (pos >= 0 && pos < arreglo.size())
			arreglo.at(pos) = persona;
	}
	void mostrarTodos() {
		for (int i = 0; i < arreglo.size(); i++) {
			cout << i + 1 << ".- ";
			arreglo[i].toString();
		}
		cout << endl;
	}

};

class Buses
{
private:
	vector<Bus*>* buses;

public:
	void agregar(Bus* bus) {

		buses->push_back(bus);
	}

	void eliminar_en_posicion(int pos) {
		if (pos >= 0 && pos < buses->size())
			buses->erase(buses->begin() + pos);

	}
	void obtener_por_posicion(int pos) {
		if (pos >= 0 && pos < buses->size())
			buses->at(pos)->toString();
	}
	void modificar_por_posicion(int pos, Bus* bus) {
		if (pos >= 0 && pos < buses->size())
			buses->at(pos) = bus;
	}
	void mostrarTodos() {
		for (int i = 0; i < buses->size(); i++) {
			cout << i + 1 << ".- ";
			buses->at(i)->toString();
		}
		cout << endl;
	}

};

struct Tiempo {
	int h, m, s;
	Tiempo() {}
	Tiempo(int h, int m, int s) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	string toString() {
		string s(to_string(h) + " " + to_string(m) + " " + to_string(s)); return s;
	}
};
class Registro {

	Agente_Seguridad* as;
	Tiempo hora_salida;
	Tiempo hora_llegada;
	Campus origen;
	Campus llegada;
	Bus b;
	float kilometraje;
	Conductor conductor;
	vector<Persona>pasajeros;
public:
	//Registro(){}
	Registro(Agente_Seguridad* as, Tiempo hs, Tiempo hll, Campus o, Campus ll, Bus b, Conductor c) {
		this->as = as;
		this->hora_salida = hs;
		this->hora_llegada = hll;
		this->origen = o;
		this->llegada = ll;
		this->b = b;
		conductor = c;
		//Registrar_pasajeros();
	}
	//void Registrar_pasajeros() {
	//	int cont = 1;
	//	string nombre, apellido;
	//	char opcion;
	//	do {
	//		cout << "Pasajero " << cont++ << endl;
	//		cout << "Ingrese Nombre: ";
	//		cin >> nombre;
	//		cout << "Ingrese Apellido";
	//		cin >> apellido;
	//		pasajeros.push_back(Persona(nombre, apellido));
	//		cout << "Desea continuar(S/N)";
	//		opcion = toupper(opcion);
	//		cin >> opcion;
	//		
	//	} while (pasajeros.size() < b.getNpasajeros() && opcion == 'S');
	//	
	//}
	string toString() {
		string s(as->toString() + " " + hora_salida.toString() + " " + hora_llegada.toString() + " " + origen.toString() + " " + llegada.toString() + " " + conductor.toString()); return s;
	}
};
class Control {
	vector<Registro*>registros;

public:
	void agregar(Registro* r) {

		registros.push_back(r);
	}

	void eliminar_en_posicion(int pos) {
		if (pos >= 0 && pos < registros.size())
			registros.erase(registros.begin() + pos);

	}
	void obtener_por_posicion(int pos) {
		if (pos >= 0 && pos < registros.size());
		//registros->at(pos)->toString();
	}
	void modificar_por_posicion(int pos, Registro* r) {
		if (pos >= 0 && pos < registros.size())
			registros.at(pos) = r;
	}
	void mostrarTodos() {
		for (int i = 0; i < registros.size(); i++) {
			cout << i + 1 << ".- ";

			cout << registros.at(i)->toString();

		}
		cout << endl;
	}


};
int main() {
	Bus b1 = Bus("ABC-56", 43, 165000);
	Bus b2 = Bus("AFE-1092", 4, 432000);
	Agente_Seguridad* as = new Agente_Seguridad("Luis", "Sernaque", 29, 2500, "Activa");
	Conductor con = Conductor("Jose", "Rojas", "O", 8);
	Tiempo t1 = Tiempo(14, 37, 9);
	Tiempo t2 = Tiempo(12, 17, 6);
	Campus c1 = Campus("Villa", "Chorillos", "0123");
	Campus c2 = Campus("SM", "San Miguel", "321");
	Control registros = Control();
	Registro* r = new Registro(as, t1, t2, c1, c2, b1, con);
	registros.agregar(r);
	registros.mostrarTodos();

	//registros.agregar(new Registro(as,t1,t2,c1,c2,b1,con));

	system("pause>0");
	return 0;


}