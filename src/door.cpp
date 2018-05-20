#include "door.h"
#include <GL/glu.h>

bool Door::open = false;

Door::~Door()
{
    if(this->square != nullptr)
        delete this->square;
}

void Door::draw()
{
    if (this->square != nullptr){
        if (Door::open){
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glTranslatef(this->translate_x,0.0f,this->translate_z);
            glRotatef(-90.0f,0.0f,1.0f,0.0f);
            glTranslatef(-this->translate_x,0.0f,-this->translate_z);
        }

        this->square->draw();

        if(Door::open)
            glPopMatrix();
    }
}

void Door::open_close()
{
    Door::open = (Door::open ? false : true);
}

DoorBuilder::DoorBuilder()
{
    this->door = new Door();
    this->square_builder = new SquareBuilder();
    this->square_builder->set_color(DEFAULT_DOOR_COLOR_RED,DEFAULT_DOOR_COLOR_GREEN,
                                    DEFAULT_DOOR_COLOR_BLUE);
}

DoorBuilder::~DoorBuilder()
{
    if (this->door != nullptr)
        delete this->door;
    if (this->square_builder != nullptr)
        delete this->square_builder;
}

DoorBuilder *DoorBuilder::set_height(float ymin, float ymax)
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

DoorBuilder *DoorBuilder::set_first_point(float x, float z)
{
    this->square_builder->set_n_vector(0, x, this->square_builder->get_n_vector_y(0), z);
    this->square_builder->set_n_vector(3, x, this->square_builder->get_n_vector_y(3), z);

    return this;
}

DoorBuilder *DoorBuilder::set_second_point(float x, float z)
{
    this->square_builder->set_n_vector(1, x, this->square_builder->get_n_vector_y(1), z);
    this->square_builder->set_n_vector(2, x, this->square_builder->get_n_vector_y(2), z);

    return this;
}

DoorBuilder *DoorBuilder::set_color(float red, float green, float blue)
{
    this->square_builder->set_color(red,green,blue);

    return this;
}

DoorBuilder *DoorBuilder::set_texture(GLuint index)
{
    this->square_builder->set_texture(index);

    return this;
}

Door *DoorBuilder::build()
{
    this->door->translate_x = this->square_builder->get_n_vector_x(0);
    this->door->translate_z = this->square_builder->get_n_vector_z(0);
    this->door->square = this->square_builder->build();
    Door* door = this->door;
    this->door = nullptr;
    return door;
}

void DoorBuilder::reset_builder()
{
    if (this->door != nullptr)
        delete this->door;
    if (this->square_builder != nullptr)
        delete this->square_builder;

    this->door = new Door();
    this->square_builder = new SquareBuilder();
    this->square_builder->set_color(DEFAULT_DOOR_COLOR_RED,DEFAULT_DOOR_COLOR_GREEN,
                                    DEFAULT_DOOR_COLOR_BLUE);
}
