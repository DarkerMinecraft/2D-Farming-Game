#include "graphics/DisplayManager.h"
#include "graphics/model/RawModel.h"
#include "graphics/Loader.h"          
#include "shaders/entities/EntityShader.h"
#include <iostream>

int main() {
	if (!DisplayManager::createDisplay(1280, 720, "Farming Game")) return -1;

	float vertices[] = {
	-0.5f, -0.5f, 
	 0.5f, -0.5f,
	 0.0f,  0.5f
	};

	RawModel* rawModel = Loader::loadToVao(vertices, sizeof(vertices) / sizeof(vertices[0]));

	EntityShader shader;

	printf("ID: %d, Vertex Count: %d", rawModel->getVao().id, rawModel->getVertexCount());
	
	while (DisplayManager::isDisplayRunning())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		Vao vao = rawModel->getVao();
		shader.start();
		vao.bindVao({ 0 });
		glDrawArrays(GL_TRIANGLES, 0, rawModel->getVertexCount());
		vao.unbindVao({ 0 });
		shader.stop();
		DisplayManager::updateDisplay();
	}
	DisplayManager::destroyDisplay();
	return 0;
}