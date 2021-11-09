#pragma once
#include <glad/glad.h>
#include <list>

class Vao
{
public:
	Vao();

	void bindVao(const std::list<int>&);
	void storeDataInAttributeList(unsigned int, int, float[]);
	void unbindVao(const std::list<int>&);

	unsigned int id;

private:
};
