#include <iostream>
#include <string>
using namespace std;


int contarVogais(string nome) {
    int qtd = 0;

    for (int i = 0; i < nome.length(); i++) {
        char c = tolower(nome[i]);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {
            qtd++;
        }
    }

    return qtd;
}


int contarConsoantes(string nome) {
    int qtd = 0;

    for (int i = 0; i < nome.length(); i++) {
        char c = tolower(nome[i]);

        if (c >= 'a' && c <= 'z' &&
            c != 'a' && c != 'e' && c != 'i' &&
            c != 'o' && c != 'u') {
            qtd++;
        }
    }

    return qtd;
}

int main() {
    string nome;

    cout << "Digite o nome completo: ";
    getline(cin, nome);

    cout << "Quantidade de vogais: "
         << contarVogais(nome) << endl;

    cout << "Quantidade de consoantes: "
         << contarConsoantes(nome) << endl;

    return 0;
}
