#include "parallelepiped.h"

Parallelepiped::Parallelepiped(float width, float height, float length)
{
    float ymin = 0.0f, ymax=height;
    float xmin = -width/2, xmax = width/2;
    float zmin = -length/2, zmax = length/2;
    SquareBuilder sb;
    shapes.push_back(sb.set_n_vector(0, xmax, ymin, zmax)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmin)->set_n_vector(3,xmin, ymin, zmax)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmax)->set_n_vector(1,xmax, ymax, zmin)->
                     set_n_vector(2,xmin,ymax, zmin)->set_n_vector(3,xmin, ymax, zmax)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmin)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmax,ymin, zmax)->set_n_vector(3,xmax, ymax, zmax)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0, xmin, ymax, zmin)->set_n_vector(1,xmin, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmax)->set_n_vector(3,xmin, ymax, zmax)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmin)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmin)->set_n_vector(3,xmin, ymax, zmin)->build());
    sb.reset_builder();
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmax)->set_n_vector(1,xmax, ymin, zmax)->
                     set_n_vector(2,xmin,ymin, zmax)->set_n_vector(3,xmin, ymax, zmax)->build());

}

Parallelepiped::~Parallelepiped()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it)
        delete (*it);

    shapes.clear();
}

void Parallelepiped::draw()
{
    std::vector<Shape *>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); ++it) {
        Shape *shape = *it;

        if (shape != nullptr)
            shape->draw();
    }
}
