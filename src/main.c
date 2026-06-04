#include <raylib.h>
#define MaxLength 625
Color turqoise={64, 224, 208, 255};

typedef struct
{
    Vector2 body[MaxLength];
    int length;
    Vector2 direction;

} Snake;


typedef struct
{
    Vector2 position;
    Texture2D texture;
}Food;
 void DrawFood(const Food* food,int cellsize, Color color){
    DrawTexture(food->texture,(int)(food->position.x*cellsize), (int)(food->position.y*cellsize), color );
 }
Vector2 randompos(int cellrow){
    float x=GetRandomValue(0,cellrow-1);
    float y=GetRandomValue(0,cellrow-1);
    return (Vector2){x,y};
}

int main() {
    int cellrow= 25;
    int cellsize=30;
    int tot=cellrow*cellsize;
    InitWindow(tot,tot,"MyBigSnake");
    SetTargetFPS(60);
    Food food;
    food.position=randompos(cellrow);
    Image image=LoadImage("3t.png");
    ImageAlphaCrop(&image,0.0f);
    ImageResize(&image, cellsize, cellsize);
    food.texture=LoadTextureFromImage(image);
    UnloadImage(image);
    Snake snake;
    snake.length=3;
    snake.body[0]=(Vector2){7,12};
    snake.body[1]=(Vector2){6,12};
    snake.body[2]=(Vector2){5,12};
    while(WindowShouldClose() == false){
        BeginDrawing();
        for (int i = 0; i < snake.length ; i++)
        {
            Color snakecolor= (i==0)? BLACK:WHITE;
            DrawRectangle(snake.body[i].x*cellsize,snake.body[i].y*cellsize,cellsize, cellsize, snakecolor);
        }
        
        ClearBackground(turqoise);
        DrawFood(&food, cellsize, WHITE);
        EndDrawing();
        
    }
    UnloadTexture(food.texture);
    CloseWindow();
    return 0;
}