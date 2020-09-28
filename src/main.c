#include "automata.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

//TODO Ver en donde se esta usando el parametro palabra que se pasa a la funcion de transicion
//TODO hacer funcionar el charBelongs sin pasarle la longitud del lenguajes
//TODO, Descartar los que no pertenecen al lenguaje, ya que se meten como basura cuando seguido hay uno que si pertenece.
//TODO, Ver como hacer para descartar llevar todo a un archivo y despues traerlo e imprimirlo

int count = 1;
void print_word();
void elimina_archivo();

int main(){
    enum STATE state = E0;
    bool exit = false;

    char currentCharacter;
    char* userInput;
    char* palabra = "";

    userInput = malloc(15 * sizeof(char));

    while (true) {
        //clrscr();
        count = 1;
        printf("ER dada: [0-9]*F|[0-9]\\.[01]?\n");
        printf("Ingrese la cadena a analizar (Centinela: %%): ");
        scanf("%s", userInput);
        printf("\n\nLas palabras del lenguaje a reconocer en la secuencia de texto ingresada son: \n\n");

        for (int i = 0; i < (strlen(userInput)); i++) {
            currentCharacter = userInput[i];
            printf("Current character: %c\n", currentCharacter);
            if (currentCharacter == SENTINEL) {
                if ((state == E2) || (state == E4)) {
                    print_word();
                    state = E0;
                }
                exit = false;
                elimina_archivo();
            }
            else {
                if (exit == false) {
                    if (state == E0){
                        state = stateZeroTransitions(currentCharacter, palabra);
                    }

                    else if (state == E1){
                        state = stateOneTransitions(currentCharacter, palabra);
                    }

                    else if (state == E2){
                        state = stateTwoTransitions(currentCharacter, palabra);
                    }

                    else if (state == E3){
                        state = stateThreeTransitions(currentCharacter, palabra);
                    }
                    
                    else if (state==E4){
                        state = stateFourTransitions(currentCharacter, palabra);
                    }
                
                    if (state == E0)
                        exit = true;
                }
            }
        }

        printf("\n==> Desea evaluar otra cadena? [Y/N] => ");
        if ((getchar() == 'N') || (getchar() == 'n'))
            break;
    }

    elimina_archivo();
    free(userInput);
    return 0;
}

void print_word() {
    char c;
    FILE *fptr;

    fptr = fopen("words_found.txt", "r");
    c = fgetc(fptr);
    
    printf("\t%d) ", count);
    while (c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    remove("words_found.txt");
    printf("\n");
    count++;
}

void elimina_archivo(){
    FILE *fptr;
    fptr = fopen("words_found.txt", "r");
    if (fptr != NULL)
        remove("words_found.txt");
    
    fclose(fptr);
}