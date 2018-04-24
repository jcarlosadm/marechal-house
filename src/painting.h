#ifndef PAINTING_H
#define PAINTING_H

#include "shape.h"
#include "square.h"

class Painting : public Shape
{
public:
    Painting();
    ~Painting();

    void draw();
private:
    Square * square = nullptr;
};

#endif // PAINTING_H
