#pragma once

using namespace System::Drawing;

class Hero {
private:
	int x, y; //location
	int dx, dy; //movement
	int idX, idY; // index
	int width, height;

public:
	Hero(int width, int height) {
		this->width = width;
		this->height = height;
		dx = dy = 15;
		x = 70;
		y = 70;
		idX = idY = 0;
	}

	~Hero() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width , height );
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g, char i) {
		switch (i) {

		case 'A':
			if (x > 0) {
				idY = 1;
				x -= dx;
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				idY = 2;
				x += dx;
			}
			break;

		case 'W':
			if (y > 0) {
				idY = 3;
				y -= dy;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				idY = 0;
				y += dy;
			}
			break;
		}

		idX++;
		if (idX > 3) idX = 0;
	}

};