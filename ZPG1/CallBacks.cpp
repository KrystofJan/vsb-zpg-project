#include "CallBacks.h"

double mouseY = 0;
double mouseX = 0;

void CallBacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void CallBacks::error_callback(int error, const char* description) { fputs(description, stderr); }

void CallBacks::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void CallBacks::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void CallBacks::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void CallBacks::cursor_callback(GLFWwindow* window, double x, double y) { 
    
    mouseX = x; mouseY = y;
    // printf("%f %f\n", mouseX, mouseY);
}

void CallBacks::button_callback(GLFWwindow* window, int button, int action, int mode) {
    if (action == GLFW_PRESS) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        GLbyte color[4];
        GLfloat depth;
        GLuint index; // identifikace tìlesa
        int newy = height - mouseY - 10;
        glReadPixels(mouseX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
        glReadPixels(mouseX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
        glReadPixels(mouseX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
        printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth % f, stencil index %u\n", mouseX, mouseY, color[0], color[1], color[2], color[3], depth, index);
    }
}
