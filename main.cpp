#include <cstddef>
#include <iostream>

using namespace std;

const size_t SIMBOLOS [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '.'};
const size_t CANT_SIMBOLOS = 15;

const size_t MATRIZ_DE_TRANSICIONES [][16] = {
///      0  1  2  3  4  5  6  7  8  9  +  -  *  /  .  ERR
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8, 1, 8}, /// q0
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 8, 8}, /// q1
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 1, 8}, /// q2
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 8, 8, 1, 8}, /// q3
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 1, 8}, /// q4
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 6, 8}, /// q5
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8}, /// q6
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 3, 3, 8, 8}, /// q7
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, /// q8 Estado de error
    };

const size_t ESTADOS_FINALES [] = {0, 5, 7};
const size_t CANT_ESTADOS_FINALES = 3;



bool automata(void);
size_t posicionAlfabeto(char);
bool esFinal(size_t);

int main() {
    char c;
    while ((c = cin.get()) != EOF) {
        cin.unget();
        int i = 0;
        if (automata()) {
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

size_t posicionAlfabeto(char c) {
    size_t i = 0;
    for(i = 0; i < CANT_SIMBOLOS; i++)
        if(SIMBOLOS[i] == c) return i;
    return i;
    }

bool esFinal(size_t estado) {
    size_t i;
    for(i = 0; i < CANT_ESTADOS_FINALES; i++)
        if(estado == ESTADOS_FINALES[i]) return true;
    return false;
    }

bool automata(void) {
    size_t estado = 0;
    char c;
    while((c = cin.get()) != '\n')
        estado = MATRIZ_DE_TRANSICIONES[estado][posicionAlfabeto(c)];
    return esFinal(estado);
    }
