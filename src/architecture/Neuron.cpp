#include "Neuron.hpp"
#include "Synapse.hpp"
#include "generateId.hpp"
#include "Activation.hpp"

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
    return Activation::activate(this->type, x);
}

double Neuron::dx_activate(double x) {
    return Activation::dx_activate(this->type, x);
}

void Neuron::backward(double gradient) {
    double delta = this->dx_activate(this->weightedSum) * gradient;
    for (int i=0; i < this->inputs.size(); i++) {
        this->inputs[i]->backward(delta);
    }
}
