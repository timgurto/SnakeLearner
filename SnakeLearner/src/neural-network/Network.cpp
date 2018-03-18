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
            auto thisColumn = Column{ *it, Neuron{ previousColumnSize } };
            _columns.push_back(thisColumn);

            previousColumnSize = *it;
        }
    }

    Values NeuralNetwork::Network::calculate(Values input) const {
        assert(input.size() == _inputSize);

        auto ret = Values{};
        for (auto i = 0; i != 4; ++i)
            ret.push_back(1.0 * rand() / RAND_MAX);
        return ret;
    }

}
