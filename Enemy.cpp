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

}


void Enemy::tick(float deltaTime){
    
    // call the tick version from the parent class. This version of the function 
   // has the code we removed from here after the inheritance
    BaseCharacter::tick(deltaTime);

}