#ifndef HANGMAN_COED_
#define HANGMAN_COED_

#include <stdio.h> // for printf and scanf... etc.

#include<conio.h> // for getch function

#include <string.h> //for strcpy, strcmp, and strlen

#include <stdlib.h> // rand function

#include <time.h> // use to implement srand


#define clear system("cls") // define system("cls") to clear for easy coding.
#define e 10
#define randomizer srand(time(NULL))

int introduction(char * answer);
void Print();
void load();
void blank();
void Game();
void showHangman(int);
void planeFig(void);


#endif