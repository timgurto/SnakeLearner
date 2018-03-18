#pragma once

#include <vector>

#include "NeuralNetwork.h"

namespace NeuralNetwork {

    struct Neuron;
    using Column = std::vector<Neuron>;

    struct Neuron {
        using Bias = double;
        using Weight = double;
        using Weights = std::vector<Weight>;

        Bias bias{ 0 };
        Weights weights;

        mutable Value output;
        void calculate(const Column &input) const;
        void calculate(const Values &input) const; // For the first column of neurons

        static double sigmoid(double raw);

        Neuron(size_t previousColumnHeight);
    };

}
