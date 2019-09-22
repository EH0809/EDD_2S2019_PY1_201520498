//
// Created by edgarh on 27/08/19.
//

#ifndef P1_LISTFILTERS_H
#define P1_LISTFILTERS_H
#include "string"
#include "iostream"
#include "Grayscale.h"
#include "Negative.h"
#include "RotacionX.h"
#include "RotacionY.h"

using namespace std;
struct NodeFilter{
    string Name;
    string User;
    GrayNode GNode;
    Negative GNegative;
    RotacionY GRotationY;
    RotacionX GRotationX;
    NodeFilter *NextFilter;
    NodeFilter *PreviousFilter;
};

class ListFilters {
public:
    NodeFilter *CreateNode(string Name);
    void InsertNodeFilter(string Name);
    void PrintFilters();
    void GraphList();
    string Dot(string Dot);
    bool IsEmpety();
};


#endif //P1_LISTFILTERS_H
