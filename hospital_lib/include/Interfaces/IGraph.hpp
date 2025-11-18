#pragma once
#include <string>
#include "IList.hpp" // Usamos nuestra propia interfaz de lista si queremos, o std::vector

namespace Interfaces {

    // T es el tipo de dato del nodo (ej: Sala)
    template <typename T>
    class IGraph {
    public:
        virtual ~IGraph() {}

        // Agrega una sala al mapa
        virtual void addNode(const T& node) = 0;

        // Conecta dos salas (con un peso/distancia)
        virtual void addEdge(const T& from, const T& to, int weight) = 0;

        // LA PARTE DIFÍCIL: Algoritmo BFS (Búsqueda en Anchura)
        // Debe devolver una lista con el camino paso a paso.
        // Usamos void* genérico o una lista de T para simplificar el contrato.
        // Aquí les pido que devuelvan un string con la ruta para probar fácil.
        virtual std::string bfs(const T& startNode, const T& targetNode) = 0;
    };
}