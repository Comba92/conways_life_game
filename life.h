#ifndef LIFE_H_INCLUDED
#define LIFE_H_INCLUDED

#define LIVE 254
#define DEAD ' '

#define FILENAME "loadFile.txt"

int R;
int C;

typedef unsigned char u_char;
typedef enum booleans { true = 1, false = 0 } bool;

/* game_logic */
bool inBounds(int x, int y);
bool isAlive(u_char c);
int checkNear(u_char** grid, int x, int y);
void update(u_char*** grid, u_char*** updateGrid);

/* initializers */
u_char** deadState();
u_char** randomState();
u_char** loadState(char* dest);

/* user_interface */
void print(u_char** p);
void wait();
void sleep(int t);
void banner();
void clear();
void loop(u_char *g);
int get_input_between();
void get_dimensions();

#endif 