#include <iostream>
using namespace std;

// Função que retorna o índice do menor valor
int indiceMenor(int vetor[], int tamanho) {
    int indice = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < vetor[indice]) {
            indice = i;
        }
    }

    return indice;
}

// Função que retorna o índice do maior valor
int indiceMaior(int vetor[], int tamanho) {
    int indice = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > vetor[indice]) {
            indice = i;
        }
    }

    return indice;
}

int main() {
    int vetor[15];

    // Leitura dos 15 números
    for (int i = 0; i < 15; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    cout << "\nIndice do menor valor: "
         << indiceMenor(vetor, 15) << endl;

    cout << "Indice do maior valor: "
         << indiceMaior(vetor, 15) << endl;

    return 0;
}
