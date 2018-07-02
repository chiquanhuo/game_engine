#version 330 core
layout (location = 0) in vec3 position; // position变量的属性位置值为0
// layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

// out vec3 vertexColor; // 为片段着色器指定一个颜色输出
out vec2 TexCoord;

// uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);  // Vclip=Mprojection⋅Mview⋅Mmodel⋅Vlocal
    //gl_Position = transform * vec4(position, 1.0); // 注意我们如何把一个vec3作为vec4的构造器的参数
    // vertexColor = color; // 把输出变量设置为暗红色
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}
