#include "oglwidget.h"

#include <QTimer>
#include <shapebuilder.h>

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

    Shape *shape1 = ShapeBuilder::make(ShapeType::CUBE);
    Shape *shape2 = ShapeBuilder::make(ShapeType::CUBE);

    shapes.push_back(shape1);
    shapes.push_back(shape2);

    std::vector<Shape *>::iterator it;

    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }

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
