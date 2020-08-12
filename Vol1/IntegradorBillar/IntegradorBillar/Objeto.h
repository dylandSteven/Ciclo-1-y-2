#pragma once
class CObjeto {

private:

	int x, y;
	int ancho, alto;

public:
	CObjeto() {}
	CObjeto(int x, int y, int ancho , int alto) {
		this->x = x;
		this->y = y;
		this->alto = alto;
		this->ancho = ancho;
	}
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	void setX(int x1) { x = x1; }
	void setY(int y1) { y = y1; }
	int getX() { return x; }
	int getY() { return y; }
};
