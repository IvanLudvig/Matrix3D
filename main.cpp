#include <iostream>
#include "Vector3D.h"

using namespace std;

int main()
{
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
