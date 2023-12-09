#pragma once
// Login: ZAH0089
#include <GL/glew.h>


//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags
#include <iostream>

class Model
{
private:
	std::vector<float> loadModel(std::string path);
protected:
	GLuint VBO;
	GLuint VAO;
	int vertexCount;
	std::vector<float> modelData;

public:
	Model();
	Model(std::string path);
	void BindModel();
	virtual void DrawModel(int id);

};

