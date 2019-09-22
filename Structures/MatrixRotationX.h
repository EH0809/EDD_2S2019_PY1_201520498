//
// Created by edgarh on 17/09/19.
//

#ifndef P1_MATRIXROTATIONX_H
#define P1_MATRIXROTATIONX_H

#include "iostream"
using namespace std;

class NodeRotateX{
public:
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    NodeRotateX *RightNodeMatrix;
    NodeRotateX *LeftNodeMatrix;
    NodeRotateX *UpNodeMatrix;
    NodeRotateX *DownNodeMatrix;

    NodeRotateX(int Col, int Fil, int ColoR, int ColorG, int ColorB) {
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
class MatrixRotationX {
public:
    NodeRotateX *HeadNode;
    MatrixRotationX (){
        NodeRotateX *Aux = new NodeRotateX(0,0,0,0,0);
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

    void GraficarCompleta();
    string DotGrayScape(string Dot);
    string DotNegative(string Dot);
};


#endif //P1_MATRIXROTATIONX_H
