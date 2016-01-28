#include "Shaders.h"

string readFile(const char* fileName){

	string str, ret = "";
	ifstream in;
	in.open(fileName);
	if (in.is_open()) {

		while (getline(in, str)) ret += str + "\n";
		//cout <<  ret;
	}
	else
		return NULL;

	return ret;

}

GLuint initShaders(const char* vShaderFile, const char* fShaderFile){

	//shader structs
	struct Shader{
		const char* fileName;
		GLenum type;
		const GLchar* source;
	} shaders[2] = {
		Shader{ vShaderFile, GL_VERTEX_SHADER, NULL },
		Shader{ fShaderFile, GL_FRAGMENT_SHADER, NULL }
	};

	//shader program
	GLuint program = glCreateProgram();

	//init all shaders
	for (int i = 0; i < 2; i++){

		Shader s = shaders[i];

		//read shader file into string
		string src = readFile(s.fileName);

		GLchar * cstr = new GLchar[src.size() + 1];
		s.source = cstr; // Weirdness to get a const char
		strcpy_s(cstr, src.size()+1, src.c_str());

		if (s.source == NULL) cerr << "Could not read " << s.fileName;

		//create shader object
		GLuint shader = glCreateShader(s.type);

		//load NULL TERMINATED shader file to object
		glShaderSource(shader, 1, &s.source, NULL);

		//compile shader object
		glCompileShader(shader);
		GLint compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled){
			GLint  logSize;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
			char* logMsg = new char[logSize];
			glGetShaderInfoLog(shader, logSize, NULL, logMsg);
			cerr << shaders[i].fileName << " could not compile\n" << logMsg << endl;
			delete[] logMsg;
		}

		//attach shaders to program
		glAttachShader(program, shader);

	}

	glLinkProgram(program);
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked){
		GLint logSize;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
		char* log = new char[logSize];
		glGetProgramInfoLog(program, logSize, NULL, log);
		cerr << "Could not link shaders" << log << endl;
		delete[] log;
	}

	return program;


}

