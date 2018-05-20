#include <iostream>
#include <GL/glut.h>
#include <house.h>

#include "floor.h"
#include "wall.h"
#include "door.h"
#include "stairs.h"

House::House()
{
    // floors
    FloorBuilder fb;
    // first floor
    shapes.push_back(fb.set_parameters(0.0f,0.0f,-2.0f,10.0f,15.0f)->build());
    fb.reset_builder();
    // second floor
    shapes.push_back(fb.set_parameters(3.2f,3.75f,2.0f,3.6f,7.5f)->build());
    fb.reset_builder();
    shapes.push_back(fb.set_parameters(0.7f,4.5f,2.0f,1.4f,6.0f)->build());
    fb.reset_builder();
    shapes.push_back(fb.set_parameters(-2.5f,3.75f,2.0f,5.0f,7.5f)->build());
    fb.reset_builder();

    // roof
    shapes.push_back(fb.set_parameters(0.0f,0.0f,5.0f,10.0f,15.5f)->set_color(0.0f, 0.0f, 0.0f)->build());

    // walls
    WallBuilder wb;

    // right wall
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(-5.0f,-7.5f)->set_second_point(-5.0f,7.5f)->build());
    wb.reset_builder();

    // left wall
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(5.0f,-7.5f)->set_second_point(5.0f,7.5f)->build());
    wb.reset_builder();

    // back wall
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(5.0f,7.5f)->set_second_point(4.2f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(4.2f,7.5f)->set_second_point(3.2f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(4.2f,7.5f)->set_second_point(3.2f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(3.2f,7.5f)->set_second_point(2.4f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(2.4f,7.5f)->set_second_point(1.4f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(2.4f,7.5f)->set_second_point(1.4f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(1.4f,7.5f)->set_second_point(0.6f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(0.6f,7.5f)->set_second_point(-0.6f,7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(-0.6f,7.5f)->set_second_point(-5.0f,7.5f)->build());
    wb.reset_builder();

    // front wall
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(5.0f,-7.5f)->set_second_point(4.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(4.2f,-7.5f)->set_second_point(3.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(4.2f,-7.5f)->set_second_point(3.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(3.2f,-7.5f)->set_second_point(2.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(2.4f,-7.5f)->set_second_point(1.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(2.4f,-7.5f)->set_second_point(1.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(1.4f,-7.5f)->set_second_point(0.6f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(0.6f,-7.5f)->set_second_point(-0.6f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(-0.6f,-7.5f)->set_second_point(-1.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(-1.4,-7.5f)->set_second_point(-2.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(-1.4f,-7.5f)->set_second_point(-2.4f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(-2.4f,-7.5f)->set_second_point(-3.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,-0.5f)->set_first_point(-3.2f,-7.5f)->set_second_point(-4.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(1.0f,5.0f)->set_first_point(-3.2f,-7.5f)->set_second_point(-4.2f,-7.5f)->build());
    wb.reset_builder();
    shapes.push_back(wb.set_height(-2.0f,5.0f)->set_first_point(-4.2f,-7.5f)->set_second_point(-5.0f,-7.5f)->build());
    wb.reset_builder();

    // first wall inside the house
    shapes.push_back(wb.set_height(-2.0f,2.0f)->set_first_point(1.4f,-0.6f)->set_second_point(1.4f,-6.0f)->build());
    wb.reset_builder();

    // second wall inside the house
    shapes.push_back(wb.set_height(-2.0f,2.0f)->set_first_point(-1.4f,4.0f)->set_second_point(-1.4f,0.0f)->build());

    // Doors
    DoorBuilder db;

    // front door
    shapes.push_back(db.set_height(-2.0f,1.0f)->set_first_point(0.6f,-7.5f)->set_second_point(-0.6f,-7.5f)->build());
    // stairs
    shapes.push_back(new Stairs());

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
