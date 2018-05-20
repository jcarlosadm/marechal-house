#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <QMouseEvent>
#include <QKeyEvent>
#include <list>
#include <vector>
#include <shape.h>
#include <math.h>

class OGLWidget : public QOpenGLWidget
{

public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    std::vector<Shape *> shapes;

    static int _width;
    static int _height;

};

#endif // OGLWIDGET_H
