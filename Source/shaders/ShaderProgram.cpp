#include "ShaderProgram.h"
#include <glad/glad.h>

#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>

ShaderProgram::ShaderProgram(std::string packName)
{
	vertexShaderID = createShader(GL_VERTEX_SHADER, std::filesystem::current_path().string() + "\\Source\\shaders\\" + packName + "\\vertexShader.glsl");
	fragmentShaderID = createShader(GL_FRAGMENT_SHADER, std::filesystem::current_path().string() + "\\Source\\shaders\\" + packName + "\\fragmentShader.glsl");
	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
}

ShaderProgram::~ShaderProgram()
{
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void ShaderProgram::start()
{
	glUseProgram(programID);
}

unsigned int ShaderProgram::createShader(unsigned int type, std::string filePath)
{
	unsigned int shader = glCreateShader(type);
	std::ifstream infile(filePath);
	std::string line;
	std::string shaderSource = "";
	while (std::getline(infile, line))
	{
		shaderSource += line + "\n";
	}
	infile.close();
	const char* fileSource = shaderSource.c_str();
	glShaderSource(shader, 1, &fileSource, NULL);
	glCompileShader(shader);
	int  success;
	char infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER::" + getShader(type) + "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return shader;
}

void ShaderProgram::storeUniforms(std::vector<Uniform>)
{

}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

std::string ShaderProgram::getShader(unsigned int type) 
{
	return type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
}

