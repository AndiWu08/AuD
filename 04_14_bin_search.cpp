#include <iostream>

class Vektor
{
private:
int dimension;
int *daten;
public:
Vektor(int dim);
virtual ~Vektor();
void set(int i, int val);
int get(int i);
int bin_suche(int sw);
};

int Vektor::bin_suche(int sw) {
    int l_u = 0, l_o = dimension - 1;
    while (l_u <= l_o) {
        int mid = l_u + (l_o - l_u) / 2; // Vermeidet Überlauf
        int current = daten[mid]; // Direkter Zugriff auf das Array
        
        if (current == sw) {
            return mid; // Element gefunden
        } else if (current < sw) {
            l_u = mid + 1; // Suche im rechten Teil
        } else {
            l_o = mid - 1; // Suche im linken Teil
        }
    }
    return -1; // Element nicht gefunden
}

// Komplexität =O(log n) für die Suche, da in jedem Schritt die Suche halbiert wird.