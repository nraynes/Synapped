#pragma once

#include <vector>
#include <memory>

class Neuron;
class Synapse;

class NeuralNetwork {
    private:
        std::vector<std::shared_ptr<Synapse>> synapses;
        double overallLoss;
        double overallAccuracy;

    public:
        std::vector<std::vector<std::shared_ptr<Neuron>>> layers;
        std::vector<std::shared_ptr<Neuron>> inputLayer;
        std::vector<std::shared_ptr<Neuron>> outputLayer;
        NeuralNetwork(int num_inputs, int num_layers, int num_neurons_per_layer, int num_outputs);

        void initialize_layer(int size, int type);

        void initialize_synapses();

        void forward(std::vector<double> inputs);

        void displayOutput();

        void backward(std::vector<double>& expectedOutputs);

        void displayLoss();

        void displayAccuracy();

        void calculateLoss(std::vector<double>& expectedOutputs);
        
        void calculateAccuracy(std::vector<double>& expectedOutputs);

        double getLoss();

        double calculateLossGradient(double& predicted, double& expected);

        void train(std::vector<std::array<std::vector<double>, 2>>& trainingData);

        void test(std::vector<std::array<std::vector<double>, 2>>& testingData);

        std::string displayNetwork();
};