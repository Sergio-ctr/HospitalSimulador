#pragma once
#include <string>

namespace Interfaces {

    template <typename T>
    class IPersistencia {
    public:
        virtual ~IPersistencia() {}

        // Guarda la estructura completa en disco
        virtual void save(const T& dataStructure, std::string fileName) = 0;

        // Carga del disco
        virtual void load(T& dataStructure, std::string fileName) = 0;
    };
}