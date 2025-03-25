#pragma once

#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>

class Neuron;
class Synapse;

class NeuralCanvas : public Gtk::DrawingArea {
    private:
        std::vector<std::shared_ptr<Neuron>> neurons;
        std::vector<std::shared_ptr<Synapse>> synapses;

    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

    public:
        void draw_neuron(std::shared_ptr<Neuron> neuron);
};
