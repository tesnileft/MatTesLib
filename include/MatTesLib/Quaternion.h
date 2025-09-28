#ifndef QUATERNION_H
#define QUATERNION_H
#include <vector>


class Quaternion {
    float a,b,c,d;

public:
    Quaternion();
    Quaternion(float a[3]);
    Quaternion(float x, float y, float z);
};



#endif //QUATERNION_H
