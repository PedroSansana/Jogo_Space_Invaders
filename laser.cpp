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
void Laser::Atualiza(){
    posicao.y += velocidade;
    if(ativo){
        if(posicao.y > GetScreenHeight() || posicao.y < 0){
            ativo = false;
            std::cout << "Laser inativo " << std::endl;
        }
    }
}