#include "navemisteriosa.hpp"

NaveMisteriosa::NaveMisteriosa()
{
    imagem = LoadTexture("graficos/navemisteriosa.png");
    vivo = false;
}

NaveMisteriosa::~NaveMisteriosa(){
    UnloadTexture(imagem);
}

void NaveMisteriosa::Spawna(){
    posicao.y = 90;
    int lado = GetRandomValue(0, 1);
    if(lado == 0){
        posicao.x = 0;
        velocidade = 3;
    }else{
        posicao.x = GetScreenWidth() - imagem.width;
        velocidade = -3;
    }
    vivo = true;
}

Rectangle NaveMisteriosa::GeraRetangulo()
{
    if(vivo){
        return {posicao.x, posicao.y, float(imagem.width), float(imagem.height)};
    }else{
        return {posicao.x, posicao.y, 0, 0};
    }
}

void NaveMisteriosa::Atualiza(){
    if(vivo){
        posicao.x += velocidade;
        if(posicao.x > GetScreenWidth() - imagem.width || posicao.x < 0){
            vivo = false;
        }
    }
}

void NaveMisteriosa::Desenha(){
    if(vivo){
    DrawTextureV(imagem, posicao, WHITE);
    }
}