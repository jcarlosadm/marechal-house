#include <iostream>
#include <GL/glut.h>
#include <house.h>

#include "floor.h"

House::House()
{
    FloorBuilder fb;
    // first floor
    shapes.push_back(fb.set_parameters(0.0f,0.0f,-2.0f,10.0f,15.0f)->set_color(1.0f,0.0f,0.0f)->build());
    fb.reset_builder();
    // second floor
    shapes.push_back(fb.set_parameters(0.0f,4.0f,2.0f,10.0f,8.0f)->set_color(1.0f,1.0f,0.0f)->build());
}

void House::draw()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }
}

House::~House() {
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}
