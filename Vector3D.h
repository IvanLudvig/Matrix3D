#ifndef MATRIX3D_VECTOR3D_H
#define MATRIX3D_VECTOR3D_H

#include "Matrix3D.h"

class Vector3D
{
private:
    double x, y, z;
public:
    Vector3D(double x, double y, double z);

    Vector3D();

    double getX() const;

    double getY() const;

    double getZ() const;

    double get(int i) const;

    void setX(double x);

    void setY(double z);

    void setZ(double y);

    void set(double value, int i);

    Vector3D operator+(const Vector3D &v1) const;

    Vector3D operator-(const Vector3D &v1) const;

    double operator*(const Vector3D &v1) const;

    Vector3D operator*(const double &scale) const;

};

std::ostream &operator<<(std::ostream &os, const Vector3D &v);

Vector3D operator*(const Matrix3D &m, const Vector3D &v);

std::istream &operator>>(std::istream &is, Vector3D &v);

Vector3D operator*(const double &scale, const Vector3D &v);


#endif //MATRIX3D_VECTOR3D_H
