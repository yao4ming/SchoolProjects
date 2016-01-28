
– How you decided to render the maze
	1. Pick start and end point, begin at start
	2. Pick direction from shuffled array(left, right, front, back)
	3. Check if two units in direction is path(0) or out of bounds
	4. If (out of bounds) goto 2
	5. If (0) goto 2
	5. Else move
	6. Recursively repeat 2-6
	Creates a maze with a few dead ends and 1 exit
	
– Decisions and tradeoffs you made
	-maze generated using recursion, simply assigned starting and ending point(no algorithm)
	-Used element buffer to reuse vertices for cube
	-Rendered same cube multiple times with translation applied, thus only one set of cube vertices has to be specified
	
– Describe any extra features you added and how to access them.
	-maze is randomly generated(each launch generates a different maze)
	-included texture mapping
	-able to change fovy using f/F
	-press q to quit
	
	Note: Opengl contains SOIL header/library
	Note: Player starts in the middle of maze
	Goal: Find your way out