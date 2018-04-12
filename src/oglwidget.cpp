#include "oglwidget.h"

#include <QTimer>

int OGLWidget::_width;
int OGLWidget::_height;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    OGLWidget::_width = this->width();
    OGLWidget::_height = this->height();
}

OGLWidget::~OGLWidget(){

//    Shape *shape = ShapeBuilder::make(ShapeType::CUBE);

//    if (shape != nullptr)
//        shape->draw();

//    delete shape;

}

void OGLWidget::initializeGL()
{
    resizeGL(this->width(),this->height());
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glFlush();
}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{

}

void OGLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);

    glOrtho(-800, 800, -600, 600, 1, -1);

}
