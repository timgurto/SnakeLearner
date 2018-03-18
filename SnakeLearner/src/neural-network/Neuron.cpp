#include "Neuron.h"

namespace NeuralNetwork {

    Neuron::Neuron(size_t previousColumnHeight){
        for (auto i = 0; i != previousColumnHeight; ++i)
            weights.push_back(1.0 * rand() / RAND_MAX );

        bias = 1.0 * rand() / RAND_MAX * previousColumnHeight;
    }
}
