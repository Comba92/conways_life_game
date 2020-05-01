#include "life.h"

int main()
{
   int choice;
   banner();
   printf("\t 1. Play a random game\n");
   printf("\t 2. Load a state\n");
   printf("\t 3. Quit\n");

   choice = get_input_between(1, 3);

   switch (choice) {
      case 1: 
         get_dimensions();
         loop(randomState());
         break;
      case 2:
         loop(loadState(FILENAME));
         break;
      case 3: exit(0);
      default: 
         printf("\t\nWHAT HAVE U DONE???\n");
   }

   return 0;
}
