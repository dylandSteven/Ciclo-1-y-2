#include<iostream>
#include<string>
#include<conio.h>
#include"Ingrediente.h"
#include"Pastel.h"
using namespace std;

int main()
{
	Ingredientes* i1 = new Ingredientes("Harina", "Gramos", 15, 2000);
	Ingredientes* i2 = new Ingredientes("Leche", "Litros", 1, 600);
	Ingredientes* i3 = new Ingredientes("Huevo", "Kg", 1, 1200);

	Pastel* nuevo = new Pastel("Tres Leches",3,60);
	nuevo->AgregarIngredientes(i1);
	return 0;
}