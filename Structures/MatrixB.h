//
// Created by edgarh on 6/09/19.
//

#ifndef P1_MATRIXB_H
#define P1_MATRIXB_H
#include <iostream>
#include <fstream>
using namespace std;
/*
struct NodeMatrixB{
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    NodeMatrixB *RightNodeMatrix;
    NodeMatrixB *LeftNodeMatrix;
    NodeMatrixB *UpNodeMatrix;
    NodeMatrixB *DownNodeMatrix;
};*/
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

    NodeMatrixB2(int Col, int Fil, int ColoR, int ColorG, int ColorB){
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
};

class MatrixB {
public:
//    NodeMatrixB *FirstNode;
    NodeMatrixB2 *HeadNode;
    MatrixB (){
        //NodeMatrixB *Aux = new NodeMatrixB;
        NodeMatrixB2 *Aux = new NodeMatrixB2(0,0,0,0,0);
        HeadNode = Aux;
    }

    /*
    NodeMatrixB *CreateNode(int Col, int Fil, int ColorR, int ColorG , int ColorB);
    void AddMatrix(int Col, int Fil, int ColorR, int ColorG , int ColorB);
    void AddMatrixCabecera(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void AddMatrixHeader(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void CreateCabecera(int Col);
    void CreateHeaders(int Fil);
    void GraficarMatrix();
    string DotMatrix(string dot);
    string DotMatirx2(string Dot);
*/

    //**************************CLASE ***************************//
    void AddMatrixC(int Col, int Fil, int ColorR, int ColorG , int ColorB);
    void AddMatrixCabeceraC(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void AddMatrixHeaderC(int Col, int Fil, int ColorR, int ColorG , int ColorB );
    void CreateCabeceraC(int Col);
    void CreateHeadersC(int Fil);
    void GraficarMatrixC();
    string DotMatrixC(string dot);
    string DotMatirx2C(string Dot);

    
    string DotGrayScape(string Dot);
    string DotNegative(string Dot);
};
#endif //P1_MATRIXB_H
