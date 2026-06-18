#include <iostream>
using namespace std;


int primeiroNegativo(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < 0) {
            return i;
        }
    }

    return -1; 
}

int main() {
    int vetor[20];

    
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
