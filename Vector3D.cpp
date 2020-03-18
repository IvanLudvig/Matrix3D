#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
}

double Vector3D::getX() const
{
    return x;
}

double Vector3D::getY() const
{
    return y;
}

double Vector3D::getZ() const
{
    return z;
}

double Vector3D::get(int i) const
{
    switch (i)
    {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
    }
    return -1;
}

void Vector3D::setX(double x)
{
    this->x = x;
}

void Vector3D::setY(double y)
{
    this->y = y;
}

void Vector3D::setZ(double z)
{
    this->z = z;
}

void Vector3D::set(double value, int i)
{
    switch (i)
    {
        case 0:
            x = value;
        case 1:
            y = value;
        case 2:
            z = value;
    }
}

Vector3D Vector3D::operator+(const Vector3D &v1) const
{
    return Vector3D(v1.x + x, v1.y + y, v1.z + z);
}

Vector3D Vector3D::operator-(const Vector3D &v1) const
{
    return Vector3D(x - v1.x, y - v1.y, z - v1.z);
}

double Vector3D::operator*(const Vector3D &v1) const
{
    return v1.x * x + v1.y * y + v1.z * z;
}

Vector3D Vector3D::operator*(const double &scale) const
{
    return Vector3D(scale * x, scale * y, scale * z);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &v)
{
    os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector3D &v)
{
    double x, y, z;
    is >> x >> y >> z;
    v = Vector3D(x, y, z);
    return is;
}

Vector3D operator*(const Matrix3D &m, const Vector3D &v)
{
    Vector3D res;
    for (int i = 0; i < 3; i++)
    {
        double temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp += m.get(i, j) * v.get(j);
        }
        res.set(temp, i);
    }
    return res;
}

Vector3D operator*(const double &scale, const Vector3D &v)
{
    return v * scale;
}
