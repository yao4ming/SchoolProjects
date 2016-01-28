#include "maze.h"

int maze[ROWS][COLS];

//returns shuffled array of directions(left, right, front, back)
Direction* getDirections()
{
    //static array to keep for duration of program
    static Direction directions[] = {LEFT, RIGHT, FRONT, BACK};

    //shuffle array 10 times to randomize directions
    for(int i = 0; i < 10; i++) {
        int one = rand() % 4;
        int two = rand() % 4;
        while(one == two) two = rand() % 4;
        swap(directions[one], directions[two]);
    }

    return directions;

}

//return true if maze was successfully generated false otherwise
bool initMaze()
{
    //used for random generator
    srand((unsigned)time(NULL));

	//init maze filled with 1(wall)
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){
			maze[i][j] = 1;
		}
	}

    //starting point
	maze[3][3] = 0;

	//go through maze
	recursion(3, 3);
    cout << endl;

    //ending point
    maze[3][8] = 0;

    return true;

}

//recursively go through maze to create a path
void recursion(int r, int c)
{
    Direction* directions = getDirections();

	for(int i = 0; i < 4; i++)
        cout << directions[i] << " ";
	cout << endl;

	//try other direction if one fails
	for(int i = 0; i < 4; i++) {
        //print maze
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++)
            {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }

    cout << "At: " << r << c << endl;
        switch (directions[i]){
            case FRONT:{
                cout << "front" << " ";
                // Whether 2 cells up is out of bounds
                if (r - 2 <= 0 || maze[r - 2][c] == 0) {
                    cout << "continue" << endl;
                    continue;
                }
                //Move 2 space front unless theres already a path
                if (maze[r - 2][c] != 0) {
                    maze[r - 2][c] = 0;
                    maze[r - 1][c] = 0;
                    cout << "moved" << endl;
                    recursion(r - 2, c);
                }
                cout << "continue/break" << endl;
                continue;

            }

            case RIGHT:{
                cout << "right" << " ";
                // Whether 2 cells to the right is out of bounds
                if (c + 2 >= COLS - 1 || maze[r][c + 2] == 0)  {
                    cout << "continue" << endl;
                    continue;
                }
                //Move 2 space front unless theres already a path
                if (maze[r][c + 2] != 0) {
                    maze[r][c + 2] = 0;
                    maze[r][c + 1] = 0;
                    cout << "moved" << endl;
                    recursion(r, c + 2);
                }
                cout << "continue/break" << endl;
                continue;
            }

            case BACK:{
                 cout << "back" << " ";
                // Whether 2 cells down is out of bounds
                if (r + 2 >= ROWS - 1 || maze[r + 2][c] == 0)  {
                    cout << "continue" << endl;
                    continue;
                }
                //Move 2 space back unless theres already a path
                if (maze[r + 2][c] != 0) {
                    maze[r + 2][c] = 0;
                    maze[r + 1][c] = 0;
                    cout << "moved" << endl;
                    recursion(r + 2, c);
                }
                cout << "continue/break" << endl;
                continue;

            }

            case LEFT:{
                cout << "left ";
                // Whether 2 cells to the left is out of bounds
                if (c - 2 <= 0 || maze[r][c - 2] == 0)  {
                    cout << "continue" << endl;
                    continue;
                }
                // Move 2 space left unless theres already a path
                if (maze[r][c - 2] != 0) {
                    maze[r][c - 2] = 0;
                    maze[r][c - 1] = 0;
                    cout << "moved" << endl;
                    recursion(r, c - 2);
                }
                cout << "continue/break" << endl;
                continue;
            }
        }
	}
	cout << "end loop" << endl;

}

