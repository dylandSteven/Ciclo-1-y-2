#include "MyForm.h"
using namespace Ejercicio2Hoja14;

#include <time.h>
int main()
{
	srand(time(NULL));
	Application::Run(gcnew MyForm);
	return 0;
}