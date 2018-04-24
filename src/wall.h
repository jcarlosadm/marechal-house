#ifndef WALL_H
#define WALL_H

#include "shape.h"
#include "square.h"

#define DEFAULT_WALL_COLOR_RED 0.0f
#define DEFAULT_WALL_COLOR_GREEN 1.0f
#define DEFAULT_WALL_COLOR_BLUE 0.3f

class Wall: public Shape
{
    friend class WallBuilder;
private:
    Wall(){}
public:
    ~Wall();

    void draw();
private:
    Square * square = nullptr;
};

class WallBuilder
{
public:
    WallBuilder();
    ~WallBuilder();
    WallBuilder * set_height(float ymin, float ymax);
    WallBuilder * set_first_point(float x, float z);
    WallBuilder * set_second_point(float x, float z);
    WallBuilder * set_color(float red, float green, float blue);
    Wall * build();
    void reset_builder();
private:
    Wall* wall = nullptr;
    SquareBuilder* square_builder = nullptr;
};

#endif // WALL_H
