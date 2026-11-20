#pragma once
#include "nave.hpp"
#include "obstaculo.hpp"
#include "alien.hpp"

class Jogo{
    public:
        Jogo();
        ~Jogo();
        void desenha();
        void atualiza();
        void inputUsuario();
    private:
        void apagaLaserInativo();
        std::vector<Obstaculo> CriarObstaculos();
        std::vector<Alien> CriarAliens();
        void MoveAliens();
        void MoveAliensY(int distancia);
        void AlienAtiraLaser();
        Nave nave;
        std::vector<Obstaculo> obstaculos;
        std::vector<Alien> aliens;
        std::vector<Laser> laserAlien;
        int direcaoAliens;
        constexpr static float intervaloAlienAtiraLaser = 0.35;
        float tempoUltimoAlienAtirou;
};