#pragma once

#include "NeuralNetwork.h"
#include "Neuron.h"

namespace NeuralNetwork {

    class Network {
    public:
        Network(Layers layers = {}); // First = inputs; last = outputs

        Values calculate(Values input) const;

        void setScore(int score) const { _score = score; }

        void mutate();

        bool operator<(const Network &rhs) { return _score < rhs._score; }

    private:
        size_t _inputSize{ 0 };

        using Columns = std::vector<Column>;
        Columns _columns;

        mutable int _score{ 0 };
    };

}
