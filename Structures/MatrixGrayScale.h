//
// Created by edgarh on 14/09/19.
//

#ifndef P1_MATRIXGRAYSCALE_H
#define P1_MATRIXGRAYSCALE_H
#include "MatrixB.h"
#include "iostream"
using namespace std;

class MatrixGrayScale {
public:
    int Id;
    MatrixB PunteroMatriz;
    void ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void GraficarCompleta();
    string GraficarC();
    void UpdateMatrixGrayScale(int Col, int Fil , int ColorR, int ColorG, int ColorB);
};


#endif //P1_MATRIXGRAYSCALE_H
