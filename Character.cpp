#include "Character.h"
#include "raymath.h"

// NOTE: Character::(scoop resolution operator) means that the setScreenPos() method belongs to the Chatacter class
Character::Character(int winWidth, int winHeight) :
    windowWidth{winWidth},
    windowHeight{winHeight}
{

    width = texture.width / maxFrames;
    height = texture.height;

    screenPos = {
        (float)winWidth / 2.0f - scale * (0.5f * width), // (float) c style casting
        (float)winHeight / 2.0f - scale * (0.5f * height)
    };
}

Vector2 Character::getScreenPos(){

    return Vector2{
        (float)windowWidth / 2.0f - scale * (0.5f * width), // (float) c style casting
        (float)windowHeight / 2.0f - scale * (0.5f * height)};
} 

void Character::tick(float deltaTime)
{


    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    // call the tick version from the parent class. This version of the function 
    // has the code we removed from here after the inheritance
    BaseCharacter::tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{}; 
    if(rightLeft > 0.f){
        origin  = {0.f, weapon.height * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = 35.f;
    }else{
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y +  offset.y  - weapon.height * scale,
            weapon.width * scale,
            weapon.height *scale

        };
        rotation = -35.f;
    }
        
    //draw sword
    Rectangle source{0.f, 0.f, (float)weapon.width *rightLeft, (float)weapon.height};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        RED
    );
}
 
