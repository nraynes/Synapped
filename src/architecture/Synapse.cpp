#include "Synapse.h"
#include "Neuron.h"

#include <memory>

Synapse::Synapse(
    std::shared_ptr<Neuron> in,
    std::shared_ptr<Neuron> out,
    double weight,
    double learnRate,
    double bias
) : 
inputNeuron(in),
outputNeuron(out),
storedValue(0.0),
weight(weight),
learnRate(learnRate),
bias(bias) {}

void Synapse::setInputNeuron(std::shared_ptr<Neuron> neuron) {
    this->inputNeuron = neuron;
}

void Synapse::setOutputNeuron(std::shared_ptr<Neuron> neuron) {
    this->outputNeuron = neuron;
}

void Synapse::setStoredValue(double newStoredValue) {
    this->storedValue= newStoredValue;
}

double Synapse::getStoredValue() {
    return this->storedValue;
} 

void Synapse::setWeight(double newWeight) {
    this->weight = newWeight;
}

double Synapse::getWeight() {
    return this->weight;
}

void Synapse::setLearnRate(double newLearnRate) {
    this->learnRate = newLearnRate;
}

void Synapse::setBias(double newBias) {
    this->bias = newBias;
}

void Synapse::forward() {
    this->storedValue = this->inputNeuron->getStoredValue() * this->weight + this->bias;
    this->outputNeuron->forward();
}

void Synapse::backward(double delta) {
    double gradient = delta * this->weight;
    double minor_adjustment = this->learnRate * delta;
    this->weight = this->weight - minor_adjustment * this->inputNeuron->getStoredValue();
    this->bias = this->bias - minor_adjustment;
    this->inputNeuron->backward(gradient);
}