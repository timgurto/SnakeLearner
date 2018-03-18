# SnakeLearner
An attempt to evolve a neural network that can play Snake

The most interesting parts to experiment with:
 - The dimensions of the neural networks (`main()`, when populating the first generation)
 - How the neurons mutate as part of the evolution process (`Neuron::mutate()` and perhaps `Network::mutate()`)
 - How the game state is represented to each neural network (`Game::compileGameStateIntoInputVector()`)
