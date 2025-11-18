#pragma once
#include <string>

namespace Modelo {

    struct Medico {
        int id_licencia;
        std::string nombre;
        std::string especialidad;
        bool disponible;

        Medico() : id_licencia(0), disponible(true) {}

        // Para comparar si un médico es "menor" que otro (por su ID)
        // Necesario para ordenarlos en el Árbol AVL
        bool operator<(const Medico& otro) const {
            return this->id_licencia < otro.id_licencia;
        }

        // Para saber si son iguales
        bool operator==(const Medico& otro) const {
            return this->id_licencia == otro.id_licencia;
        }
    };
}