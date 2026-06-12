#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double altura, soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> altura;
        soma += altura;
    }

    double media = soma / n;

    cout << media << endl;

    return 0;
}
