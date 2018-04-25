#include "bed.h"
#include <GL/glu.h>

Bed::Bed()
{
    shapes.push_back(new Parallelepiped(0.0f,-1.5f,0.0f,2.7f,0.15f,1.5f));

    SquareBuilder sb;
    shapes.push_back(sb.set_n_vector(0,1.35f,-1.0f,-0.75f)->set_n_vector(1,1.35f,-1.0f,0.75f)->
                     set_n_vector(2,1.35f,-2.0f,0.75f)->set_n_vector(3,1.35f,-2.0f,-0.75f)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,-1.35f,-1.0f,-0.75f)->set_n_vector(1,-1.35f,-1.0f,0.75f)->
                     set_n_vector(2,-1.35f,-2.0f,0.75f)->set_n_vector(3,-1.35f,-2.0f,-0.75f)->build());
}

Bed::~Bed()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}

void Bed::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3.6f,0.0f,5.5f);

    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }

    glPopMatrix();
}
