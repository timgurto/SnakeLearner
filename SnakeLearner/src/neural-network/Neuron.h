#pragma once

#include <vector>

struct Neuron {
    using Bias = double;
    using Weight = double;
    using Weights = std::vector<Weight>;

    Bias bias{ 0 };
    Weights weights;

    Neuron(size_t previousColumnHeight);
};

using Column = std::vector<Neuron>;
