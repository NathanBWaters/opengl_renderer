#include <glad/include/glad/glad.h>
#include <glad/src/glad.c>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "Shader.hpp"
#include "Camera.hpp"

#include "mesh/mesh.cpp"
#include "cube/cube.cpp"
#include "triangle/triangle.cpp"
#include "point_light/point_light.cpp"
#include "scene/Scene.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);


// Window settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Camera settings
Camera camera(glm::vec3(0.0f, 0.0f, 9.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
//extern bool useMouseControls;

// Light Settings
glm::vec3 ambientLight = glm::vec3(0.06f, 0.05f, 0.05f);

// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    std::cout << "Starting up the gears with GO_STOP_PATH: " << std::getenv("GO_STOP_PATH") << std::endl;
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    
    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers.  Load this early!
    // ----------------------------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glEnable(GL_DEPTH_TEST);
    
    Scene scene;
    
    Cube mesh(&scene,
              glm::vec3(2.0f, 0.0f, 2.0f),
              glm::vec3(0.0f, 0.0f, 0.0f),
              glm::vec3(1.0f, 1.0f, 1.0f));
    
    Cube mesh2(&scene,
               glm::vec3(0.0f, 0.0f, -1.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));
    
    Cube mesh3(&scene,
               glm::vec3(-3.0f, 2.0f, -7.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));
    
    PointLight pointLight1(&scene,
                           glm::vec3(0.0f, 0.0f, 3.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));
    
    // initializes all of the objects in the scene to prepare them for being rendered
//    scene.initialize();
    mesh.init();
    mesh2.init();
    mesh3.init();
    pointLight1.init();
 
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // ------------------------
        // input
        // ------------------------
        processInput(window);
        
        // Clear the color buffer and the z depth buffer
        glClearColor(ambientLight.x, ambientLight.y, ambientLight.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // ------------------------
        // render
        // ------------------------
//        scene.render();
        mesh.render();
        mesh2.render();
        mesh3.render();
        pointLight1.render();
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    pointLight1.deAllocate();
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(CAMERA_MOVE_UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS) {
        std::cout << "Set mouse controls to on" << std::endl;
//        useMouseControls = true;
    }
//    if (useMouseControls == true && glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_RELEASE) {
//        std::cout << "Set mouse controls to off" << std::endl;
//        useMouseControls = false;
//    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    
    lastX = xpos;
    lastY = ypos;
    
    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
