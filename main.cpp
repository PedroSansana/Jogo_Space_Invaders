#include <raylib.h>
int main(){
    int larguraJanela = 720;
    int alturaJanela = 700;
    InitWindow(larguraJanela, alturaJanela, "Space Invaders");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        EndDrawing();
    }
    CloseWindow();
}