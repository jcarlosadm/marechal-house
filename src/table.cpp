#include "table.h"
#include "GL/glu.h"

Table::Table()
{
    float h = 1.0f,w = 0.7f, l = 2.0f;
    float adjw = w * 0.10f, adjl = l * 0.10f;

    SquareBuilder sb;
    shapes.push_back(sb.set_n_vector(0,w/2,-2+h,-l/2)->set_n_vector(1,-w/2,-2+h,-l/2)->
                     set_n_vector(2,-w/2,-2+h,l/2)->set_n_vector(3,w/2,-2+h,l/2)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,(w - adjw)/2,-2+h,-(l-adjl)/2)->set_n_vector(1,-(w-adjw)/2,-2,-(l - adjl)/2)->
                     set_n_vector(2,-(w-adjw)/2,-2,(l-adjl)/2)->set_n_vector(3,(w-adjw)/2,-2+h,(l-adjl)/2)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0,(w - adjw)/2,-2,-(l-adjl)/2)->set_n_vector(1,-(w-adjw)/2,-2+h,-(l - adjl)/2)->
                     set_n_vector(2,-(w-adjw)/2,-2+h,(l-adjl)/2)->set_n_vector(3,(w-adjw)/2,-2,(l-adjl)/2)->build());
    shapes.push_back(new Parallelepiped(0.0f,-2.0f+h-0.2f,0.0f,w-adjw,0.2f,l-adjl));
}

Table::~Table()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}

void Table::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3.5f,0.0f,-5.0f);

    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }

    glPopMatrix();
}
