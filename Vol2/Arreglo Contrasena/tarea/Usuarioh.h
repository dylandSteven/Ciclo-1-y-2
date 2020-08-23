#pragma once
#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
class Usuario {


public:

	void setNombre(string nombre)         { this->nombre = nombre; }
	void setCodigo(long codigo)          { this->codigo = codigo; }
	
	void setTicket(string Ticket)         { 
	
	this->Ticket = Ticket;
	}
	void setTipoCliente(char tipoCliente) { this->tipoCliente = tipoCliente; }
	string getNombre() { return nombre; }
	long  getCodigo() { return codigo; }
	string getTicket() { return Ticket; }
	char   getTipoCliente() { return tipoCliente; }



private:
	string nombre;
	long codigo;
	string Ticket;
	char tipoCliente;


};