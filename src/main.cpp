#include "NeuralNetwork.hpp"
#include "readCSV.hpp"
#include "log.hpp"
#include "MainWindow.hpp"

#include <vector>
#include <memory>
#include <gtkmm/application.h>

int main() {
    auto app = Gtk::Application::create("neuralnetwork");
    MainWindow window;

    std::unique_ptr<NeuralNetwork> nn(new NeuralNetwork(7, 1, 10, 1));
    
    std::string file = "../Resources/sample_data.csv";
    int dataSplitPoint = 7;

    std::vector<std::array<std::vector<double>, 2>> data = readCSV(file, dataSplitPoint);
    size_t splitPoint = data.size() * 0.8;
    std::vector<std::array<std::vector<double>, 2>> trainingData(data.begin(), data.begin() + splitPoint);
    std::vector<std::array<std::vector<double>, 2>> testingData(data.begin() + splitPoint, data.end());

    nn->train(trainingData);
    log("");
    nn->test(testingData);
    log("FINAL OUTPUT!");
    nn->displayAccuracy();
    
    return app->run(window);
}