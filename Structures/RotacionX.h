//
// Created by edgarh on 13/09/19.
//

#ifndef P1_ROTACIONX_H
#define P1_ROTACIONX_H

#include "iostream"
using namespace std;

struct RotacionNodeX {
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;

    RotacionNodeX *NextRotacion;
    RotacionNodeX *PreviousRotacion;
};
class RotacionX {
public:
    RotacionNodeX *FirstRotation = NULL;
    RotacionNodeX *EndRotation = NULL;

    bool IsEmptyP();
    RotacionNodeX *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONX(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONXStart(RotacionNodeX *&Node);
    void AddROTACIONXBetween(RotacionNodeX *&Node);
    void AddROTACIONXInEnd(RotacionNodeX *&Node);
    string Rotacion();
};


#endif //P1_ROTACIONX_H
