#include "Model.h"
Model::Model() {}

void Model::BindModel() {
	glBindVertexArray(this->VAO);
}
