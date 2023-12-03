#include "Line.h"

glm::vec3 Line::calculatePoint()
{
    glm::vec3 result = A + (B - A) * t;
    A = result;
    return result;
}
