#version 330 core

layout (location = 0) in vec2 aPos;

uniform vec2 screenSize = vec2(800.0f, 600.0f);

//Translate from window pixel co-ordinates to GL co-ordinates (+ or - 1.0f in x and y axes)
vec2 ToGLSpace(in vec2 point)
{
	vec2 temp;
	temp.x = (point.x / (screenSize.x/2)) - 1.0f;
	temp.y = (point.y / (screenSize.y/2)) - 1.0f;
	return temp;
}

void main()
{
	vec2 newPos = ToGLSpace(aPos);
	gl_Position = vec4(newPos.x, newPos.y, 0.0, 1.0);
};

