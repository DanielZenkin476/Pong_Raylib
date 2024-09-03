// Pong_Raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
using namespace std;

int main()
{
    const int sWidth = 1200;
    const int sHeight = 800;
    InitWindow(sWidth,sHeight, "PONG");// size of window
    SetTargetFPS(60);// sets Game Target FPS
    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);// font for display
    while (WindowShouldClose()==false)// will run until esc key is pressed
    {
      
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(Blue);// change backround color
        DrawRectangleRounded({ 0, 0, sWidth, sHeight }, float(0.3), 6, BLUE);// rectangle for backround

        DrawCircle(600, 400, 100, cyan);
        DrawLine(600, 0, 600, 800, Blue);//draws line- multiple for width
        DrawLine(601, 0, 601, 800, Blue);
        DrawLine(602, 0, 602, 800, Blue);
        DrawLine(599, 0, 599, 800, Blue);
        DrawLine(598, 0, 598, 800, Blue);
        DrawCircle(600, 400, 20, Blue);

        DrawTextEx(font, "PO NG", { 550,5 }, 38, 2, WHITE);// draw PONG
        // game objects here 


        DrawRectangle(20, sHeight/2 -50, 30, 100, white);
        DrawRectangle(1150, sHeight / 2-50 , 30, 100, white);

        DrawCircle(600, 400, 15, white);





        EndDrawing();// end canvas drawing

    }
}
