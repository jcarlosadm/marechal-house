#include "wall.h"

Wall::~Wall()
{
    if (this->square != nullptr)
        delete this->square;
}

void Wall::draw()
{
    this->square->draw();
}

WallBuilder::WallBuilder()
{
    this->wall = new Wall();
    this->square_builder = new SquareBuilder();
    this->square_builder->set_color(DEFAULT_WALL_COLOR_RED,DEFAULT_WALL_COLOR_GREEN,
                                    DEFAULT_WALL_COLOR_BLUE)->set_texture(1);
}

WallBuilder::~WallBuilder()
{
    if (this->wall != nullptr)
        delete this->wall;
    if (this->square_builder != nullptr)
        delete this->square_builder;
}

WallBuilder *WallBuilder::set_height(float ymin, float ymax)
{
    this->square_builder->set_n_vector(0,this->square_builder->get_n_vector_x(0),
                                       ymin,this->square_builder->get_n_vector_z(0));
    this->square_builder->set_n_vector(1,this->square_builder->get_n_vector_x(1),
                                       ymin,this->square_builder->get_n_vector_z(1));
    this->square_builder->set_n_vector(2,this->square_builder->get_n_vector_x(2),
                                       ymax,this->square_builder->get_n_vector_z(2));
    this->square_builder->set_n_vector(3,this->square_builder->get_n_vector_x(3),
                                       ymax,this->square_builder->get_n_vector_z(3));

    return this;
}

WallBuilder *WallBuilder::set_first_point(float x, float z)
{
    this->square_builder->set_n_vector(0, x, this->square_builder->get_n_vector_y(0), z);
    this->square_builder->set_n_vector(3, x, this->square_builder->get_n_vector_y(3), z);

    return this;
}

WallBuilder *WallBuilder::set_second_point(float x, float z)
{
    this->square_builder->set_n_vector(1, x, this->square_builder->get_n_vector_y(1), z);
    this->square_builder->set_n_vector(2, x, this->square_builder->get_n_vector_y(2), z);

    return this;
}

WallBuilder *WallBuilder::set_color(float red, float green, float blue)
{
    this->square_builder->set_color(red,green,blue);

    return this;
}

Wall *WallBuilder::build()
{
    this->wall->square = this->square_builder->build();
    Wall* wall = this->wall;
    this->wall = nullptr;
    return wall;
}

void WallBuilder::reset_builder()
{
    if (this->wall != nullptr)
        delete this->wall;
    if (this->square_builder != nullptr)
        delete this->square_builder;

    this->wall = new Wall();
    this->square_builder = new SquareBuilder();
    this->square_builder->set_color(DEFAULT_WALL_COLOR_RED,DEFAULT_WALL_COLOR_GREEN,
                                    DEFAULT_WALL_COLOR_BLUE)->set_texture(0);
}
