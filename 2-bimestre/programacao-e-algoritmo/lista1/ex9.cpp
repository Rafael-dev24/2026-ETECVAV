#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 1;

    while (a <= n) {
        cout << a << endl;

        int prox = a + b;
        a = b;
        b = prox;
    }

    return 0;
}
