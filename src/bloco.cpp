#include "bloco.hpp"

Bloco::Bloco(Vector2 posicao)
{
    this -> posicao = posicao;
}
void Bloco::Desenha(){
    DrawRectangle(posicao.x, posicao.y, 3, 3, {243, 216, 63, 255});
    
}