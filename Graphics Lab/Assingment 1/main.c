#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Keyboard callback function
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Check if key 'G' is pressed (GLFW_KEY_G handles both lower and uppercase)
    if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        std::cout << "Key 'G' pressed. Closing window...\n";
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Configure OpenGL context version (3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window titled "window"
    GLFWwindow* window = glfwCreateWindow(800, 600, "window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // Register key callback
    glfwSetKeyCallback(window, key_callback);

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Clear color set to Magenta: RGB(1.0, 0.0, 1.0)
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll event queues
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}