#include "stairs.h"

#include "square.h"

#include <GL/glu.h>

Stairs::Stairs()
{
    GLuint texture = 8;

    SquareBuilder sb;
    // first stairs
    shapes.push_back(sb.set_n_vector(0,0.0f,-2.0f,-2.0f)->set_n_vector(1,-1.4f,-2.0f,-2.0f)->
                     set_n_vector(2,-1.4f,0.0f,1.0f)->set_n_vector(3,0.0f,0.0f,1.0f)->set_texture(texture)->build());
    // base
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,1.4f,0.0f,1.0f)->set_n_vector(1,-1.4f,0.0f,1.0f)->
                     set_n_vector(2,-1.4f,0.1f,2.0f)->set_n_vector(3,1.4f,0.1f,2.0f)->set_texture(texture)->build());
    sb.reset_builder();
    // second stairs
    shapes.push_back(sb.set_n_vector(0,1.4f,2.0f,-2.0f)->set_n_vector(1,0.0f,2.0f,-2.0f)->
                     set_n_vector(2,0.0f,0.0f,1.0f)->set_n_vector(3,1.4f,0.0f,1.0f)->set_texture(texture)->build());
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
