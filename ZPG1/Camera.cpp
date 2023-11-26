#include "Camera.h"

Camera::Camera(GLFWwindow* window)
{
    this->window = window;
}

void Camera::notify() {
    for (Observer* o : observers) {
        o->update();
    }
}

void Camera::call_cursor(double x, double y) {

    if (firstMouse) // initially set to true
    {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }
    double xoffset = x - lastX;
    double yoffset = lastY - y;

    lastX = x;
    lastY = y;

    xoffset *= sensitivity; // sensitivity set to 0.1
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

void Camera::controls() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    float cameraSpeed = static_cast<float>(2.5 * deltaTime);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        double x, y;
        glfwGetCursorPos(this->window, &x, &y);
        this->call_cursor(x, y);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE)
    {
        this->firstMouse = true;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        cameraSpeed = static_cast<float>(2.5 * deltaTime) * 4;
    }
}

glm::mat4 Camera::getViewMatrix() {
    this->viewMatrix = glm::lookAt(this->cameraPos, this->cameraPos + this->cameraFront, this->cameraUp);
    return this->viewMatrix;
}

glm::vec3  Camera::getPosition()
{
    return this->cameraPos;
}
glm::vec3 Camera::getDirection() {
    return this->cameraFront;
}
glm::vec3 Camera::unProjectCameraPos(glm::vec3 position)
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glm::vec4 viewPort = glm::vec4(0, 0, width, height);
    return  glm::unProject(position, viewMatrix, projectionMatrix, viewPort);
}
glm::mat4 Camera::getProjectionMatrix()
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    this->projectionMatrix = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
    return this->projectionMatrix;
}
