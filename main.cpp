#include <raylib.h>
int main(){
    int larguraJanela = 720;
    int alturaJanela = 700;
    Color cinza = {29, 29, 27, 255};
    InitWindow(larguraJanela, alturaJanela, "Space Invaders");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
            ClearBackground(cinza);
        EndDrawing();
    }
    CloseWindow();
}