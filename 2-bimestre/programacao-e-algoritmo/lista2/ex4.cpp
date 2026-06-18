#include <iostream>
using namespace std;


int adicionar(int a, int b) {
    return a + b;
}


int subtrair(int a, int b) {
    return a - b;
}


int multiplicar(int a, int b) {
    return a * b;
}


float dividir(int a, int b) {
    return (float)a / b;
}

int main() {
    int num1, num2;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << "Adicao: " << adicionar(num1, num2) << endl;
    cout << "Subtracao: " << subtrair(num1, num2) << endl;
    cout << "Multiplicacao: " << multiplicar(num1, num2) << endl;

    if (num2 != 0) {
        cout << "Divisao: " << dividir(num1, num2) << endl;
    } else {
        cout << "Divisao impossivel (divisao por zero)." << endl;
    }

    return 0;
}
