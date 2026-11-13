#include <raylib.h>
#include "nave.hpp"
int main(){
    int larguraJanela = 720;
    int alturaJanela = 700;
    Color cinza = {29, 29, 27, 255};
    InitWindow(larguraJanela, alturaJanela, "Space Invaders");
    SetTargetFPS(60);

    Nave nave;

    while(WindowShouldClose() == false){
        BeginDrawing();
            ClearBackground(cinza);
            nave.desenha();
        EndDrawing();
    }
    CloseWindow();
}