#include <iostream>
#include <string>
using namespace std;


bool ehPalindromo(string palavra) {
    int inicio = 0;
    int fim = palavra.length() - 1;

    while (inicio < fim) {
        if (palavra[inicio] != palavra[fim]) {
            return false;
        }
        inicio++;
        fim--;
    }

    return true;
}

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (ehPalindromo(palavra)) {
        cout << "A palavra e um palindromo." << endl;
    } else {
        cout << "A palavra nao e um palindromo." << endl;
    }

    return 0;
}
