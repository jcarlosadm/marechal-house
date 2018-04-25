#include "locker.h"
#include <GL/glu.h>

Locker::Locker()
{
    shapes.push_back(new Parallelepiped(0.0f,-1.5f,0.0f,1.0f,2.0f,0.3f));

    SquareBuilder sb;
    shapes.push_back(sb.set_n_vector(0,0.5f,-1.5f,0.15f)->set_n_vector(1,0.5f,-1.5f,-0.15f)->
                     set_n_vector(2,0.5f,-2.0f,-0.15f)->set_n_vector(3,0.5f,-2.0f,0.15f)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,-0.5f,-1.5f,0.15f)->set_n_vector(1,-0.5f,-1.5f,-0.15f)->
                     set_n_vector(2,-0.5f,-2.0f,-0.15f)->set_n_vector(3,-0.5f,-2.0f,0.15f)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,0.8f,0.4f,-0.2f)->set_n_vector(1,0.4f,0.4f,-0.15f)->
                     set_n_vector(2,0.4f,-1.4f,-0.15f)->set_n_vector(3,0.8f,-1.4f,-0.2f)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,-0.4f,0.4f,-0.15f)->set_n_vector(1,-0.8f,0.4f,-0.20f)->
                     set_n_vector(2,-0.8f,-1.4f,-0.20f)->set_n_vector(3,-0.4f,-1.4f,-0.15f)->build());
}

Locker::~Locker()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}

void Locker::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-2.5f,0.0f,7.2f);

    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }

    glPopMatrix();
}
