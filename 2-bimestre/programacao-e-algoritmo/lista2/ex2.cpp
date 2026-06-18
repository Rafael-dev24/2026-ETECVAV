#include <iostream>
using namespace std;


int potencia(int base, int expoente) {
    int resultado = 1;

    for (int i = 1; i <= expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    int base, expoente;

    cout << "Digite a base: ";
    cin >> base;

    cout << "Digite o expoente: ";
    cin >> expoente;

    cout << "Resultado: " << potencia(base, expoente) << endl;

    return 0;
}
