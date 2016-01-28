#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

#include "../include/include.h"

#define ROWS 9
#define COLS 9

enum Direction { LEFT, RIGHT, FRONT, BACK };

extern int maze[ROWS][COLS];

//prototypes
Direction* getDirections();
bool initMaze();
void recursion(int, int);


#endif // MAZE_H_INCLUDED
