#include <cstddef>
#include <iostream>
#include "Automata.hpp"

using namespace std;

int main() {
    char c;
    Automata automata;
    cout<<"Ingrese la cadena\n-> ";
    while ((c = cin.get()) != EOF) {
        cin.unget();
        int i = 0;
        if (automata.procesar()) {
            cout << "Se acepta la cadena operacion.\n";
            }
        else {
            cout << "No se acepta la cadena, hubo un error a partir de donde indica la flecha:\n";
            cout << automata.getErr() << "<-\n";
            }
        system("pause");
        system("cls");
        cout<<"Ingrese la cadena\n-> ";
        }
    return 0;
    }
