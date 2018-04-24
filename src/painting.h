#ifndef PAINTING_H
#define PAINTING_H

#include "shape.h"

class Painting : public Shape
{
public:
    Painting();
    ~Painting();

    void draw();
};

#endif // PAINTING_H
