// Simulacion.cpp
#include <iostream>

// 1. INCLUIR TUS ARCHIVOS
// Si estas líneas no marcan error rojo, ¡tu configuración de Includes funcionó!
#include <models/Paciente.hpp>
#include <interfaces/IStack.hpp> 

int main() {
    std::cout << "--- INICIO DE PRUEBA DE ARQUITECTURA ---" << std::endl;

    // 2. PROBAR LOS MODELOS
    // Creamos un paciente para ver si la estructura "viaja" bien desde la librería
    Modelo::Paciente p1(1, "Juan Perez", Modelo::NivelUrgencia::Urgencia, "Dolor de pecho");
    std::cout << "Modelo cargado correctamente: " << p1.nombre << std::endl;

    // 3. PROBAR LAS INTERFACES
    // No podemos crear un objeto "IStack" porque es abstracto (es un contrato),
    // pero podemos declarar un PUNTERO. Si esto compila, el contrato es válido.
    Interfaces::IStack<int>* pilaDePrueba = nullptr;
    std::cout << "Interfaz IStack reconocida por el compilador." << std::endl;

    std::cout << "--- TODO FUNCIONA: Tus compañeros pueden empezar ---" << std::endl;

    // Pausa para que no se cierre la ventana
    std::cin.get();
    return 0;
}