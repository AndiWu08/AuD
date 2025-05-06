#include <iostream>

int counter_r = 0;
int counter_i = 0; 

int fact_r( int n) {
    /* 
    Zeitkomplexität: O(n)
    Speicherkomplexität: O(n)
    */
    counter_r++; 
    if (n<=1)
        return 1;
    else
        return n*fact_r (n-1); // rekursiver Aufruf n-1 statt --n 
}

int fact_i( int n) {
    /* 
    Zeitkomplexität: O(n)
    Speicherkomplexität: O(1) 
    */
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i; 
        counter_i++; 
    }
    return result;    
}

int main() {
    int n = 5; // Beispielwert
    std::cout << "Fakultaet von " << n << " ist " << fact_r(n) << " Counter: " << counter_r << std::endl;
    std::cout << "Fakultaet von " << n << " ist " << fact_i(n) << " Counter: " << counter_i << std::endl;
    return 0;
}