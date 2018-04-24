#include "square.h"
#include <GL/glut.h>

void Square::draw()
{
    glBegin(GL_QUADS);
    glColor3f(this->colors[0], this->colors[1], this->colors[2]);
    glVertex3f(this->vectors[0][0], this->vectors[0][1], this->vectors[0][2]);
    glVertex3f(this->vectors[1][0], this->vectors[1][1], this->vectors[1][2]);
    glVertex3f(this->vectors[2][0], this->vectors[2][1], this->vectors[2][2]);
    glVertex3f(this->vectors[3][0], this->vectors[3][1], this->vectors[3][2]);
    glEnd();
}

SquareBuilder::SquareBuilder()
{
    this->square = new Square();
}

SquareBuilder::~SquareBuilder()
{
    if(this->square != nullptr)
        delete this->square;
}

SquareBuilder* SquareBuilder::set_n_vector(int n, float x, float y, float z)
{
    if (n >= 0 && n < 4){
        this->square->vectors[n][0] = x;
        this->square->vectors[n][1] = y;
        this->square->vectors[n][2] = z;
    }
    return this;
}

float SquareBuilder::get_n_vector_x(int n)
{
    if(n < 0)
        n = 0;
    if(n > 3)
        n = 3;
    return this->square->vectors[n][0];
}

float SquareBuilder::get_n_vector_y(int n)
{
    if(n < 0)
        n = 0;
    if(n > 3)
        n = 3;
    return this->square->vectors[n][1];
}

float SquareBuilder::get_n_vector_z(int n)
{
    if(n < 0)
        n = 0;
    if(n > 3)
        n = 3;
    return this->square->vectors[n][2];
}

SquareBuilder* SquareBuilder::set_color(float red, float green, float blue)
{
    this->square->colors[0] = red;
    this->square->colors[1] = green;
    this->square->colors[2] = blue;
    return this;
}

Square *SquareBuilder::build()
{
    Square * square;
    square = this->square;
    this->square = nullptr;
    return square;
}

void SquareBuilder::reset_builder()
{
    if(this->square != nullptr)
        delete this->square;
    this->square = new Square();
}

