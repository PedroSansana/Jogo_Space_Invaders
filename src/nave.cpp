#include "nave.hpp"

Nave::Nave(){
    imagem = LoadTexture("graficos/nave.png");
    posicao.x = (GetScreenWidth() - imagem.width)/2;
    posicao.y = GetScreenHeight() - imagem.height - 100;
    tempoUltimoTiro = 0.0;
    somLaser = LoadSound("sons/laser.ogg");
}

Nave::~Nave(){
    UnloadTexture(imagem);
    UnloadSound(somLaser);
}

void Nave::desenha(){
    DrawTextureV(imagem, posicao, WHITE);
}

void Nave::esquerda(){
    posicao.x -= 7;
    if(posicao.x < 25){
        posicao.x = 25;
    }
}

void Nave::direita()
{
    posicao.x += 7;
    if(posicao.x > GetScreenWidth() - imagem.width - 25){
        posicao.x = GetScreenWidth() - imagem.width - 25;
    }
}

void Nave::atiralaser()
{
    if(GetTime() - tempoUltimoTiro >= 0.35){
        lasers.push_back(Laser({posicao.x + imagem.width/2 -2, posicao.y}, -6));
        tempoUltimoTiro = GetTime();
        PlaySound(somLaser);
    }
}

void Nave::Restart()
{
    posicao.x = (GetScreenWidth() - imagem.width)/2.0f;
    posicao.y = GetScreenHeight() - imagem.height - 100;
    lasers.clear();
}

Rectangle Nave::GeraRetangulo()
{
    return {posicao.x, posicao.y, float(imagem.width), float(imagem.height)};
}
