#include "stairs.h"

#include "square.h"
#include "parallelepiped.h"

#include <GL/glu.h>

Stairs::Stairs()
{
    GLuint textures[6] = {8,8,8,8,8,8};

    // first stairs
    for(int i = 0; i < 10; ++i)
        shapes.push_back(new Parallelepiped(-0.7f, -2.0f + i*0.2f, -2.0f + i*0.3f, 1.35f, 0.2f, 0.3f, textures));

    // base
    shapes.push_back(new Parallelepiped(0.0f, -0.2f, 1.5f, 2.7f, 0.2f, 1.2f, textures));

    // second stairs
    for(int i = 0; i < 10; ++i)
        shapes.push_back(new Parallelepiped(0.7f, 0.0f + i*0.2f, 1.0f - i*0.3f, 1.35f, 0.2f, 0.3f, textures));
}

Stairs::~Stairs()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}

void Stairs::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,0.0f,2.0f);

    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }

    glPopMatrix();
}
