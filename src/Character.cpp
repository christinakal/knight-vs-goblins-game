#include "Character.h"
#include "raymath.h"

// NOTE: Character::(scoop resolution operator) means that the setScreenPos() method belongs to the Chatacter class
Character::Character(int winWidth, int winHeight){
    width = texture.width / maxFrames;
    height = texture.height;

    screenPos = {
        (float)winWidth / 2.0f - scale * (0.5f * width), // (float) c style casting
        (float)winHeight / 2.0f - scale * (0.5f * height)
    };
}

void Character::tick(float deltaTime)
{
    // call the tick version from the parent class. This version of the function 
   // has the code we removed from here after the inheritance
    BaseCharacter::tick(deltaTime);

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
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
 
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        // check the direction of the movement and play the correct animation
        texture = run;
    }
    else
    {
        texture = idle;
    }


    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}
 
