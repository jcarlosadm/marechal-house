        #include <iostream>
    #include <GL/glut.h>
    #include <house.h>

    House::House()
    {
        std::cout << "House" << std::endl;
    }

    void House::draw()
    {
    //    std::cout << "House::draw" << std::endl;

            glScalef(2.0, 1.0, 2.0f);

//            glPolygonMode(GL_FRONT_AND_BACK, GL_COLOR);


            glBegin(GL_QUADS);
            // top
            glColor3f(1.0f, 0.0f, 0.0f);
            glNormal3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-1.5f, 1.5f, 1.5f);
            glVertex3f(1.5f, 1.5f, 1.5f);
            glVertex3f(1.5f, 1.5f, -1.5f);
            glVertex3f(-1.5f, 1.5f, -1.5f);

            glEnd();

            glBegin(GL_QUADS);
            // front
            glColor3f(0.0f, 1.0f, 0.0f);
            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-1.5f, -1.5f, 1.5f);
            glVertex3f(1.5f, -1.5f, 1.5f);
            glVertex3f(1.5f, 1.5f, 1.5f);
            glVertex3f(-1.5f, 1.5f, 1.5f);

            glEnd();

            glBegin(GL_QUADS);
            // right
            glColor3f(0.0f, 0.0f, 1.0f);
            glNormal3f(1.0f, 0.0f, 0.0f);
            glVertex3f(1.5f, -1.5f, 1.5f);
            glVertex3f(1.5f, -1.5f, -1.5f);
            glVertex3f(1.5f, 1.5f, -1.5f);
            glVertex3f(1.5f, 1.5f, 1.5f);

            glEnd();

            glBegin(GL_QUADS);
            // left
            glColor3f(0.0f, 0.0f, 1.5f);
            glNormal3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(-1.5f, -1.5f, 1.5f);
            glVertex3f(-1.5f, 1.5f, 1.5f);
            glVertex3f(-1.5f, 1.5f, -1.5f);
            glVertex3f(-1.5f, -1.5f, -1.5f);

            glEnd();

            glBegin(GL_QUADS);
            // bottom
            glColor3f(1.5f, 0.0f, 0.0f);
            glNormal3f(0.0f, -1.0f, 0.0f);
            glVertex3f(-1.5f, -1.5f, 1.5f);
            glVertex3f(1.5f, -1.5f, 1.5f);
            glVertex3f(1.5f, -1.5f, -1.5f);
            glVertex3f(-1.5f, -1.5f, -1.5f);

            glEnd();

            glBegin(GL_QUADS);
            // back
            glColor3f(0.0f, 1.5f, 0.0f);
            glNormal3f(0.0f, 0.0f, -1.0f);
            glVertex3f(1.5f, 1.5f, -1.5f);
            glVertex3f(1.5f, -1.5f, -1.5f);
            glVertex3f(-1.5f, -1.5f, -1.5f);
            glVertex3f(-1.5f, 1.5f, -1.5f);

            glEnd();


    //        glPushMatrix();
    //        glRotatef(.0f, 0.0f, 1.0f, 0.0f);

    //        glPopMatrix();



    }

    House::~House() {
        std::cout << "destructin House..." << std::endl;
    }
