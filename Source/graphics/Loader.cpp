#include "Loader.h"

RawModel Loader::loadToVao(float vertices[])
{
    Vao vao;
    vao.bindVao({});
    vao.storeDataInAttributeList(0, 2, vertices);
    vao.unbindVao({});
    int verticesSize = sizeof(vertices);
    return { vao, verticesSize / 2 };
}
