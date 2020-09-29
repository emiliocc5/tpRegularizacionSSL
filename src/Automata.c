#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Automata.h"

static char languageA[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static int languageASize = sizeof languageA / sizeof *languageA;
static char languageB[] = {'F'};
static int languageBSize = sizeof languageB / sizeof *languageB;
static char languageC[] = {'.'};
static int languageCSize = sizeof languageC / sizeof *languageC;
static char languageD[] = {'0', '1'};
static int languageDSize = sizeof languageD / sizeof *languageD;

bool charBelongs(char, char*, int);
char* intermediate(char*, const char);
char* concatCharToWord(char*, const char, char*, size_t);

enum STATE stateZeroTransitions(char c, char **palabra) {
    enum STATE state = E0;
    if (charBelongs(c, languageA, languageASize)) {
        *palabra = intermediate(*palabra, c);
        state = E1;
    }

    if (charBelongs(c, languageB, languageBSize)) {
        *palabra = intermediate(*palabra, c);
        state = E2;
    }
    return state;
}

enum STATE stateOneTransitions(char c, char **palabra) {
    enum STATE state = E0;
    if (charBelongs(c, languageA, languageASize)){
        *palabra = intermediate(*palabra, c);
        state = E3;
    }

    if (charBelongs(c, languageB, languageBSize)){
        *palabra = intermediate(*palabra, c);
        state = E2;
    }

    if (charBelongs(c, languageC, languageCSize)){
        *palabra = intermediate(*palabra, c);
        state = E4;
    }
    
    return state;
}

enum STATE stateTwoTransitions(char c, char **palabra) {
    enum STATE state = E0;
    *palabra = intermediate(*palabra, c);
    return state;
}

enum STATE stateThreeTransitions(char c, char **palabra) {
    enum STATE state = E0;
    if (charBelongs(c, languageA, languageASize)){
        *palabra = intermediate(*palabra, c);
        state = E3;
    }

    if (charBelongs(c, languageB, languageBSize)){
        *palabra = intermediate(*palabra, c);
        state = E2;
    }
    return state;
}

enum STATE stateFourTransitions(char c, char **palabra) {
    enum STATE state = E0;
     if (charBelongs(c, languageD, languageDSize)){
        *palabra = intermediate(*palabra, c);
        state = E2;
    }

    return state;
}

bool charBelongs(char c, char *languageToBelong, int languageToBelongSize) {
    for (int i=0; i < languageToBelongSize; i++){
        if (c == languageToBelong[i]){
            return true;
        }
    }
    return false;
}

char* intermediate(char* cadena1, const char caracterAConcatenar) {
    size_t len = strlen(cadena1);
    char *str2 = malloc(len + 1 + 1 );
    return concatCharToWord(cadena1, caracterAConcatenar, str2, len);
}

char* concatCharToWord(char* cadena1, const char caracterAConcatenar, char *strFinal, size_t len) {
    strcpy(strFinal, cadena1);
    strFinal[len] = caracterAConcatenar;
    strFinal[len + 1] = '\0';
    return (strFinal);
}