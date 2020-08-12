#pragma once
#include<iostream>
#include<string>
using namespace std;

class Auto {
private:

	string placa;
	int cantGalones;
public:
	Auto(){}
	Auto(string _Placa, int _cantGalones) : placa(_Placa), cantGalones(_cantGalones) {}
	~Auto() {}
	string getPlaca() { return placa; }
	int getCangalo() { return cantGalones; }


};