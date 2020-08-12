#pragma once
#include<iostream>
#include"Animal.h"
#include<string>
using namespace std;

class Perro :public Animal{

private:
public:
	
	using Animal::Animal;


	~Perro() {}
	void sonido() {
		cout << "Wuau Wuau" << endl;
	}
	

};