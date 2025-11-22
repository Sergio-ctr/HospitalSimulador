#include "pch.h"
#include "CppUnitTest.h"
#include "../hospital_lib/include/interfaces/MiCola.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnitarias {
    TEST_CLASS(PruebaCola) {
public:
    TEST_METHOD(PruebaColaFunciona) {
        MiCola<int> cola;

        // Probar que inicia vacía
        Assert::IsTrue(cola.isEmpty());

        // Probar enqueue y peek
        cola.enqueue(10);
        Assert::AreEqual(10, cola.peek());

        cola.enqueue(20);
        cola.enqueue(30);
        Assert::AreEqual(10, cola.peek()); // El frente sigue siendo 10 (FIFO)

        // Probar dequeue - Primero en entrar, primero en salir
        Assert::AreEqual(10, cola.dequeue());
        Assert::AreEqual(20, cola.dequeue());
        Assert::AreEqual(30, cola.dequeue());
        Assert::IsTrue(cola.isEmpty());
    }

    TEST_METHOD(PruebaColaVacia) {
        MiCola<std::string> cola;

        // Probar que lanza excepción cuando está vacía
        auto func = [&cola]() { cola.dequeue(); };
        Assert::ExpectException<std::runtime_error>(func);

        auto func2 = [&cola]() { cola.peek(); };
        Assert::ExpectException<std::runtime_error>(func2);
    }
    };
}