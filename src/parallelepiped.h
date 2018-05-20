#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "shape.h"
#include "square.h"
#include <GL/glut.h>

class Parallelepiped : public Shape
{
public:
    Parallelepiped(float centerx, float centery, float centerz, float width, float height, float length, GLuint textures[6]);
    ~Parallelepiped();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // PARALLELEPIPED_H
