#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Automata.h"

static char languageA[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static char languageB[] = {'F'};
static char languageC[] = {'.'};
static char languageD[] = {'0', '1'};
/* 
static char lang_a[] = {'0', '1'};
static int size_lang_a = 2;
static char lang_b[] = {'.'};
static int size_lang_b = 1;
static int size_lang_c = 10;
static char lang_d[] = {'B'};
static int size_lang_d = 1; */

bool charBelongsV2(char, char*);
//bool char_belongs(char, char*, int);
char* str_concat(char*, char);
void word_to_file(char);

enum STATE stateZeroTransitions(char c, char* palabra) {
    enum STATE state = E0;

    if (charBelongsV2(c, languageA))
        state = E1;

    if (charBelongsV2(c, languageB))
        state = E2;
    
    return state;
}

enum STATE stateOneTransitions(char c, char* palabra) {
    enum STATE state = E1;

    if (charBelongsV2(c, languageA))
        state = E3;

    if (charBelongsV2(c, languageB))
        state = E2;

    if (charBelongsV2(c, languageC))
        state = E4;
    
    return state;
}

enum STATE stateTwoTransitions(char c, char* palabra) {
    enum STATE state = E2;
    return state;
}

enum STATE stateThreeTransitions(char c, char* palabra) {
    enum STATE state = E3;
//El estado 3 tiene un bucle si llega una a, no lo contemplo en un condicional ya que no cambiaria de estado.
    if (charBelongsV2(c, languageB))
        state = E2;

    return state;
}

enum STATE stateFourTransitions(char c, char* palabra) {
    enum STATE state = E4;

     if (charBelongsV2(c, languageD))
        state = E2;

    return state;
}

//TODO Verificar si esto funciona
bool charBelongsV2(char c, char language[]) {
    int languageLength = strlen(language);
    for (int i = 0; i < languageLength; i++){
        if (c == language[i]){
            word_to_file(c);
            return true;
        }
    }
    return false;
}

/* bool char_belongs(char c, char *lang_x, int size_lang_x) {
    
    for (int i=0; i<size_lang_x; i++){
        if (c == lang_x[i]){
            word_to_file(c);
            return true;
        }
    }
    return false;
}
 */
void word_to_file(char c) {
    FILE *fptr;
    fptr = fopen("words_found.txt", "a");

    fprintf(fptr, "%c", c);
    fclose(fptr);
}