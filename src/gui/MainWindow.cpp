#include "MainWindow.h"

#include <gtkmm/window.h>

MainWindow::MainWindow() {
    this->set_title("Neural Network");
    this->set_default_size(400,300);
    add(canvas);
    canvas.show();
}
