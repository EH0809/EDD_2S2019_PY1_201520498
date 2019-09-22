//
// Created by edgarh on 6/09/19.
//

#ifndef P1_MATRIXB_H
#define P1_MATRIXB_H
#include <iostream>
#include <fstream>
using namespace std;
class NodeMatrixB2{
public:
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    NodeMatrixB2 *RightNodeMatrix;
    NodeMatrixB2 *LeftNodeMatrix;
    NodeMatrixB2 *UpNodeMatrix;
    NodeMatrixB2 *DownNodeMatrix;

    NodeMatrixB2(int Col, int Fil, int ColoR, int ColorG, int ColorB) {
        this->Col = Col;
        this->Fil = Fil;
        this->ColorR = ColoR;
        this->ColorG = ColorG;
        this->ColorB = ColorB;
        this->RightNodeMatrix = NULL;
        this->LeftNodeMatrix = NULL;
        this->UpNodeMatrix = NULL;
        this->DownNodeMatrix = NULL;
    }
    int print(){

    }
};

class MatrixB {
public:
    NodeMatrixB2 *HeadNode;
    MatrixB (){
        NodeMatrixB2 *Aux = new NodeMatrixB2(0,0,0,0,0);
        HeadNode = Aux;
    }
    //**************************CLASE ***************************//
    void AddMatrixC(int Col, int Fil, int ColorR, int ColorG , int ColorB);
    void AddMatrixCabeceraC(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void AddMatrixHeaderC(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void CreateCabeceraC(int Col);
    void CreateHeadersC(int Fil);
    void GraficarMatrixC();
    string DotMatrixC(string dot);
    string DotMatirx2C(string Dot);
    string DotCompleta();

    void Graficar();

    string DotGrayScape(string Dot);
    string DotNegative(string Dot);

    void EditNodeMatrix(int Col, int Fil , int ColorR, int ColorG, int ColorB);
};
#endif //P1_MATRIXB_H
