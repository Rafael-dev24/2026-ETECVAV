#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    int pares[10], impares[10];
    int soma[10];

    int qtdPares = 0;
    int qtdImpares = 0;

    
    for (int i = 0; i < 10; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> numeros[i];

        if (numeros[i] % 2 == 0) {
            pares[qtdPares] = numeros[i];
            qtdPares++;
        } else {
            impares[qtdImpares] = numeros[i];
            qtdImpares++;
        }
    }

    
    for (int i = 0; i < qtdPares - 1; i++) {
        for (int j = i + 1; j < qtdPares; j++) {
            if (pares[i] > pares[j]) {
                int aux = pares[i];
                pares[i] = pares[j];
                pares[j] = aux;
            }
        }
    }

    
    for (int i = 0; i < qtdImpares - 1; i++) {
        for (int j = i + 1; j < qtdImpares; j++) {
            if (impares[i] > impares[j]) {
                int aux = impares[i];
                impares[i] = impares[j];
                impares[j] = aux;
            }
        }
    }

    
    int tamanhoSoma;

    if (qtdPares < qtdImpares)
        tamanhoSoma = qtdPares;
    else
        tamanhoSoma = qtdImpares;

    for (int i = 0; i < tamanhoSoma; i++) {
        soma[i] = pares[i] + impares[i];
    }

   
    cout << "\nVetor de Pares:\n";
    for (int i = 0; i < qtdPares; i++) {
        cout << pares[i] << " ";
    }

    cout << "\n\nVetor de Impares:\n";
    for (int i = 0; i < qtdImpares; i++) {
        cout << impares[i] << " ";
    }

    cout << "\n\nVetor Soma:\n";
    for (int i = 0; i < tamanhoSoma; i++) {
        cout << soma[i] << " ";
    }

    cout << endl;

    return 0;
}
