#include"Usuario.h"

char* Usuario::getNombre() { return nombre; }
char* Usuario::getApellido() { return apellido; }
long  Usuario::getCodigo() { return codigo; }
short Usuario::getNroTicket() { return nroTicket; }
char  Usuario::getTipoUsuario() { return tipoUsuario; }

void Usuario::setnombre(char* nombre) { this->nombre = nombre; }
void Usuario::setapellido(char* apellido) { this->apellido = apellido; }
void Usuario::setcodigo(long codigo) { this->codigo = codigo; }
void Usuario::setnroTicket(short nroTicket) { this->nroTicket = nroTicket; }
void Usuario::settipoUsuario(char tipoUsuario) { this->tipoUsuario = tipoUsuario; }


Usuario::Usuario()
{
	this->nombre = new char[10];
	this->apellido = new char[10];
	this->codigo = 0;
	this->nroTicket = 0;
	this->tipoUsuario = 'A';
}
Usuario::Usuario(char* nombre, char* apellido, long codigo, short nroTicket, char tipoUsuario)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigo = codigo;
	this->nroTicket = nroTicket;
	this->tipoUsuario = tipoUsuario;
}


Usuario::~Usuario()
{
	delete nombre;
	delete apellido;
}