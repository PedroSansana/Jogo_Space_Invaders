#include "laser.hpp"
#include <iostream>
Laser::Laser(Vector2 posicao, int velocidade){
    this -> posicao = posicao;
    this -> velocidade = velocidade;
    ativo = true;
}
void Laser::Desenha(){
    if(ativo){
        DrawRectangle(posicao.x, posicao.y, 4, 15, {243, 216, 63, 255});
    }
}
Rectangle Laser::GeraRetangulo()
{
    Rectangle retangulo;
    retangulo.x = posicao.x;
    retangulo.y = posicao.y;
    retangulo.width = 4;
    retangulo.height = 15;
    return retangulo;
}
void Laser::Atualiza()
{
    posicao.y += velocidade;
    if(ativo){
        if(posicao.y > GetScreenHeight() - 100 || posicao.y < 25){
            ativo = false;
        }
    }
}