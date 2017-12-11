// QT Libs
#include <QApplication>
#include <QTextEdit>

#include <assimp/Importer.hpp>

#include <glad/include/glad/glad.h>
#include <glad/src/glad.c>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "Shader.hpp"
#include "Camera.hpp"

#include "scene_object/scene_object.hpp"
#include "model/model.hpp"
#include "mesh/mesh.hpp"
#include "cube/cube.hpp"
#include "skybox/skybox.hpp"
#include "framebuffer/framebuffer.hpp"
#include "triangle/triangle.hpp"
#include "point_light/point_light.hpp"
#include "scene/Scene.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// Window settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

// Camera settings
Camera camera(glm::vec3(0.0f, 0.0f, 9.0f));
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;
//extern bool useMouseControls;

// Light Settings
glm::vec3 ambientLight = glm::vec3(0.1f, 0.1f, 0.1f);

// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;


int main2(int argv, char **args) {
    QApplication app(argv, args);

    QTextEdit textEdit;
    textEdit.show();

    return app.exec();
}

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
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
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
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers.  Load this early!
    // ----------------------------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    Scene scene;
    
    Cube scene_object(&scene,
              glm::vec3(2.0f, 0.0f, 2.0f),
              glm::vec3(0.0f, 0.0f, 0.0f),
              glm::vec3(1.0f, 1.0f, 1.0f));
    
    Cube scene_object2(&scene,
               glm::vec3(0.0f, 3.0f, -1.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));
    
    Cube scene_object3(&scene,
               glm::vec3(-3.0f, 2.0f, -7.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));
    
    FrameBuffer frameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    Skybox skybox(&scene);
    
    // blue light
    PointLight pointLight1(&scene,
                           glm::vec3(0.4f, 0.6f, 2.2f),
                           glm::vec3(-1.0f, 1.3f, 5.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));
    
    // orange light
    PointLight pointLight2(&scene,
                           glm::vec3(1.0f, 0.5f, 0.2f),
                           glm::vec3(2.0f, 2.5f, -1.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));
    
    // green light
    PointLight pointLight3(&scene,
                           glm::vec3(0.5f, 2.0f, 0.2f),
                           glm::vec3(0.0f, -2.5f, -2.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));
    
    Model nanoSuit(&scene,
                   "/Users/nwaters/code/go_stop/go_stop/assets/nanosuit/nanosuit.obj",
                   glm::vec3(-1.0f, 0.0f, 2.0f),
                   glm::vec3(0.0f, 0.0f, 0.0f),
                   glm::vec3(0.2f, 0.2f, 0.2f));
    
    // initializes all of the objects in the scene to prepare them for being rendered
    scene.initialize();
    
    Shader stencilShader = Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/scene_object/scene_object.vert",
                                  "/Users/nwaters/code/go_stop/go_stop/go_stop/border/border.frag");
    
    // configure global opengl state
    // -----------------------------
    glEnable(GL_CULL_FACE);
    glEnable(GL_BACK);

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
        glEnable(GL_STENCIL_TEST);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // don't forget to clear the stencil buffer!
        
        float timeValue = glfwGetTime();
        pointLight1.translate(glm::vec3(sin(timeValue) / 70.0,
                                        sin(timeValue) / 50.0,
                                        sin(timeValue) / 40.0));
        pointLight2.translate(glm::vec3(-(sin(timeValue) / 70.0),
                                        -(sin(timeValue) / 50.0),
                                        sin(timeValue) / 40.0));

        // --------------------------------------------------------------------
        // Render the scene
        // --------------------------------------------------------------------
//        glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer.framebuffer);
        
        // 1st. render pass, draw objects as normal, writing to the stencil buffer
        // --------------------------------------------------------------------
        glEnable(GL_DEPTH_TEST);
        
        // glStencilFunc only described what OpenGL should do with the content of the stencil buffer,
        // not how we can actually update the buffer
        glStencilFunc(GL_ALWAYS, 1, 0xFF); // all fragments should update the stencil buffer

        // The glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass) describes what to do with the buffer.
        // GL_KEEP: means keep what is already in the stencil
        // GL_REPLACE: means replace what is in the stencil
        glStencilOp(GL_KEEP,     // sfail: action to take if the stencil test fails.
                    GL_KEEP,     // dpfail: action to take if the stencil test passes, but the depth test fails.
                    GL_REPLACE); // dppass: action to take if both the stencil and the depth test pass
        
        glStencilMask(0xFF); // each bit is written to the stencil buffer as is
        
        scene.resetShader();
        scene.render();
        nanoSuit.Draw(nanoSuit.getShader());

        // --------------------------------------------------------------------
        // Border
        // 2nd. render pass: now draw slightly scaled versions of the objects, this time
        // disabling stencil writing.  Because the stencil buffer is now filled with several 1s.
        // The parts of the buffer that are 1 are not drawn, thus only drawing the objects'
        // size differences, making it look like borders.
        // --------------------------------------------------------------------
        glStencilFunc(GL_NOTEQUAL,  // func: Passes if the stencils value is not equal to the stored stencil value.
                      1,            // ref: Reference value for the stencil test that is compared against
                      0xFF);        // mask: mask that is ANDed with both the reference value and the stored stencil
                                    // value before the test compares them
        
        // THIS SHOULD WORK BUT DOESN'T. Each bit ends up as 0 in the stencil buffer (disabling writes)
        // glStencilMask(0x00);
        scene.setShader(stencilShader);
        scene.scale(glm::vec3(1.1, 1.1, 1.1));
        scene.render();
        scene.scale(glm::vec3(0.90909090909, 0.90909090909, 0.90909090909));
        
        glEnable(GL_DEPTH_TEST);
        
        // --------------------------------------------------------------------
        // Post-Processing
        // --------------------------------------------------------------------
//        glBindFramebuffer(GL_FRAMEBUFFER, 0); // back to default
//        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        frameBuffer.render();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    scene.deAllocate();
    
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
        camera.setMouseControl(true);
    }
    if (camera.getMouseControl() && glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_RELEASE) {
        std::cout << "Set mouse controls to off" << std::endl;
        camera.setMouseControl(false);
    }
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
