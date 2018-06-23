//
//  triangle_test.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/5/29.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "shader.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // 避免invalid operation

    // create window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "game engine", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    // keyboard
    glfwSetKeyCallback(window, key_callback);
    
    // glew true
    glewExperimental = GL_TRUE;
    
    // GLEW init
    glewInit();

    glViewport(0, 0, WIDTH, HEIGHT);
    
    // shader init
    Shader testShader("vertex.vs", "fragment.frag");

    // 顶点输入，标准化坐标
    GLfloat vertices[] = {
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // 右下方
        -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // 左下方
        0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // 上面顶点
    };

    // vbo vao
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        testShader.Use();

        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
