#include <iostream>
using namespace std;


void inverterSinais(int vetor1[], int vetor2[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor2[i] = -vetor1[i];
    }
}


int somaPositivos(int vetor[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > 0) {
            soma += vetor[i];
        }
    }

    return soma;
}

int main() {
    int vetor1[10];
    int vetor2[10];

    
    for (int i = 0; i < 10; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vetor1[i];
    }

    
    inverterSinais(vetor1, vetor2, 10);

    
    cout << "\nVetor com sinais invertidos:\n";
    for (int i = 0; i < 10; i++) {
        cout << vetor2[i] << " ";
    }

    
    int soma = somaPositivos(vetor1, 10) + somaPositivos(vetor2, 10);

    cout << "\n\nSoma dos valores positivos dos dois vetores: "
         << soma << endl;

    return 0;
}
