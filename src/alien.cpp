#include "alien.hpp"
Texture2D Alien::imagemAlien[3] = {};

Alien::Alien(int tipo, Vector2 posicao)
{
    this -> tipo = tipo;
    this -> posicao = posicao;

    if(imagemAlien[tipo -1].id == 0){
    
        switch(tipo){
            case 1:
                imagemAlien[0] = LoadTexture("graficos/alien_1.png");
                break;
            case 2:
                imagemAlien[1] = LoadTexture("graficos/alien_2.png");
                break;
            case 3:
                imagemAlien[2] = LoadTexture("graficos/alien_3.png");
                break;
            default:
                imagemAlien[0] = LoadTexture("graficos/alien_1.png");
                break; 
        }
    }
}

void Alien::Desenha(){
    DrawTextureV(imagemAlien[tipo -1], posicao, WHITE);
}
int Alien::GetTipo(){
    return tipo;
}

void Alien::UnloadImagens()
{
    for(int i = 0; i < 3; i++){
        UnloadTexture(imagemAlien[i]);
    }
}

Rectangle Alien::GeraRetangulo()
{
    return {
        posicao.x, posicao.y,
        float(imagemAlien[tipo -1].width),
        float(imagemAlien[tipo -1].height)
    };
}

void Alien::Atualiza(int direcao){
    posicao.x += direcao;
}