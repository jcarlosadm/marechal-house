#ifndef WALL_H
#define WALL_H

#include "shape.h"
#include "square.h"

#define DEFAULT_WALL_COLOR_RED 1.0f
#define DEFAULT_WALL_COLOR_GREEN 1.0f
#define DEFAULT_WALL_COLOR_BLUE 1.0f

#define DEFAULT_WALL_TEXTURE 6

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
    WallBuilder * set_texture(GLuint index);
    WallBuilder * set_normal(int x, int y, int z);
    Wall * build();
    void reset_builder();
private:
    Wall* wall = nullptr;
    SquareBuilder* square_builder = nullptr;
};

#endif // WALL_H
