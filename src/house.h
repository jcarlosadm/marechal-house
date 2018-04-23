#ifndef HOUSE_H
#define HOUSE_H

#include <shape.h>

class House : public Shape
{
public:
    House();
    ~House();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // HOUSE_H
