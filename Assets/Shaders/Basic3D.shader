#shader vertex
#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec2 texCoord;


out vec2 ourCoord;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    gl_Position = u_Projection * u_View * u_Model * aPos;
    ourCoord = texCoord;
}

#shader fragment
#version 330 core
layout (location = 0) out vec4 color;

uniform vec4 u_Color;
uniform vec4 lightColor;
uniform sampler2D ourTexture;

in vec2 ourCoord;

void main()
{
    color = u_Color;
    //color = texture(ourTexture, ourCoord);
}