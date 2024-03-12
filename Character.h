#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
private:
public:
    Character(int winWidth, int winHEight);
    virtual void tick(float deltaTime) override;
    Vector2 getScreenPos() { return screenPos; };
};

#endif