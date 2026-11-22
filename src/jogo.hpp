#pragma once
#include "nave.hpp"
#include "obstaculo.hpp"
#include "alien.hpp"
#include "navemisteriosa.hpp"

class Jogo{
    public:
        Jogo();
        ~Jogo();
        void desenha();
        void atualiza();
        void inputUsuario();
        bool runJogo;
        int vidas;
        int pontuacao;
        int pontuacaoMaxima;
    private:
        void apagaLaserInativo();
        std::vector<Obstaculo> CriarObstaculos();
        std::vector<Alien> CriarAliens();
        void MoveAliens();
        void MoveAliensY(int distancia);
        void AlienAtiraLaser();
        void ColisaoRetangulo();
        void GameOver();
        void Restart();
        void iniciaJogo();
        void checarPontMaxima();
        void salvaPontMaximaArquivo(int pontuacaoMaxima);
        int carregaPontMaximaArquivo();
        Nave nave;
        std::vector<Obstaculo> obstaculos;
        std::vector<Alien> aliens;
        std::vector<Laser> laserAlien;
        int direcaoAliens;
        constexpr static float intervaloAlienAtiraLaser = 0.35;
        float tempoUltimoAlienAtirou;
        NaveMisteriosa naveMisteriosa;
        float intervaloSpawnMS;
        float tempoUltimoSpawn;
    };