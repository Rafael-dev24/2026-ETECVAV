#include <iostream>
using namespace std;


bool ehImpar(int num) {
    return num % 2 != 0;
}

int main() {
    int numero, soma = 0;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        if (ehImpar(i)) {
            soma += i;
        }
    }

    cout << "A soma dos numeros impares ate " << numero << " e: " << soma << endl;

    return 0;
}
