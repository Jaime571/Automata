#ifndef AUTOMATA_HPP_INCLUDED
#define AUTOMATA_HPP_INCLUDED

#include <iostream>
#include <cstddef>
#include <string>

class Automata {
    private:
        int CONT_ERROR = 0;

        const size_t SIMBOLOS [15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '.'};

        const size_t MATRIZ_DE_TRANSICIONES [9][16] = {
            ///  0  1  2  3  4  5  6  7  8  9  +  -  *  /  .  ERR
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

        const size_t CANT_SIMBOLOS = 15;
        const size_t ESTADOS_FINALES [3] = {0, 5, 7};
        const size_t CANT_ESTADOS_FINALES = 3;
        std::string err;
        size_t posicionAlfabeto(char);
        bool esFinal(size_t);

    public:
        bool procesar(void);
        void setErr(char);
        std::string getErr(void);
        void eraseErr(void);

    };

#endif // AUTOMATA_HPP_INCLUDED
