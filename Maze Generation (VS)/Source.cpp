#include "Shaders/Shaders.h"
#include "Maze/maze.h"
#define PI 3.14159265

vec3 vertices[] = {

    //cube
    vec3(0.0, 0.0, 0.0),   //front
    vec3(1.0, 0.0, 0.0),
    vec3(1.0, 1.0, 0.0),
    vec3(0.0, 1.0, 0.0),
    vec3(0.0, 0.0, -1.0),  //back
    vec3(1.0, 0.0, -1.0),
    vec3(1.0, 1.0, -1.0),
    vec3(0.0, 1.0, -1.0),

};

GLuint elements[] = {
	// front
    0, 1, 2,
    2, 3, 0,
    // top
    3, 2, 6,
    6, 7, 3,
    // back
    7, 6, 5,
    5, 4, 7,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // left
    4, 0, 3,
    3, 7, 4,
    // right
    1, 5, 6,
    6, 2, 1,

};

vec3 cubes[ROWS][COLS] = {

    {
    vec3(0.0, 0.0, -8.0),   //cube 0,0
    vec3(1.0, 0.0, -8.0),   //cube 0,1
    vec3(2.0, 0.0, -8.0),   //cube 0,2
    vec3(3.0, 0.0, -8.0),   //cube 0,3
    vec3(4.0, 0.0, -8.0),   //cube 0,4
    vec3(5.0, 0.0, -8.0),   //cube 0,5
    vec3(6.0, 0.0, -8.0),   //cube 0,6
    vec3(7.0, 0.0, -8.0),   //cube 0,7
    vec3(8.0, 0.0, -8.0),   //cube 0,8
    },

    {
    vec3(0.0, 0.0, -7.0),   //cube 1,0
    vec3(1.0, 0.0, -7.0),   //cube 1,1
    vec3(2.0, 0.0, -7.0),   //cube 1,2
    vec3(3.0, 0.0, -7.0),   //cube 1,3
    vec3(4.0, 0.0, -7.0),   //cube 1,4
    vec3(5.0, 0.0, -7.0),   //cube 1,5
    vec3(6.0, 0.0, -7.0),   //cube 1,6
    vec3(7.0, 0.0, -7.0),   //cube 1,7
    vec3(8.0, 0.0, -7.0),   //cube 1,8
    },

    {
    vec3(0.0, 0.0, -6.0),   //cube 2,0
    vec3(1.0, 0.0, -6.0),   //cube 2,1
    vec3(2.0, 0.0, -6.0),   //cube 2,2
    vec3(3.0, 0.0, -6.0),   //cube 2,3
    vec3(4.0, 0.0, -6.0),   //cube 2,4
    vec3(5.0, 0.0, -6.0),   //cube 2,5
    vec3(6.0, 0.0, -6.0),   //cube 2,6
    vec3(7.0, 0.0, -6.0),   //cube 2,7
    vec3(8.0, 0.0, -6.0),   //cube 2,8
    },

    {
    vec3(0.0, 0.0, -5.0),   //cube 3,0
    vec3(1.0, 0.0, -5.0),   //cube 3,1
    vec3(2.0, 0.0, -5.0),   //cube 3,2
    vec3(3.0, 0.0, -5.0),   //cube 3,3
    vec3(4.0, 0.0, -5.0),   //cube 3,4
    vec3(5.0, 0.0, -5.0),   //cube 3,5
    vec3(6.0, 0.0, -5.0),   //cube 3,6
    vec3(7.0, 0.0, -5.0),   //cube 3,7
    vec3(8.0, 0.0, -5.0),   //cube 3,8
    },

    {
    vec3(0.0, 0.0, -4.0),   //cube 4,0
    vec3(1.0, 0.0, -4.0),   //cube 4,1
    vec3(2.0, 0.0, -4.0),   //cube 4,2
    vec3(3.0, 0.0, -4.0),   //cube 4,3
    vec3(4.0, 0.0, -4.0),   //cube 4,4
    vec3(5.0, 0.0, -4.0),   //cube 4,5
    vec3(6.0, 0.0, -4.0),   //cube 4,6
    vec3(7.0, 0.0, -4.0),   //cube 4,7
    vec3(8.0, 0.0, -4.0),   //cube 4,8
    },

    {
    vec3(0.0, 0.0, -3.0),   //cube 5,0
    vec3(1.0, 0.0, -3.0),   //cube 5,1
    vec3(2.0, 0.0, -3.0),   //cube 5,2
    vec3(3.0, 0.0, -3.0),   //cube 5,3
    vec3(4.0, 0.0, -3.0),   //cube 5,4
    vec3(5.0, 0.0, -3.0),   //cube 5,5
    vec3(6.0, 0.0, -3.0),   //cube 5,6
    vec3(7.0, 0.0, -3.0),   //cube 5,7
    vec3(8.0, 0.0, -3.0),   //cube 5,8
    },

    {
    vec3(0.0, 0.0, -2.0),   //cube 6,0
    vec3(1.0, 0.0, -2.0),   //cube 6,1
    vec3(2.0, 0.0, -2.0),   //cube 6,2
    vec3(3.0, 0.0, -2.0),   //cube 6,3
    vec3(4.0, 0.0, -2.0),   //cube 6,4
    vec3(5.0, 0.0, -2.0),   //cube 6,5
    vec3(6.0, 0.0, -2.0),   //cube 6,6
    vec3(7.0, 0.0, -2.0),   //cube 6,7
    vec3(8.0, 0.0, -2.0),   //cube 6,8
    },

    {
    vec3(0.0, 0.0, -1.0),   //cube 7,0
    vec3(1.0, 0.0, -1.0),   //cube 7,1
    vec3(2.0, 0.0, -1.0),   //cube 7,2
    vec3(3.0, 0.0, -1.0),   //cube 7,3
    vec3(4.0, 0.0, -1.0),   //cube 7,4
    vec3(5.0, 0.0, -1.0),   //cube 7,5
    vec3(6.0, 0.0, -1.0),   //cube 7,6
    vec3(7.0, 0.0, -1.0),   //cube 7,7
    vec3(8.0, 0.0, -1.0),   //cube 7,8
    },

    {
    vec3(0.0, 0.0, 0.0),   //cube 8,0
    vec3(1.0, 0.0, 0.0),   //cube 8,1
    vec3(2.0, 0.0, 0.0),   //cube 8,2
    vec3(3.0, 0.0, 0.0),   //cube 8,3
    vec3(4.0, 0.0, 0.0),   //cube 8,4
    vec3(5.0, 0.0, 0.0),   //cube 8,5
    vec3(6.0, 0.0, 0.0),   //cube 8,6
    vec3(7.0, 0.0, 0.0),   //cube 8,7
    vec3(8.0, 0.0, 0.0),   //cube 8,8
    },

};

vec2 texCoord[] = {
	vec2(1.0f, 1.0f),   // Top Right
	vec2(1.0f, 0.0f),   // Bottom Right
	vec2(0.0f, 0.0f),   // Bottom Left
	vec2(0.0f, 1.0f),   // Top Left

	vec2(1.0f, 1.0f),   // Top Right
	vec2(1.0f, 0.0f),   // Bottom Right
	vec2(0.0f, 0.0f),   // Bottom Left
	vec2(0.0f, 1.0f)    // Top Left

};

const GLuint NUMCUBES = sizeof(cubes) / sizeof(vec3);
const GLuint NUMELEMENTS = sizeof(elements) / sizeof(GLuint);
const GLfloat WIDTH = 800, HEIGHT = 600;
bool INIT_MAZE = false;
GLuint program;

//Rotate center
GLfloat radius = 20.0;
GLfloat theta = 90.0;

//view
GLfloat eyeX = 3.5;
GLfloat eyeY = 0.5;
GLfloat eyeZ = -5.5;
GLfloat centerX = eyeX + cos(theta*PI/180); //same axis as eye
GLfloat centerY = 0.5;
GLfloat centerZ = eyeZ - sin(theta*PI/180); //1 unit in front

//perspective
GLfloat fovy = 45.0f;
GLfloat aspect = (GLfloat)WIDTH / (GLfloat)HEIGHT;
GLfloat zNear = 0.1f;
GLfloat zFar = 100.0f;



void init(){
	//-----------------------------------------VERTEX ARRAY OBJECT-----------------------------------------------

	//Create and bind VAO
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//----------------------------------------VERTEX BUFFER OBJECT------------------------------------------------

	//create VBO and bind as current array buffer
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//specify size of buffer and store vertice and texture positions
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(texCoord), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(texCoord), texCoord);


	//----------------------------------------ELEMENT BUFFER OBJECT-------------------------------------------------

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	//--------------------------------------------TEXTURE OBJECT------------------------------------------------------

	//generate and bind texture object as current texture
	GLuint tbo;
	glGenTextures(1, &tbo);
	glBindTexture(GL_TEXTURE_2D, tbo);

    //texture settings
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //create texture from image
    int width, height;
    unsigned char* image = SOIL_load_image("Textures/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    //automatically generate mipmap for texture
	glGenerateMipmap(GL_TEXTURE_2D);

    //free image
	SOIL_free_image_data(image);

	//----------------------------------------------INIT SHADERS----------------------------------------------------

	//create and init shaders
	program = initShaders("Shaders/vshader.glsl", "Shaders/fshader.glsl");
	glUseProgram(program);


	//-------------------------------------------- ATTRIBUTES---------------------------------------------------

	//position
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //texture Coordinates
	GLuint texCoord = glGetAttribLocation(program, "texCoord");
	glEnableVertexAttribArray(texCoord);
	glVertexAttribPointer(texCoord, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)sizeof(vertices));

	//---------------------------------------SETUP DEPTH, COLOR BUFFER------------------------------------------------

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(1, 1, 1, 1);

	//-----------------------------------------------GENERATE MAZE-----------------------------------------------------

    INIT_MAZE = initMaze();
    if(!INIT_MAZE) cerr << "Did not init maze";

    //maze after recursion
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mat4 trans;
	mat4 model;
	mat4 view;
	mat4 projection;

    //PROJECTION * VIEW * MODEL
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){

            //identity
            model = mat4(1.0);

            //RENDER WALLS(1)
            if(maze[r][c] != 1) continue;
            //cout << r << " " << c << endl;

            model = translate(model, cubes[r][c]);
            view = lookAt(vec3(eyeX, eyeY, eyeZ), vec3(centerX, centerY, centerZ), vec3(0.0, 1.0, 0.0));
            projection = perspective(fovy, aspect, zNear, zFar);
            trans = projection * view * model;

            //pass transformation to shader
            GLint vTransform = glGetUniformLocation(program, "transform");
            glUniformMatrix4fv(vTransform, 1, GL_FALSE, value_ptr(trans));

            glDrawElements(GL_TRIANGLES, NUMELEMENTS, GL_UNSIGNED_INT, 0);
        }
    }

	glutSwapBuffers();

}

GLboolean birdView = false;
void keyboard(unsigned char key, int x, int y){
	switch (key){
		case 'q':
		case 'Q':   exit(EXIT_SUCCESS);
		case 'f':	fovy += 0.1; cout << "fovy " << fovy << endl; break;
		case 'F':	fovy -= 0.1; cout << "fovy " << fovy << endl; break;
    	case  32: { //space for birdView

            static GLfloat eyeX_tem, eyeY_tem, eyeZ_tem, centerX_tem, centerY_tem, centerZ_tem;
            if(!birdView){
                birdView = true;

                //store state
                eyeX_tem = eyeX;
                eyeY_tem = eyeY;
                eyeZ_tem = eyeZ;
                centerX_tem = centerX;
                centerY_tem = centerY;
                centerZ_tem = centerZ;

                //switch to birdview
                eyeX = 6;
                eyeY = 14;
                eyeZ = -4;
                centerX = 0;
                centerY = -120;
            }
            else{
                birdView = false;

                //restore state
                eyeX = eyeX_tem;
                eyeY = eyeY_tem;
                eyeZ = eyeZ_tem;
                centerX = centerX_tem;
                centerY = centerY_tem;
                centerZ = centerZ_tem;
            }
            break;
		}

	}

	glutPostRedisplay();
}

GLboolean quadrant1 = false,
          quadrant2 = false,
          quadrant3 = false,
          quadrant4 = false;

void checkQuadrant(GLfloat theta) {

    if(theta > 0 && theta < 90) {        //quadrant 1
        quadrant1 = true;
        quadrant2 = false,
        quadrant3 = false,
        quadrant4 = false;
        cout << "1st quadrant" << endl;
    }
    else if(theta > 90 && theta < 180) {  //quadrant 2
        quadrant2 = true;
        quadrant1 = false,
        quadrant3 = false,
        quadrant4 = false;
        cout << "2nd quadrant" << endl;
    }
    else if(theta > 180 && theta < 270) {  //quadrant 3
        quadrant3 = true;
        quadrant2 = false,
        quadrant1 = false,
        quadrant4 = false;
        cout << "3rd quadrant" << endl;
    }
    else if(theta > 270 && theta < 360) {  //quadrant 4
        quadrant4 = true;
        quadrant2 = false,
        quadrant3 = false,
        quadrant1 = false;
        cout << "4th quadrant" << endl;
    }
}

void specialKey(int key, int x, int y) {
    GLfloat m;  //slope

    //disable keys on birdView
    if(birdView) return;


	switch (key){

		case GLUT_KEY_RIGHT: {

		    theta -= 1; if(theta == 0) theta = 360;

		    checkQuadrant(theta);

		    centerX = eyeX + cos(theta*PI/180) * radius;
		    centerZ = eyeZ - sin(theta*PI/180) * radius;

		    //cout << "centerX " << centerX << " " << "centerZ" << centerZ << endl;
            break;
		}

		case GLUT_KEY_LEFT: {

		    theta += 1; if(theta == 360) theta = 0;

		    checkQuadrant(theta);

		    centerX = eyeX + cos(theta*PI/180) * radius;
		    centerZ = eyeZ - sin(theta*PI/180) * radius;
		    //cout << "centerX " << centerX << " " << "centerZ" << centerZ << endl;
            break;
		}

		case GLUT_KEY_UP: {

            //--------------------------------BEFORE MOVE----------------------------------------
            //eye(x,z)
            cout << "before eyeX " << eyeX << " before eyeZ " << eyeZ << endl;

            //center(x,z)
            cout << "before centerX " << centerX << " before centerZ " << centerZ << endl;

            //store position before move
            GLfloat oldX = eyeX, oldZ = eyeZ,
                    oldX_center = centerX, oldZ_center = centerZ;

            //--------------------------------MOVE--------------------------------------------

            //check if slope is undefined
            if(centerX - eyeX == 0) {
                //cout << "slope is undefined " << eyeX << "/" << centerX << endl;
                eyeZ -= 0.1;
                centerZ -= 0.1;
            }else{
                //slope between center and eye
                m = (centerZ - eyeZ) / (centerX - eyeX);
                cout << "\nm = " << m << endl;

                //set move according to center's quadrant
                if(quadrant1 || quadrant4) eyeX += 0.01;
                else if(quadrant2 || quadrant3) eyeX -= 0.01;

                //y -y1 = m(x - x1)
                GLfloat mx =  m * eyeX;
                GLfloat mx1 = m * oldX;
                GLfloat y1 = oldZ;
                eyeZ = mx - mx1 + y1;
    //          cout << "mx = " << mx << endl;
    //          cout << "mx1 = " << mx1 << endl;
    //          cout << "mx - mx1 + y1 = " << eyeZ << endl;
            }


            //--------------------------------AFTER MOVE--------------------------------------------------

            cout << "\n\nnew eyeX " << eyeX << " new eyeZ " << eyeZ << endl;
            cout << "new centerX " << centerX << " new centerZ " << centerZ << endl;

            //check exit
            if(eyeX >= 8 && (eyeZ <= -5 && eyeZ > -6)) {
               exit(EXIT_SUCCESS);
               cout << "Congratulations you have cleared the maze" << endl;
            }
            break;
        }

		case GLUT_KEY_DOWN: {

            //--------------------------------BEFORE MOVE----------------------------------------
            //eye(x,z)
            cout << "before eyeX " << eyeX << " before eyeZ " << eyeZ << endl;

            //center(x,z)
            cout << "before centerX " << centerX << " before centerZ " << centerZ << endl;

            //store position before move
            GLfloat oldX = eyeX, oldZ = eyeZ,
                    oldX_center = centerX, oldZ_center = centerZ;

            //--------------------------------MOVE--------------------------------------------

            //check if slope is undefined
            if(centerX - eyeX == 0) {
                //cout << "slope is undefined " << eyeX << "/" << centerX << endl;
                eyeZ += 0.1;
                centerZ += 0.1;
            }else{
                //slope between center and eye
                m = (centerZ - eyeZ) / (centerX - eyeX);
                //cout << "\nm = " << m << endl;

                //set move according to center's quadrant
                if(quadrant1 || quadrant4) eyeX -= 0.01;
                else if(quadrant2 || quadrant3) eyeX += 0.01;

                //y -y1 = m(x - x1)
                GLfloat mx =  m * eyeX;
                GLfloat mx1 = m * oldX;
                GLfloat y1 = oldZ;
                eyeZ = mx - mx1 + y1;
    //          cout << "mx = " << mx << endl;
    //          cout << "mx1 = " << mx1 << endl;
    //          cout << "mx - mx1 + y1 = " << eyeZ << endl;
            }

            //--------------------------------AFTER MOVE--------------------------------------------------

            cout << "\n\nnew eyeX " << eyeX << " new eyeZ " << eyeZ << endl;
            cout << "new centerX " << centerX << " new centerZ " << centerZ << endl;

            break;
		}
	}
	glutPostRedisplay();
}

void idle() {
	glutPostRedisplay();
}

int main(int argc, char** argv) {


	//init window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Prog2");

	glewInit();

	glViewport(0, 0, WIDTH, HEIGHT);

	//init VBO (Vertex buffer objects)
	init();

	//callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);
	glutIdleFunc(idle);

	//loop to continously listen for window events
	glutMainLoop();
	return 0;

}
