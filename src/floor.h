#ifndef FLOOR_H
#define FLOOR_H

#include "square.h"
#include "shape.h"

class Floor: public Shape
{
    friend class FloorBuilder;
private:
    Floor(){}
public:
    ~Floor();
    void draw();
private:
    Square* square = nullptr;
};

class FloorBuilder
{
public:
    FloorBuilder();
    ~FloorBuilder();
    FloorBuilder* set_parameters(float centerx, float centerz, float y, float width, float length);
    FloorBuilder* set_color(float red, float green, float blue);
    Floor* build();
    void reset_builder();
private:
    Floor* floor = nullptr;
    SquareBuilder* squareBuilder = nullptr;
};

#endif // FLOOR_H
