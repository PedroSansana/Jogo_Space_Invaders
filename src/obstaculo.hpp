#pragma once
#include <vector>
#include "bloco.hpp"

class Obstaculo{
    public:
        Obstaculo(Vector2 posicao);
        void Desenha();
        Vector2 posicao;
        std::vector<Bloco> blocos;
        static std::vector<std::vector<int>> grade;
    private:

};