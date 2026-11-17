#pragma once
#include "nave.hpp"

class Jogo{
    public:
        Jogo();
        ~Jogo();
        void desenha();
        void atualiza();
        void inputUsuario();
    private:
    void apagaLaserInativo();
    Nave nave;
};