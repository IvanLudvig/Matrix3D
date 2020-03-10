#ifndef MATRIX3D_MATRIX3D_H
#define MATRIX3D_MATRIX3D_H


class Matrix3D {
protected:
    double data[9];
public:
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);

    Matrix3D(double* d);

    Matrix3D();

    double get(int i, int j) const;

    void set(double value, int i, int j);

    double det() const;

    Matrix3D operator+(const Matrix3D &m1) const;

    Matrix3D operator-(const Matrix3D &m1) const;

    Matrix3D operator*(const Matrix3D &m1) const;

    Matrix3D operator*(const double &scale) const;

};


#endif //MATRIX3D_MATRIX3D_H
