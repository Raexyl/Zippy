#version 330 core

out vec4 FragColor;

uniform vec4 ourColor;// = {1.0f, 0.0f, 1.0f, 1.0f};
uniform vec2 screenSize;// = {800.0f, 600.0f};

out vec2 vs_ScreenSize;

void main()
{
   FragColor = ourColor;

   //Pass on uniforms to vs.
   vs_ScreenSize = screenSize;
};