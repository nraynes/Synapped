#include "Neuron.h"
#include "Synapse.h"
#include "generateId.h"

#include <vector>

Neuron::Neuron(int type) : type(type), id(generateId()) {}

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
    if (this->type == 1) {
        return this->sigmoid(x);
    } else if (this->type == 2) {
        return this->reLU(x);
    } else {
        return x;
    }
}

double Neuron::dx_activate(double x) {
    if (this->type == 1) {
        return this->dx_sigmoid(x);
    } else if (this->type == 2) {
        return this->dx_reLU(x);
    } else {
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
