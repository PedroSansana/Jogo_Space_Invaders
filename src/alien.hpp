#pragma once
#include <raylib.h>

class Alien{
    public:
        Alien(int tipo, Vector2 posicao);
        void Desenha();
        void Atualiza(int direcao);
        int GetTipo();
        static void UnloadImagens();
        static Texture2D imagemAlien[3];
        int tipo;
        Vector2 posicao;
    private:
};