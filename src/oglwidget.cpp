#include "oglwidget.h"

#include <QTimer>
#include <shapebuilder.h>

int OGLWidget::_width;
int OGLWidget::_height;

static double angle_left_right = 90;
static double angle_up_down = 0;
static float adj_x = 0.0;
static float adj_y = 0.0;
static float adj_z = -10.0;

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

    shapes.push_back(shape1);
    shapes.push_back(shape2);
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
    glEnable(GL_DEPTH_TEST);
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    gluLookAt(// eye position
              adj_x, adj_y, adj_z,
              // center position
              adj_x + cos(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0),
                adj_y + sin(angle_up_down * 3.14 / 180.0),
                adj_z + sin(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0),
              // up vector
              0.0, 1.0, 0.0);

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
            angle_left_right += 1.0;
            break;

        case Qt::Key_A:
            angle_left_right -= 1.0;
            break;

        case Qt::Key_S:
            angle_up_down -= 1.0;
            break;

        case Qt::Key_W:
            angle_up_down += 1.0;
            break;

        case(Qt::Key_Up):
            adj_x += cos(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0);
            adj_y += sin(angle_up_down * 3.14 / 180.0);
            adj_z += sin(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0);
            break;

        case(Qt::Key_Down):
            adj_x -= cos(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0);
            adj_y -= sin(angle_up_down * 3.14 / 180.0);
            adj_z -= sin(angle_left_right * 3.14 / 180.0) * cos(angle_up_down * 3.14 / 180.0);
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
