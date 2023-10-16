#include <iostream>
#include <vector>
#include <cmath>

// Definimos la ecuación diferencial de segundo orden
double SecondOrderDifferentialEquation(double x, double y, double dy) {
    return -4 * dy - 4 * y; // Por ejemplo: y'' - 2y' - 3y = 0
}

int main() {
    // Parámetros de la ecuación diferencial
    double x0 = 0.0;      // Valor inicial de x
    double y0 = 1.0;      // Valor inicial de y(x0)
    double dy0 = 0.0;     // Valor inicial de y'(x0)
    double x_final = 1.0; // Valor final de x
    double h = 0.1;       // Tamaño del paso

    // Calculamos el número de pasos
    int num_steps = static_cast<int>((x_final - x0) / h);

    // Vectores para almacenar los valores de x, y, y'
    std::vector<double> x_values(num_steps + 1);
    std::vector<double> y_values(num_steps + 1);
    std::vector<double> dy_values(num_steps + 1);

    // Inicializamos los valores iniciales
    x_values[0] = x0;
    y_values[0] = y0;
    dy_values[0] = dy0;

    // Resolvemos la ecuación diferencial por el método de Euler
    for (int i = 0; i < num_steps; ++i) {
        double x = x_values[i];
        double y = y_values[i];
        double dy = dy_values[i];

        double dydx = SecondOrderDifferentialEquation(x, y, dy);

        x_values[i + 1] = x + h;
        y_values[i + 1] = y + h * dy;
        dy_values[i + 1] = dy + h * dydx;
    }

    // Imprimimos los resultados
    for (int i = 0; i <= num_steps; ++i) {
        std::cout << "x = " << x_values[i] << ", y = " << y_values[i] << std::endl;
    }

    return 0;
}


