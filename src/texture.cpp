#include "texture.h"

sf::Image Texture::image;
GLuint Texture::textures[20];

bool Texture::loadImage(string name) {
    string path = "/home/moabson/projetos/marechal-house/images/" + name;

    cout << path << endl;

    if ( !image.loadFromFile(path) ) {
        return false;
    }

    return true;
}


bool Texture::loadTexture(string name, GLuint index) {
    if (loadImage(name)) {
        glGenTextures(1, &Texture::textures[index]);
        glBindTexture(GL_TEXTURE_2D, Texture::textures[index]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(
                        GL_TEXTURE_2D,
                        0,
                        GL_RGBA,
                        Texture::image.getSize().x,
                        Texture::image.getSize().y,
                        0,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE,
                        Texture::image.getPixelsPtr()
                     );
        glBindTexture(GL_TEXTURE_2D, 0);
        return true;
    }

    return false;
}
