#include <iostream>
using namespace std;


double calcularArea(double raio) {
    const double PI = 3.14159;
    return PI * raio * raio;
}

int main() {
    double raio, somaAreas = 0;

    for (int i = 1; i <= 5; i++) {
        cout << "Digite o raio do circulo " << i << ": ";
        cin >> raio;

        somaAreas += calcularArea(raio);
    }

    cout << "Soma das areas: " << somaAreas << endl;

    return 0;
}
