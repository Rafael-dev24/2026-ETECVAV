#include <iostream>
using namespace std;

// Função que substitui números negativos por zero
void substituirNegativos(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < 0) {
            vetor[i] = 0;
        }
    }
}

int main() {
    int vetor[10];

    // Leitura dos 10 números
    for (int i = 0; i < 10; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    // Substitui os negativos por zero
    substituirNegativos(vetor, 10);

    // Exibe o vetor
    cout << "\nVetor resultante:\n";

    for (int i = 0; i < 10; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    return 0;
}
