#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;

}


void Enemy::tick(float deltaTime){
    


    // BASIC enemy AI
    //get toTarget vector-> a vector from enemyPos to knightPos
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    screenPos = Vector2Subtract(worldPos, target->getWorldPos());

    // call the tick version from the parent class. This version of the function 
   // has the code we removed from here after the inheritance
    BaseCharacter::tick(deltaTime);

    //normalize toTarget vector so we can have a consistent length each frame
    // toTarget = Vector2Normalize(toTarget);

    // //multiply toTarget by enemy's speed
    // toTarget = Vector2Scale(toTarget, speed);

    // // move enemy towards the knight by adding toTarget vector to it's current position
    // worldPos = Vector2Add(worldPos, toTarget);
}

Vector2 Enemy::getScreenPos(){
    return  Vector2Subtract(worldPos, target->getWorldPos());
}