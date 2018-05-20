#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include "texture.h"
#include <GL/glu.h>

class Square : public Shape
{
    friend class SquareBuilder;
private:
    Square(){}
public:
    ~Square(){}
    void draw();
private:
    float colors[3] = {1.0f,0.0f,0.0f};
    bool applyTexture = false;
    GLuint texture = -1;
    float vectors[4][3] =
    {
        {0.0f,0.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {1.0f,1.0f,0.0f},
        {0.0f,1.0f,0.0f}
    };
};

class SquareBuilder
{
public:
    SquareBuilder();
    ~SquareBuilder();
    /**
     * @brief add_n_vector
     * @param n number of vector, starting in 0
     * @param x
     * @param y
     * @param z
     * @return SquareBuilder instance
     */
    SquareBuilder* set_n_vector(int n, float x, float y, float z);
    float get_n_vector_x(int n);
    float get_n_vector_y(int n);
    float get_n_vector_z(int n);
    SquareBuilder* set_color(float red, float green, float blue);
    SquareBuilder* set_texture(GLuint index);
    Square * build();
    void reset_builder();
private:
    Square * square = nullptr;
};

#endif // SQUARE_H
