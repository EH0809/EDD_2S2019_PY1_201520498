//
// Created by edgarh on 1/09/19.
//

#ifndef P1_COMPLETEMATRIX_H
#define P1_COMPLETEMATRIX_H

#include "MatrixB.h"
struct CompleteM{
    int Id;
    MatrixB PunteroMatriz;
    CompleteM *NextComplete;
    CompleteM *PreviousComplete;
};
class CompleteMatrix {
public:

    int Id;
    MatrixB PunteroMatriz;
    void ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void GraficarCompleta();
    void GraphLayer(int ab);
    string GraficarC();
    void UpdateNode(int Col, int Fil, int ColorR, int ColorG, int ColorB);
/*
    CompleteM *FirstMatrixC=NULL;
    CompleteM *EndMatrixC= NULL;
    CompleteM *Create_Matrix(int Id);
    bool IsEmptyP();
    void AddMatrixC(int Id);
    void AddMatrixCStart(CompleteM *& Node);
    void AddMatrixCBetween(CompleteM *& Node);
    void AddMatrixCInEnd(CompleteM *& Node);
    CompleteM *SearchHeader(int Id);
    bool IsMatrixC(int Id);
    void PrintList();
    CompleteM* MandarCompleta(int id);
    */
};


#endif //P1_COMPLETEMATRIX_H
