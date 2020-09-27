#ifndef AUTOMATA_H
#define AUTOMATA_H

// Centinela
static char SENTINEL = '%';

// Estados
enum STATE {E0, E1, E2, E4, E5}; 

// Funciones Utilizadas por automata
enum STATE stateZeroTransitions(char, char*);
enum STATE stateOneTransitions(char, char*);
enum STATE stateTwoTransitions(char, char*);
enum STATE stateFourTransitions(char, char*);
enum STATE stateFiveTransitions(char, char*);

#endif