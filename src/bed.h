#ifndef BED_H
#define BED_H

#include "shape.h"
#include "parallelepiped.h"
#include "square.h"

class Bed : public Shape
{
public:
    Bed();
    ~Bed();

    void draw();
private:
    std::vector<Shape*> shapes;
};

#endif // BED_H
