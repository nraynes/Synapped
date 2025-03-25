#include "NeuralCanvas.h"
#include "Neuron.h"
#include "Synapse.h"

#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>

bool NeuralCanvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source_rgb(1, 1, 1);
    cr->paint();

    cr->set_source_rgb(0.1, 0.1, 0.9);
    cr->arc(200, 150, 30, 0, 2 * M_PI);
    cr->fill();

    return true;
}

void NeuralCanvas::draw_neuron(std::shared_ptr<Neuron> neuron) {}
