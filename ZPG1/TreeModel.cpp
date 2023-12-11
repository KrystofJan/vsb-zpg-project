#include "TreeModel.h"
#include "Tree.h"

TreeModel::TreeModel() : Model("models/tree.obj")
{
	this->type = "tree";
	this->VBO = 0;
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, modelData.size() * sizeof(float), &modelData[0], GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1); //enable vertex attributes
	glEnableVertexAttribArray(2); //enable vertex attributes

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	//this->VBO = 0;
	//glGenBuffers(1, &this->VBO); // generate the VBO
	//glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(tree), tree, GL_STATIC_DRAW);

	////Vertex Array Object (VAO)
	//this->VAO = 0;
	//glGenVertexArrays(1, &this->VAO); //generate the VAO
	//glBindVertexArray(this->VAO); //bind the VAO
	//glEnableVertexAttribArray(0); //enable vertex attributes
	//glEnableVertexAttribArray(1); //enable vertex attributes

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	//glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	//std::cout << id << std::endl;
}
