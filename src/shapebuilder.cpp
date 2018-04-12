#include <shapebuilder.h>
#include <cube.h>

ShapeBuilder::ShapeBuilder() {

}

Shape* ShapeBuilder::make(ShapeType shapeType) {
    if (shapeType == CUBE)
        return new Cube();

    return nullptr;
}

ShapeBuilder::~ShapeBuilder() {


}
