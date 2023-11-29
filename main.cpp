#include <cstddef>
#include <iostream>
#include "Automata.hpp"

using namespace std;

int main() {
    char c;
    Automata automata;
    while ((c = cin.get()) != EOF) {
        cin.unget();
        int i = 0;
        if (automata.procesar()) {
            // Se acepta
            cout << "Se acepta la cadena operacion.\n";
            }
        else {
            /// cin.get();
            cout << "No se acepta la cadena operacion.\n";
            }
        }
    return 0;
    }
