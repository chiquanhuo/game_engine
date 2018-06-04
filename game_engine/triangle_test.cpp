//
//  triangle_test.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/5/29.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>  // 管理opengl函数指针
#include <GLFW/glfw3.h>
#include "Textfile.h"

#define GLEW_STATIC

// 顶点输入，标准化坐标
GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f,
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void createShaderFile(const char *VShaderFile, const char *FShaderFile);

// 顶点着色器对象
GLuint vShader;



int main(int argc, const char * argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 设置主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 设置次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // OpenGL核心模式
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);  // 不可改变大小
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // 避免invalid operation
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "game engine", nullptr, nullptr);  // create window
    if (window == nullptr)
    {
        std::cout << "Fail to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    glfwSetKeyCallback(window, key_callback);
    
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    if (vertexShader == 0)
    {
        std::cout << "fail vertexshader" << std::endl;
        return -1;
    }
    
    glewExperimental = GL_TRUE;  // glew现代化技术
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Fail to init glew" << std::endl;
        return -1;
    }
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);  // set window 维度, (0,0) window 左下角位置
    // 处理过的opengl坐标范围只为(-1, 1)
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();  // 检查出发时间
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // 用自定义颜色清空屏幕
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);  // 交换颜色缓冲,使用双缓冲避免窗口闪烁，前缓冲保存最终输出的图像，所有渲染指令在后缓冲绘制
    }
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
