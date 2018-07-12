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
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


using namespace glm;

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.25f;
const GLfloat ZOOM = 45.0f;

class Camera
{
public:
    vec3 Position;
    vec3 Front;
    vec3 Up;
    vec3 Right;
    vec3 WorldUp;
    
    GLfloat Yaw;
    GLfloat Pitch;
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;
    
    Camera(vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 up = vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH) : Front(vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM)
    {
        this->Position = position;
        this->WorldUp = up;
        this->Yaw = yaw;
        this->Pitch = pitch;
        this->updateCameraVectors();
    }
    
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : Front(vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM)
    {
        this->Position = glm::vec3(posX, posY, posZ);
        this->WorldUp = glm::vec3(upX, upY, upZ);
        this->Yaw = yaw;
        this->Pitch = pitch;
        this->updateCameraVectors();
    }
    
    mat4 GetViewMatrix();
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);  // 键盘
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);  // 鼠标
    void ProcessMouseScroll(GLfloat yoffset);  // 鼠标滑动
private:
    // Calculates the front vector from the Camera's (updated) Eular Angles
    void updateCameraVectors();
};

//vec3 cameraPos = vec3(0.0f, 0.0f, 3.0f);
//vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
//vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

//vec3 cameraTarget = vec3(0.0f, 0.0f, 0.0f);
//vec3 cameraDirection = normalize(cameraPos - cameraTarget);
//vec3 cameraRight = normalize(cross(up, cameraDirection));
//vec3 cameraUp = cross(cameraDirection, cameraRight);

//mat4 LookAtView = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);;
//LookAtView = lookAt(
//    vec3(0.0f, 0.0f, 3.0f),  // camera pos
//    vec3(0.0f, 0.0f, 0.0f),  // camera target
//    vec3(0.0f, 1.0f, 0.0f)   // up in world
//);



#endif /* camera_hpp */
