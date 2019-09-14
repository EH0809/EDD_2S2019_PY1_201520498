//
// Created by edgarh on 11/09/19.
//

#ifndef P1_ROTACIONY_H
#define P1_ROTACIONY_H

#include "MatrixB.h"

using namespace std;
struct RotacionNodeY {
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;

    RotacionNodeY *NextRotacion;
    RotacionNodeY *PreviousRotacion;
};

class RotacionY {
public:
    RotacionNodeY *FirstRotation = NULL;
    RotacionNodeY *EndRotation = NULL;

    bool IsEmptyP();
    RotacionNodeY *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONY(int Pixel, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa);
    void AddROTACIONYStart(RotacionNodeY *&Node);
    void AddROTACIONYBetween(RotacionNodeY *&Node);
    void AddROTACIONYInEnd(RotacionNodeY *&Node);
    void T(int Tama);
    void HTMLY();
    void CCSSY(int WidthC, int HeightC, int WidthP, int HeightP);
    string HtmlRY(string html);
    string CssRY(string css, int WidthC, int HeightC, int WidthP, int HeightP);
    string Rotacion();

};


#endif //P1_ROTACIONY_H
