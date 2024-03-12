#include "Character.h"
#include "raymath.h"

Character::Character()
{
    width = texture.width / frame;
    height = texture.height;
}

void Character::setScreenPos(int winWidth, int winHeigth)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * width / 6.0f),
        (float)winHeigth / 2.0f - 4.0f * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    // map direction
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));

        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    // update animation frame
    runningTime += deltaTime;
    if (runningTime > updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrame)
            frame = 0;
    }
    // draw charater
    Rectangle source{frame * width / 6.f, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}