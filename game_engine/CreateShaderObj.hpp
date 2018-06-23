//
//  CreateShaderObj.hpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/4.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#ifndef CreateShaderObj_hpp
#define CreateShaderObj_hpp

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>  // 管理opengl函数指针
#include <GLFW/glfw3.h>
#include "Testfile.hpp"

void initShaderObj(char VShaderFile[], char FShaderFile[], GLuint* vshader, GLuint* fshader);
void initVBO(GLfloat positionData[], GLfloat colorData[], GLuint* vaoObj, GLuint* vboObj);

#endif /* CreateShaderObj_hpp */
