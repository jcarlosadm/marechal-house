#ifndef SHAPEBUILDER_H
#define SHAPEBUILDER_H

#include <shape.h>

enum ShapeType {HOUSE, CUBE, TRIANGLE, PLANE};

class ShapeBuilder
{

public:
    ShapeBuilder();
    ~ShapeBuilder();

    static Shape* make(ShapeType shapeType);

};

#endif // SHAPEBUILDER_H
