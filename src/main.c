#include <raylib.h>
Color turqoise={64, 224, 208, 255};
typedef struct
{
    Vector2 position;
}Food;
 void DrawFood(const Food* food,int cellsize, Color turqoise){
    DrawRectangle(food->position.x*cellsize, food->position.y*cellsize, cellsize,cellsize, turqoise );
 }

int main() {
    int cellrow= 25;
    int cellsize=30;
    int tot=cellrow*cellsize;
    InitWindow(tot,tot,"MyBigSnake");
    SetTargetFPS(60);
    Food food={{5,6}};
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(turqoise);
        DrawFood(&food, cellsize, turqoise);
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}