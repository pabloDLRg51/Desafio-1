#include <iostream>
using namespace std;
void validacionEntradaTablero(int filas, int columnas) {
    while (filas < 8 || cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "No ingrese letras.";
        }
        cout << "Ingrese un alto o mayor o igual a 8: ";
        cin >> filas;
    }
    while (columnas % 8 != 0 || columnas < 8 || cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "No ingrese letras. ";
        }
        cout << "Ingrese un ancho mayor o igual a 8 y multiplo de 8: ";
        cin >> columnas;
    }
}
