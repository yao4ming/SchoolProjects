
#include <windows.h>
#include <Angel.h>
#include <iostream>
using namespace std;

typedef Angel::vec4  color4;
typedef Angel::vec4  point4;

// Vertices of a Trapezoidal Prism 
point4 vertices[] = {

	//--------------------------------front face-------------------------------------------

	point4(-0.7, -0.5, 0.5, 1.0),	//left bottom front face
	point4(0.7, -0.5, 0.5, 1.0),	//right bottom front face
	point4(0.3, 0.5, 0.5, 1.0),		//right top front face

	point4(0.3, 0.5, 0.5, 1.0),		//right top front face
	point4(-0.3, 0.5, 0.5, 1.0),	//left top front face
	point4(-0.7, -0.5, 0.5, 1.0),	//left bottom front face

	//--------------------------------Back face---------------------------------------------


	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom back face
	point4(0.7, -0.5, -0.5, 1.0),	//right bottom back face
	point4(0.3, 0.5, -0.5, 1.0),	//right top back face


	point4(0.3, 0.5, -0.5, 1.0),	//right top back face
	point4(-0.3, 0.5, -0.5, 1.0),	//left rop back face
	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom back face

	//---------------------------------Right face---------------------------------------


	point4(0.7, -0.5, -0.5, 1.0),	//right bottom back face
	point4(0.3, 0.5, -0.5, 1.0),	//right top back face
	point4(0.3, 0.5, 0.5, 1.0),		//right top front face

	
	point4(0.3, 0.5, 0.5, 1.0),		//right top front face
	point4(0.7, -0.5, 0.5, 1.0),	//right bottom front face
	point4(0.7, -0.5, -0.5, 1.0),	//right bottom back face

	//---------------------------------Left face----------------------------------------

	point4(-0.3, 0.5, 0.5, 1.0),	//left top front face
	point4(-0.7, -0.5, 0.5, 1.0),	//left bottom front face
	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom back face

	point4(-0.3, 0.5, -0.5, 1.0),	//left top back face
	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom back face
	point4(-0.3, 0.5, 0.5, 1.0),	//left top front face

	//---------------------------------Top face------------------------------------------

	point4(-0.3, 0.5, -0.5, 1.0),	//left top front face
	point4(0.3, 0.5, -0.5, 1.0),	//right top front face
	point4(0.3, 0.5, 0.5, 1.0),		//right top back face

	point4(-0.3, 0.5, 0.5, 1.0),	//left top back face
	point4(-0.3, 0.5, -0.5, 1.0),	//left top front face
	point4(0.3, 0.5, 0.5, 1.0),		//right top back face

	//---------------------------------Bottom face----------------------------------------

	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom front face
	point4(0.7, -0.5, -0.5, 1.0),	//right bottom front face
	point4(0.7, -0.5, 0.5, 1.0),	//right bottom back face

	point4(-0.7, -0.5, 0.5, 1.0),	//left bottom back face
	point4(-0.7, -0.5, -0.5, 1.0),	//left bottom front face
	point4(0.7, -0.5, 0.5, 1.0)		//right bottom back face
};

//compute the center of object 
//(left + right)/2 = x
//(top + bottom)/2 = y
//(near + far)/2 = z
point4 trapezoidal_center = (
	(vertices[0].x + vertices[1].x) / 2,
	(vertices[1].y + vertices[2].y) / 2,
	(vertices[3].z + vertices[4].z) / 2
);

const int NumVertices = sizeof(vertices) / sizeof(vertices[0]); 

// RGBA olors
color4 colors[] = {

	//front face
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 1.0, 0.0, 1.0),  // green

	////back face
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 0.0, 1.0, 1.0),  // magenta

	//right face
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 0.0, 0.0, 1.0),  // red

	//left face
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(0.0, 0.0, 1.0, 1.0),  // blue

	//top face
	color4(0.0, 1.0, 1.0, 1.0),  // cyan
	color4(0.0, 1.0, 1.0, 1.0),  // cyan
	color4(0.0, 1.0, 1.0, 1.0),  // cyan
	color4(0.0, 1.0, 1.0, 1.0),  // cyan
	color4(0.0, 1.0, 1.0, 1.0),  // cyan
	color4(0.0, 1.0, 1.0, 1.0),  // cyan

	//bottom face
	color4(0.3, 0.3, 0.3, 1.0),  // gray
	color4(0.3, 0.3, 0.3, 1.0),  // gray
	color4(0.3, 0.3, 0.3, 1.0),  // gray
	color4(0.3, 0.3, 0.3, 1.0),  // gray
	color4(0.3, 0.3, 0.3, 1.0),  // gray
	color4(0.3, 0.3, 0.3, 1.0)   // gray
};

// Array of rotation angles (in degrees) for each coordinate axis
enum {	Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int   Axis = Xaxis;
GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

//----------------------------------------------------------------------------
// OpenGL initialization
void
init()
{
	// Create a vertex array object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create and initialize a buffer object
	GLuint buffer;
	glGenBuffers(1, &buffer);

	//Designate buffer as ARRAY BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	//specify size of buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)+sizeof(colors),
		NULL, GL_STATIC_DRAW);

	//store vertex attributes in buffer
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

	// Load shaders and use the resulting shader program
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// set up vertex attributes
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(0));

	GLuint vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(sizeof(vertices)));

	//enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(1.0, 1.0, 1.0, 1.0);
}

//----------------------------------------------------------------------------
//USED TO TRANSFORMATIONS
GLfloat scalar = 1.0;
GLfloat angle = 0.3;	//angle of rotation
GLfloat factor = 0.0;	//shear factor
GLfloat clippedX;		//map windows x coord to clipping (-1,1)
GLfloat clippedY;		//map windows y coord to clipping (-1,1)

//----------------------------------------------------------------------------
//NOT USED
mat4 Shear(vec3 coord3d)
{
	mat4 shear;
	shear[0][1] = coord3d.x;
	shear[1][0] = coord3d.y;
	shear[2][1] = coord3d.z;
	return shear;
}

void display(void)
{
	//clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//multiple transformations, Scale first
	mat4  transform = (
		Translate(vec3(clippedX, clippedY, trapezoidal_center.z)) *
		RotateX(Theta[Xaxis]) *
		RotateY(Theta[Yaxis]) *
		RotateZ(Theta[Zaxis]) *
		Scale(vec3(scalar))
		);

	//perform transformations on all vertices
	point4 transformed_points[NumVertices];
	for (int i = 0; i < NumVertices; ++i) {
		transformed_points[i] = transform * vertices[i];
	}

	//reallocate new object location to buffer
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformed_points),
		transformed_points);

	//send vertex attributes to vertex shader
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	//swap display with back buffer
	glutSwapBuffers();

}

//----------------------------------------------------------------------------
//Adjust angle of rotation
GLfloat rotateSpeed = 0.0;
void rotate(int sign){

	if (sign > 0){
		Theta[Axis] = Theta[Axis] + angle + rotateSpeed;
		if (Theta[Axis] > 360.0) Theta[Axis] = 0;
		//cout << Theta[Axis] << endl;
	}
	else{
		Theta[Axis] = Theta[Axis] - angle - rotateSpeed;
		if (Theta[Axis] < -360.0) Theta[Axis] = 0;
		//cout << Theta[Axis] << endl;
	}

}

bool stop_animation = false;
void
keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1':	if (!stop_animation) stop_animation = true; 
				else stop_animation = false; 
				break;
	case '-':	if(rotateSpeed != 0) rotateSpeed -= 0.5; cout << "Decrease Speed: " << rotateSpeed << endl; break;
	case '+':	if(rotateSpeed <= 10) rotateSpeed += 0.5; cout << "Increase Speed: " << rotateSpeed << endl;  break;
	case 's':	scalar -= 0.1; break;
	case 'S':	scalar += 0.1; break;
	case 'x':   Axis = Xaxis; rotate(1);  break;
	case 'y':	Axis = Yaxis; rotate(1); break;
	case 'z':   Axis = Zaxis; rotate(1); break;
	case 'X':   Axis = Xaxis; rotate(-1); break;
	case 'Y':	Axis = Yaxis; rotate(-1); break;
	case 'Z':   Axis = Zaxis; rotate(-1); break;
	case 033: // Escape Key
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;

	}
}

void mouse(int button, int state, int x, int y){
	
	if (state == GLUT_DOWN) {

		//use proportions to map glut coordinates(0,512) to clippling coordinates(-1,1)
		clippedX = (-1 + x / 256.0);
		clippedY = (1 - y / 256.0);
	}

}

//----------------------------------------------------------------------------
//Rotate objects x,y,z coords when idle
void
idle(void)
{
	//check animation flag
	if (!stop_animation){
		Theta[Xaxis] = Theta[Xaxis] + angle + rotateSpeed;
		Theta[Yaxis] = Theta[Yaxis] + angle + rotateSpeed;
		Theta[Zaxis] = Theta[Zaxis] + angle + rotateSpeed;
	}

	//reset degrees past 360
	if (Theta[Xaxis] > 360.0) Theta[Xaxis] = 0;
	if (Theta[Yaxis] > 360.0) Theta[Yaxis] = 0;
	if (Theta[Zaxis] > 360.0) Theta[Zaxis] = 0;

	glutPostRedisplay();
}

//----------------------------------------------------------------------------

int
main(int argc, char **argv)
{
	//init window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Prog1");

	glewInit();

	//init VBO (Vertex buffer objects)
	init();

	cout << "Press 1 to stop animation" << endl;
	cout << "Press + to increase rotation speed (Max = 10)" << endl;
	cout << "Press - to decrease rotation speed (Min = 0)" << endl;

	//callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	//loop to continously listen for window events
	glutMainLoop();
	return 0;
}
