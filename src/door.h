#ifndef DOOR_H
#define DOOR_H

#include "shape.h"
#include "square.h"

#define DEFAULT_DOOR_COLOR_RED 0.0f
#define DEFAULT_DOOR_COLOR_GREEN 0.0f
#define DEFAULT_DOOR_COLOR_BLUE 0.5f

class Door: public Shape
{
    friend class DoorBuilder;
private:
    Door(){}
public:
    ~Door();

    void draw();
    static void open_close();
private:
    Square * square = nullptr;
    static bool open;
    float translate_x, translate_z;
};

class DoorBuilder
{
public:
    DoorBuilder();
    ~DoorBuilder();
    DoorBuilder* set_height(float ymin, float ymax);
    DoorBuilder* set_first_point(float x, float z);
    DoorBuilder* set_second_point(float x, float z);
    DoorBuilder* set_color(float red, float green, float blue);
    Door * build();
    void reset_builder();
private:
    Door * door = nullptr;
    SquareBuilder * square_builder = nullptr;
};

#endif // DOOR_H
