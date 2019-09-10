//
// Created by edgarh on 30/08/19.
//

#ifndef P1_LISTMATIX_H
#define P1_LISTMATIX_H
#include "iostream"
#include "Matrix.h"
#include "CompleteMatrix.h"
#include "MatrixB.h"
#include "LinearizeMatrix.h"

using namespace std;
struct MatrixList{
    int Id;
    string Name;
    string Archivo;
    LinearizeMatrix Linear;
    MatrixB PunteroMatrixB;
    MatrixList *NextMatrix;
    MatrixList *PreviousMatrix;
};
class ListMatix {
public:
    MatrixList *FirstMatrixList=NULL;
    MatrixList *EndMatrixList= NULL;
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
    void MandarCompleta(int id);
    void GraficarMatizCompleta();
    void AgregarMatrixCompleta();

    void GraficarLFilas();
    void MandarHtml();
    void MandarCSS(int WidthC, int HeightC, int WidthP, int HeightP);
    void MandarTamanio(int WidthM, int HeightM);

    //*****************Mandar GRAYSCALE ******//////////
    void MandarHtmGRAYSCALEl();
    void MandarCSSGRAYSCALE(int WidthC, int HeightC, int WidthP, int HeightP);
    //******************MANDAR NEGATIVE *********////////
    void MandarHtmlNEGATIVE();
    void MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP);

    //***********************MANDAR POR CAPAS *****///////////
    void GrayscapeCapas(int Id);
    void NegativeCapas(int Id);


};


#endif //P1_LISTMATIX_H
