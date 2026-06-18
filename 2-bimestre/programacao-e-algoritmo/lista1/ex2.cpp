#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long potencia = 1; 

    for (int i = 0; i <= n; i++) {
        cout << potencia << endl;
        potencia *= 2;
    }

    return 0;
}
