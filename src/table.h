#ifndef TABLE_H
#define TABLE_H

#include "shape.h"
#include "square.h"
#include "parallelepiped.h"

class Table : public Shape
{
public:
    Table();
    ~Table();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // TABLE_H
