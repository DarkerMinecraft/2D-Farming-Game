#pragma once
#include "../../opengl/Vao.h"
class RawModel
{
public:
	RawModel(Vao vao, int vertexCount)
		: m_vao(vao), m_vertexCount(vertexCount) {}
	Vao getVao() { return m_vao;  };
	int getVertexCount() { return m_vertexCount; };
private:
	Vao m_vao;
	int m_vertexCount;
};

