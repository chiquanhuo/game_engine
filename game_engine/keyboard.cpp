//
//  keyboard.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/28.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include "keyboard.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode, vec3* cameraPos, vec3* cameraFront, vec3* cameraUp)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    GLfloat cameraSpeed = 0.05f;
    if (key == GLFW_KEY_W)
        cameraPos += cameraFront * cameraSpeed;
    if(key == GLFW_KEY_S)
        cameraPos -= cameraFront * cameraSpeed;
    if(key == GLFW_KEY_A)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(key == GLFW_KEY_D)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
