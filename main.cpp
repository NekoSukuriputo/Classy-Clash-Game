#include "raylib.h"

int main()
{
    // variable window
    const int windowWidth{384};
    const int windowHeigth{384};

    // init window
    InitWindow(windowWidth, windowHeigth, "Top Down Game");

    // def Map
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // draw map
        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }

    CloseWindow();
}