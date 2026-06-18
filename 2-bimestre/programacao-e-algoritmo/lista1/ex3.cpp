#include <iostream>
using namespace std;

int main() {
    int num;
    int soma = 0;

    while (true) {
        cin >> num;

        if (num < 0)
            break;

        soma += num;
    }

    cout << soma << endl;

    return 0;
}
