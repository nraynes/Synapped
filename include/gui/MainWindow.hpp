#pragma once

#include "NeuralCanvas.hpp"

#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {
    private:
        NeuralCanvas canvas;

    public:
        MainWindow();
};
