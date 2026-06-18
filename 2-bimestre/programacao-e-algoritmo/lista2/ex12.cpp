#include <iostream>
using namespace std;


int contarPares(int vetor[], int tamanho) {
    int quantidade = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            quantidade++;
        }
    }

    return quantidade;
}


int contarImpares(int vetor[], int tamanho) {
    int quantidade = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 != 0) {
            quantidade++;
        }
    }

    return quantidade;
}

int main() {
    int vetor[15];

    
    for (int i = 0; i < 15; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    cout << "\nQuantidade de pares: "
         << contarPares(vetor, 15) << endl;

    cout << "Quantidade de impares: "
         << contarImpares(vetor, 15) << endl;

    return 0;
}
