#pragma once
#include <raylib.h>

class Laser{
    public:
        Laser(Vector2 posicao, int velocidade);
        void Atualiza();
        void Desenha();
        bool ativo;
    private:
        Vector2 posicao;
        int velocidade;
};