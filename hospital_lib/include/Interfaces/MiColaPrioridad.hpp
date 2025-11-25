#pragma once
#include <queue>
#include <stdexcept>

// Copia PEGADA de la interfaz IPriorityQueue
namespace Interfaces {
    template <typename T>
    class IPriorityQueue {
    public:
        virtual ~IPriorityQueue() {}
        virtual void enqueue(const T& item, int prioridad) = 0;
        virtual T dequeue() = 0;
        virtual T& peek() = 0;
        virtual bool isEmpty() const = 0;
    };
}

// Implementación
template <typename T>
class MiColaPrioridad : public Interfaces::IPriorityQueue<T> {
private:
    std::priority_queue<std::pair<int, T>> elementos;

public:
    void enqueue(const T& item, int prioridad) override {
        elementos.push({ -prioridad, item });
    }

    T dequeue() override {
        if (elementos.empty()) {
            throw std::runtime_error("Cola de prioridad vacía");
        }
        T elemento = elementos.top().second;
        elementos.pop();
        return elemento;
    }

    T& peek() override {
        if (elementos.empty()) {
            throw std::runtime_error("Cola de prioridad vacía");
        }
        return const_cast<T&>(elementos.top().second);
    }

    bool isEmpty() const override {
        return elementos.empty();
    }
};