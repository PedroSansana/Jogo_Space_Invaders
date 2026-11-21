#pragma once
#include <raylib.h>

class NaveMisteriosa{
    public: 
        NaveMisteriosa();
        ~NaveMisteriosa();
        void Atualiza();
        void Desenha();
        void Spawna();
        bool vivo;
    private:
        Vector2 posicao;
        Texture2D imagem;
        int velocidade;
};