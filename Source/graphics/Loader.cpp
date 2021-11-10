#include "Loader.h"

#include <iostream>

RawModel* Loader::loadToVao(float vertices[], size_t verticesSize)
{
    Vao vao;
    vao.bindVao({});
    vao.storeDataInAttributeList(0, 2, vertices);
    vao.unbindVao({});
    return new RawModel( vao, verticesSize / 2 );
}
