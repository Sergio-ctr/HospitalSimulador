#include "pch.h"
#include "CppUnitTest.h"
#include "../hospital_lib/include/Interfaces/MiPila.hpp "

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnitarias {
    TEST_CLASS(PruebaPila) {
public:
    TEST_METHOD(PruebaPilaFunciona) {
        MiPila<int> pila;

        // Probar que inicia vacía
        Assert::IsTrue(pila.isEmpty());

        // Probar push y top
        pila.push(10);
        Assert::AreEqual(10, pila.top());

        pila.push(20);
        Assert::AreEqual(20, pila.top());

        // Probar pop
        Assert::AreEqual(20, pila.pop());
        Assert::AreEqual(10, pila.pop());
        Assert::IsTrue(pila.isEmpty());
    }
    };
}