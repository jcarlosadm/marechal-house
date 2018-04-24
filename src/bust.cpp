#include "bust.h"
#include <GL/glu.h>
#include <GL/glut.h>

Bust::Bust()
{
    this->base = new Parallelepiped(0.0f,0.0f,0.0f,0.5f,1.5f,0.5f);
    this->base2 = new Parallelepiped(0.0f,0.0f,0.0f,0.5f,0.3f,0.5f);
}

Bust::~Bust()
{
    if (this->base != nullptr)
        delete this->base;
    if (this->base2 != nullptr)
        delete this->base2;
}

void Bust::draw()
{
    if (this->base != nullptr){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(4.5f,-2.0f,-5.0f);

        this->base->draw();

        glTranslatef(0.0f,1.55f,0.0f);
        this->base2->draw();

        glTranslatef(0.0f,0.5f,0.0f);
        glColor3f(1.0f,0.0f,0.0f);
        glutSolidSphere(0.25,50,50);

        glPopMatrix();
    }
}
