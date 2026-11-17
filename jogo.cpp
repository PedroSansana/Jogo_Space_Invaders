#include "jogo.hpp"
#include <iostream>
Jogo::Jogo()
{

}
Jogo::~Jogo(){

}

void Jogo::atualiza(){
    for(auto& laser: nave.lasers){
        laser.Atualiza();
    }
    apagaLaserInativo();
    std::cout << "Vector Size: " << nave.lasers.size() << std::endl;
}

void Jogo::desenha(){
    nave.desenha();
    for(auto& laser: nave.lasers){
        laser.Desenha();
    }
}

void Jogo::inputUsuario(){
    if(IsKeyDown(KEY_LEFT)){
        nave.esquerda();
    }else if(IsKeyDown(KEY_RIGHT)){
        nave.direita();
    }else if(IsKeyDown(KEY_SPACE)){
        nave.atiralaser();
    }
}

void Jogo::apagaLaserInativo()
{
    for(auto i = nave.lasers.begin(); i != nave.lasers.end();){
        if(!i -> ativo){
            i = nave.lasers.erase(i);
        }else{
            ++ i;
        }
    }
}
