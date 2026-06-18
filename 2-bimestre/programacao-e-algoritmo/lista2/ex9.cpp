#include <iostream>
#include <string>
using namespace std;


string substituirVogais(string palavra) {
    for (int i = 0; i < palavra.length(); i++) {
        if (palavra[i] == 'a' || palavra[i] == 'e' ||
            palavra[i] == 'i' || palavra[i] == 'o' ||
            palavra[i] == 'u' || palavra[i] == 'A' ||
            palavra[i] == 'E' || palavra[i] == 'I' ||
            palavra[i] == 'O' || palavra[i] == 'U') {

            palavra[i] = '*';
        }
    }

    return palavra;
}

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    cout << "Resultado: " << substituirVogais(palavra) << endl;

    return 0;
}
