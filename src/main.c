#include <raylib.h>

int main() {
    InitWindow(800,800,"MyBigSnake");
    SetTargetFPS(60);
    Color turqoise={64, 224, 208, 255};
    int x=400;
    int y=400;
    while(WindowShouldClose() == false){

        if (IsKeyDown(KEY_RIGHT)){
            x+=3;
        }else if(IsKeyDown(KEY_LEFT)){
            x-=3;
        }else if(IsKeyDown(KEY_UP)){
            y-=3;
        }else if(IsKeyDown(KEY_DOWN))
        {
            y+=3;
        }
        
        BeginDrawing();
        ClearBackground(turqoise);
        DrawCircle(x,y,20, WHITE);
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}