# NeuralVisualizer

**NeuralVisualizer** is a C++ application designed to provide a graphical representation of neural network architectures and their training processes. Utilizing the GTKmm library for the graphical interface, this tool offers an intuitive visualization of neural networks in action.

---

## ✨ Features

- **Graphical Representation**: Visualize neural network structures, including neurons and their connections.
- **Training Visualization**: Observe the training process in real-time, with updates to the network's state.
- **Modular Design**: Clean, maintainable codebase with clearly separated components for GUI, neural architecture, and utility functions.

---

## 📁 Project Structure

```
NeuralVisualizer/
├── .vscode/                 # VSCode configuration files
├── build/                   # Directory for build outputs
├── include/                 # Header files
│   ├── architecture/        # Neural network architecture headers
│   ├── gui/                 # GUI component headers
│   └── utils/               # Utility headers
├── src/                     # Source files
│   ├── architecture/        # Neural network architecture implementations
│   ├── gui/                 # GUI component implementations
│   └── utils/               # Utility implementations
├── CMakeLists.txt           # CMake build configuration
└── README.md                # Project documentation
```

---

## 🔧 Dependencies

- [GTKmm 3.0](https://www.gtkmm.org/) — C++ interface for GTK+ GUI toolkit
- C++17 compiler
- CMake ≥ 3.10

---

## 🛠️ Installation

### 1. Install GTKmm

**macOS (via Homebrew):**
```bash
brew install gtkmm3
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libgtkmm-3.0-dev
```

---

### 2. Clone the Repository

```bash
git clone https://github.com/nraynes/NeuralVisualizer.git
cd NeuralVisualizer
```

### 3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### 4. Run the Application

```bash
./neural_visualizer
```

---

## ✅ Usage

Upon launching the application, the main window will display the neural network visualization. Users can observe neuron layouts, live training behavior, and activation pathways.

---

## 🤝 Contributing

Contributions are welcome! If you have suggestions for improvements or new features, please fork the repository and submit a pull request.

---

## 📄 License

This project is licensed under the LGPL License. See the `LICENSE` file for more details.
