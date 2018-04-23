#ifndef SQUARE_H
#define SQUARE_H

class Square
{
    friend class SquareBuilder;
private:
    Square(){}
public:
    void draw();
private:
    float colors[3] = {1.0f,0.0f,0.0f};
    float vectors[4][3] =
    {
        {0.0f,0.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {1.0f,1.0f,0.0f},
        {0.0f,1.0f,0.0f}
    };
};

class SquareBuilder
{
public:
    SquareBuilder();
    ~SquareBuilder();
    /**
     * @brief add_n_vector
     * @param n number of vector, starting in 0
     * @param x
     * @param y
     * @param z
     * @return SquareBuilder instance
     */
    SquareBuilder* set_n_vector(int n, float x, float y, float z);
    SquareBuilder* set_color(float red, float green, float blue);
    Square * build();
private:
    Square * square = nullptr;
};

#endif // SQUARE_H
