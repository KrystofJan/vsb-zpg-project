#include "Renderer.h"


Renderer::Renderer(Scene* scene) {
	this->scene = scene;
}

void Renderer::Render() {
    this->scene->initScene();
    this->scene->displayTransform();
    glClearColor(.1, .1, .1, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    while (!this->scene->isWindowClosed()) {
        

        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        this->scene->display();
        
        glfwPollEvents();
        this->scene->swapBuffer();
        
    }
    this->scene->destroyWindow();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
