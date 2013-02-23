#include "GraphicsCore.h"

int windowWidth, windowHeight;
void resizeCallback(int width, int height)
{
	windowWidth = width; // remember new size
	windowHeight = height;
	glViewport(0, 0, width, height); // change viewport size in gl
}

TempCam mCam;
void My_mouse_routine(int x, int y)
	{
		mCam.SetMousePos(x, y); //place current mouse pos in mouseX, mouseY (in Camera class)
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

//temporary function
void GraphicsCore::tempValues(uint shaderProgHandle, Object3D object)
{
	vec3 eye(mCam.GetCamPos().x, mCam.GetCamPos().y, mCam.GetCamPos().z); // camera position in world coordinates
	vec3 centre(mCam.GetCamPos().x, mCam.GetCamPos().y, mCam.GetCamPos().z-1); // orient camera to point towards a target position
	vec3 up(0.0f, 1.0f, 0.0f); // vector pointing up from camera's head  (describes roll of camera)
	mat4 viewMatrix = glm::mat4(1.0f); // initialise to identity
	viewMatrix = glm::lookAt(eye, centre, up); // this function is similar to one from the older opengl

	//matrices
	mat4 Projection = glm::perspective(45.0f, float(windowWidth) / (float)windowHeight, 0.1f, 300.f);	
	//mat4 rotationMatrix = glm::rotate(mat4(1.0f), rotAngle, vec3(0.0f,1.0f,0.0f));
	mat4 Model = mCam.GetRotationMatrix() * glm::translate(object.GetWorldPos());
	mat4 ModelView =  Model * viewMatrix; 
	mat4 MVP = Projection * ModelView;
	
	mat3 normalMatrix = glm::transpose(glm::inverse(mat3(ModelView)));

	uint location = glGetUniformLocation(shaderProgHandle, "ProjectionMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &Projection[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "ModelViewMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &ModelView[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "MVP");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &MVP[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "NormalMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix3fv(location, 1, GL_FALSE, &normalMatrix[0][0]); }
}


uint GraphicsCore::Initialize(int argc, char** argv)
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
	//glutDisplayFunc(renderCallback); // register rendering callback
	glutReshapeFunc(resizeCallback); // register callback for reshape

	// set colour to clear screen buffer to
	glClearColor(0.1, 0.1, 0.1, 1.0f);

	// enable some useful GL behaviours
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // set depth-testing function type
	glEnable(GL_CULL_FACE); // enable culling of back-faces
	glCullFace(GL_BACK); // enable culling of back-faces
	glFrontFace(GL_CCW); // use clock-wise 'winding' to define order used to make fronts of polygons
	
	// start GLEW (that's it! - we could also use GLEW to check for driver support of all GL extensions)
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		printf("ERROR starting GLEW: %s\n", glewGetErrorString(err));
	}
}

uint GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	return mShader.CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
}

uint GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath)
{
	return mShader.CreateShaderProgram(vertexShaderPath, fragmentShaderPath, geometryShaderPath);
}

uint GraphicsCore::LoadTexture(const char* file)
{
	return mTexture.LoadTexture(file);
}

uint GraphicsCore::SendModel(vector<VertexPoint> vertexList)
{
	return mVAOModel.CreateModel(vertexList);
}

uint GraphicsCore::SendModel(vec3 position)
{
	return mVAOModel.CreateModel(position);
}


void GraphicsCore::BeginRendering()
{
	glutMainLoopEvent();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffer using colour
}

void GraphicsCore::RenderObject(uint textureID, uint modelID, uint shaderID, vec3 color, float scale)
{
	glutMainLoopEvent();
}

void GraphicsCore::RenderObject(Object3D object)
{
	
	glUseProgram(object.GetShaderID());
	//set uniform variables?

	//---------temporary--------
	tempValues(object.GetShaderID(), object);
	//--------------------------

	glEnable(GL_BLEND); //for transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, object.GetTextureID());
	glBindVertexArray(object.GetModelID());

	//if billboard
	if(mVAOModel.GetVertexCount(object.GetModelID()) == 1)
	{
		glDrawArrays(GL_POINTS, 0, 1);
	}
	
	//if 
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, mVAOModel.GetVertexCount(object.GetModelID()));
	}

	glUseProgram(0); // disable shader
	glBindVertexArray(0);
}

void GraphicsCore::EndRendering()
{
	glutSwapBuffers(); // swap drawing back-buffer to displayed front buffer
	glutPostRedisplay(); // flag for redraw
}

 
int GraphicsCore::UpdateCamera(vec3 eye, vec3 target, vec3 up)
{
	return 0;
}

int GraphicsCore::UpdateUniform(const char* variable, uint shaderProgHandle, float value)
{
	return mShader.UpdateUniform(variable, shaderProgHandle, value);
}

int GraphicsCore::UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value)
{
	return mShader.UpdateUniform(variable, shaderProgHandle, value);
}

void GraphicsCore::TempCamUpdate()
{
	
	if(GetKeyState(VK_LSHIFT) == 0)
	{
		glutPassiveMotionFunc(My_mouse_routine);
		glutSetCursor(GLUT_CURSOR_NONE);
		mCam.Control(0.5, 0.3, true, windowWidth*0.5, windowHeight*0.5);
	}
}
