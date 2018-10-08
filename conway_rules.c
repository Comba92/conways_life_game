/*
 * Conway's Game of Life Rules
 * Coded by Comba92
 * 
 */
 
#include "conway.h"

char grid[MAXH][MAXW];
char nextGen[MAXH][MAXW]; 
char tempGen[MAXH][MAXW];

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
