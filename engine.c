#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "life.h"

extern int R;
extern int C;
extern int sleepTime;

void print(u_char** p) {
   for (int j = 0; j < C*2 + 2; j++)
      if(j == 0 || j == C*2 + 1)
         putchar('+');
      else 
         putchar('-');
   putchar('\n');
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         if(j == 0 )
            putchar('|');
         putchar(p[i][j]);
         putchar(' ');
      }
      putchar('|');
      putchar('\n');
   }
   for (int j = 0; j < C * 2 + 2; j++)
      if (j == 0 || j == C * 2 + 1)
         putchar('+');
      else
         putchar('-');
   putchar('\n');
}

void wait() {
   printf("\nPress any key to continue\n");
   _getch();
}

bool pause() {
   if (!_kbhit())
      return false;
   else {
      _getch();
      return true;
   }
}

void sleep() {
   Sleep(sleepTime);
}

void clear() {
   system("cls");
}

void stats(int gens) {
   printf("\nGeneration #%d", gens);
   printf("\tPress any button to pause\n");
}

void banner() {
   char* name = " CONWAY'S GAME OF LIFE ";
   int len = strlen(name);
   putchar('\n');
   putchar('\t');
   for (int i = 0; i < len; i++)
      putchar('*');
   printf("\n\t%s\n\t", name);
   for (int i = 0; i < len; i++)
      putchar('*');
   putchar('\n');
}

int get_input_between(int x, int y) {
   int choice;
   do
      scanf_s("%d", &choice);
   while(choice < x || choice > y);

   return choice;
}

void defaultConfig() {
   R = 25;
   C = 50;
   sleepTime = 500;
}

void get_dimensions() {
   printf("Choose # of cols -> ");
   C = get_input_between(2, 100);
   printf("Choose # of rows -> ");
   R = get_input_between(2, 100);
}

void get_sleep_time() {
   printf("Choose sleep time -> ");
   sleepTime = get_input_between(1, 10000);
}
