#include "square.h"
#include <GL/glut.h>
#include <texture.h>

void Square::draw()
{

    if (applyTexture) {
        glBindTexture(GL_TEXTURE_2D, Texture::textures[this->texture]);
        glEnable(GL_TEXTURE_2D);
    }

    glBegin(GL_QUADS);
//    glNormal3f(0, 0, 0);

    if (applyTexture) {
        glColor3f(1.0f, 1.0f, 1.0f);
    } else {
        glColor3f(this->colors[0], this->colors[1], this->colors[2]);
    }

    glTexCoord2i(0, 0); glVertex3f(this->vectors[0][0], this->vectors[0][1], this->vectors[0][2]);
    glTexCoord2i(0, 1); glVertex3f(this->vectors[1][0], this->vectors[1][1], this->vectors[1][2]);
    glTexCoord2i(1, 1); glVertex3f(this->vectors[2][0], this->vectors[2][1], this->vectors[2][2]);
    glTexCoord2i(1, 0); glVertex3f(this->vectors[3][0], this->vectors[3][1], this->vectors[3][2]);
    glEnd();

    if (applyTexture) {
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, Texture::textures[this->texture]);
    }
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

SquareBuilder* SquareBuilder::set_texture(GLuint index)
{
    this->square->applyTexture = true;
    this->square->texture = index;

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

