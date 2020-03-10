#include "Matrix3D.h"

Matrix3D::Matrix3D(double a0, double a1, double a2,
                   double a3, double a4, double a5,
                   double a6, double a7, double a8) {
    data[0] = a0;
    data[1] = a1;
    data[2] = a2;
    data[3] = a3;
    data[4] = a4;
    data[5] = a5;
    data[6] = a6;
    data[7] = a7;
    data[8] = a8;
}

Matrix3D::Matrix3D(double* data) {
    for (int i = 0; i < 9; i++) {
        this->data[i] = data[i];
    }
    delete[] data;
}

Matrix3D::Matrix3D() {
    for (int i = 0; i < 9; i++) {
        data[i] = 0;
    }
}

double Matrix3D::get(int i, int j) const {
    if ((i < 0) || (j < 0) || (i > 2) || (j > 2)) {
        return -1;
    }
    return data[(i * 3) + j];
}

void Matrix3D::set(double value, int i, int j) {
    data[(i * 3) + j] = value;
}

double Matrix3D::det() const {
    return data[0] * (data[4] * data[8] - data[5] * data[7])
           - data[1] * (data[3] * data[8] - data[5] * data[6])
           + data[2] * (data[3] * data[7] - data[4] * data[6]);
}

Matrix3D Matrix3D::operator+(const Matrix3D &m1) const {
    double* res = new double[9];
    for (int i = 0; i < 9; i++) {
        res[i] = data[i] + m1.data[i];
    }
    return Matrix3D(res);
}

Matrix3D Matrix3D::operator-(const Matrix3D &m1) const {
    return Matrix3D(m1 * (-1.0) + *this);
}

Matrix3D Matrix3D::operator*(const double &scale) const {
    double* res = new double[9];
    for (int i = 0; i < 9; i++) {
        res[i] = scale * data[i];
    }
    return Matrix3D(res);
}

Matrix3D Matrix3D::operator*(const Matrix3D &m1) const {
    double* res = new double[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[(i * 3) + j] = 0;
            for (int k = 0; k < 3; k++) {
                res[(i * 3) + j] += get(i, k) * m1.get(k, j);
            }
        }
    }
    return Matrix3D(res);
}







