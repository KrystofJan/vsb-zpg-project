#include "SkyCubeModel.h"
#include "SkyCube.h"
SkyCubeModel::SkyCubeModel()
{
	this->VBO = 0;
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skycube), skycube, GL_STATIC_DRAW);

	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void SkyCubeModel::DrawModel()
{
    // glClear(GL_DEPTH_BUFFER_BIT);
    glDepthMask(GL_FALSE);
	glDrawArrays(GL_TRIANGLES, 0, 36); //mode,first,count
    glDepthMask(GL_TRUE);
}
