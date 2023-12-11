#include "Model.h"


Model::Model() 
{
    
}

Model::Model(std::string path)
{
    modelData = loadModel(path);
}


std::vector<float> Model::loadModel(std::string path)
{
    vertexCount = 0;
    Assimp::Importer importer;
    unsigned int importOptions = aiProcess_Triangulate
        | aiProcess_OptimizeMeshes              // reduce the number of draw calls
        | aiProcess_JoinIdenticalVertices       // identifies and joins identical vertex data sets within all imported meshes
        | aiProcess_Triangulate                 // triangulates all faces of all meshes 
        | aiProcess_CalcTangentSpace;           // calculates the tangents and bitangents for the imported meshes

    const aiScene* scene = importer.ReadFile(path.c_str(), importOptions);

    if (scene) {
        aiMesh* mesh = scene->mMeshes[0];//Only first mesh 
        printf("Triangles:%d \n", mesh->mNumFaces);
        vertexCount = mesh->mNumFaces * 3;

        aiFace* f;
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) 
        {
            aiFace face = mesh->mFaces[i];

            for (unsigned int j = 0; j < 3; j++)
            {
                int id = face.mIndices[j];

                //Vertex position
                aiVector3D pos = mesh->mVertices[id];
                modelData.push_back(pos.x);
                modelData.push_back(pos.y);
                modelData.push_back(pos.z);

                //Vertex normal
                aiVector3D nor = mesh->mNormals[id];
                modelData.push_back(nor.x);
                modelData.push_back(nor.y);
                modelData.push_back(nor.z);

                //Vertex uv
                aiVector3D uv = mesh->mTextureCoords[0][id];
                modelData.push_back(uv.x);
                modelData.push_back(uv.y);

            }
        }
    }
    else 
    {
        std::cout << "An error occurred while loading model." << std::endl;
        exit(EXIT_FAILURE);
    };

    return modelData;
}
void Model::BindModel() {
	glBindVertexArray(this->VAO);
}

void Model::DrawModel(int id)
{
    glStencilFunc(GL_ALWAYS, id, 0xFF);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

std::string Model::getType()
{
    return this->type;
}
