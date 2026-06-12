#include <iostream>
using namespace std;

int main() {
    int num, menor, maior;

    cin >> num;
    menor = maior = num;

    for (int i = 1; i < 10; i++) {
        cin >> num;

        if (num < menor)
            menor = num;

        if (num > maior)
            maior = num;
    }

    cout << menor << endl;
    cout << maior << endl;

    return 0;
}
