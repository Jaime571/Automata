#include "Automata.hpp"


bool Automata::procesar(void) {
    size_t estado = 0;
    char c;
    while((c = std::cin.get()) != '\n')
        estado = MATRIZ_DE_TRANSICIONES[estado][posicionAlfabeto(c)];
    return esFinal(estado);
    }

size_t Automata::posicionAlfabeto(char c) {
    size_t i = 0;
    for(i = 0; i < CANT_SIMBOLOS; i++)
        if(SIMBOLOS[i] == c) return i;
    return i;
    }

bool Automata::esFinal(size_t estado) {
    size_t i;
    for(i = 0; i < CANT_ESTADOS_FINALES; i++)
        if(estado == ESTADOS_FINALES[i]) return true;
    return false;
    }

