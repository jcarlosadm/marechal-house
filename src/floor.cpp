#include "floor.h"

Floor::~Floor()
{
    if (this->square != nullptr)
        delete this->square;
}

void Floor::draw()
{
    if (this->square != nullptr)
        this->square->draw();
}

FloorBuilder::FloorBuilder()
{
    this->floor = new Floor();
    this->squareBuilder = new SquareBuilder();
    this->squareBuilder->set_color(DEFAULT_FLOOR_COLOR_RED,DEFAULT_FLOOR_COLOR_GREEN,
                                   DEFAULT_FLOOR_COLOR_BLUE);
}

FloorBuilder::~FloorBuilder()
{
    if(this->floor != nullptr)
        delete this->floor;
    if(this->squareBuilder != nullptr)
        delete this->squareBuilder;
}

FloorBuilder *FloorBuilder::set_parameters(float centerx, float centerz, float y, float width, float length)
{
    this->squareBuilder->set_n_vector(0, centerx - width/2.0f, y, centerz - length/2.0f);
    this->squareBuilder->set_n_vector(1, centerx - width/2.0f, y, centerz + length/2.0f);
    this->squareBuilder->set_n_vector(2, centerx + width/2.0f, y, centerz + length/2.0f);
    this->squareBuilder->set_n_vector(3, centerx + width/2.0f, y, centerz - length/2.0f);

    return this;
}

FloorBuilder *FloorBuilder::set_color(float red, float green, float blue)
{
    this->squareBuilder->set_color(red,green,blue);
    return this;
}

FloorBuilder *FloorBuilder::set_texture(GLuint index)
{
    this->squareBuilder->set_texture(index);
    return this;
}

Floor *FloorBuilder::build()
{
    this->floor->square = this->squareBuilder->build();
    Floor* floor = this->floor;
    this->floor = nullptr;
    return floor;
}

void FloorBuilder::reset_builder()
{
    if (this->floor != nullptr)
        delete this->floor;
    if (this->squareBuilder != nullptr)
        delete this->squareBuilder;

    this->floor = new Floor();
    this->squareBuilder = new SquareBuilder();
    this->squareBuilder->set_color(DEFAULT_FLOOR_COLOR_RED,DEFAULT_FLOOR_COLOR_GREEN,
                                   DEFAULT_FLOOR_COLOR_BLUE);
}
