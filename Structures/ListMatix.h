//
// Created by edgarh on 30/08/19.
//

#ifndef P1_LISTMATIX_H
#define P1_LISTMATIX_H
#include "iostream"
#include "Matrix.h"


using namespace std;
struct MatrixList{
    int Id;
    string Name;
    string Archivo;
    Matrix PunteroMatrix;
    MatrixList *NextMatrix;
    MatrixList *PreviousMatrix;
};
class ListMatix {
public:
    MatrixList *FirstMatrixList;
    MatrixList *EndMatrixList;
    MatrixList *Create_Matrix(int Id, string Name);
    bool IsEmptyP();
    void AddMatrixList(int Id, string Name);
    void AddMatrixListStart(MatrixList *& Node);
    void AddMatrixListBetween(MatrixList *& Node);
    void AddMatrixListInEnd(MatrixList *& Node);
    MatrixList *SearchHeader(int Id);
    bool IsMatrix(int Id);
    void Graph();

    void ADDMatrix();
    void DesEncapar(MatrixList *& Node);
    void PrintList();
    MatrixList* MandarAGraficar(int Id);
    void GraphCapas(int Id);
    void MostarCapas();
    void ConvertRGBaHex();

};


#endif //P1_LISTMATIX_H