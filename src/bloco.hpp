#pragma once
#include <raylib.h>
class Bloco{
    public:
        Bloco(Vector2 posicao);
        void Desenha();
        Rectangle GeraRetangulo();
    private:
    Vector2 posicao;
};