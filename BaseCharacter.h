// --- define the class once and fix compiler definition errors
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"


class BaseCharacter{
    public:
        BaseCharacter();

        BaseCharacter(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
        Vector2 getWorldPos() { return worldPos; }

        void undoMovement();
        Rectangle getCollisionRec();

        // virtual: can be inheritted and altered by child class
        virtual void tick(float deltaTime);
        
        //pure virtual function
        virtual Vector2 getScreenPos() = 0;

    protected:
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};
        
        Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};


        // animation
        float rightLeft{1.f};
        float runningTime{};
        int frame{};
        int maxFrames{6};
        float updateTime{1.f / 12.f};
        float speed{4.f};

        float width{};
        float height{};

        float scale{4.0f};
        Vector2 velocity{};

    private:

};

#endif

