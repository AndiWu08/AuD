#include <iostream>

// Rekursive Hilfsfunktion zur Berechnung von F(n)
double f(int n, int maxDepth, double epsilon) {
    if (maxDepth <= 0) return 1.0;

    double term = static_cast<double>(n) / (2 * n + 1);
    if (term < epsilon) return 1.0;

    return 1.0 + term * f(n + 1, maxDepth - 1, epsilon);
}


// Hauptfunktion, die pi berechnet
int main() {
    double pi = 2.0 * f(1, 1000, 1e-4); // max 1000 Schritte
    std::cout << pi << std::endl;
    // 3.14159
}
