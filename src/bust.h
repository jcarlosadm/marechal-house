#ifndef BUST_H
#define BUST_H

#include "shape.h"
#include "parallelepiped.h"

class Bust : public Shape
{
public:
    Bust();
    ~Bust();

    void draw();
private:
    Parallelepiped * base = nullptr;
    Parallelepiped * base2 = nullptr;

};

#endif // BUST_H
