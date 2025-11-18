// /hospital_lib/include/interfaces/IStack.hpp
#pragma once

namespace Interfaces {

    template <typename T>
    class IStack {
    public:
        // Destructor virtual: regla de C++ para clases abstractas [3, 4]
        virtual ~IStack() {}

        // Funciones "virtuales puras" (el '= 0') [5, 3]
        // Esto OBLIGA a tus compañeros a implementar estas funciones.
        // Es el "contrato".
        virtual void push(const T& item) = 0;
        virtual T pop() = 0;
        virtual T& top() = 0;
        virtual bool isEmpty() const = 0;
    };

} // namespace Interfaces
