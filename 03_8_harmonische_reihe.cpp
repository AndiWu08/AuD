#include <iostream>

double h_r(int n) {
    if (n <= 0)
    {
        return 0.0;
    }
    
    return (1.0 / n) + h_r(n-1);
}

double h_i(int n) {
    double result = 0.0;

    for (int i = n; i > 0; i--)
    {
        result += 1.0 / i;
    }
    

    return result;
}

int main() {
    std::cout << h_i(3) << std::endl;
    std::cout << h_r(3) << std::endl;
    /* 
    1.83333
    1.83333
    */
}