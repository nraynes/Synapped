#include "NeuralNetwork.h"
#include "Neuron.h"
#include "Synapse.h"
#include "log.h"
#include "generateRandomNumber.h"

#include <iostream>
#include <vector>
#include <memory>

NeuralNetwork::NeuralNetwork(int num_inputs, int num_layers, int num_neurons_per_layer, int num_outputs) {
    this->initialize_layer(num_inputs, 2);
    for (int i=0; i < num_layers; i++) {
        this->initialize_layer(num_neurons_per_layer, 2);
    }
    this->initialize_layer(num_outputs, 3);
    this->initialize_synapses();
    this->inputLayer = this->layers[0];
    this->outputLayer = this->layers[this->layers.size()-1];
    this->overallLoss = 0;
    int neuron_count = 0;
    for (int i=0; i < this->layers.size(); i++) {
        for (int j=0; j < this->layers[i].size(); j++) {
            neuron_count++;
        }
    }
}

void NeuralNetwork::initialize_layer(int size, int type) {
    std::vector<std::shared_ptr<Neuron>> layer;
    for (int i=0; i < size; i++) {
        std::shared_ptr<Neuron> new_neuron = std::make_shared<Neuron>(Neuron(type));
        layer.push_back(new_neuron);
    }
    this->layers.push_back(layer);
}

void NeuralNetwork::initialize_synapses() {
    for (int i=1; i < this->layers.size(); i++) {
        for (int f=0; f < this->layers[i].size(); f++) {
            for (int b=0; b < this->layers[i-1].size(); b++) {
                std::shared_ptr<Synapse> synapse = std::make_shared<Synapse>(Synapse(this->layers[i-1][b], this->layers[i][f], generateRandomNumber(), 0.05, generateRandomNumber()));
                this->layers[i-1][b]->addOutput(synapse);
                this->layers[i][f]->addInput(synapse);
                this->synapses.push_back(synapse);
            }
        }
    }
}

void NeuralNetwork::forward(std::vector<double> inputs) {
    if (inputs.size() == this->inputLayer.size()) {
        for (int i=0; i < this->inputLayer.size(); i++) {
            this->inputLayer[i]->forward(inputs[i]);
        }
    } else {
        log("ERROR: Input vector size " + std::to_string(inputs.size()) + " does match input layer size " + std::to_string(this->inputLayer.size()) + ".");
    }
}

void NeuralNetwork::displayOutput() {
    std::string message = "Outputs:";
    for (int i=0; i < this->outputLayer.size(); i++) {
        message += " " + std::to_string(this->outputLayer[i]->getStoredValue());
    }
    log(message);
}

void NeuralNetwork::backward(std::vector<double>& expectedOutputs) {
    if (this->outputLayer.size() == expectedOutputs.size()) {
        this->calculateLoss(expectedOutputs);
        this->calculateAccuracy(expectedOutputs);
        for (int i=0; i < this->outputLayer.size(); i++) {
            double output = this->outputLayer[i]->getStoredValue();
            double lossGradient = this->calculateLossGradient(output, expectedOutputs[i]);
            this->outputLayer[i]->backward(lossGradient);
        }
    } else {
        log("Expected outputs is not the same size as output layer.");
    }
}

void NeuralNetwork::displayLoss() {
    log("Overall Loss: " + std::to_string(this->overallLoss));
}

void NeuralNetwork::displayAccuracy() {
    log("Overall Accuracy: " + std::to_string(this->overallAccuracy));
}

void NeuralNetwork::calculateLoss(std::vector<double>& expectedOutputs) {
    this->overallLoss = 0;
    for (int i=0; i < this->outputLayer.size(); i++) {
        this->overallLoss += std::pow(expectedOutputs[i] - this->outputLayer[i]->getStoredValue(), 2) / 2;
    }
}

void NeuralNetwork::calculateAccuracy(std::vector<double>& expectedOutputs) {
    this->overallAccuracy = 0;
    for (int i=0; i < this->outputLayer.size(); i++) {
        this->overallAccuracy += std::abs((expectedOutputs[i] - this->outputLayer[i]->getStoredValue()) / std::max(1.0, std::abs(expectedOutputs[i])));
    }
    this->overallAccuracy = this->overallAccuracy / this->outputLayer.size();
}

double NeuralNetwork::getLoss() {
    return this->overallLoss;
}

double NeuralNetwork::calculateLossGradient(double& predicted, double& expected) {
    return predicted - expected;
}

void NeuralNetwork::train(std::vector<std::array<std::vector<double>, 2>>& trainingData) {
    log("TRAINING");
    int reportThreshold = trainingData.size() / 5;
    double init_loss_train = this->overallLoss;
    double sum_loss_difference = 0;
    for (int i=0; i < trainingData.size(); i++) {
        this->forward(trainingData[i][0]);
        this->backward(trainingData[i][1]);
        if (i % reportThreshold == 0) {
            this->displayOutput();
            std::cout << "Expected Output: " << trainingData[i][1][0] << std::endl;
            this->displayAccuracy();
        }
        sum_loss_difference += this->overallLoss - init_loss_train;
    }
    double end_loss_train = this->overallLoss;
    log("Average Loss Reduction: " + std::to_string(sum_loss_difference / trainingData.size()));
    log("Final Loss Reduction: " + std::to_string(end_loss_train - init_loss_train));
}

void NeuralNetwork::test(std::vector<std::array<std::vector<double>, 2>>& testingData) {
    log("TESTING");
    for (int i=0; i < testingData.size(); i++) {
        std::vector<double>& data = testingData[i][0];
        std::vector<double>& expectedOutput = testingData[i][1];
        this->forward(data);
        this->calculateLoss(expectedOutput);
        std::cout << "Expected Output: " << expectedOutput[0] << std::endl;
        this->displayOutput();
        this->displayAccuracy();
    }
}

std::string NeuralNetwork::displayNetwork() {
    std::string full = "";
    for (int i=1; i < this->layers.size(); i++) {
        for (int j=0; j < this->layers[i].size(); j++) {
            std::string line = "";
            for (int k=0; k < this->layers[i][j]->getInputs().size(); k++) {
                line += std::to_string(this->layers[i][j]->getInputs()[k]->getWeight()) + " ";
            }
            log(line);
            full += line;
        }
    }
    return full;
}
