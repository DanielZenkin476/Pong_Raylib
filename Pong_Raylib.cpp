// Pong_Raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
#include <ball.h>
#include <paddle.h>

using namespace std;

int main()
{
    const int sWidth = 1200;
    const int sHeight = 800;
    InitWindow(sWidth,sHeight, "PONG");// size of window
    SetTargetFPS(60);// sets Game Target FPS
    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);// font for display

    Ball ball = Ball(sWidth / 2, sHeight / 2, 15, white,8,8,sHeight,sWidth);

    // paddle ids- 1 for p1 ,2 for p2, 3 for ai
    Paddle p1 = Paddle(1,20, sHeight / 2 - 50, 100, 30, sWidth, sHeight, red);
    Paddle p2 = Paddle(3,1150, sHeight / 2 - 50 , 100, 30, sWidth, sHeight, orange);
 

    while (WindowShouldClose()==false)// will run until esc key is pressed
    {
      
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(Blue);// change backround color, also to to a "soft reset" of screen to not show past iterations
        DrawRectangleRounded({ 0, 0, sWidth, sHeight }, float(0.3), 6, BLUE);// rectangle for backround

        DrawCircle(600, 400, 100, cyan);
        DrawLine(600, 0, 600, 800, Blue);//draws line- multiple for width
        DrawLine(601, 0, 601, 800, Blue);
        DrawLine(602, 0, 602, 800, Blue);
        DrawLine(599, 0, 599, 800, Blue);
        DrawLine(598, 0, 598, 800, Blue);
        DrawCircle(600, 400, 20, Blue);

        DrawTextEx(font, "PO NG", { 550,5 }, 38, 2, WHITE);// draw PONG

        // update game objects      
        ball.Update();
        p1.Update();
        if (p2.player == 2) { 
            p2.Update();
        }
        else { 
            p2.AIUpdate(ball);
        }

        // colision detection
        if (CheckCollisionCircleRec(Vector2{ (float)ball.posX ,(float)ball.posY }, ball.radius, Rectangle{ (float)p1.posX, (float)p1.posY, (float)p1.width, (float)p1.height }))// check collision p1
        {
            ball.speed_x = -ball.speed_x;
        }

        if (CheckCollisionCircleRec(Vector2{ (float)ball.posX ,(float)ball.posY }, ball.radius, Rectangle{ (float)p2.posX, (float)p2.posY, (float)p2.width, (float)p2.height }))// check collision p1
        {
            ball.speed_x = -ball.speed_x;
        }

        // check if scored
        if (ball.posX-(int)ball.radius == 0) {
            p2.score++;

        }
        if (ball.posX + (int)ball.radius ==sWidth) {
            p1.score++;

        }
       // draw game objects
        p1.Draw();
        p2.Draw();
        ball.Draw();
        //Draw score 
        char scoreText[10];
        sprintf_s(scoreText, "%d", p1.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, Vector2{ 100 ,200}, 38, 2, WHITE);//draw score centered

        char scoreText2[10];
        sprintf_s(scoreText2, "%d", p2.score);
        Vector2 textSize2 = MeasureTextEx(font, scoreText2, 38, 2);
        DrawTextEx(font, scoreText2, Vector2{ 800 ,200 }, 38, 2, WHITE);//draw score centered
        EndDrawing();// end canvas drawing

    }
}

