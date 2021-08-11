#include "vetor.h"

using namespace std;

int main () {
    Vetor<int> p;
    p.aloca(5);
    for(int i = 0; i < 5; i++) {
        cin >> p[i];
    }
    cout << "Vetor p: " << p;
    cout << "Tamanho do vetor = " << p.getUsedTam() << endl;
    p.countingSort(10);
    cout << "p ordenado: " << p;

    for(int i = 0; i < 5; i++) {
        cout << p.buscaBinaria(p[i]) << '\n';
    }
    return 0;
}