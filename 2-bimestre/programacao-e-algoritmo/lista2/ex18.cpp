#include <iostream>
using namespace std;

// Função que verifica se uma letra é vogal
bool ehVogal(char letra) {
    letra = tolower(letra);

    return letra == 'a' || letra == 'e' ||
           letra == 'i' || letra == 'o' ||
           letra == 'u';
}

int main() {
    char letras[20];
    int vogais[5] = {0, 0, 0, 0, 0}; // a, e, i, o, u

    // Leitura das 20 letras
    for (int i = 0; i < 20; i++) {
        cout << "Digite a letra " << i + 1 << ": ";
        cin >> letras[i];
    }

    // Contagem das vogais
    for (int i = 0; i < 20; i++) {
        char letra = tolower(letras[i]);

        if (ehVogal(letra)) {
            switch (letra) {
                case 'a':
                    vogais[0]++;
                    break;
                case 'e':
                    vogais[1]++;
                    break;
                case 'i':
                    vogais[2]++;
                    break;
                case 'o':
                    vogais[3]++;
                    break;
                case 'u':
                    vogais[4]++;
                    break;
            }
        }
    }

    // Exibição do vetor de contagem
    cout << "\nQuantidade de cada vogal:\n";
    cout << "a: " << vogais[0] << endl;
    cout << "e: " << vogais[1] << endl;
    cout << "i: " << vogais[2] << endl;
    cout << "o: " << vogais[3] << endl;
    cout << "u: " << vogais[4] << endl;

    return 0;
}
