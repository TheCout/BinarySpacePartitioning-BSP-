#include "Engine.h"
#include <Windows.h>
#include <chrono>
#include <thread>



using namespace Engine;


Player player;


void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);


void App::init()
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow(Configurations::WIDTH, Configurations::HEIGHT, Configurations::TITLE, nullptr, nullptr);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyboard);

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}


void App::mainLoop()
{
    using clock = std::chrono::steady_clock;
    auto next_frame = clock::now();

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, Configurations::WIDTH, Configurations::HEIGHT);

        // Draw stuff
        glClearColor(0.1, 0.1, 0.1, 0.5);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
        gluPerspective(Player::FOV, (double)Configurations::WIDTH / (double)Configurations::HEIGHT, 0.1, 100);

        glMatrixMode(GL_MODELVIEW_MATRIX);
        glTranslatef(0, 0, -50);

        render();


        // Finish draw and listen to user events
        glfwSwapBuffers(window);
        glfwPollEvents();


        player.movement();


        // Tick
        tick();
        next_frame += std::chrono::milliseconds(1000 / Configurations::FPS);
        std::this_thread::sleep_until(next_frame);
    }
}


void App::cleanup()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        player.moving.front = true;
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        player.moving.back = true;
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
        player.moving.left = true;
    else if (key == GLFW_KEY_D && action == GLFW_PRESS)
        player.moving.right = true;


    if (key == GLFW_KEY_W && action == GLFW_RELEASE)
        player.moving.front = false;
    if (key == GLFW_KEY_S && action == GLFW_RELEASE)
        player.moving.back = false;
    if (key == GLFW_KEY_A && action == GLFW_RELEASE)
        player.moving.left = false;
    if (key == GLFW_KEY_D && action == GLFW_RELEASE)
        player.moving.right = false;
}