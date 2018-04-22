#ifndef HOUSE_H
#define HOUSE_H

#include <shape.h>

class House : public Shape
{

public:
    House();
    ~House();

    void draw();

};

#endif // HOUSE_H
