#include "automata.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int count = 1;
void print_word();
void elimina_archivo();

int main(){
    enum STATE state = E0;
    bool pop_out = false;

    char curr_char;
    char* usr_input;
    char* palabra = "";

    usr_input = malloc(5 * sizeof(char));

    while (true) {
        //clrscr();
        count = 1;
        printf("==> Expresion regular a analizar => [0-9]*F|[0-9]\\.[01]?\n");
        printf("==> Por favor, ingrese la linea de texto a analizar => ");
        scanf("%s", usr_input);
        printf("\n\n==> Las palabras del lenguaje a reconocer en la secuencia de texto ingresada son\n\n");

        for (int i = 0; i < (strlen(usr_input)); i++){
            curr_char = usr_input[i];

            if (curr_char == SENTINEL) {
                if ((state == E2) || (state == E4)) {
                    print_word();
                    state = E0;
                }

                pop_out = false;
                elimina_archivo();
            }
            else {
                if (pop_out == false) {
                    if (state == E0){
                        state = stateZeroTransitions(curr_char, palabra);
                    }

                    else if (state==E1){
                        state = stateOneTransitions(curr_char, palabra);
                    }

                    else if (state==E2){
                        state = stateTwoTransitions(curr_char, palabra);
                    }

                    else if (state==E3){
                        state = stateThreeTransitions(curr_char, palabra);
                    }
                    
                    else if (state==E4){
                        state = stateFourTransitions(curr_char, palabra);
                    }
                
                    if (state == E0)
                        pop_out = true;
                }
            }
        }

        printf("\n==> Desea evaluar otra cadena? [Y/N] => ");
        if ((getchar() == 'N') || (getchar() == 'n'))
            break;
    }

    elimina_archivo();
    free(usr_input);
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