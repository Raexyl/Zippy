#version 330 core

layout (location = 0) in vec2 aPos;

in vec2 vs_ScreenSize;

//Translate from window pixel co-ordinates to GL co-ordinates (+ or - 1.0f in x and y axes)
vec2 ToGLSpace(in vec2 point)
{
	vec2 temp;
	temp.x = (point.x / (vs_ScreenSize.x/2)) - 1.0f;
	temp.y = (point.y / (vs_ScreenSize.y/2)) - 1.0f;
	return temp;
}

void main()
{
	vec2 newPos = ToGLSpace(aPos);
	gl_Position = vec4(newPos.x, newPos.y, 0.0, 1.0);
};

