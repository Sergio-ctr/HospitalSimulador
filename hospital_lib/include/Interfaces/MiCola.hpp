#pragma once
#include "IQueue.hpp"
#include <queue>
#include <stdexcept>

template <typename T>
class MiCola : public Interfaces::IQueue<T> {
private:
    std::queue<T> elementos;

public:
    void enqueue(const T& item) override {
        elementos.push(item);
    }

    T dequeue() override {
        if (elementos.empty()) {
            throw std::runtime_error("Cola vacía");
        }
        T frente = elementos.front();
        elementos.pop();
        return frente;
    }

    T& peek() override {
        if (elementos.empty()) {
            throw std::runtime_error("Cola vacía");
        }
        return elementos.front();
    }

    bool isEmpty() const override {
        return elementos.empty();
    }
};