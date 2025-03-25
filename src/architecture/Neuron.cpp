#include "Neuron.hpp"
#include "Synapse.hpp"
#include "generateId.hpp"
#include "ActivationType.hpp"

#include <vector>

Neuron::Neuron(ActivationType type) : type(type), id(generateId()) {}

double Neuron::getStoredValue() {
    return this->storedValue;
}
        
void Neuron::addInput(std::shared_ptr<Synapse> input) {
    this->inputs.push_back(input);
}

std::vector<std::shared_ptr<Synapse>> Neuron::getInputs() {
    return this->inputs;
}

void Neuron::addOutput(std::shared_ptr<Synapse> output) {
    this->outputs.push_back(output);
}

void Neuron::setWeightedSum(double newWeightedSum) {
    this->weightedSum = newWeightedSum;
}

void Neuron::forward() {
    this->calculateWeightedSum();
    this->storedValue = this->activate(this->weightedSum);
    for (int i=0; i < this->outputs.size(); i++) {
        this->outputs[i]->forward();
    }
}

void Neuron::forward(double input) {
    this->storedValue = input;
    for (int i=0; i < this->outputs.size(); i++) {
        this->outputs[i]->forward();
    }
}

void Neuron::calculateWeightedSum() {
    this->weightedSum = 0.0;
    for (int i=0; i < this->inputs.size(); i++) {
        this->weightedSum += this->inputs[i]->getStoredValue();
    }
}

double Neuron::activate(double x) {
    switch (this->type) {
        case ActivationType::SIGMOID:
            return this->sigmoid(x);
        case ActivationType::RELU:
            return this->reLU(x);
        default:
            return x;
    }
}

double Neuron::dx_activate(double x) {
    switch (this->type) {
        case ActivationType::SIGMOID:
            return this->dx_sigmoid(x);
        case ActivationType::RELU:
            return this->dx_reLU(x);
        default:
            return 1;
    }
}

double Neuron::sigmoid(double x) {
    return 1 / (1 + std::exp(-x));
}

double Neuron::dx_sigmoid(double x) {
    double y = this->sigmoid(x);
    return y * (1 - y);
}

double Neuron::reLU(double x) {
    return std::max(0.0, x);
}

double Neuron::dx_reLU(double x) {
    return x > 0 ? 1.0 : 0.0;
}

void Neuron::backward(double gradient) {
    double delta = this->dx_activate(this->weightedSum) * gradient;
    for (int i=0; i < this->inputs.size(); i++) {
        this->inputs[i]->backward(delta);
    }
}
