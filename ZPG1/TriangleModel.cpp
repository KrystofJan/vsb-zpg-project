#include "TriangleModel.h"

TriangleModel::TriangleModel()
{
	this->VBO = 0;
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->points), this->points, GL_STATIC_DRAW);

	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(this->points[0]), (GLvoid*)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(this->points[1]), (GLvoid*)sizeof(this->points[1][0]));
}

void TriangleModel::DrawModel(int id) {
	// draw triangles
	glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
}
