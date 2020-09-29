#ifndef AUTOMATA_H
#define AUTOMATA_H

// Centinela
static char SENTINEL = '%';

// Estados
enum STATE {E0, E1, E2, E3, E4}; 

// Funciones Utilizadas por automata
enum STATE stateZeroTransitions(char, char**);
enum STATE stateOneTransitions(char, char*);
enum STATE stateTwoTransitions(char, char*);
enum STATE stateThreeTransitions(char, char*);
enum STATE stateFourTransitions(char, char*);

#endif