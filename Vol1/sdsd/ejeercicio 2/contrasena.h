#ifdef  __CONTRASENA_H__
#define __CONTRASENA_H__

#include<string>

user namespace std;

char lower[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

char upper[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int numbers[] = { 0,1,2,3,4,5,6,7,8,9 };


class contrasena {

private:

	int length;
	string contrasena;
	int nLower;
	int nUpper;
	int nNumber;


public:

	contrasena() {

		nNumber = 0;
		nUpper = 0;
		nLower = 0;
		length = 15;

		generaContrasena();
	}

	void generaContrasena() {
	
		int n; 
		for (int i = 0; i < length; i++) {
			n = 1 + rand()3 - 1;

			switch (n)
			{
			case(1):contrasena.push_back(lower[rand() % 26]);
				nLower++; break;
			case(2):contrasena.pushback(upper[rand() % 26]);
				nUpper++;
			case(3):contrasena+to_string(numbers[rand() % 10]);
				nNumber++;
			}
		}
	}

	bool isSafe() {
		if (nUpper > 2 && nLower > 1 && nNumber > 5) { return true }
		else return false;
	}
	
	void setLength(int v) { length = v; }
	int getLength() { return length; }
	string getContrasena(){return contrasena}
};

#endif // 

