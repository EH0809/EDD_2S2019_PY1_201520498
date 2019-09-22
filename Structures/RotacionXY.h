//
// Created by edgarh on 21/09/19.
//

#ifndef P1_ROTACIONXY_H
#define P1_ROTACIONXY_H

#include "MatrixB.h"
using namespace std;
struct RotacionNodeXY {
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;

    RotacionNodeXY *NextRotacion;
    RotacionNodeXY *PreviousRotacion;
};

class RotacionXY {
public:
    RotacionNodeXY *FirstRotation = NULL;
    RotacionNodeXY *EndRotation = NULL;

    bool IsEmptyP();
    RotacionNodeXY *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONY(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONYStart(RotacionNodeXY *&Node);
    void AddROTACIONYBetween(RotacionNodeXY *&Node);
    void AddROTACIONYInEnd(RotacionNodeXY *&Node);
    void T(int Tama);
    void HTMLY();
    void CCSSY(int WidthC, int HeightC, int WidthP, int HeightP);
    string HtmlRY(string html);
    string CssRY(string css, int WidthC, int HeightC, int WidthP, int HeightP);
    string Rotacion();

};


#endif //P1_ROTACIONXY_H
