#include "pch.h"
#include "CppUnitTest.h"
#include "../hospital_lib/MiColaPrioridad.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnitarias {
    TEST_CLASS(PruebaColaPrioridad) {
public:
    TEST_METHOD(PruebaColaPrioridadFunciona) {
        MiColaPrioridad<std::string> cola;

        Assert::IsTrue(cola.isEmpty());

        cola.enqueue("Paciente rutinario", 2);
        cola.enqueue("Paciente urgente", 0);
        cola.enqueue("Paciente medio", 1);

        Assert::AreEqual(std::string("Paciente urgente"), cola.dequeue());
        Assert::AreEqual(std::string("Paciente medio"), cola.dequeue());
        Assert::AreEqual(std::string("Paciente rutinario"), cola.dequeue());
        Assert::IsTrue(cola.isEmpty());
    }
    };
}