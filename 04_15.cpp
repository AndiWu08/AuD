#include <iostream>

int counter = 0;

int T_r(int n) {
    counter++;
    if (n == 1)
    {
        return 1;
    } else   {
        return n * T_r(n-1) + n;
    }        
}

int T_i(int n) {
    int result = 1; // T(1) = 1
    if (n == 1) return result;
    
    for (int i = 2; i <= n; i++)
    {
        result = i * result + i;
        std::cout << "T (" << i << ") = " << result << std::endl;
    }

    return result;
}

int main() {
    std::cout << T_r(10) << std::endl;
    std::cout << counter << std::endl;
    std::cout << T_i(10) << std::endl;
}

/* 
9864100
10
T (2) = 4
T (3) = 15
T (4) = 64
T (5) = 325
T (6) = 1956
T (7) = 13699
T (8) = 109600
T (9) = 986409
T (10) = 9864100
9864100

c) Ordunungsklasse = O(n)  
d) 10 bzw n Aufrufe
e) linear = O(n)
*/