#shader vertex
#version 330 core
layout(location = 0) in vec4 aPos;

uniform mat4 proj_matrix;
uniform mat4 u_Matrix;

void main()
{
    gl_Position = (proj_matrix * u_Matrix * aPos);
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
    color = u_Color;
};
