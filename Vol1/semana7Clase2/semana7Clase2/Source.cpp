
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Persona
{
protected:
	string nombre;
	string apellido;
	short edad;
public:
	Persona(string n = "", string a = "") :nombre(n), apellido(a) {};
	void setNombre(string n) { n = nombre; }
	void setApellido(string a) { a = apellido; }
	void setEdad(int x) { edad = x; }
	int  getEdad() { return edad; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string toString() { string s(nombre + " " + apellido + " "); return s; }

};
class Empleado :public Persona {
protected:
	string grupoSanguineo;
	float sueldo;
public:
	Empleado() {}
	~Empleado() {}
	Empleado(string nombre, string apellido, string grupo) :Persona(nombre, apellido) { grupoSanguineo = grupo; }
	void setSueldo(int x) { sueldo = x; }
	float  getSueldo() { return sueldo; }
	string toString() {
		string s(Persona::toString() + " " + grupoSanguineo + " ");
		return s;
	}

};
class Estudiante :public Persona {
private:
	string codigo;

public:
	Estudiante(string n, string a, string cod) {
		Persona::nombre = n;
		apellido = a;
		codigo = cod;
	}

	~Estudiante() {}
	void setCodigo(string g) { codigo = g; }
	string getCodigo() { return codigo; }
	string toString() {
		string aux(Persona::toString() + "  " + codigo + "\n");
		return aux;

	};
};
class Conductor :public Empleado {

private:

	short nroPapeletas;

public:

	Conductor(string nombre, string apellido, string grupo, short nroPapeletas) :Empleado()
	{}
	Conductor() {
		grupoSanguineo = 'O';
		nroPapeletas = 0;
		nombre = " ";
	}
	~Conductor() {}

	void setNroPapeletas(short nroPapeletas) {
		this->nroPapeletas = nroPapeletas;
	}

	string toString() {
		string aux;
		aux.append(nombre);
		aux.append("\n");
		aux.append(to_string(nroPapeletas));
		aux.append("\n");
		return aux;
	}

	class Personas
	{
	private:
		vector<Persona> arreglo;

	public:
		void agregar(Persona tipo) {

			arreglo.push_back(tipo);
		};
		void insertar_al_final(Persona tipop) {
			arreglo.push_back(tipop);
		};
		void eliminar_en_posicion(int pos) {
			arreglo.erase(arreglo.begin() + pos);
		};
		void buscar_por_posicion(int pos) {
			arreglo.at(pos).toString();
		};
		void modificar_por_posicion(int pos, Persona persona) {
			arreglo.at(pos) = persona;
		};
		void mostrarTodos() {
			for (int i = 0; i < arreglo.size(); i++) {
				cout << i + 1 << ". ";
				arreglo[i].toString();
			}
			cout << endl;
		}


	};


};
class Administrativo :public Empleado
{
private:
	string tipo;
public:
	Administrativo(string nombre, string apellido, int edad, int sueldo, string codigo) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->sueldo = sueldo;
		this->tipo = tipo;
	}
	~Administrativo() {}
	void setCodigo(string x) { tipo = x; }
	string  getCodigo() { return tipo; }
	string Information() {
		string s(Empleado::toString() + "  " + tipo);
	}

};
class Profesor :public Empleado
{
private:
	string especialidad;
public:
	Profesor(string nombre, string apellido, string especialidad) :Empleado(nombre, apellido, grupoSanguineo) {
		this->especialidad = especialidad;
	}
	~Profesor() {}
	void setCodigo(string x) { especialidad = x; }
	string  getCodigo() { return especialidad; }
	string Information() {
		string s(Empleado::toString() + "  " + especialidad);
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

private:
	string nombre;
	string distrito;
	string cod;
};
class Bus {
private:
	string placa;
	Conductor* conductor;
	short npasajeros;
	float kilometraje;
public:
	Bus(string p = " ", short na = 0, short k = 0) {
		placa = p;
		conductor = nullptr;
		npasajeros = na;
		kilometraje = k;
	}
	~Bus() {}

	void setPlaca(string pl) { placa = pl; }
	void setNasientos(short na) { npasajeros = na; }
	void setKil(short k) { kilometraje = k; }

	string getplaca() { return placa; }
	string getnombre_cond() { return conductor->getNombre(); }
	short getnasientos() { return npasajeros; }
	float getkil() { return kilometraje; }

	string tostring() {
		string s(placa + "-" + conductor->getNombre() + "-" + to_string(npasajeros) + "-");
		return s;
	}

};
class Ruta {
private:
	char campusOrigen;
	char campusLlegada;
	int kilos;
public:
	Ruta() {
		campusOrigen = 'V';
		campusLlegada = 'M';
		kilos = 0;
	}
	Ruta(char campusOrigen, char campusLlegada, int kilos) {
		this->campusOrigen = campusOrigen;
		this->campusLlegada = campusLlegada;
		this->kilos = kilos;
	}
	~Ruta() {};
	void setCampusOrigen(char campusOrigen) {
		this->campusOrigen = campusOrigen;
	}
	void setCampusLlegada(char campusLlegada) {
		this->campusLlegada = campusLlegada;
	}
	void setkilos(int kilos) {
		this->kilos = kilos;
	}
	char getCampusOrigen() {
		return this->campusOrigen;
	}
	char getCampusLlegada() {
		return this->campusLlegada;
	}
	int getKilos() {
		return this->kilos;
	}
};

class Personas
{
private:
	vector<Persona> arreglo;

public:
	void Agregar(Persona tipo) {
		arreglo.push_back(tipo);
	};

	void eliminar_en_posicion(int pos) {
		arreglo.erase(arreglo.begin() + pos);
	};
	string obtener(int pos) {
		if (pos >= 0 && pos < arreglo.size()) {
			return arreglo.at(pos).toString();
		}
	}

	void modificar_por_posicion(int pos, Persona persona) {
		if (pos >= 0 && pos < arreglo.size()) {
			arreglo.at(pos) = persona;
		}
	}
	void mostrarTodos() {
		for (int i = 0; i < arreglo.size(); i++) {
			cout << i + 1 << ". " <<
				arreglo[i].toString();
		}
		cout << endl;
	}

};
class Buses
{
private:
	vector<Bus*>* arreglo;

public:
	void Agregar(Bus* tip) {
		arreglo->push_back(tip);
	};

	void eliminar_en_posicion(int pos) {
		arreglo->erase(arreglo->begin() + pos);
	};
	string obtener(int pos) {
		if (pos >= 0 && pos < arreglo->size()) {
			return arreglo->at(pos)->tostring();
		}
	}

	void modificar_por_posicion(int pos, Bus* persona) {
		if (pos >= 0 && pos < arreglo->size()) {
			arreglo->at(pos) = persona;
		}
	}
	void mostrarTodos() {
		for (int i = 0; i < arreglo->size(); i++) {
			cout << i + 1 << ". " <<
				arreglo->at(i)->tostring();
		}
		cout << endl;
	}

};
struct Tiempo
{
	short h, m, s;
	Tiempo() {}
	Tiempo(short h1, short m1, short s1) :h(h1), m(m1), s(s1) {};
};

class AgenteSeguridad :public Empleado {
private:
	string licencia;
public:
	AgenteSeguridad(string nombre, string apellido, int edad, int sueldo, string licencia) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->sueldo = sueldo;
		this->licencia = licencia;
	}
	~AgenteSeguridad() {}
	void setLicencia(string lic) { licencia = lic; }
	string getLicecia() { return licencia; }
	string toString() {
		string s(Empleado::toString() + "  " + licencia);
	}


};

class Registro {
protected:
	AgenteSeguridad* as;
	Tiempo horaSalida;
	Tiempo horaLlegada;
	Campus origen;
	Campus llegada;
	Bus bus;
	float kilometraje;
	Conductor conductor;
	vector<Persona>pasajeros;
public:
	Registro() {}
	Registro(AgenteSeguridad* as, Tiempo hs, Tiempo hll, Campus co, Campus cll, Bus b, Conductor c) {
		this->as = as;
		horaSalida = hs;
		origen = co;
		llegada = cll;
		bus = b;
		conductor = c;
		//registrarPasajero();
	}
	/*void registrarPasajero() {
		char opcion;
		int c = 1;
		string nombre, apellido;
		do {
			cout << "Ingrese Pasajero" << endl;
			cout << "Nombre: ";
			cin >> nombre;
			cout << "Apellido: ";
			cin >> apellido;
			pasajeros.push_back(Persona(nombre, apellido));
			cout << "Desea Continuar(S/N)";
			opcion = toupper(opcion);
			cin >> opcion;
		} while (pasajeros.size() < bus.getnasientos() && opcion == 'S');
	}*/
	string tostring() {

		string aux;
		aux.append(as->getNombre());
		aux.append("/");
		aux.append(as->getApellido());
		return aux;
	}


};

class Control {
	vector<Registro*>registros;
	
public:
	
	void agregar(Registro* tip) {
		registros.push_back(tip);
	};

	void eliminar_en_posicion(int pos) {
		if (pos >= 0 && pos < registros.size())
			registros.erase(registros.begin() + pos);
	};
	string obtener(int pos) {
		if (pos >= 0 && pos < registros.size()) {
			//return registros->at(pos)->tostring();
		}
	}

	void modificar_por_posicion(int pos, Registro* bus) {
		if (pos >= 0 && pos < registros.size()) {
			registros.at(pos) = bus;
		}
	}
	void mostrarTodos() {
		for (int i = 0; i < registros.size(); i++) {
			cout << i + 1 << ". " <<registros.at(i)->tostring();
		}
		cout << endl;
	}
	
};





int main() {
	Bus bus = Bus("ABC-123", 50,452100);
	Bus bus1 = Bus("KND-123", 80, 450010);
	Bus bus2 = Bus("KMD-123", 10,852100);
	AgenteSeguridad* as = new AgenteSeguridad("Luis", "Sernaque", 29, 2500,"ABS-123");
	Conductor conductor1 = Conductor("Rodrigo", "Salas","o",0); 
	Tiempo t1 = Tiempo(14, 37, 0);
	Tiempo t2 = Tiempo(15, 37, 0);
	Campus c1 = Campus("Villa", "Chorrillos", "01");
	Campus c2 = Campus("San Miguel", "Monterrico", "02");

	Control registros = Control();
	registros.agregar(new Registro(as,t1,t2,c1,c2,bus1, conductor1));
	registros.mostrarTodos();
	cin.get();
		cin.ignore();
	return 0;
}


