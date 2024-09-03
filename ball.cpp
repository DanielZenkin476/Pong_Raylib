#include "ball.h"

Ball::Ball(int posx, int posy, float r, Color c, int sx, int sy,int sH,int sW)
{
	posX = posx;
	posY = posy;
	radius = r;
	color = c;
	speed_x = sx;
	speed_y = sy;
	sHeight = sH;
	sWidth = sW;
}

void Ball::Draw()
{
	DrawCircle(posX, posY, radius, color);
}

void Ball::ChangeColor(Color c)
{
	color = c;
}
void Ball::Update() {
	posX += speed_x;
	posY += speed_y;
	if (posX >= sWidth - int(radius)) {
		posX = sWidth - radius;
		speed_x = -speed_x;
	}
	if (posX <= 0) {
		posX = radius;
		speed_x = -speed_x;
	}
	if (posY >= sHeight - int(radius) ) {
		posY = sHeight - radius;
		speed_y = -speed_y;
	}
	if (posY <= 0) {
		posY = radius;
		speed_y = -speed_y;
	}
}


