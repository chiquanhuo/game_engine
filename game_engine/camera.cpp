//
//  camera.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/7/12.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include <stdio.h>
#include "camera.hpp"

mat4 Camera::GetViewMatrix()
{
    return lookAt(this->Position, this->Position + this->Front, this->Up);
}

void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = this->MovementSpeed * deltaTime;
    if (direction == FORWARD)
        this->Position += this->Front * velocity;
    if (direction == BACKWARD)
        this->Position -= this->Front * velocity;
    if (direction == LEFT)
        this->Position -= this->Right * velocity;
    if (direction == RIGHT)
        this->Position += this->Right * velocity;
}

void Camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= this->MouseSensitivity;
    yoffset *= this->MouseSensitivity;
    
    this->Yaw   += xoffset;
    this->Pitch += yoffset;
    
    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (this->Pitch > 89.0f)
            this->Pitch = 89.0f;
        if (this->Pitch < -89.0f)
            this->Pitch = -89.0f;
    }
    
    // Update Front, Right and Up Vectors using the updated Eular angles
    this->updateCameraVectors();
}

void Camera::ProcessMouseScroll(GLfloat yoffset)
{
    if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
        this->Zoom -= yoffset;
    if (this->Zoom <= 1.0f)
        this->Zoom = 1.0f;
    if (this->Zoom >= 45.0f)
        this->Zoom = 45.0f;
}

// angle 计算 front
void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    vec3 front;
    front.x = cos(radians(this->Yaw)) * cos(radians(this->Pitch));
    front.y = sin(radians(this->Pitch));
    front.z = sin(radians(this->Yaw)) * cos(radians(this->Pitch));
    this->Front = normalize(front);
    this->Right = normalize(cross(this->Front, this->WorldUp));
    this->Up    = normalize(cross(this->Right, this->Front));
}







