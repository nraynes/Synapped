#pragma once

#include "NeuralCanvas.h"

#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {
    private:
        NeuralCanvas canvas;

    public:
        MainWindow();
};
