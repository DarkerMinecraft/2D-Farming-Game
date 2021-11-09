#include "Vao.h"
#include "Vbo.h"

#include <iostream>

Vao::Vao()
{
	glGenVertexArrays(1, &id);
}

void Vao::bindVao(const std::list<int>& index)
{
	glBindVertexArray(id);
	if(index.size() != 0)
	{
		for (int i : index) 
		{
			glEnableVertexArrayAttrib(id, i);
		}
	}
		
}

void Vao::storeDataInAttributeList(unsigned int index, int size, float data[])
{
	Vbo vbo (GL_ARRAY_BUFFER);
	vbo.bindVbo();
	vbo.storeData(data);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	vbo.unbindVbo();
}

void Vao::unbindVao(const std::list<int>& index)
{
	if (index.size() != 0)
	{
		for (int i : index)
		{
			glDisableVertexArrayAttrib(id, i);
		}
	}
	glBindVertexArray(0);
}
