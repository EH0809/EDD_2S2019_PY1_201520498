//
// Created by edgarh on 20/08/19.
//

#ifndef P1CLASES_LATERAL_H
#define P1CLASES_LATERAL_H

#include "HorizontalList.h"

struct NodeLateral{
    int Lateral;
    NodeLateral *NextLateral;
    NodeLateral *PreviousLateral;
    HorizontalList Fila;

};

class Lateral {
public:
    NodeLateral *FirstLateral=NULL;
    NodeLateral *EndLateral=NULL;
    NodeLateral * Create_Lateral(int Lateral);
    void AddLateral(int NodeLateral);
    void AddLateral2(NodeLateral *& New_Lateral);
    void AddLateralStart(NodeLateral *& New_Lateral);
    void AddLateralBetween(NodeLateral *& New_Lateral);
    void AddLateralInEnd(NodeLateral *& New_Lateral);
    void CoverLaterales();
    bool IsLateral (int Lateral);
    NodeLateral *SearchLateral(int Lateral);
    void PrintLaterales();
    string DotLaterales();

    bool IsEmpty();
};


#endif //P1CLASES_LATERAL_H
