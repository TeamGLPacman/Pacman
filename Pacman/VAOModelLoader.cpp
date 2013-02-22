#include "VAOModelLoader.h"


VAOModelLoader::VAOModelLoader(void)
{
}


VAOModelLoader::~VAOModelLoader(void)
{
}

uint VAOModelLoader::CreateModel(vector<VertexPoint> vertexList)
{
	GLuint VAOHandle;
	float* positionData = new float[vertexList.size()*3];
	float* texCoordData = new float[vertexList.size()*2];
	float* normalData = new float[vertexList.size()*3];
	int count = 0;

	for(int i = 0; i < vertexList.size(); i++)
	{
		positionData[3*count] = vertexList[i].mPosition.x;
		positionData[3*count+1] = vertexList[i].mPosition.y;
		positionData[3*count+2] = vertexList[i].mPosition.z;

		texCoordData[2*count] = vertexList[i].mTexCoord.x;
		texCoordData[2*count+1] = vertexList[i].mTexCoord.y;

		normalData[3*count] = vertexList[i].mNormal.x;
		normalData[3*count+1] = vertexList[i].mNormal.y;
		normalData[3*count+2] = vertexList[i].mNormal.z;

		count++;
	}
	
	// remember how many
	int numberOfPoints = count*3;

	// Make 3 new VBO handles
	GLuint VBOHandles[3];
	glGenBuffers(3, VBOHandles);

	// "Bind" (switch focus to) first buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[0]); 

	// Put data in currently bound buffer
	glBufferData(GL_ARRAY_BUFFER, numberOfPoints * sizeof(float), positionData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[1]);
	glBufferData(GL_ARRAY_BUFFER, numberOfPoints * sizeof(float), normalData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[2]);
	glBufferData(GL_ARRAY_BUFFER, count*2 * sizeof(float), texCoordData, GL_STATIC_DRAW);

	// create 1 VAO
	glGenVertexArrays(1, &VAOHandle);
	glBindVertexArray(VAOHandle);

	// enable "vertex attribute arrays"
	glEnableVertexAttribArray(0); // position
	glEnableVertexAttribArray(1); // normal
	glEnableVertexAttribArray(2); // texCoord

	// map index 0 to position buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[2]);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

	glBindVertexArray(0); // disable VAO
	glUseProgram(0); // disable shader programme

	delete positionData, normalData, texCoordData;

	mModelVertexCount.insert(VAOHandle, vertexList.size());

	return VAOHandle;
}

uint VAOModelLoader::CreateModel(vec3 position)
{
	GLuint VAOHandle;
	float* positionData = new float[3];
	positionData[0] = position.x;
	positionData[1] = position.y;
	positionData[2] = position.z;

	// Make 2 new VBO handles
	GLuint VBOHandles[1];
	glGenBuffers(1, VBOHandles);

	// "Bind" (switch focus to) first buffer, then Put data in currently bound buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[0]); 
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float), positionData, GL_STATIC_DRAW);

	// create 1 VAO
	glGenVertexArrays(1, &VAOHandle);
	glBindVertexArray(VAOHandle);

	// enable "vertex attribute arrays"
	glEnableVertexAttribArray(0); // position

	// map index 0 to position buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBOHandles[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);


	glBindVertexArray(0); // disable VAO
	glUseProgram(0); // disable shader programme

	delete positionData;

	mModelVertexCount.insert(VAOHandle, 1);

	return VAOHandle;
}