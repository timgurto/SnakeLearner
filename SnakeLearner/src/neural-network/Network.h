#pragma once

#include "NeuralNetwork.h"
#include "Neuron.h"

namespace NeuralNetwork {

    class Network {
    public:
        Network(Layers layers); // First = inputs; last = outputs

        Values calculate(Values input) const;

    private:
        size_t _inputSize{ 0 };

        using Columns = std::vector<Column>;
        Columns _columns;
    };

}
