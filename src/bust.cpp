#include "bust.h"
#include <GL/glu.h>
#include <GL/glut.h>

GLUquadricObj *sphere = NULL;
GLUquadricObj *cylinder = NULL;
GLuint _textureId = 10;

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_CULL_FACE);

    sphere = gluNewQuadric();
    cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluQuadricTexture(cylinder, GL_TRUE);
    gluQuadricNormals(cylinder, GLU_SMOOTH);

    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
}

Bust::Bust()
{

    init();

    GLuint texturesBase[6] = {
        5, // 0 front
        5, // 1 back
        5, // 2 left
        5, // 3 right
        5, // 4 up
        5  // 5 bottom
    };

    GLuint texturesBase2[6] = {
        5, // 0 front
        5, // 1 back
        5, // 2 left
        5, // 3 right
        5, // 4 up
        5  // 5 bottom
    };


    this->base = new Parallelepiped(0.0f,0.0f,0.0f,0.5f,1.5f,0.5f, texturesBase);
    this->base2 = new Parallelepiped(0.0f,0.0f,0.0f,0.5f,0.3f,0.5f, texturesBase2);
}

Bust::~Bust()
{
    if (this->base != nullptr)
        delete this->base;
    if (this->base2 != nullptr)
        delete this->base2;

     gluDeleteQuadric(sphere);
     gluDeleteQuadric(cylinder);
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

        glTranslatef(0.0f,0.55f,0.0f);
        glRotatef(-80, 0, 0, 1);
        glRotatef(90, 0, 1, 0);

//        Texture::sphere = true;
        glBindTexture(GL_TEXTURE_2D, Texture::textures[_textureId]);
        glEnable(GL_TEXTURE_2D);
        gluSphere(sphere, 0.25, 150, 150);
//        glutSolidSphere(0.25,50,50);
        gluCylinder(cylinder, 20.0, 20.0, 20.0, 1, 16);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, Texture::textures[_textureId]);

        glPopMatrix();
    }
}
