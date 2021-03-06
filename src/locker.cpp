#include "locker.h"
#include <GL/glu.h>

Locker::Locker()
{
    GLuint textures[6] = {
        2,
        1,
        1,
        1,
        1,
        1
    };

    shapes.push_back(new Parallelepiped(0.0f,-1.5f,0.0f,1.0f,2.0f,0.3f, textures));

    SquareBuilder sb;

    // pé esquerdo
    shapes.push_back(sb.set_n_vector(0,0.5f,-1.5f,0.15f)->set_n_vector(1,0.5f,-1.5f,-0.15f)->
                     set_n_vector(2,0.5f,-2.0f,-0.15f)->set_n_vector(3,0.5f,-2.0f,0.15f)->set_texture(1)->
                     set_normal_vec(1,0,0)->build());
    sb.reset_builder();

    // pé direito
    shapes.push_back(sb.set_n_vector(0,-0.5f,-1.5f,0.15f)->set_n_vector(1,-0.5f,-1.5f,-0.15f)->
                     set_n_vector(2,-0.5f,-2.0f,-0.15f)->set_n_vector(3,-0.5f,-2.0f,0.15f)->set_texture(1)->
                     set_normal_vec(-1,0,0)->build());
    sb.reset_builder();

    // porta esquerda
    shapes.push_back(sb.set_n_vector(0,0.8f,0.4f,-0.2f)->set_n_vector(1,0.4f,0.4f,-0.15f)->
                     set_n_vector(2,0.4f,-1.4f,-0.15f)->set_n_vector(3,0.8f,-1.4f,-0.2f)->set_texture(1)->
                     set_normal_vec(0,0,-1)->build());
    sb.reset_builder();

    // porta direita
    shapes.push_back(sb.set_n_vector(0,-0.4f,0.4f,-0.15f)->set_n_vector(1,-0.8f,0.4f,-0.20f)->
                     set_n_vector(2,-0.8f,-1.4f,-0.20f)->set_n_vector(3,-0.4f,-1.4f,-0.15f)->set_texture(1)->
                     set_normal_vec(0,0,-1)->build());
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
