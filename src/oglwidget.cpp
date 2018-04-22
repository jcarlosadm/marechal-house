#include "oglwidget.h"

#include <QTimer>
#include <shapebuilder.h>

int OGLWidget::_width;
int OGLWidget::_height;

static int distance = 10;
static int left_right = 0;
static int down_up = 0;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    this->setMouseTracking(true);

    OGLWidget::_width = this->width();
    OGLWidget::_height = this->height();

    Shape *shape1 = ShapeBuilder::make(ShapeType::HOUSE);
    Shape *shape2 = ShapeBuilder::make(ShapeType::CUBE);

//    Shape *shape2 = ShapeBuilder::make(ShapeType::CUBE);

    shapes.push_back(shape1);
    shapes.push_back(shape2);

//    shapes.push_back(shape2);



}

OGLWidget::~OGLWidget(){
    std::vector<Shape *>::iterator it;

    for (it = shapes.begin(); it != shapes.end(); ++it) {
        delete (*it);
    }

    shapes.clear();
}


void OGLWidget::initializeGL()
{
    resizeGL(this->width(),this->height());
}



void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
    gluLookAt(0.0, 0.0, distance, // eye position
              0, 0, 0, // center position
              0.0, 1.0, 0.0 // up vector
              );

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.5f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-50.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.5f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -50.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.5f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(50.0f, 50.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.1f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-50.0f, -50.0f, 0.0f);
    glEnd();

    glRotatef ((GLfloat) down_up, 1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat) left_right, 0.0f, 1.0f, 0.0f);

//    glScalef( 2.0, 2.0, 0.0 );

    std::vector<Shape *>::iterator it;

    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr) {
            glPushMatrix();
                shape->draw();
            glPopMatrix();
        }
    }

    glPopMatrix();
    glFlush();

}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{
    std::cout << "x: " << event->x() << " y: " << event->y() << std::endl;
}

void OGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    std::cout << "x: " << event->x() << " y: " << event->y() << std::endl;
}

void OGLWidget::keyPressEvent(QKeyEvent *event)
{


    switch (event->key()) {
        case Qt::Key_D:
//            observerPosition[0] -= 0.1;
            break;

        case Qt::Key_A:
//            observerPosition[0] += 0.1;
            break;

        case Qt::Key_S:
//            observerPosition[1] -= 0.1;
              distance += 1;
            break;

        case Qt::Key_W:
//            observerPosition[1] += 0.1;
              distance -= 1;
            break;

        case(Qt::Key_Up):
            down_up = (down_up + 5) % 360;
            break;

        case(Qt::Key_Down):
            down_up = (down_up - 5) % 360;
            break;

        case(Qt::Key_Left):
            left_right = (left_right + 5) % 360;
            break;

        case(Qt::Key_Right):
            left_right = (left_right - 5) % 360;
            break;

        default:
            break;
    }
}


void OGLWidget::resizeGL(int w, int h)
{
    GLfloat ratio = (GLfloat) w / (GLfloat) h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(60.0, ratio, 1.0, 20.0);

}
