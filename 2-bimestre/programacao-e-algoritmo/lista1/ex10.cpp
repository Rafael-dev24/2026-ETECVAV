#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secreto = rand() % 100 + 1; 
    int palpite;
    int tentativas = 0;

    do {
        cin >> palpite;
        tentativas++;

        if (palpite < secreto)
            cout << "Muito baixo" << endl;
        else if (palpite > secreto)
            cout << "Muito alto" << endl;
        else {
            cout << "Correto" << endl;
            cout << "Quantidade de palpites: "
                 << tentativas << endl;
        }

    } while (palpite != secreto);

    return 0;
}
