#pragma once
class Usuario
{
public:
	Usuario(char* nombre,char* apellido,long codigo,short nroTicket,char tipoUsuario);
	Usuario();
	~Usuario();
	char* getNombre();
	char* getApellido();    
	long getCodigo();       
	short getNroTicket();   
	char getTipoUsuario();  

	void setnombre(char* nombre);
	void setapellido(char* apellido);
	void setcodigo(long codigo);
	void setnroTicket(short nroTicket);
	void settipoUsuario(char tipoUsuario);


private:
	char* nombre;
	char* apellido;
	long codigo;
	short nroTicket;
	char tipoUsuario;
};