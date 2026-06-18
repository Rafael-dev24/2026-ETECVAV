#include <iostream>
using namespace std;


int indiceMenor(int vetor[], int tamanho) {
    int indice = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < vetor[indice]) {
            indice = i;
        }
    }

    return indice;
}


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
