#include "parallelepiped.h"

Parallelepiped::Parallelepiped(float centerx, float centery, float centerz, float width, float height, float length, GLuint textures[6])
{
    float ymin = centery, ymax = centery + height,
            xmin = centerx - width/2, xmax = centerx + width/2,
            zmin = centerz - length/2, zmax = centerz + length/2;

//    const GLuint texture = 1;

    // 0 front
    // 1 back
    // 2 left
    // 3 right
    // 4 up
    // 5 bottom

//    const GLuint textures[6] = {
//        2,
//        1,
//        1,
//        1,
//        1,
//        1
//    };

    SquareBuilder sb;

    // face inferior : 5
    shapes.push_back(sb.set_n_vector(0, xmax, ymin, zmax)->set_color(0,0,0)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmin)->set_n_vector(3,xmin, ymin, zmax)->set_texture(textures[5])->
                     set_normal_vec(0,-1,0)->build());
    sb.reset_builder();
    // face superior : 4
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmax)->set_n_vector(1,xmax, ymax, zmin)->
                     set_n_vector(2,xmin,ymax, zmin)->set_n_vector(3,xmin, ymax, zmax)->set_texture(textures[4])->
                     set_normal_vec(0,1,0)->build());
    sb.reset_builder();
    // face direita : 3
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmin)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmax,ymin, zmax)->set_n_vector(3,xmax, ymax, zmax)->set_texture(textures[3])->
                     set_normal_vec(-1,0,0)->build());
    sb.reset_builder();
    // face esquerda : 2
    shapes.push_back(sb.set_n_vector(0, xmin, ymax, zmin)->set_n_vector(1,xmin, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmax)->set_n_vector(3,xmin, ymax, zmax)->set_texture(textures[2])->
                     set_normal_vec(1,0,0)->build());
    sb.reset_builder();
    // face frontal : 0
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmin)->set_n_vector(1,xmax, ymin, zmin)->
                     set_n_vector(2,xmin,ymin, zmin)->set_n_vector(3,xmin, ymax, zmin)->set_texture(textures[0])->
                     set_normal_vec(0,0,-1)->build());
    sb.reset_builder();
    // face de trás : 1
    shapes.push_back(sb.set_n_vector(0, xmax, ymax, zmax)->set_n_vector(1,xmax, ymin, zmax)->
                     set_n_vector(2,xmin,ymin, zmax)->set_n_vector(3,xmin, ymax, zmax)->set_texture(textures[1])->
                     set_normal_vec(0,0,1)->build());

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
