#include <iostream>
#include <chrono>

int counter = 0;

long fibonacci_r(int n) {
    /*
    Zeitkomplexität: O(2^n), da jeder Aufruf zwei weitere Aufrufe erzeugt
    Speicherkomplexität: O(n) linear
    */

    counter++;
    if (n <= 2)
    {
        return 1;
    }
    long result = fibonacci_r(n-1) + fibonacci_r(n-2);
    return result;
}

long fibonacci_i(int n) {
    /*
    Zeitkomplexität: O(n)
    Speicherkomplexität: O(n) 
    */

    int* afib = new int[n+1];
    afib[1] = 1;
    afib[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        afib[i] = afib[i-1] + afib[i-2];
    }
    return afib[n];
}

long fibonacci_i2(int n) {
    /*
    Zeitkomplexität: O(n)
    Speicherkomplexität: O(1) es werden immer nur 3 Variablen benötigt
    */

    if (n <= 2) {
        return 1; // Die ersten beiden Fibonacci-Zahlen sind 1
    }

    long prev2 = 1; // Fibonacci(n-2)
    long prev1 = 1; // Fibonacci(n-1)
    long current = 0; // Fibonacci(n)

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2; // Berechne Fibonacci(n)
        prev2 = prev1; // Verschiebe prev1 zu prev2
        prev1 = current; // Setze current als prev1
    }

    return current;
}

int main() {
    std::cout << fibonacci_r(5) << std::endl;   // 55
    std::cout << counter << std::endl;           // 109
    std::cout << fibonacci_i(10) << std::endl;  // 55 
    std::cout << fibonacci_i2(10) << std::endl;  // 55   
}
