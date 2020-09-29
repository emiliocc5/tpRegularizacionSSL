#include "automata.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

//TODO, armar una especie de "Sistema anti fallos", en el cual, si el ultimo caracter de la cadena no es un %, se le concatena uno

int count = 1;

int main(){
    enum STATE state = E0;
    bool exit = false;

    char currentCharacter;
    char* userInput;
    char *palabra = "";

    userInput = malloc(15 * sizeof(char));

    while (true) {
        count = 1;
        printf("ER dada: [0-9]*F|[0-9]\\.[01]?\n");
        printf("Ingrese la cadena a analizar (Centinela: %%): ");
        scanf("%s", userInput);
        printf("\n\nLas palabras a reconocer en la secuencia de texto ingresada son: \n\n");

        for (int i = 0; i < (strlen(userInput)); i++) {
            currentCharacter = userInput[i];
            if (currentCharacter == SENTINEL) {
                if ((state == E2) || (state == E4)) {
                    printf("\t%d) %s \n ", count, palabra);
                    count++;
                    palabra = "";
                    state = E0;
                }
                exit = false;
            }
            else {
                if (exit == false) { 
                    switch (state) {
                    case E0:
                        state = stateZeroTransitions(currentCharacter, &palabra);
                        break;
                    case E1:
                        state = stateOneTransitions(currentCharacter, &palabra);
                        break;
                    case E2:
                        state = stateTwoTransitions(currentCharacter, &palabra);
                        break;
                    case E3:
                        state = stateThreeTransitions(currentCharacter, &palabra);
                        break;
                    case E4:
                        state = stateFourTransitions(currentCharacter, &palabra);
                        break;
                    }
                    if (state == E0)
                        exit = true;
                }
            }
        }
        printf("\n Desea evaluar otra cadena? [Y/N]:  ");
        if ((getchar() == 'N') || (getchar() == 'n'))
            break;
    }
    free(userInput);
    return 0;
}

