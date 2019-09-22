//
// Created by edgarh on 14/09/19.
//

#ifndef P1_MATRIXROTATIONY_H
#define P1_MATRIXROTATIONY_H
#include "iostream"
using namespace std;

class NodeRotateY{
public:
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    NodeRotateY *RightNodeMatrix;
    NodeRotateY *LeftNodeMatrix;
    NodeRotateY *UpNodeMatrix;
    NodeRotateY *DownNodeMatrix;

    NodeRotateY(int Col, int Fil, int ColoR, int ColorG, int ColorB) {
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
class MatrixRotationY {
public:
    NodeRotateY *HeadNode;
    MatrixRotationY (){
        NodeRotateY *Aux = new NodeRotateY(0,0,0,0,0);
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


#endif //P1_MATRIXROTATIONY_H
