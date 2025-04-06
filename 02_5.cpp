#include <iostream>

// Rekursive Funktion f(n)
int F_r(int n) {
    if (n<=2)
    {
        return 1;
    } else
    {
        return n + F_r(n-2);
    }
}

// Iterative Funktion f(n)
int F_i(int n) {
    if (n<=2)
    {
        return 1;
    }

    int result=1;
    while (n>2)
    {
        result += n;
        n -= 2;
    }
    return result;    
}

int main() {
    std::cout << "Rekursiv berechnet:" << std::endl;
    for (int n = 1; n <= 5; ++n) {
        std::cout << "f(" << n << ") = " << F_r(n) << std::endl;
    }

    std::cout << "\nIterativ berechnet:" << std::endl;
    for (int n = 1; n <= 5; ++n) {
        std::cout << "f(" << n << ") = " << F_i(n) << std::endl;
    }
}

/*
Rekursiv berechnet:
f(1) = 1
f(2) = 1
f(3) = 4
f(4) = 5
f(5) = 9

Iterativ berechnet:
f(1) = 1
f(2) = 1
f(3) = 4
f(4) = 5
f(5) = 9
*/
