#pragma once

#include <iostream>

enum class ActivationType {
    NONE,
    SIGMOID,
    RELU,
    TANH
};

class Activation {
    public:
        static double activate(ActivationType& type, double x);
        static double dx_activate(ActivationType& type, double x);

        // Activation Functions
        static double sigmoid(double x);
        static double reLU(double x);
        static double tanh(double x);
        

        // Activation Derivatives
        static double dx_sigmoid(double x);
        static double dx_reLU(double x);
        static double dx_tanh(double x);
};
