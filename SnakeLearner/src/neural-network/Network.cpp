#include <cassert>

#include "Network.h"

namespace NeuralNetwork {
    Network::Network(Layers layers) {
        assert(layers.size() >= 2);

        _inputSize = layers.front();

        auto it = layers.begin();
        auto previousColumnSize = *it;
        ++it;
        for (; it != layers.end(); ++it) {
            auto thisColumn = Column{};
            for (auto i = 0; i != *it; ++i)
                thisColumn.push_back(Neuron{ previousColumnSize });
            _columns.push_back(thisColumn);

            previousColumnSize = *it;
        }
    }

    Values NeuralNetwork::Network::calculate(Values input) const {
        assert(input.size() == _inputSize);

        // Inputs -> first column of neurons
        auto it = _columns.begin();
        for (auto &neuron : *it)
            neuron.calculate(input);

        auto *previousColumn = &*it;
        ++it;
        for (; it != _columns.end(); ++it) {
            for (auto &neuron : *it)
                neuron.calculate(*previousColumn);
            previousColumn = &*it;
        }

        auto ret = Values{};
        const auto &lastColumn = _columns.back();
        for (auto &neuron : lastColumn)
            ret.push_back(neuron.output);
        return ret;
    }

}
