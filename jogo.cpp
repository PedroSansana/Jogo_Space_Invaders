#include "jogo.hpp"

Jogo::Jogo()
{

}
Jogo::~Jogo(){

}

void Jogo::desenha(){
    nave.desenha();
}

void Jogo::inputUsuario(){
    if(IsKeyDown(KEY_LEFT)){
        nave.esquerda();
    }else if(IsKeyDown(KEY_RIGHT)){
        nave.direita();
    }
}