#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"



int main()
{

    const int windowWidth{384};
    const int windowHeight{384};

    InitWindow(windowWidth, windowHeight, "Classy Class Game");

    // --- MAP
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};


    // --- CREATE CHATACTER
    Character knight(windowWidth, windowHeight);

    // --- CREATE ENEMY
    Enemy goblin{Vector2{}, 
                LoadTexture("characters/goblin_idle_spritesheet.png"), 
                LoadTexture("characters/goblin_run_spritesheet.png")
                };

    //--- CREATE PROPS
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };


    SetTargetFPS(100);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(WHITE);

        // --- DRAW MAP
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // --- DRAW PROPS
        for ( auto prop : props) {
            prop.Render(knight.getWorldPos());    
        }
        

        // --- KNIGHT MOVEMENT
        knight.tick(GetFrameTime());



        // --- check if the player exeeds the boundaries of the map
        if( knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f || 
            knight.getWorldPos().x + windowWidth > map.width * mapScale || 
            knight.getWorldPos().y + windowWidth > map.height * mapScale)
        {
            knight.undoMovement();
        }

        for ( auto prop : props) {

           if( CheckCollisionRecs( prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()) ){
               knight.undoMovement();
           }
        }

        // --- GOBLIN MOVEMENT
        goblin.tick(GetFrameTime());
        
        
        EndDrawing();
    }

    UnloadTexture(map);
    //UnloadTexture(texture);

    CloseWindow();
}