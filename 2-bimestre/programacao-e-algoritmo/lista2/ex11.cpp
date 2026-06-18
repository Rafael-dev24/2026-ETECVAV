#include <iostream>
using namespace std;


void substituirNegativos(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < 0) {
            vetor[i] = 0;
        }
    }
}

int main() {
    int vetor[10];

    
    for (int i = 0; i < 10; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    
    substituirNegativos(vetor, 10);

    
    cout << "\nVetor resultante:\n";

    for (int i = 0; i < 10; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    return 0;
}
