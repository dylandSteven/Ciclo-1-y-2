#include<iostream>
using namespace std;

class Sudoku
{
private:

	const short lado = 9;
	short** tablero;

	void inicializarMatrizValores();
	void liberarMemoriaMatriz();
	bool validarDatosIngresados(short _N, short _x, short _y);
	bool validarRango(short _n,short _min,short _max);

public:

	Sudoku() {inicializarMatrizValores();};
	~Sudoku(){liberarMemoriaMatriz(); };

	void mostrarTablero();
	void escribirNumero();
	bool continuarJuego();
};

void Sudoku::inicializarMatrizValores() {

	this->tablero = new short* [this->lado];
	for (int i = 0;i<this->lado; i++) {
		tablero[i] = new short[this->lado];
		
		for (int j = 0; j < this->lado; j++) {
			this->tablero[i][j] = 0;
	}
	}

}

void Sudoku::liberarMemoriaMatriz() {

	for (short i = 0; i < this->lado; i++) {
		delete[] this->tablero[i];
	}
	delete[]this->tablero;
}

void Sudoku::escribirNumero() {
	
	short N, x, y;
	cout << "Ingrese: "<<endl;
	cout << "Numero: "; cin >> N;
	cout << "X: "; cin >> x;
	cout << "Y: "; cin >> y;
	x--; 
	y--;
	if (validarDatosIngresados(N, x, y))
		this->tablero[y][x]=N;
	else {
		cout << "Valores ingresados incorrectos." << endl;
		system("pause");
	}
}


bool Sudoku::continuarJuego() {
	for (short i = 0; i < 9; i++) {
		for (short j = 0; j < 9; j++) {
			if (this->tablero[i][j] == 0) {
				return true;
			}
	        cout << "Felicityaciones , lo has conseguido." << endl;
	        return false;
		}
	}

}

void Sudoku::mostrarTablero(){
	system("cls");
	for (short i = 0; i < 9; i++) {
		if (i % 3 == 0)cout << "+---+---+---+" <<endl;
		for (short j = 0; j < 9; j++) {
			if (j % 3 == 0)cout << "|";
			if (this->tablero[i][j] == 0)cout << ".";
			else cout << this->tablero[i][j];
		}
		cout << "|" << endl;
	}
	cout << "+---+---+---+"<<endl;

}
bool Sudoku::validarDatosIngresados(short _N, short _x, short _y) {
	if (_N == 0)
		return true;
	if (_N > 0) {

		if (!(this->validarRango(_N, 1, 9)) &&
			(this->validarRango(_x, 0, this->lado - 1)) &&
			(this->validarRango(_y, 0, this->lado - 1)))
			return false;

		for (short i = 0; i < 9; i++)
			if (i != _x && this->tablero[_y][i] == _N)
				return false;

		for (short i = 0; i < 9; i++)
			if (i != _y && this->tablero[i][_x] == _N)
				return false;

		short casillax = (_x / 3) * 3;
		short casillay = (_y / 3) * 3;
		for (short i = casillax; i < casillax + 3; i++)
			for (short j = casillay; j < casillay + 3; j++)
				if ((_x != i && _y != j) && this->tablero[_y][_x] == _N)
					return false;
	}
	return true;
}

bool Sudoku::validarRango(short _N, short min, short max) {

	if (_N >= min && min && _N <= max)return true;
	else return false;
}
	
int main() {
	Sudoku juego = Sudoku();
		do {
			juego.mostrarTablero();
			juego.escribirNumero();
		} while (juego.continuarJuego());
		
	return 0;
}