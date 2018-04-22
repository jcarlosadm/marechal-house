#include <iostream>
#include <GL/glut.h>
#include <cube.h>

Cube::Cube()
{
    std::cout << "Cube" << std::endl;
}

void Cube::draw()
{
//    std::cout << "Cube::draw" << std::endl;

        glBegin(GL_QUADS);
        // top
        glColor3f(1.0f, 0.0f, 0.0f);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        glEnd();

        glBegin(GL_QUADS);
        // front
        glColor3f(0.0f, 1.0f, 0.0f);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);

        glEnd();

        glBegin(GL_QUADS);
        // right
        glColor3f(0.3f, 0.5f, 1.3f);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);

        glEnd();

        glBegin(GL_QUADS);
        // left
        glColor3f(3.0f, 1.0f, 0.5f);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);

        glEnd();

        glBegin(GL_QUADS);
        // bottom
        glColor3f(0.5f, 0.0f, 3.0f);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);

        glEnd();

        glBegin(GL_QUADS);
        // back
        glColor3f(3.0f, 0.5f, 0.0f);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        glEnd();


//        glPushMatrix();
//        glRotatef(.0f, 0.0f, 1.0f, 0.0f);

//        glPopMatrix();



}

Cube::~Cube() {
    std::cout << "destructin cube..." << std::endl;
}
