#include <raylib.h>
#include "jogo.hpp"

int main(){
    int larguraJanela = 720;
    int alturaJanela = 700;
    Color cinza = {29, 29, 27, 255};
    InitWindow(larguraJanela, alturaJanela, "Space Invaders");
    SetTargetFPS(60);

    Jogo jogo;

    while(WindowShouldClose() == false){

        jogo.inputUsuario();
        jogo.atualiza();
        BeginDrawing();
            ClearBackground(cinza);
            jogo.desenha();
        EndDrawing();
    }
    CloseWindow();
}