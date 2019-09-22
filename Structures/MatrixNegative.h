//
// Created by edgarh on 14/09/19.
//

#ifndef P1_MATRIXNEGATIVE_H
#define P1_MATRIXNEGATIVE_H


#include "MatrixB.h"
#include "iostream"
using namespace std;

class MatrixNegative {
public:
    int Id;
    MatrixB PunteroMatriz;
    void ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void GraficarCompleta();
    string GraficarC();
};


#endif //P1_MATRIXNEGATIVE_H
