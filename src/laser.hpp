#pragma once
#include <raylib.h>

class Laser{
    public:
        Laser(Vector2 posicao, int velocidade);
        void Atualiza();
        void Desenha();
        Rectangle GeraRetangulo();
        bool ativo;
    private:
        Vector2 posicao;
        int velocidade;
};