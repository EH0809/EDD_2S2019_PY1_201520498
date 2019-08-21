//
// Created by edgarh on 20/08/19.
//

#ifndef P1CLASES_HORIZONTALLIST_H
#define P1CLASES_HORIZONTALLIST_H


#include "NodeMatrix.h"

class HorizontalList {
public:
    MatrixNode *FirstNodeCentralH;
    MatrixNode *EndNodeCentralH;
    bool IsEmpty();
    void AddHorizontal(MatrixNode *& Node);
    void AddHorizontalStart(MatrixNode *& Node);
    void AddHorizontalBetween(MatrixNode *& Node);
    void AddHorizontalInEnd(MatrixNode *& Node);
    void GoHorizontalList();
};


#endif //P1CLASES_HORIZONTALLIST_H
