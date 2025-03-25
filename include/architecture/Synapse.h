#pragma once

#include <memory>

class Neuron;

class Synapse {
    private:
        std::shared_ptr<Neuron> inputNeuron;
        std::shared_ptr<Neuron> outputNeuron;
        double storedValue;
        double weight;
        double learnRate;
        double bias;

    public:
        Synapse(
            std::shared_ptr<Neuron> in,
            std::shared_ptr<Neuron> out,
            double weight,
            double learnRate,
            double bias
        );

        void setInputNeuron(std::shared_ptr<Neuron> neuron);
        void setOutputNeuron(std::shared_ptr<Neuron> neuron);
        void setStoredValue(double newStoredValue);
        double getStoredValue();
        void setWeight(double newWeight);
        double getWeight();
        void setLearnRate(double newLearnRate);
        void setBias(double newBias);
        void forward();
        void backward(double delta);
};
