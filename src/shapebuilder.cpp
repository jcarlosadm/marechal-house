#include <shapebuilder.h>
#include <cube.h>
#include <house.h>

ShapeBuilder::ShapeBuilder() {

}

Shape* ShapeBuilder::make(ShapeType shapeType) {
    if (shapeType == CUBE) {
        return new Cube();
    } else if (shapeType == HOUSE) {
        return new House();
    }

    return nullptr;
}

ShapeBuilder::~ShapeBuilder() {


}
