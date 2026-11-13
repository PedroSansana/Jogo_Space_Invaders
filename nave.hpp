#pragma once
#include <raylib.h>
class Nave{
    public:
        Nave();
        ~Nave(); 
        void desenha();
        void direita();
        void esquerda();
        void atiralaser();
    private:
    Texture2D imagem;
    Vector2 posicao;
};