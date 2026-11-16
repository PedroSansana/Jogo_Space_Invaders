#include "nave.hpp"
Nave::Nave(){
    imagem = LoadTexture("graficos/nave.png");
    posicao.x = (GetScreenWidth() - imagem.width)/2;
    posicao.y = (GetScreenHeight() - imagem.height)/2;
}
Nave::~Nave(){
    UnloadTexture(imagem);
}
void Nave::desenha(){
    DrawTextureV(imagem, posicao, WHITE);
}
void Nave::esquerda(){
    posicao.x -= 7;
}
void Nave::direita(){
    posicao.x += 7;
}