#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

class RenderObject
{
	public:
		RenderObject();
		virtual ~RenderObject();

		virtual void Draw();
};

#endif