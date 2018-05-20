#include "painting.h"

#include <GL/glu.h>

Painting::Painting()
{
    SquareBuilder sb;
    this->square = sb.set_n_vector(0, 0.0f, -0.3f, -0.2f)->set_n_vector(1, 0.0f, -0.3f, 0.2f)->
            set_n_vector(2, 0.1f, 0.3f, 0.2f)->set_n_vector(3,0.1f,0.3f,-0.2)->
            set_color(0.4f,0.4f,0.4f)->set_texture(11)->build();
}

Painting::~Painting()
{
    if (this->square != nullptr)
        delete this->square;
}

void Painting::draw()
{
    if(this->square != nullptr){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(-4.9f,0.0f,-5.0f);

        this->square->draw();

        glPopMatrix();
    }
}
