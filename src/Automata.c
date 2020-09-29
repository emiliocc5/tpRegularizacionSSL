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
char* concatCharToWord(char*, char);
void word_to_file(char);

enum STATE stateZeroTransitions(char c, char **palabra) {
    enum STATE state = E0;
    printf("State 0\n");
    if (charBelongs(c, languageA, languageASize)) {
        printf("transition to E1\n");
        //concatCharToWord(*palabra, c);
        state = E1;
    }

    if (charBelongs(c, languageB, languageBSize)) {
        printf("transition to E2\n");
        //concatCharToWord(*palabra, c);
        state = E2;
    }
    /* char *auxPalabra;
    auxPalabra = *palabra;
    printf("Palabra: %s \n", auxPalabra);
    *palabra = "emilio";
    strcat(auxPalabra, *palabra);
     */return state;
}

enum STATE stateOneTransitions(char c, char* palabra) {
    enum STATE state = E0;
    printf("State 1\n");
    if (charBelongs(c, languageA, languageASize)){
        printf("transition to E3\n");
        state = E3;
    }

    if (charBelongs(c, languageB, languageBSize)){
        printf("transition to E2\n");
        state = E2;
    }

    if (charBelongs(c, languageC, languageCSize)){
        printf("transition to E4\n");
        state = E4;
    }
    
    return state;
}

enum STATE stateTwoTransitions(char c, char* palabra) {
    printf("State 2\n");
    enum STATE state = E0;
    printf("final state, transition to 0\n");
    return state;
}

enum STATE stateThreeTransitions(char c, char* palabra) {
    enum STATE state = E0;
    printf("State 3\n");
    if (charBelongs(c, languageA, languageASize)){
        printf("transition to E3\n");
        state = E3;
    }

    if (charBelongs(c, languageB, languageBSize)){
        printf("transition to E2\n");
        state = E2;
    }

    return state;
}

enum STATE stateFourTransitions(char c, char* palabra) {
    enum STATE state = E0;
    printf("State 4\n");
     if (charBelongs(c, languageD, languageDSize)){
        printf("transition to E2");
        state = E2;
    }

    return state;
}

bool charBelongs(char c, char *languageToBelong, int languageToBelongSize) {
    for (int i=0; i < languageToBelongSize; i++){
        if (c == languageToBelong[i]){
            word_to_file(c); //TODO Sacar esto
            return true;
        }
    }
    return false;
}
 
void word_to_file(char c) {
    FILE *fptr;
    fptr = fopen("words_found.txt", "a");

    fprintf(fptr, "%c", c);
    fclose(fptr);
}

char* concatenarCadena (char* cadena1, const char* cadena2)
{
    int i = sizeof cadena1 / sizeof *cadena1;
    int j;
    for (j = 0; cadena2[j] != '\0'; j++, i++) {
        cadena1[i] = cadena2[j];
    } 
    cadena1[i] = '\0';
    return (cadena1);
}