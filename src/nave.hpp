#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>
class Nave{
    public:
        Nave();
        ~Nave(); 
        void desenha();
        void direita();
        void esquerda();
        void atiralaser();
        Rectangle GeraRetangulo();
        std::vector<Laser> lasers;
    private:
    Texture2D imagem;
    Vector2 posicao;
    double tempoUltimoTiro;
};