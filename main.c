#include <stdio.h>
#include "life.h"


void loop(u_char** grid) {
   u_char** updateGrid = deadState();
   clear();
   int counter=1;
   while (1) {
      print(grid);
      stats(counter++);
      update(&grid, &updateGrid);
      if (pause()) {
         wait();
      }
      else sleep();
      clear();
   }
}


int main()
{
   int choice;
   defaultConfig();

   while(1) {
      banner();
      printf("\t 1. Play a random game\n");
      printf("\t 2. Load a state\n");
      printf("\t 3. Settings\n");
      printf("\t 4. Quit\n\t ");

      choice = get_input_between(1, 4);

      switch (choice) {
         case 1: 
            loop(randomState());
            break;
         case 2:
            loop(loadState(FILENAME));
            break;
         case 3:
            get_dimensions();
            get_sleep_time();
            clear();
            break;
         case 4: exit(0);
      }
   }

   return 0;
}
