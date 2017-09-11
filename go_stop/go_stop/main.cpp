#include <iostream>

// GLEW handles the specification to a driver that the specific graphics card supports
#define GLEW_STATIC
#include <GL/glew.h>
#include <cmath>

#include "window.hpp"s

// GLFW is a library, written in C, specifically targeted at OpenGL providing the bare necessities
// required for rendering goodies to the screen. It allows us to create an OpenGL context, define
// window parameters and handle user input which is all that we need.
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
