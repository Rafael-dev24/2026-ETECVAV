#include <iostream>
using namespace std;

// Função que conta quantas vezes uma letra aparece no vetor
int contarOcorrencias(char vetor[], int tamanho, char letra) {
    int quantidade = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == letra) {
            quantidade++;
        }
    }

    return quantidade;
}

int main() {
    char letras[20];
    char letraProcurada;

    // Leitura das 20 letras
    for (int i = 0; i < 20; i++) {
        cout << "Digite a letra " << i + 1 << ": ";
        cin >> letras[i];
    }

    cout << "\nDigite a letra que deseja procurar: ";
    cin >> letraProcurada;

    cout << "A letra '" << letraProcurada << "' aparece "
         << contarOcorrencias(letras, 20, letraProcurada)
         << " vez(es)." << endl;

    return 0;
}
