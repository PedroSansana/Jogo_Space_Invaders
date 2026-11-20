#include "jogo.hpp"
#include <iostream>
Jogo::Jogo()
{
    obstaculos = CriarObstaculos();
    aliens = CriarAliens();
    direcaoAliens = 1;
    tempoUltimoAlienAtirou = 0;
}
Jogo::~Jogo(){
    Alien::UnloadImagens();
}

void Jogo::atualiza(){
    for(auto& laser: nave.lasers){
        laser.Atualiza();
    }
    MoveAliens();

    AlienAtiraLaser();
    for(auto& laser: laserAlien){
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

    for(auto& alien: aliens){
        alien.Desenha();
    }

    for(auto& laser: laserAlien){
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
    for(auto i = laserAlien.begin(); i != laserAlien.end();){
        if(!i -> ativo){
            i = laserAlien.erase(i);
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

std::vector<Alien> Jogo::CriarAliens()
{
    std::vector<Alien> aliens;
    for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 11; coluna++){
            int tipoAlien;
            if(linha == 0){
                tipoAlien = 3;
            } else if(linha == 1 || linha == 2){
                tipoAlien = 2;
            }else{
                tipoAlien = 1;
            }
            float x = 75 + coluna *55;
            float y = 110 + linha *55;
            aliens.push_back(Alien(tipoAlien, {x, y}));
        }
    }
    return aliens;
}

void Jogo::MoveAliens(){
    for(auto& alien: aliens){
        if(alien.posicao.x + alien.imagemAlien[alien.tipo - 1].width > GetScreenWidth()){
            direcaoAliens = -1;
            MoveAliensY(4);
        }
        if(alien.posicao.x < 0){
            direcaoAliens = 1;
            MoveAliensY(4);
        }
        alien.Atualiza(direcaoAliens);
    }
}

void Jogo::MoveAliensY(int distancia)
{
    for(auto& alien: aliens){
        alien.posicao.y += distancia;
    }
}

void Jogo::AlienAtiraLaser()
{
    double tempoAtual = GetTime();
    if(tempoAtual - tempoUltimoAlienAtirou >= intervaloAlienAtiraLaser && !aliens.empty()){
        int random = GetRandomValue(0, aliens.size() - 1);
        Alien& alien = aliens[random];
        laserAlien.push_back(Laser({alien.posicao.x + alien.imagemAlien[alien.tipo - 1].width/2,   alien.posicao.y + alien.imagemAlien[alien.tipo - 1].height}, 6));
        tempoUltimoAlienAtirou = GetTime();
    }
}
