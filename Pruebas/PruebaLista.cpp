#include "pch.h"
#include "CppUnitTest.h"
#include "../hospital_lib/MiLista.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnitarias {
    TEST_CLASS(PruebaLista) {
public:
    TEST_METHOD(PruebaListaFunciona) {
        MiLista<std::string> lista;

        Assert::IsTrue(lista.isEmpty());
        Assert::AreEqual(0, lista.size());

        lista.add("Evento 1");
        lista.add("Evento 2");
        lista.add("Evento 3");

        Assert::AreEqual(3, lista.size());
        Assert::IsFalse(lista.isEmpty());

        Assert::AreEqual(std::string("Evento 1"), lista.get(0));
        Assert::AreEqual(std::string("Evento 2"), lista.get(1));
        Assert::AreEqual(std::string("Evento 3"), lista.get(2));

        lista.remove(1); // Eliminar "Evento 2"
        Assert::AreEqual(2, lista.size());
        Assert::AreEqual(std::string("Evento 1"), lista.get(0));
        Assert::AreEqual(std::string("Evento 3"), lista.get(1));
    }

    TEST_METHOD(PruebaListaIndicesInvalidos) {
        MiLista<int> lista;
        lista.add(10);

        auto func = [&lista]() { lista.get(5); };
        Assert::ExpectException<std::runtime_error>(func);

        auto func2 = [&lista]() { lista.remove(5); };
        Assert::ExpectException<std::runtime_error>(func2);
    }
    };
}