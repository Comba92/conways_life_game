/*
 * Conway's Game of Life Header
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXH 10
#define MAXW 10


/* The grid that will be printed */
extern char grid[MAXH][MAXW];

/* The grid needed for evolve; all the configs will be saved on nextGen
 * and then copied into grid. */
extern char nextGen[MAXH][MAXW]; 

/* Temp grid for restore initial stats */
extern char tempGen[MAXH][MAXW];


void init();
void initToAlive();
void start();
void menu();
void print();
void saveGrid();
void loadGrid();

int isAlive(int height, int width);
int sumNear(int height, int width);
char updateStat(int height, int width);
void updateGen();
void updateNGens(int gens);
void restore();
void debugCell(int height, int width);
