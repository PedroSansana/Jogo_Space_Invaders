#include <raylib.h>
#include "jogo.hpp"

int main(){
    int deslocamento = 50;
    int larguraJanela = 750;
    int alturaJanela = 700;
    Color cinza = {29, 29, 27, 255};
    Color amarelo = {243, 216, 63, 255};
    InitWindow(larguraJanela + deslocamento, alturaJanela + 2 * deslocamento, "Space Invaders");

    Font fonte = LoadFontEx("fonte/monogram.ttf", 64, 0, 0);
    Texture2D imagemNave = LoadTexture("graficos/nave.png");

    SetTargetFPS(60);

    Jogo jogo;

    while(WindowShouldClose() == false){

        jogo.inputUsuario();
        jogo.atualiza();
        BeginDrawing();
            ClearBackground(cinza);
            DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, amarelo);
            DrawLineEx({25, 730}, {775, 730}, 3, amarelo);
            if(jogo.runJogo){
                DrawTextEx(fonte, "NIVEL 1", {570, 740}, 34, 2, amarelo);
            }else {
                DrawTextEx(fonte, "GAME OVER", {570, 740}, 34, 2, amarelo);
            }
            float x = 50.0;
            for(int i = 0; i < jogo.vidas; i++){
                DrawTextureV(imagemNave, {x, 745}, WHITE);
                x += 50;
            }
            jogo.desenha();
        EndDrawing();
    }
    CloseWindow();
}