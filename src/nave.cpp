#include "nave.hpp"

Nave::Nave(){
    imagem = LoadTexture("graficos/nave.png");
    posicao.x = (GetScreenWidth() - imagem.width)/2;
    posicao.y = GetScreenHeight() - imagem.height;
    tempoUltimoTiro = 0.0;
}

Nave::~Nave(){
    UnloadTexture(imagem);
}

void Nave::desenha(){
    DrawTextureV(imagem, posicao, WHITE);
}

void Nave::esquerda(){
    posicao.x -= 7;
    if(posicao.x < 0){
        posicao.x = 0;
    }
}

void Nave::direita()
{
    posicao.x += 7;
    if(posicao.x > GetScreenWidth() - imagem.width){
        posicao.x = GetScreenWidth() - imagem.width;
    }
}

void Nave::atiralaser()
{
    if(GetTime() - tempoUltimoTiro >= 0.35){
        lasers.push_back(Laser({posicao.x + imagem.width/2 -2, posicao.y}, -6));
        tempoUltimoTiro = GetTime();
    }
}

Rectangle Nave::GeraRetangulo()
{
    return {posicao.x, posicao.y, float(imagem.width), float(imagem.height)};
}
