#pragma once
#include "nave.hpp"
#include "obstaculo.hpp"

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
        Nave nave;
        std::vector<Obstaculo> obstaculos;
};