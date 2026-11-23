#include "jogo.hpp"
#include <iostream>
#include <fstream>
Jogo::Jogo()
{
    musica = LoadMusicStream("sons/musica.ogg");
    somExplosao = LoadSound("sons/explosao.ogg");
    PlayMusicStream(musica);

    iniciaJogo();
}
Jogo::~Jogo(){
    Alien::UnloadImagens();
    UnloadMusicStream(musica);
    UnloadSound(somExplosao);
}

void Jogo::atualiza(){
    if(runJogo){

        double tempoAtual = GetTime();
        if(tempoAtual - tempoUltimoSpawn > intervaloSpawnMS){
            naveMisteriosa.Spawna();
            tempoUltimoSpawn = GetTime();
            intervaloSpawnMS = GetRandomValue(10, 20);
        }
        for(auto& laser: nave.lasers){
            laser.Atualiza();
        }
        MoveAliens();

        AlienAtiraLaser();
        for(auto& laser: laserAlien){
            laser.Atualiza();
        }

        apagaLaserInativo();

        naveMisteriosa.Atualiza();

        ColisaoRetangulo();
    } else {
        if(IsKeyDown(KEY_ENTER)){
            Restart();
            iniciaJogo();
        }
    }  
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

    naveMisteriosa.Desenha();
}

void Jogo::inputUsuario(){
    if(runJogo){
        if(IsKeyDown(KEY_LEFT)){
            nave.esquerda();
        }else if(IsKeyDown(KEY_RIGHT)){
            nave.direita();
        }else if(IsKeyDown(KEY_SPACE)){
            nave.atiralaser();
        }
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
        obstaculos.push_back(Obstaculo({distanciaX, float (GetScreenHeight() - 200)}));
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
        if(alien.posicao.x + alien.imagemAlien[alien.tipo - 1].width > GetScreenWidth() - 25){
            direcaoAliens = -1;
            MoveAliensY(4);
        }
        if(alien.posicao.x < 25){
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

void Jogo::ColisaoRetangulo()
{
    //Lasers
    for(auto& laser: nave.lasers){
        auto i = aliens.begin();
        while(i != aliens.end()){
            if(CheckCollisionRecs(i -> GeraRetangulo(), laser.GeraRetangulo())){
                PlaySound(somExplosao);
                if(i -> tipo == 1){
                    pontuacao += 100;
                }else if(i -> tipo == 2){
                    pontuacao += 200;
                }else if(i -> tipo == 3){
                    pontuacao += 300;
                }

                checarPontMaxima();
                i = aliens.erase(i);
                laser.ativo = false;
            }else {
                ++i;
            }
        }
        for(auto& obstaculo: obstaculos){
            auto i = obstaculo.blocos.begin();
            while(i != obstaculo.blocos.end()){
                if(CheckCollisionRecs(i ->  GeraRetangulo(), laser.GeraRetangulo())){
                    i = obstaculo.blocos.erase(i);
                    laser.ativo = false;
                }else{
                    ++i;
                }
            }
        }
        if(CheckCollisionRecs(naveMisteriosa.GeraRetangulo(), laser.GeraRetangulo())){
            PlaySound(somExplosao);
            naveMisteriosa.vivo = false;
            laser.ativo = false;
            pontuacao += 500;
            checarPontMaxima();
        }
    }
    
    //Laser dos aliens
    for(auto& laser: laserAlien){
        if(CheckCollisionRecs(laser.GeraRetangulo(), nave.GeraRetangulo())){
            laser.ativo = false;
            vidas--;
            if(vidas == 0){
                GameOver();
            }
        }
         for(auto& obstaculo: obstaculos){
            auto i = obstaculo.blocos.begin();
            while(i != obstaculo.blocos.end()){
                if(CheckCollisionRecs(i ->  GeraRetangulo(), laser.GeraRetangulo())){
                    i = obstaculo.blocos.erase(i);
                    laser.ativo = false;
                }else{
                    ++i;
                }
            }
        }
    }

    //Colisão de aliens (sprite) com os obstáculos
    for(auto& alien: aliens){
        for(auto& obstaculo: obstaculos){
            auto i = obstaculo.blocos.begin();
            while(i != obstaculo.blocos.end()){
                if(CheckCollisionRecs(i -> GeraRetangulo(), alien.GeraRetangulo())){
                    i = obstaculo.blocos.erase(i);
                }else {
                    i++;
                }
            }
        }
        if(CheckCollisionRecs(alien.GeraRetangulo(), nave.GeraRetangulo())){
            GameOver();
        }
    }
}

void Jogo::GameOver()
{
    runJogo = false;
}

void Jogo::iniciaJogo()
{
    obstaculos = CriarObstaculos();
    aliens = CriarAliens();
    direcaoAliens = 1;
    tempoUltimoAlienAtirou = 0;
    intervaloSpawnMS = GetRandomValue(10, 20);
    vidas = 3;
    runJogo = true;
    tempoUltimoSpawn = 0;
    pontuacao = 0;
    pontuacaoMaxima = carregaPontMaximaArquivo();
}

void Jogo::checarPontMaxima()
{
    if(pontuacao > pontuacaoMaxima){
        pontuacaoMaxima = pontuacao;   
        salvaPontMaximaArquivo(pontuacaoMaxima); 
    }
}

void Jogo::salvaPontMaximaArquivo(int pontuacaoMaxima)
{
    std::ofstream arquivoPontMaxima("pontuacaoMaxima.txt");
    if(arquivoPontMaxima.is_open()){
        arquivoPontMaxima << pontuacaoMaxima;
        arquivoPontMaxima.close();
    }else{
        std::cerr << "Erro ao salvar arquivo de pontuacao máxima" << std::endl;
    }
}

int Jogo::carregaPontMaximaArquivo()
{
    int pontMaximaCarregada = 0;
    std::ifstream arquivoPontMaxima("pontuacaoMaxima.txt");
    if(arquivoPontMaxima.is_open()){
        arquivoPontMaxima >> pontMaximaCarregada;
        arquivoPontMaxima.close();
    }else {
        std::cerr << "Erro ao carregar a pontuacao maxima do arquivo" << std::endl;
    }
    return pontMaximaCarregada;
}

void Jogo::Restart(){
    nave.Restart();
    aliens.clear();
    laserAlien.clear();
    obstaculos.clear();
}
