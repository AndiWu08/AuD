#include <iostream>

int ggT(int a, int b) {
    int m = a;
    int n = b;
    int r = 1;

    while (r != 0)
    {
        if (m<n)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        
        r = m-n;
        m = n;
        n = r;
    }
    return m;    
}

int main() {
    std::cout << ggT(9,15) << std::endl;
    // 3
    std::cout << ggT(16,28) << std::endl;
    // 4
    std::cout << ggT(119,544) << std::endl;
    // 17
}