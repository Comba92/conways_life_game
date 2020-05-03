#include <stdio.h>
#include <stdlib.h>
#include "life.h"

u_char** deadState() {

   u_char** p = (u_char**)malloc(R * sizeof(u_char*));

   for (int i = 0; i < R; i++) {
      p[i] = (u_char*)malloc(C * sizeof(u_char));
      memset(p[i], DEAD, C);
   }
   return p;
}

u_char** randomState() {
   u_char** p = (u_char**)malloc(R * sizeof(u_char*));

   for (int i = 0; i < R; i++) {
      p[i] = (u_char*)malloc(C * sizeof(u_char));
      for (int j = 0; j < C; j++) {
         u_char state = (rand() % 2) ? LIVE : DEAD;
         p[i][j] = state;
      }

   }
   return p;
}

u_char** loadState(char* dest) {
   FILE* fp;
   char** p;
   int c;

   fopen_s(&fp, "toad.txt", "r");
   if (fp) {
      int rows = 0, cols = 0;
      while ((c = fgetc(fp)) != EOF)
         if (rows == 0 && c != '\n') cols++;
         else if (c == '\n') rows++;
      R = rows;
      C = cols;
      rewind(fp);

      p = (char**)malloc(R * sizeof(char*));
      for (int i = 0, j = 0; i < R; i++) {
         p[i] = (char*)malloc(C * sizeof(char));
         while ((c = fgetc(fp)) != '\n')
            if (c == '1') p[i][j++] = LIVE;
            else p[i][j++] = DEAD;
         j = 0;
      }
   }

   else {
      fprintf(stderr, "File not found!");
      return NULL;
   }

   return p;
}