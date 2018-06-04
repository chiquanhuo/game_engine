//
//  CreateShaderObj.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/4.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include "CreateShaderObj.hpp"

void createShaderFile(const char *VShaderFile, const char *FShaderFile)
{
    // declare
    
    // 创建着色器
    vShader = glCreateShader(GL_VERTEX_SHADER);
    if (0 == vShader)
    {
        std::cout << "ail create vshader" << std::endl;
        exit(1);
    }
    
    // .vert 读shader
    const GLchar *vShaderCode = textFileRead(VShaderFile);
    const GLchar *vCodeArray[1] = {vShaderCode};
    
    //绑定code到着色器对象
    glShaderSource(vShader, 1, vCodeArray, NULL);
    
    // 编译着色器对象
    glCompileShader(vShader);
    
    // 检查编译是否成功
    GLint compileResult;
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &compileResult);
    if (GL_FALSE == compileResult)
    {
        GLint logLen;
        glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logLen);
        if (logLen > 0)
        {
            char *log = (char *)malloc(logLen);
            GLsizei written;
            // 得到日志信息
            glGetShaderInfoLog(vShader, logLen, &written, log);
            std::cout << "fail compile shader" << std::endl;
            std::cout << log << std::endl;
            free(log);
        }
    }
    // TODO 片段着色器
    
    // 链接着色器对象
    GLuint programHandle = glCreateProgram();
    if (!programHandle)
    {
        std::cout << "fail link program" << std::endl;
        exit(1);
    }
    
    // 将着色器链接到创建的程序中
    glAttachShader(programHandle, vShader);
    
    // LINK
    glLinkProgram(programHandle);
    
    GLint linkStatus;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkStatus);
    if (GL_FALSE == linkStatus)
    {
        std::cout << "fail link program" << std::endl;
        GLint logLen;
        glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &logLen);
        if (logLen > 0)
        {
            char *log = (char *)malloc(logLen);
            GLsizei written;
            glGetProgramInfoLog(programHandle, logLen, &written, log);
            std::cout << "program log: " << std::endl;
            std::cout << log << std::endl;
        }
    }
    else
    {
        glUseProgram(programHandle);
    }
}
