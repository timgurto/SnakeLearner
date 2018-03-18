#include <cassert>
#include <cmath>

#include "Neuron.h"

namespace NeuralNetwork {
    void Neuron::calculate(const Column & input) const {
        auto sum = 0.0;
        assert(input.size() == weights.size());

        for (auto i = 0; i != input.size(); ++i)
            sum += weights[i] * input[i].output;

        sum -= bias;

        output = sigmoid(sum);
    }

    void Neuron::calculate(const Values & input) const {
        auto sum = 0.0;
        assert(input.size() == weights.size());

        for (auto i = 0; i != input.size(); ++i)
            sum += input[i];

        sum -= bias;

        output = sigmoid(sum);
    }

    double Neuron::sigmoid(double raw) {
        auto result = 1.0 / (1.0 + exp(-raw));
        assert(result >= 0.0);
        assert(result <= 1.0);
        return result;
    }

    Neuron::Neuron(size_t previousColumnHeight){
        for (auto i = 0; i != previousColumnHeight; ++i)
            weights.push_back(1.0 * rand() / RAND_MAX );

        bias = 1.0 * rand() / RAND_MAX * previousColumnHeight;
    }
}
