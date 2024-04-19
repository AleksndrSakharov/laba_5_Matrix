#include "Vector.h"
#include "Matrix.h"

int main(){
    double arr1[5] = {1, 2, 3, 4, 5};
    double arr2[5] = {2, 6, 1, 2, 5};
    double arr3[5] = {8, 3, -4, 0, 5};
    double arr4[5] = {3, 2, 61, -82, -3};
    double arr5[1] = {1};
    double arr6[1] = {0};
    double arr7[1] = {4};
    double arr8[1] = {-2};
    double arr9[1] = {5};
    double arr10[4] = {1, 2, 3, 5};
    double arr11[4] = {8, 2, 3, 4};
    double arr12[4] = {1, 8, 3, 4};
    double arr13[4] = {1, 2, 3, 4};
    double arr14[3] = {1, 2, 3};
    double arr15[3] = {1, 2, 3};
    double arr16[3] = {1, 2, 3};

    Vector<double> vector3 = Vector<double>(5, arr3);
    Vector<double> vector4 = Vector<double>(5, arr4);
    Vector<double> vector1 = Vector<double>(5, arr1);
    Vector<double> vector2 = Vector<double>(5, arr2);
    Vector<double> vector5 = Vector<double>(1, arr5);
    Vector<double> vector6 = Vector<double>(1, arr6);
    Vector<double> vector7 = Vector<double>(1, arr7);
    Vector<double> vector8 = Vector<double>(1, arr8);
    Vector<double> vector9 = Vector<double>(1, arr9);
    Vector<double> vector10 = Vector<double>(4, arr10);
    Vector<double> vector11 = Vector<double>(4, arr11);
    Vector<double> vector12 = Vector<double>(4, arr12);
    Vector<double> vector13 = Vector<double>(4, arr13);



    Vector<double>* a1 = new Vector<double>[2];
    a1[0] = vector1;
    a1[1] = vector2;
    Vector<double>* a2 = new Vector<double>[2];
    a2[0] = vector3;
    a2[1] = vector4;
    Vector<double>* a3 = new Vector<double>[5];
    a3[0] = vector5;
    a3[1] = vector6;
    a3[2] = vector7;
    a3[3] = vector8;
    a3[4] = vector9;
    Vector<double>* a4 = new Vector<double>[4];
    a4[0] = vector10;
    a4[1] = vector11;
    a4[2] = vector12;
    a4[3] = vector13;
    Matrix<double> m1 = Matrix<double>(2, 5, a1);
    Matrix<double> m2 = Matrix<double>(2, 5,a2);
    Matrix<double> m3 = Matrix<double>(5, 1,a3);
    Matrix<double> m4 = Matrix<double>(4, 4,a4);
    Matrix<double> m5 = Matrix<double>(4);
    try {
//        std::cout << m3 << std::endl << m3.Transposition() << std::endl << std::endl;
//        std::cout << m1 - m2 << std::endl;
//        std::cout << m1 + m2 << std::endl;
//        std::cout << m1 << m3 << m1 * m3 << std::endl;
//        std::cout << m3 << std::endl << m3.Transposition() << std::endl;
        // std::cout  << m4.determinant();
        m5 = m4.Inverse();
        std::cout << m4 << m5
        << "|m4| = " << m4.determinant() << ", |m5| = " << m5.determinant() << std::endl << "|m4|+|m5| = "
        << m4.determinant() + m5.determinant() << std::endl
        << "|m4 + m5| = " << (m4 + m5).determinant() << std::endl
        << m5 - m4 << m5 + m4 << m5.Transposition() << m5.Transposition() * m4;
    }
    catch (const char* e){
        std::cerr << e << std::endl;
    }

    // Matrix<double> mat = Matrix<double>();
    // std::cout << mat;

    delete [] a1;
    delete [] a2;
    delete [] a3;
    delete [] a4;
    return 0;
}