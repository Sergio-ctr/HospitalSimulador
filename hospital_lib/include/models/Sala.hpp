#pragma once
#include <string>

namespace Modelo {

    struct Sala {
        int id_sala;
        std::string nombre;
        bool ocupada;

        Sala() : id_sala(0), ocupada(false) {}

        // Necesario para el Árbol de Salas
        bool operator<(const Sala& otro) const {
            return this->id_sala < otro.id_sala;
        }

        bool operator==(const Sala& otro) const {
            return this->id_sala == otro.id_sala;
        }
    };
}