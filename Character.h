#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
private:
public:
    Character(int winWidth, int winHEight);
    void tick(float deltaTime);
};