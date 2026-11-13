#include "nave.hpp"
Nave::Nave(){
    imagem = LoadTexture("graficos/nave.png");
    posicao.x = 100;
    posicao.y = 100;
}
Nave::~Nave(){
    UnloadTexture(imagem);
}
void Nave::desenha(){
    DrawTextureV(imagem, posicao, WHITE);
}