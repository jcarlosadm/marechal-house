#include "oglwidget.h"
#include "house.h"
#include "painting.h"
#include "bust.h"
#include "table.h"

#include <QTimer>

int OGLWidget::_width;
int OGLWidget::_height;

static double cam_angle_left_right = 90;
static double cam_angle_up_down = 0;
static float adj_x = 0.0;
static float adj_y = 0.0;
static float adj_z = -15.0;

static double world_angle_left_right = 0;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    this->setMouseTracking(true);

    OGLWidget::_width = this->width();
    OGLWidget::_height = this->height();

    shapes.push_back(new House());
    shapes.push_back(new Painting());
    shapes.push_back(new Bust());
    shapes.push_back(new Table());
}

OGLWidget::~OGLWidget(){
    std::vector<Shape *>::iterator it;

    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

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
              adj_x + cos(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0),
                adj_y + sin(cam_angle_up_down * 3.14 / 180.0),
                adj_z + sin(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0),
              // up vector
              0.0, 1.0, 0.0);

    // rotate around center
    glRotatef(world_angle_left_right,0.0f,1.0f,0.0f);

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
            cam_angle_left_right += 1.0;
            break;

        case Qt::Key_A:
            cam_angle_left_right -= 1.0;
            break;

        case Qt::Key_S:
            cam_angle_up_down -= 1.0;
            break;

        case Qt::Key_W:
            cam_angle_up_down += 1.0;
            break;

        case(Qt::Key_Up):
            adj_x += cos(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0);
            adj_y += sin(cam_angle_up_down * 3.14 / 180.0);
            adj_z += sin(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0);
            break;

        case(Qt::Key_Down):
            adj_x -= cos(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0);
            adj_y -= sin(cam_angle_up_down * 3.14 / 180.0);
            adj_z -= sin(cam_angle_left_right * 3.14 / 180.0) * cos(cam_angle_up_down * 3.14 / 180.0);
            break;

        case(Qt::Key_Left):
            world_angle_left_right -= 1.0;
            break;

        case(Qt::Key_Right):
            world_angle_left_right += 1.0;
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

    gluPerspective(60.0, ratio, 1.0, 30.0);

}
