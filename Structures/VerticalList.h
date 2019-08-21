//
// Created by edgarh on 20/08/19.
//

#ifndef P1CLASES_VERTICALLIST_H
#define P1CLASES_VERTICALLIST_H

class VerticalList {
public:
    MatrixNode *FirstNodeCentralV;
    MatrixNode *EndNodeCentralV;
    bool IsEmpty();
    void AddLateral(MatrixNode *& Node);
    void AddLateralStart(MatrixNode *& Node);
    void AddLateralBetween(MatrixNode *& Node);
    void AddLateralInEnd(MatrixNode *& Node);
    void GoVerticalList();

};


#endif //P1CLASES_VERTICALLIST_H
