#pragma once
#include <vector>
#include <stdexcept>

// Copia de la interfaz IList directamente
namespace Interfaces {
    template <typename T>
    class IList {
    public:
        virtual ~IList() {}
        virtual void add(const T& item) = 0;
        virtual T get(int index) const = 0;
        virtual void remove(int index) = 0;
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
    };
}

// Implementación
template <typename T>
class MiLista : public Interfaces::IList<T> {
private:
    std::vector<T> elementos;

public:
    void add(const T& item) override {
        elementos.push_back(item);
    }

    T get(int index) const override {
        if (index < 0 || index >= elementos.size()) {
            throw std::runtime_error("Índice fuera de rango");
        }
        return elementos[index];
    }

    void remove(int index) override {
        if (index < 0 || index >= elementos.size()) {
            throw std::runtime_error("Índice fuera de rango");
        }
        elementos.erase(elementos.begin() + index);
    }

    int size() const override {
        return elementos.size();
    }

    bool isEmpty() const override {
        return elementos.empty();
    }
};