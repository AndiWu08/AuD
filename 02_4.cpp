#include <iostream>

// Rekursive Funktion f(n)
int F_r(int n) {
    if (n <= 2) {
        return 1;
    } else {
        return n * F_r(n - 1) - F_r(n - 2);
    }
}

// Iterative Funktion f(n)
int F_i(int n) {
    if (n <= 2) {
        return 1;
    }
    int f_prev2 = 1; // f(1) und f(2) sind 1
    int f_prev1 = 1;
    int f_curr;

    for (int i = 3; i <= n; i++) {
        f_curr = i * f_prev1 - f_prev2;
        f_prev2 = f_prev1;
        f_prev1 = f_curr;
    }

    return f_curr;
}

int main() {
    // a) Berechnung der Funktionswerte für n = 1, 2, ..., 5
    std::cout << "Rekursiv berechnet:" << std::endl;
    for (int n = 1; n <= 5; ++n) {
        std::cout << "f(" << n << ") = " << F_r(n) << std::endl;
    }

    /*
    Rekursiv berechnet:
    f(1) = 1
    f(2) = 1
    f(3) = 2
    f(4) = 7
    f(5) = 33
    */

    std::cout << "\nIterativ berechnet:" << std::endl;
    for (int n = 1; n <= 5; ++n) {
        std::cout << "f(" << n << ") = " << F_i(n) << std::endl;
    }
       /*
    Iterativ berechnet:
    f(1) = 1
    f(2) = 1
    f(3) = 2
    f(4) = 7
    f(5) = 33
    */
}
