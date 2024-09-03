#pragma once
#include <raylib.h>
#include <ball.h>
class Paddle
{
public:
	Paddle(int play, int posx, int posy, int h, int w, int sW, int sH, Color c);
	void Draw();
	void Update();
	void AIUpdate(Ball ball);
	int player;
	int posX;
	int posY;
	int height;
	int width;
	Color color;
	int sHeight;
	int sWidth;
	int speed;
	int score;
};

