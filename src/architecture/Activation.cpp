#include "Activation.hpp"

double Activation::activate(ActivationType& type, double x) {
    switch (type) {
        case ActivationType::SIGMOID:
            return Activation::sigmoid(x);
        case ActivationType::RELU:
            return Activation::reLU(x);
        case ActivationType::TANH:
            return Activation::tanh(x);
        default:
            return x;
    }
}

double Activation::dx_activate(ActivationType& type, double x) {
    switch (type) {
        case ActivationType::SIGMOID:
            return Activation::dx_sigmoid(x);
        case ActivationType::RELU:
            return Activation::dx_reLU(x);
        case ActivationType::TANH:
            return Activation::dx_tanh(x);
        default:
            return 1;
    }
}

double Activation::sigmoid(double x) {
    return 1 / (1 + std::exp(-x));
}

double Activation::dx_sigmoid(double x) {
    double y = Activation::sigmoid(x);
    return y * (1 - y);
}

double Activation::reLU(double x) {
    return std::max(0.0, x);
}

double Activation::dx_reLU(double x) {
    return x > 0 ? 1.0 : 0.0;
}

double Activation::tanh(double x) {
    return std::tanh(x);
}

double Activation::dx_tanh(double x) {
    double tanh_x = std::tanh(x);
    return 1.0 - tanh_x * tanh_x;
}
