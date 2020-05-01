#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "life.h"

extern int R;
extern int C;

void print(u_char** p) {
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         putchar(p[i][j]);
         putchar(' ');
      }
      putchar('\n');
   }
}

void wait() {
   getchar();
}

void sleep(int t) {
   Sleep(t);
}

void clear() {
   system("cls");
}


void banner() {
   char* name = " CONWAY'S GAME OF LIFE ";
   int len = strlen(name);
   putchar('\t');
   for (int i = 0; i < len; i++)
      putchar('*');
   printf("\n\t%s\n\t", name);
   for (int i = 0; i < len; i++)
      putchar('*');
   putchar('\n');
}

void loop(u_char **grid) {
   u_char **updateGrid = deadState();
   clear();
   while (1) {
      print(grid);
      update(&grid, &updateGrid);
      sleep(500);
      clear();
   }
}


int get_input_between(int x, int y) {
   int choice;
   do
      scanf_s("%d", &choice);
   while(choice < x || choice > y);

   return choice;
}

void get_dimensions() {
   printf("Choose # of cols -> ");
   C = get_input_between(2, 100);
   printf("Choose # of rows -> ");
   R = get_input_between(2, 100);
}