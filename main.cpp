#include <iostream>
#include "Vector3D.h"
#include "Matrix3D.h"

using namespace std;

std::ostream &operator<<(std::ostream &os, const Vector3D &v) {
    os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector3D &v) {
    double x, y, z;
    is >> x >> y >> z;
    v = Vector3D(x, y, z);
    return is;
}

Vector3D operator*(const double &scale, const Vector3D &v) {
    return v*scale;
}

std::ostream &operator<<(std::ostream &os, const Matrix3D &m) {
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<m.get(i, j)<<", ";
        }
        cout<<endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix3D &m) {
    double* data = new double[9];
    for(int i = 0; i<9; i++)
    {
        is>>data[i];
    }
    m = Matrix3D(data);
    return is;
}

Matrix3D operator*(const double &scale, const Matrix3D &m) {
    return m*scale;
}

Vector3D operator*(const Matrix3D &m, const Vector3D &v) {
    Vector3D res;
    for (int i = 0; i < 3; i++) {
        double temp = 0;
        for (int j = 0; j < 3; j++) {
            temp+=m.get(i, j)*v.get(j);
        }
        res.set(temp, i);
    }
    return res;
}

int main() {
    Vector3D A(1, 2, 3);
    Vector3D B;
    cin >> B;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    Matrix3D D;
    cin >> D;

    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    cout << "det(D) = " << D.det() << endl;

    cout << "D * B = " << D * B << endl;
    return 0;
}
