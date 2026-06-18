#include <iostream>
using namespace std;

int main() {
    int fim, m;

    cin >> fim;
    cin >> m;

    for (int i = m; i <= fim; i += m) {
        cout << i << endl;
    }

    return 0;
}
