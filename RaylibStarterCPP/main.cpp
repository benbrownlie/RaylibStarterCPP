/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        hash = (hash << 4) + *i;
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}

//Hash function that takes in two unsigned arguments, one of type char, and another of type int.
unsigned int myHash(unsigned char* data, unsigned int length)
{
    //unsigned int variable, hash, set to 0
    unsigned int hash = 0;

    //For loop while int i is less than the length argument, increment i
    for (int i = 0; i < length; ++i)
    {
        //sets hash to hash * a pattern number, in this case 1000, + data at the index of i
        hash = (hash * 1000) + data[i];
    }

    //Returns hash, will always be positive
    return (hash & 0x7FFFFFFF);
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    int checkSum = 0;
    unsigned char* input = new unsigned char[0];

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        
        std::cin >> input;
        checkSum = myHash(input, 5);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}