#include "Automata.hpp"

using namespace std;

bool Automata::procesar(void) {
    size_t estado = 0;
    char c;

    bool isFlotante = false;

    while((c = cin.get()) != '\n') {
        if(estado != 8) setErr(c);

        if(c == '.'){
            cout << "[Flotante] ";
            isFlotante = true;
        }else if(c == '+' or c == '-' or c == '*' or c == '/'){
            if(!isFlotante)
                cout << "[Entero] ";
                isFlotante = false;
        }

        switch(c){
            case '+':
                cout << "Suma ";
            break;

            case '-':
                cout << "Resta ";
            break;

            case '*':
                cout << "Multiplicacion ";
            break;

            case '/':
                cout << "Division ";
            break;
        }
        estado = MATRIZ_DE_TRANSICIONES[estado][posicionAlfabeto(c)];
        }

        if(!isFlotante){
            cout << "[Entero] ";
            isFlotante = false;
        }
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

void Automata::setErr(char c) {
    err += c;
    }

string Automata::getErr(void) {
    return err;
    }

void Automata::eraseErr(void) {
    err = '\0';
    }

