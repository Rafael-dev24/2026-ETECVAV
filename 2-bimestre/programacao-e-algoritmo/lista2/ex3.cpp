#include <iostream>
using namespace std;


float pesoMasculino(float altura) {
    return (72.7 * altura) - 58;
}


float pesoFeminino(float altura) {
    return (62.1 * altura) - 44.7;
}

int main() {
    char sexo;
    float altura;

    cout << "Digite o sexo (M/F): ";
    cin >> sexo;

    cout << "Digite a altura: ";
    cin >> altura;

    if (sexo == 'M' || sexo == 'm') {
        cout << "Peso ideal: " << pesoMasculino(altura) << " kg" << endl;
    }
    else if (sexo == 'F' || sexo == 'f') {
        cout << "Peso ideal: " << pesoFeminino(altura) << " kg" << endl;
    }
    else {
        cout << "Sexo invalido!" << endl;
    }

    return 0;
}
