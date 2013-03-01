#include "GraphicsCore.h"
int windowWidth, windowHeight;

void resizeCallback(int width, int height)
{
	windowWidth = width; // remember new size
	windowHeight = height;
	glViewport(0, 0, width, height); // change viewport size in gl
}
bool GraphicsCore::fullsceen(){
	while(true)
	{
		char ans= 'y';
		printf("Do you want to play in fullscreen? (y/n)");
		cin >> ans;
		if(ans == 'y') 
			return true;
		else if (ans == 'n')
			return false;
	}
}

GraphicsCore::GraphicsCore(void)
{
	fov = 40.0f;
	//int w, h;
	if(fullsceen())
	{
		GetDesktopResolution(windowWidth, windowHeight);
		//glutFullScreen();
	}
	else
	{
		windowWidth = 800; 
		windowHeight = 600;
	}
	windowTitle = "Pacman";
}
void GraphicsCore::GetDesktopResolution(int& Width,int& Heigth)
{
   RECT skrivbord; 
   const HWND hSkrivbord = GetDesktopWindow();// hämtar handtaget till skrivbordet
   GetWindowRect(hSkrivbord, &skrivbord);// lägger in skrivbordets " RECT" i skrivbord
   Width = skrivbord.right; // hämtar width
   Heigth = skrivbord.bottom; // hämtar Height
}

GraphicsCore::~GraphicsCore(void)
{
}

//temporary function
void GraphicsCore::UpdateLightValues(Object3D object)
{
	//lightinfo
	//vec4 lightPos = vec4(0.0, 0.0, 0.0, 1.0);
	vec3 ambient = vec3(0.4, 0.4, 0.4);
	//vec3 diffuse = vec3(0.9, 0.9, 0.9);
	//vec3 specular = vec3(0.6, 0.6, 0.6);

	//material
	vec3 ambientRefl = vec3(1.0f, 1.0f, 1.0f);	
	vec3 diffuseRefl = vec3(0.9f, 0.9f, 0.9f);	
	vec3 specularRefl = vec3(0.4f, 0.4f, 0.4f);
	float shininess = 2.0;

	uint shaderProgHandle = object.GetShaderID();
	
	//uint location = glGetUniformLocation(shaderProgHandle, "Light.LightPosition");	//gets the UniformLocation from shader.vertex
	//glUniform4fv(location, 1, &lightPos[0]);

	uint location = glGetUniformLocation(shaderProgHandle, "Light.La");	//gets the UniformLocation from shader.vertex
	glUniform3fv(location, 1, &ambient[0]);

	//location = glGetUniformLocation(shaderProgHandle, "Light.Ld");	//gets the UniformLocation from shader.vertex
	//glUniform3fv(location, 1, &diffuse[0]);

	//location = glGetUniformLocation(shaderProgHandle, "Light.Ls");	//gets the UniformLocation from shader.vertex
	//glUniform3fv(location, 1, &specular[0]);

	//-------------------
	location = glGetUniformLocation(shaderProgHandle, "Material.Ka");	//gets the UniformLocation from shader.vertex
	glUniform3fv(location, 1, &ambientRefl[0]);

	location = glGetUniformLocation(shaderProgHandle, "Material.Kd");	//gets the UniformLocation from shader.vertex
	glUniform3fv(location, 1, &diffuseRefl[0]);

	location = glGetUniformLocation(shaderProgHandle, "Material.Ks");	//gets the UniformLocation from shader.vertex
	glUniform3fv(location, 1, &specularRefl[0]);

	location = glGetUniformLocation(shaderProgHandle, "Material.Shininess");	//gets the UniformLocation from shader.vertex
	glUniform1fv(location, 1, &shininess);
	
}

void GraphicsCore::UpdateBillboardObjectValues(Object3D object)
{
	vec3 eye = mCam.GetCamPos(); 
	vec3 centre = vec3(mCam.GetCamPos().x, mCam.GetCamPos().y, mCam.GetCamPos().z-1);
	vec3 up(0.0f, 1.0f, 0.0f);
	
    mat4 Projection = glm::perspective(fov, float(windowWidth) / (float)windowHeight, 0.1f, 300.f); 	
    mat4 Model = glm::translate(object.GetWorldPos());
	mat4 viewMatrix = mCam.GetRotationMatrix() * glm::lookAt(eye, centre, up);
    mat4 ModelView =  viewMatrix * Model; 

	float Size = object.GetSize();;
	
	uint shaderProgHandle = object.GetShaderID();

	uint location = glGetUniformLocation(shaderProgHandle, "ProjectionMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &Projection[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "ModelViewMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &ModelView[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "Size");	//gets the UniformLocation from shader.vertex
	glUniform1fv(location, 1, &Size);
}

void GraphicsCore::UpdateObjectValues(Object3D object)
{
	vec3 eye = mCam.GetCamPos(); 
	vec3 centre = vec3(mCam.GetCamPos().x, mCam.GetCamPos().y, mCam.GetCamPos().z-1);
	vec3 up(0.0f, 1.0f, 0.0f);
	
    mat4 Projection = glm::perspective(fov, float(windowWidth) / (float)windowHeight, 0.1f, 300.f); 	
    mat4 Model = glm::translate(object.GetWorldPos());
	mat4 viewMatrix = mCam.GetRotationMatrix() * glm::lookAt(eye, centre, up);
    mat4 ModelView =  viewMatrix * Model;   	
    mat4 MVP = Projection * ModelView;

	mat3 normalMatrix = glm::transpose(glm::inverse(mat3(ModelView)));
	
	uint shaderProgHandle = object.GetShaderID();

	uint location = glGetUniformLocation(shaderProgHandle, "NormalMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix3fv(location, 1, GL_FALSE, &normalMatrix[0][0]); }

		location = glGetUniformLocation(shaderProgHandle, "ProjectionMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &Projection[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "ViewMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &viewMatrix[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "ModelViewMatrix");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &ModelView[0][0]); }

	location = glGetUniformLocation(shaderProgHandle, "MVP");	//gets the UniformLocation from shader.vertex
	if( location >= 0 ){ glUniformMatrix4fv(location, 1, GL_FALSE, &MVP[0][0]); }

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

void GraphicsCore::RenderObject(Object3D *object)
{
	glUseProgram(object->GetShaderID());
	glBindTexture(GL_TEXTURE_2D, object->GetTextureID());
	glBindVertexArray(object->GetModelID());

	
	if(mVAOModel.GetVertexCount(object->GetModelID()) == 1)
	{
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		UpdateBillboardObjectValues(*object);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisable(GL_BLEND);
	}
	else
	{
		UpdateLightValues(*object);
		UpdateObjectValues(*object);
		glDrawArrays(GL_TRIANGLES, 0, mVAOModel.GetVertexCount(object->GetModelID()));
	}
}

void GraphicsCore::RenderObjects(vector<Object3D*> objects)
{
	glUseProgram(objects[0]->GetShaderID());
	glBindTexture(GL_TEXTURE_2D, objects[0]->GetTextureID());
	glBindVertexArray(objects[0]->GetModelID());
	
	//if billboard
	if(mVAOModel.GetVertexCount(objects[0]->GetModelID()) == 1)
	{
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (int i = 0; i < objects.size(); i++)
		{
			UpdateBillboardObjectValues(*objects[i]);
			glDrawArrays(GL_POINTS, 0, 1);
		}
		glDisable(GL_BLEND);
	}
	//if 
	else
	{
		UpdateLightValues(*objects[0]);
		for (int i = 0; i < objects.size(); i++)
		{
			UpdateObjectValues(*objects[i]);
			glDrawArrays(GL_TRIANGLES, 0, mVAOModel.GetVertexCount(objects[i]->GetModelID()));
		}
	}
}

void GraphicsCore::EndRendering()
{
	glutSwapBuffers(); // swap drawing back-buffer to be displayed as front buffer
	//glutPostRedisplay(); // flag for redraw
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
	mCam.Control(0.1, 2.5, true);
}
