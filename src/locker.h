#ifndef LOCKER_H
#define LOCKER_H

#include "shape.h"
#include "parallelepiped.h"
#include "square.h"

class Locker : public Shape
{
public:
    Locker();
    ~Locker();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // LOCKER_H
