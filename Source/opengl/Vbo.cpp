#include "Vbo.h"

Vbo::Vbo(GLenum target)
	: m_target(target)
{
	glGenBuffers(1, &id);
}

void Vbo::bindVbo()
{
	glBindBuffer(m_target, id);
}

void Vbo::storeData(float data[])
{
	glBufferData(m_target, sizeof(data), data, GL_STATIC_DRAW);
}

void Vbo::storeData(int data[])
{
	glBufferData(m_target, sizeof(data), data, GL_STATIC_DRAW);
}

void Vbo::unbindVbo()
{
	glBindBuffer(m_target, 0);
}
