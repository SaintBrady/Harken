#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shaders/shader.h>

#include "container.h"
#include "weapon.h"
#include "player.h"
#include "npc.h"
#include "gamecontroller.h"
#include "vector3d.h"
#include "quaternion.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 800;
const float PI = 3.14159265;

//g++ -o main.exe -I ./TransformComponents *.cpp TransformComponents/*.cpp
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1000, 800, "Harken", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to generate window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD Loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Build and compile shaders
    Shader mainShader("includes/shaders/shader.vs", "includes/shaders/shader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    // Create buffers
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind Buffers
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Textur coord attrib
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // load and create a texture 
    // -------------------------
    unsigned int mainTexture;

    // texture
    // ---------
    glGenTextures(1, &mainTexture);
    glBindTexture(GL_TEXTURE_2D, mainTexture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;

    unsigned char* data = stbi_load("Resources/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    Container chest(Container::CHEST);
    Vector3D chestPos = chest.transform.position;
    Quaternion chestRot = chest.transform.rotation;

    Vector3D rotAxis(0.2, 0.3, 0.4);
    rotAxis.Normalize();
    float angle = 0.0;

    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // Render pipeline
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, mainTexture);

        angle += 0.0005;
        if (angle >= 360) angle -= 360;

        chestRot.Rotate(rotAxis, angle);
        chestRot.Normalize();
        
        glm::quat myQuat(chestRot.w, chestRot.x, chestRot.y, chestRot.z);
        glm::mat4 transform = glm::toMat4(myQuat);

        mainShader.use();
        unsigned int transformLoc = glGetUniformLocation(mainShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;

    /*GameController gc;
    Player player("Hero", 100);
    NPC npc("Orc", 100, Weapon("Gore Dagger"));
    Container chest(Container::CHEST);

    // Global axis rotation quaternions for testing
    Quaternion xQ(0.0, 1.0, 0.0, 0.0);
    Quaternion yQ(0.0, 0.0, 1.0, 0.0);
    Quaternion zQ(0.0, 0.0, 0.0, 1.0);
    
    while (true)
    {
        std::cout << "-- Available Actions --\n1 - Spawn Chest\n2 - Open Inventory\n3 - Orc Swing\n4 - Player Swing\n5 - Print Objects\n6 - Rotate Chest\n7 - Exit" << std::endl;

        int input;
        std::string choice = "";
        bool validInput = true;

        std::getline(std::cin, choice);
        try
        {
            input = stoi(choice);
        }
        catch(std::exception e)
        {
            std::cout << "Invalid Input..." << std::endl;
            validInput = false;
        }

        if(validInput) {
            switch(input)
            {
                case 1:
                {
                    chest.open(player);
                    break;
                }
                    break;
                case 2:
                    player.openInventory();
                    break;
                case 3:
                    npc.attack(player);
                    break;
                case 4:
                    player.attack(npc);
                    break;
                case 5:
                    chest.transform.position.setPosition(3.0, 0.0, 0.0);
                    player.transform.position.setPosition(2.0, 7.0, -5.0);
                    gc.envObjects.push_back(&chest);
                    gc.envObjects.push_back(&player);
                    gc.envObjects.push_back(&npc);
                    gc.printObjects();
                    break;
                case 6:
                    std::cout << "--Chest Points Before Rotation--" << std::endl;
                    chest.mesh.printPoints();

                    //chest.transform.rotation.Rotate(chest.mesh, yQ, PI/6);
                    chest.transform.rotation.Rotate(chest.mesh, zQ, PI/4);

                    std::cout << std::endl << "--Chest Points After Rotation--" << std::endl;
                    chest.mesh.printPoints();

                    break;
                case 7:
                    return 0;
                default:
                    std::cout << "Invalid input..." << std::endl;
            }
        }
    }
    return 0;*/
}

// Handles window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Exit window
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}