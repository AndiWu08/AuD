#include <iostream>

int counter = 0;

void hanoi(int n, char start, char ziel, char mitte) {
    counter++;
    if (n == 1) {
        std::cout << "Bewege Scheibe 1 von " << start << " nach " << ziel << std::endl;
        return;
    }
    hanoi(n - 1, start, mitte, ziel);
    std::cout << "Bewege Scheibe " << n << " von " << start << " nach " << ziel << std::endl;
    hanoi(n - 1, mitte, ziel, start);
}

int main() {
    int scheibenanzahl;
    std::cout << "Gib die Anzahl der Scheiben ein: ";
    std::cin >> scheibenanzahl;
    
    hanoi(scheibenanzahl, 'A', 'C', 'B');  // A, B, C sind die Stäbe
    std::cout << counter << std::endl;
    
}
    // 2^n - 1

    /*
    Gib die Anzahl der Scheiben ein: 3
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 2 von A nach B
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 3 von A nach C
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 2 von B nach C
    Bewege Scheibe 1 von A nach C
    7

    Gib die Anzahl der Scheiben ein: 4
    Bewege Scheibe 1 von A nach B
    Bewege Scheibe 2 von A nach C
    Bewege Scheibe 1 von B nach C
    Bewege Scheibe 3 von A nach B
    Bewege Scheibe 1 von C nach A
    Bewege Scheibe 2 von C nach B
    Bewege Scheibe 1 von A nach B
    Bewege Scheibe 4 von A nach C
    Bewege Scheibe 1 von B nach C
    Bewege Scheibe 2 von B nach A
    Bewege Scheibe 1 von C nach A
    Bewege Scheibe 3 von B nach C
    Bewege Scheibe 1 von A nach B
    Bewege Scheibe 2 von A nach C
    Bewege Scheibe 1 von B nach C
    15
    
    Gib die Anzahl der Scheiben ein: 5
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 2 von A nach B
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 3 von A nach C
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 2 von B nach C
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 4 von A nach B
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 2 von C nach A
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 3 von C nach B
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 2 von A nach B
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 5 von A nach C
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 2 von B nach C
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 3 von B nach A
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 2 von C nach A
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 4 von B nach C
    Bewege Scheibe 1 von A nach C
    Bewege Scheibe 2 von A nach B
    Bewege Scheibe 1 von C nach B
    Bewege Scheibe 3 von A nach C
    Bewege Scheibe 1 von B nach A
    Bewege Scheibe 2 von B nach C
    Bewege Scheibe 1 von A nach C
    31
    */