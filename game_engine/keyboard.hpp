//
//  keyboard.hpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/28.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#ifndef keyboard_hpp
#define keyboard_hpp

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode, vec3* cameraPos, vec3* cameraFront, vec3 cameraUp);

#endif /* keyboard_h */
