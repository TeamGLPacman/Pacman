#include "GraphicsCore.h"


void renderCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffer using colour

	//draw shit?

	glutSwapBuffers(); // swap drawing back-buffer to displayed front buffer
	glutPostRedisplay(); // flag for redraw
}

void resizeCallback(int width, int height)
{
	windowWidth = width; // remember new size
	windowHeight = height;
	glViewport(0, 0, width, height); // change viewport size in gl
}

GraphicsCore::GraphicsCore(void)
{
	windowWidth = 800;
	windowHeight = 600;
	windowTitle = "Pacman";
}

GraphicsCore::~GraphicsCore(void)
{
}


unsigned int GraphicsCore::Initialize(int argc, char** argv)
{
	// initialise freeGLUT
	glutInit(&argc, argv);

	// create Window on O/S using freeGLUT
	glutInitWindowSize(windowWidth, windowHeight); // specify size of window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	// create window with freeGLUT
	int windowHandle = glutCreateWindow(windowTitle);
	if (windowHandle < 1) { printf("ERROR: creating window\n"); exit(1); }

	// get version info and print it to the console (have a look to see what version you can support)
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* vendor = glGetString(GL_VENDOR); // vendor
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION); // glsl version string
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major); // get integer (only if gl version > 3)
	glGetIntegerv(GL_MINOR_VERSION, &minor); // get dot integer (only if gl version > 3)
	printf("OpenGL on %s %s\n", vendor, renderer);
	printf("OpenGL version supported %s\n", version);
	printf("GLSL version supported %s\n", glslVersion);
	printf("Will now set GL to version %i.%i\n", major, minor);
	
	// force GL to use a specific version
	glutInitContextVersion(major, minor); // set version of gl to 4.1
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE); // do not allow deprecated
	glutInitContextProfile(GLUT_CORE_PROFILE); // force current version of spec
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// start GLEW (that's it! - we could also use GLEW to check for driver support of all GL extensions)
	GLenum glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		printf("glError: %s\n", gluErrorString(glErr));
	}

	// set-up callbacks. we can also do a keyboard and mouse input callback, and various others (see freeGLUT website)
	glutDisplayFunc(renderCallback); // register rendering callback
	glutReshapeFunc(resizeCallback); // register callback for reshape

	// set colour to clear screen buffer to
	glClearColor(0.1, 0.1, 0.1, 1.0f);

	// enable some useful GL behaviours
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // set depth-testing function type
	//glEnable(GL_CULL_FACE); // enable culling of back-faces
	glCullFace(GL_BACK); // enable culling of back-faces
	glFrontFace(GL_CCW); // use clock-wise 'winding' to define order used to make fronts of polygons
	
	// start GLEW (that's it! - we could also use GLEW to check for driver support of all GL extensions)
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		printf("ERROR starting GLEW: %s\n", glewGetErrorString(err));
	}
}

int GraphicsCore::RenderObject(unsigned int textureID, unsigned int modelID, unsigned int shaderID, vec3 color, float scale)
{
}

int GraphicsCore::RenderObject(Object3D object)
{
}

UINT GraphicsCore::LoadTexture(const char* file, UINT shaderProgHandle)
{
	return mTexture.LoadTexture_TGA(file, shaderProgHandle);
}

unsigned int GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int shaderProgHandle)
{
}

unsigned int GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath, unsigned int shaderProgHandle)
{
}

unsigned int GraphicsCore::SendModel(vector<VertexPoint> vertexList)
{
}

unsigned int GraphicsCore::SendModel(vec3 position)
{
}
 
int GraphicsCore::UpdateCamera(vec3 eye, vec3 target, vec3 up)
{
}

int GraphicsCore::UpdateUniform(const char* variable, unsigned int shaderProgHandle, const void* value)
{
}