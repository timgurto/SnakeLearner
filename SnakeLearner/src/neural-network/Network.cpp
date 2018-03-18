#include "Network.h"

namespace NeuralNetwork {

    Values NeuralNetwork::Network::calculate(Values input) const {
        auto ret = Values{};
        for (auto i = 0; i != 4; ++i)
            ret.push_back(1.0 * rand() / RAND_MAX);
        return ret;
    }

}
