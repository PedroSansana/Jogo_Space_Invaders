#include "jogo.hpp"
#include <iostream>
Jogo::Jogo()
{
    obstaculos = CriarObstaculos();
}
Jogo::~Jogo(){

}

void Jogo::atualiza(){
    for(auto& laser: nave.lasers){
        laser.Atualiza();
    }
    apagaLaserInativo();
}

void Jogo::desenha(){
    nave.desenha();
    for(auto& laser: nave.lasers){
        laser.Desenha();
    }

    for(auto& obstaculo: obstaculos){
        obstaculo.Desenha();
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

std::vector<Obstaculo> Jogo::CriarObstaculos()
{
    int larguraObstaculo = Obstaculo::grade[0].size()*3;
    float vao = (GetScreenWidth() - (4 * larguraObstaculo))/5;
    
    for(int i = 0; i < 4; i++){
        float distanciaX = (i+1) * vao + i * larguraObstaculo;
        obstaculos.push_back(Obstaculo({distanciaX, float (GetScreenHeight() - 100)}));
    }
    return obstaculos;
}
