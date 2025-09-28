#include <assert.h>
#include <iostream>

#include "../include/MatTesLib/Matrix.h"
#include "../src/Matrix.cpp"

int main()
{
    std::cout << "Identity:" << std::endl;
    Matrix::mat4 id = Matrix::Identity();
    std::cout << id.ToString() << std::endl;

    std::cout << "Scaling by 1 2 3:" << std::endl;
    Matrix::mat4 scale = Matrix::Scale(1,2,3);
    std::cout << scale.ToString() << std::endl;

    std::cout << "Translation by 10, -5, 3.45" << std::endl;
    Matrix::mat4 translation = Matrix::Translation(10, -5, 3.45);
    std::cout << translation.ToString() << std::endl;


    return 0;
}
