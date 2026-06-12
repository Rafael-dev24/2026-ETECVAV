#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int somaPares = 0;
    int somaImpares = 0;

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0)
            somaPares += i;
        else
            somaImpares += i;
    }

    cout << somaPares << endl;
    cout << somaImpares << endl;

    return 0;
}
