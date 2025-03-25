#pragma once

#include "ActivationType.hpp"

#include <vector>
#include <memory>

class Synapse;

class Neuron {
    private:
        std::vector<std::shared_ptr<Synapse>> inputs;
        std::vector<std::shared_ptr<Synapse>> outputs;
        double weightedSum;
        double storedValue;
        ActivationType type;

    public:
        std::string id;
        Neuron(ActivationType type);

        void addInput(std::shared_ptr<Synapse> input);
        void addOutput(std::shared_ptr<Synapse> output);
        void setWeightedSum(double newWeightedSum);
        void setStoredValue(double newStoredValue);
        double getStoredValue();
        void forward();
        void forward(double input);
        void calculateWeightedSum();
        double activate(double x);
        double dx_activate(double x);
        void backward(double gradient);
        double sigmoid(double x);
        double reLU(double x);
        double dx_sigmoid(double x);
        double dx_reLU(double x);
        std::vector<std::shared_ptr<Synapse>> getInputs();
};
