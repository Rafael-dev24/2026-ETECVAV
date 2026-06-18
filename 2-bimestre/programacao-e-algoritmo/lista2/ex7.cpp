#include <iostream>
using namespace std;


string verificarOrdem(int n1, int n2, int n3, int n4, int n5) {

    if (n1 < n2 && n2 < n3 && n3 < n4 && n4 < n5) {
        return "Ordem crescente";
    }

    if (n1 > n2 && n2 > n3 && n3 > n4 && n4 > n5) {
        return "Ordem decrescente";
    }

    return "Nao ordenados";
}

int main() {
    int n1, n2, n3, n4, n5;

    cout << "Digite 5 numeros: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    cout << verificarOrdem(n1, n2, n3, n4, n5) << endl;

    return 0;
}
