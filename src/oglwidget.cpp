#include "oglwidget.h"
#include "house.h"
#include "painting.h"
#include "bust.h"
#include "table.h"
#include "locker.h"
#include "bed.h"
#include "door.h"
#include "texture.h"

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
    shapes.push_back(new Locker());
    shapes.push_back(new Bed());
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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    Texture::loadTexture("parede.jpg", 0);
    Texture::loadTexture("wood.jpg", 1);
    Texture::loadTexture("armario.jpg", 2);
    Texture::loadTexture("whitebed.jpeg", 3);
    Texture::loadTexture("front_house.jpg", 4);
    Texture::loadTexture("blackwood.png", 5);
    Texture::loadTexture("wall_default.jpg", 6);
    Texture::loadTexture("piso.png", 7);
    Texture::loadTexture("escada.jpg", 8);
    Texture::loadTexture("bust.png", 9);
    Texture::loadTexture("head_2.jpg", 10);
    Texture::loadTexture("quadro.jpg", 11);
    Texture::loadTexture("porta.png", 12);
    Texture::loadTexture("telhado.jpg", 13);
    Texture::loadTexture("left.jpg", 14);
    Texture::loadTexture("top.png", 15);
    Texture::loadTexture("right.jpg", 16);
    Texture::loadTexture("orange.png", 17);
    Texture::loadTexture("inner_left.png", 18);
    Texture::loadTexture("inner_right.png", 19);
}

void OGLWidget::defineLighting()
{
    // http://www.inf.pucrs.br/~manssour/CG/p-Iluminacao/

    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={1.0,1.0,1.0,1.0}; // "cor"
    GLfloat luzEspecular[4]={2.0, 2.0, 2.0, 2.0};// "brilho"
    GLfloat posicaoLuz[4]={0.0, 0.0, -2.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 40;

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    defineLighting();

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

        case(Qt::Key_Space):
            Door::open_close();
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

    defineLighting();

    glViewport(0, 0, w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    gluPerspective(60.0, ratio, 1.0, 30.0);

}
