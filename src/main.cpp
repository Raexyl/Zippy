//Test GLAD and GLFW3 together, no extras

//Logging (& debugging)
#include <iostream>

//Graphics
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main(void)
{
    std::cout << "Starting..." << std::endl;

    //InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    return 0;
}