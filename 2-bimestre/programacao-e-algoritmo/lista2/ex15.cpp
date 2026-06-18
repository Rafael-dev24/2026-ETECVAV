#include <iostream>
using namespace std;

// Função que retorna o índice do primeiro número negativo
int primeiroNegativo(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < 0) {
            return i;
        }
    }

    return -1; // Não encontrou número negativo
}

int main() {
    int vetor[20];

    // Leitura dos 20 números
    for (int i = 0; i < 20; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor[i];
    }

    int indice = primeiroNegativo(vetor, 20);

    if (indice != -1) {
        cout << "Indice do primeiro numero negativo: "
             << indice << endl;
    } else {
        cout << "Nao ha numeros negativos no vetor." << endl;
    }

    return 0;
}
