#pragma once
#include <vector>
#include "Uniform.h"
#include <string>

class ShaderProgram
{
public:
	ShaderProgram(std::string);
	~ShaderProgram();

	void start();
	unsigned int createShader(unsigned int, std::string);
	void storeUniforms(std::vector<Uniform>);
	void stop();

private:
	unsigned int programID, vertexShaderID, fragmentShaderID;

	std::string getShader(unsigned int);
};

