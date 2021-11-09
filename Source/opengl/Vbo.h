#pragma once
#include <glad/glad.h>
#include <list>
class Vbo
{
public:
	Vbo(GLenum);

	void bindVbo();
	void storeData(float[]);
	void storeData(int[]);
	void unbindVbo();
private:
	GLenum m_target;
	unsigned int id;
};

