/*
 * Conway's Game of Life Menus
 * 
 */

#include "conway.h"

char grid[MAXH][MAXW];
char nextGen[MAXH][MAXW]; 
char tempGen[MAXH][MAXW];

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
		
	// Saving the tempGrid
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++)
			tempGen[h][w] = grid[h][w];
}


void restore()
{
	int h, w;
	for(h=0; h < MAXH; h++)
		for(w=0; w < MAXW; w++)
			grid[h][w] = tempGen[h][w];
}


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

void saveGrid()
{
	FILE *fp;
	int h, w;
	char filename[128];
	
	printf("\n\tInsert file name \n \
\t(if doesn't exits, will be created):\n\t");
	scanf("%s", filename);
	
	// Get template file for edit
	if(strcmp(filename, "template") == 0){
		fp = fopen(filename, "w");
		for(h=0; h < MAXH; h++){
			if (h != 0)
				fprintf(fp, "n\n");
			for(w=0; w < MAXW; w++)
				fprintf(fp, ". ");
		}
		fputc(EOF, fp);
		fclose(fp);
		return;
	}
	
	fp = fopen(filename, "a");
	
	for(h=0; h < MAXH; h++){
		if (h != 0)
			fprintf(fp, "n\n");
		for(w=0; w < MAXW; w++)
			fprintf(fp, "%c ", grid[h][w]);
	}
	fputc(EOF, fp);
	fclose(fp);
}

void loadGrid() // NOT WORKING
{
	FILE *fp;
	int h, w, c;
	char filename[128];
	
	printf("\n\tInsert file name:\n\t");
	scanf("%s", filename);
	
	// Cancel loading if input is 'q'
	if(strcmp(filename, "q") == 0){
		system("cls");
		printf("\tLoading canceled.\n");
		return;
	}
	
	fp = fopen(filename, "r");
	
	c = fgetc(fp);
	
	for(h=0; c != EOF; h++){
		printf("trying to load...\n");
		for(w=0; c != 'n'; w++){
			if(c == 'O' || c == '.')
				grid[h][w] = c;
			c = fgetc(fp);
		}
		c = fgetc(fp);
	}
	
	fclose(fp);
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
				loadGrid();
				printf("\tFile loaded!\n");
				menu();
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
		printf("\t5. Restore to this grid start\n");
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
				saveGrid();
				print();
				printf("\n\tFile saved!");
				break;
			case 5:
				restore();
				print();
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


