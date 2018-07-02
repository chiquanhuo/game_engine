//
//  camera.hpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/28.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

vec3 cameraPos = vec3(0.0f, 0.0f, 3.0f);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

//vec3 cameraTarget = vec3(0.0f, 0.0f, 0.0f);
//vec3 cameraDirection = normalize(cameraPos - cameraTarget);
//vec3 cameraRight = normalize(cross(up, cameraDirection));
//vec3 cameraUp = cross(cameraDirection, cameraRight);

mat4 LookAtView = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);;
//LookAtView = lookAt(
//    vec3(0.0f, 0.0f, 3.0f),  // camera pos
//    vec3(0.0f, 0.0f, 0.0f),  // camera target
//    vec3(0.0f, 1.0f, 0.0f)   // up in world
//);



#endif /* camera_hpp */
