#include "paddle.h"
Paddle::Paddle(int play,int posx, int posy, int h, int w, int sW, int sH, Color c) {
	player = play;
	posX = posx;
	posY = posy;
	height = h;
	width = w;
	sWidth = sW;
	sHeight = sH;
	color = c;
	speed = 10 ;
	score = 0;
}
void Paddle::Draw(){
	DrawRectangle(posX,posY,width,height,color);
}
void Paddle::Update() {
	if (player == 1) {
		if (IsKeyDown(KEY_UP)) {
			if (posY <= 0) {
				posY = 0;
			}
			else posY = posY - speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			if (posY >= sHeight - height) {
				posY = sHeight - height;
			}
			else posY = posY + speed;
		}
	}
	else if (player ==2){
		if (IsKeyDown(KEY_W)) {
			if (posY <= 0) {
				posY = 0;
			}
			else posY = posY - speed;
		}
		if (IsKeyDown(KEY_S)) {
			if (posY >= sHeight - height) {
				posY = sHeight - height;
			}
			else posY = posY + speed;
		}
	}
}

void Paddle::AIUpdate(Ball ball) {
	if (posY + height / 2 > ball.posY) {
		if (posY <= 0) {
			posY = 0;
		}
		else posY = posY - speed;
	}
	else {
		if (posY >= sHeight - height) {
			posY = sHeight - height;
		}
		else posY = posY + speed;
	}
}

