/*
 * Conway's Game of Life
 * Alpha v 2.0
 * Coded by Comba92
 * 
 * 
 * TO-DO LIST: 
 *  1. CAPISCI che cazzo succede in sumNear
 * 	2. DIVIDERE il programma in più files
 *  3. CAMBIA tutte le variabili di input da int in char (per evitare
 * 	buffer overflow); inoltre, non sarebbe meglio verificare l'input 
 * 	con un do-while piuttosto che nello switch???
 * 	4. Implementare salvataggio/caricamento files
 * 	5. Possibilità di scegliere grandezza griglia
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXH 10
#define MAXW 10


/* The grid that will be printed */
char grid[MAXH][MAXW];

/* The grid needed for evolve; all the configs will be saved on nextGen
 * and then copied into grid. */
char nextGen[MAXH][MAXW]; 

/* Temp grid for restore initial stats */
char tempGen[MAXH][MAXW];

void init();
void initToAlive();
void start();
void menu();
void print();

int isAlive(int height, int width);
int sumNear(int height, int width);
char updateStat(int height, int width);
void updateGen();
void updateNGens(int gens);
void debugCell(int height, int width);


int main(int argc, char **argv)
{
	srand(time(0));
	
	start();
	return 0;
}

void initToAlive()
{
	int h, w;
	
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++){
			grid[h][w] = 'O';
		}
}

void debugCell(int h, int w)
{
	printf("\n[DEBUG]: Checking stat of (%d, %d)...\tIt's %s.\t%d \
near are alive.\n", h, w,
(isAlive(h, w))? "Alive" : "Dead", sumNear(h, w));
}


// RULES HERE 


/* Initialize the grid to random stats. */
void init()
{
	int h, w;
	char stat;
	
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++){
			if(rand() % 2)
				stat = 'O';
			else
				stat = '.';
			grid[h][w] = stat;
		}
}

/* Takes cell coordinates and returns if it's alive or not;
 * We need this function because in the grid are actually saved the 
 * chars 'O' and '.'. This function will then be used in booleans
 * operations. */
int isAlive(int h, int w)
{
	if (grid[h][w] == 'O')
		return 1;
	else
		return 0;
}

/* Takes the cell coordinates and returns how many neighboors
 * the cell has; I actually don't know how it work... */
int sumNear(int h, int w)
{
	// NOT WORKING 
	/*int total = 0;
	
	if(isAlive(h-1, w)) // UP
		total++;
	if(isAlive(h+1, w)) // DOWN
		total++;
	if(isAlive(h, w-1)) // LEFT
		total++;
	if(isAlive(h, w+1)) // RIGHT
		total++;
	if(isAlive(h-1, w-1)) // UP-LEFT
		total++;
	if(isAlive(h+1, w-1)) // DOWN-LEFT
		total++;
	if(isAlive(h-1, w+1)) // UP-RIGHT
		total++;
	if(isAlive(h+1, w+1)) // DOWN-RIGHT
		total++;
	
	return total;*/
	
	// HOW THE FUCK SHOULD THIS WORK???
    int total = 0;
    int x, y, i, j; 
    for (x = -1; x <= 1; x += 1) {
		for (y = -1; y <= 1; y += 1) {
			i = h + y,
            j = w + x;
            if (i >= 0 && i < MAXW && j >= 0 && j < MAXH && !(y == 0 && x == 0) && isAlive(i, j)) {
				total += 1;
            }
        }
    }
	return total;
}

/* Takes the cell coordinates and returns Alive or Dead char applying 
 * the game's rules. sumNear() returns the number of neighboors a cell 
 * has, so we can store it in a var and check the conditions. */
char updateStat(int h, int w)
{
	int near = sumNear(h, w);
	
	if(isAlive(h, w)) {
		if(near == 2 || near == 3)
			return 'O';
		else return '.';
	}
	else
		if(near == 3)
			return 'O';
		else return '.';
}

/* Now updateStat() will do all the work; here we only need to copy all 
 * the values returned in a temp grid (nextGen). Then we copy the temp
 * grid in the actual grid. */
void updateGen()
{
	int h, w;
	
	// SETTING NEW GENERATION INTO nextGen GRID.
	
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++)
			nextGen[h][w] = updateStat(h, w);
	
	// COPYING nextGen into grid.
	
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++)
			grid[h][w] = nextGen[h][w];
}

void updateNGens(int n)
{
	int i;
	for(i = 0; i < n; i++)
		updateGen();
}


// MENUS HERE


void print()
{
	int h, w, i;
	
	system("cls");
	
	for(h=0; h < MAXH; h++){
		if(h==0){
			printf("\t");
			for(i=0; i < MAXH; i++)
				printf("%-3d", i);
			printf("\n\n");
		}
		printf("%d\t", h);
		for(w=0; w < MAXW; w++)
			printf("%c  ", grid[h][w]);
		printf("\n");
	}
}

void start()
{
	int i, input;
	for(i=0; i<49; i++)
		printf("*");
	printf("\n*\tWELCOME TO CONWAY'S GAME OF LIFE\t*\n");
	for(i=0; i<49; i++)
		printf("*");
	
	while(1){
		printf("\n\n\tSelect an option and press enter:\n");
		printf("\t1. INIT AND PRINT GRID\n");
		printf("\t2. LOAD CUSTOM GRID\n");
		printf("\t3. QUIT\n\t");
		scanf("%d", &input);
		
		switch(input){
			case 1:
				init();
				menu();
				break;
			case 2:
				system("cls");
				printf("\tWork in progress...\n");
				break;
			case 3:
				exit(1);
			default:
				system("cls");
				printf("\tChoose a number!\n");
		}
	}
}

void menu()
{
	int input;
	
	print();
	
	while(1){
		printf("\n\n\tWhat to do?\n");
		printf("\t1. Evolve to Next Generation\n");
		printf("\t2. Evolve n Generations\n");
		printf("\t3. Get cell stat\n");
		printf("\t4. Save grid to file\n");
		printf("\t5. Retrurn to this grid start\n");
		printf("\t6. Random reset\n");
		printf("\t7. < Back <\n\t");
		scanf("%d", &input);
		
		switch(input){
			case 1:
				updateGen();
				print();
				break;
			case 2:
				printf("\tHow many Gens?\t");
				scanf("%d", &input);
				updateNGens(input);
				print();
				break;
			case 3:
				printf("\tInsert a cell coordinate in 'x y' format\n\t");
				int x, y;
				scanf("%d%d", &x, &y);
				print();
				debugCell(x, y);
				break;
			case 4:
				print();
				printf("\n\tWork in progress...");
				break;
			case 5:
				print();
				printf("\n\tWork in progress...");
				break;
			case 6:
				init();
				print();
				break;
			case 7:
				system("cls");
				return;
			default:
				print();
				printf("\tChoose a number!");
		}
	}
}




