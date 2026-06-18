#include <iostream>
using namespace std;

int main() {
    int numero;
    int soma = 0;
    long long produto = 1;

    while (soma <= 100) {
        cout << "Digite um numero: ";
        cin >> numero;

        soma += numero;
        produto *= numero;
    }

    cout << "\nA soma ultrapassou 100." << endl;
    cout << "Produto dos numeros lidos: " << produto << endl;

    return 0;
}
