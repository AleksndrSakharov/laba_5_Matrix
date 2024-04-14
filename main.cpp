#include "Vector.h"
#include "Matrix.h"

int main(){
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {2, 6, 1, 2, 5};
    int arr3[5] = {8, 3, -4, 0, 5};
    int arr4[5] = {3, 2, 61, -82, -3};
    int arr5[1] = {1};
    int arr6[1] = {0};
    int arr7[1] = {4};
    int arr8[1] = {-2};
    int arr9[1] = {5};
    int arr10[4] = {1, 2, 3, 4};
    int arr11[4] = {1, 2, 3, 4};
    int arr12[4] = {1, 2, 3, 4};
    int arr13[4] = {1, 2, 3, 4};

    Vector<int> vector3 = Vector<int>(5, arr3);
    Vector<int> vector4 = Vector<int>(5, arr4);
    Vector<int> vector1 = Vector<int>(5, arr1);
    Vector<int> vector2 = Vector<int>(5, arr2);
    Vector<int> vector5 = Vector<int>(1, arr5);
    Vector<int> vector6 = Vector<int>(1, arr6);
    Vector<int> vector7 = Vector<int>(1, arr7);
    Vector<int> vector8 = Vector<int>(1, arr8);
    Vector<int> vector9 = Vector<int>(1, arr9);
    Vector<int> vector10 = Vector<int>(4, arr10);
    Vector<int> vector11 = Vector<int>(4, arr11);
    Vector<int> vector12 = Vector<int>(4, arr12);
    Vector<int> vector13 = Vector<int>(4, arr13);



    Vector<int>* a1 = new Vector<int>[2];
    a1[0] = vector1;
    a1[1] = vector2;
    Vector<int>* a2 = new Vector<int>[2];
    a2[0] = vector3;
    a2[1] = vector4;
    Vector<int>* a3 = new Vector<int>[5];
    a3[0] = vector5;
    a3[1] = vector6;
    a3[2] = vector7;
    a3[3] = vector8;
    a3[4] = vector9;
    Vector<int>* a4 = new Vector<int>[4];
    a4[0] = vector10;
    a4[1] = vector11;
    a4[2] = vector12;
    a4[3] = vector13;
    Matrix<int> m1 = Matrix<int>(2, 5, a1);
    Matrix<int> m2 = Matrix<int>(2, 5,a2);
    Matrix<int> m3 = Matrix<int>(5, 1,a3);
    Matrix<int> m4 = Matrix<int>(4, 4,a4);
    try {
//        std::cout << m3 << std::endl << m3.Transposition() << std::endl << std::endl;
//        std::cout << m1 - m2 << std::endl;
//        std::cout << m1 + m2 << std::endl;
//        std::cout << m1 << m3 << m1 * m3 << std::endl;
//        std::cout << m3 << std::endl << m3.Transposition() << std::endl;
        std::cout << m4.determinantNxN();
    }
    catch (const char* e){
        std::cerr << e << std::endl;
    }

    // Matrix<int> mat = Matrix<int>();
    // std::cout << mat;

    delete [] a1;
    delete [] a2;
    return 0;
}