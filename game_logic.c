#include "life.h"

extern int R;
extern int C;

bool inBounds(int x, int y) {
   if (x < 0 || x >= R || y < 0 || y >= C) return false;
   else return true;
}

bool isAlive(u_char c) {
   if (c == DEAD) return false;
   else return true;
}

int checkNear(u_char** grid, int x, int y) {
   int sum = 0;
   for (int i = x - 1; i <= x + 1; i++)
      for (int j = y - 1; j <= y + 1; j++)
         if (inBounds(i, j) && isAlive(grid[i][j]) && !(i == x && j == y))
            sum++;

   return sum;
}

void update(u_char*** grid, u_char*** updateGrid) {
   for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) {
         int nears = checkNear(*grid, i, j);

         if (isAlive((*grid)[i][j])) {
            if (nears == 3 || nears == 2)
               (*updateGrid)[i][j] = LIVE;
            else (*updateGrid)[i][j] = DEAD;
         }
         else if (nears == 3) (*updateGrid)[i][j] = LIVE;
         else (*updateGrid)[i][j] = DEAD;
      }

   /* We swap the two pointers so we haven't to rewrite the updated matrix
   *  to the old one, and always using the same memory. The updatedGrid becomes
   *  the grid to be printed, and grid becomes the next updateGrid
   */
   u_char** temp = *grid;
   *grid = *updateGrid;
   *updateGrid = temp;
}
