#include <iostream>
using namespace std;

int main() {
    int vetor[10];
    int aux;

    
    for (int i = 0; i < 10; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (vetor[i] > vetor[j]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    
    cout << "\nTerceiro menor valor: " << vetor[2] << endl;

    return 0;
}
