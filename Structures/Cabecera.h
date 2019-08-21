//
// Created by edgarh on 20/08/19.
//

#ifndef P1CLASES_CABECERA_H
#define P1CLASES_CABECERA_H
#include <iostream>
#include "string"
#include "VerticalList.h"

using namespace std;

struct NodeHeader{
    int Header;
    NodeHeader *NextHeader;
    NodeHeader *PreviousHeader;
    VerticalList Colum ;

};
class Cabecera {
public:
    NodeHeader *FirstHeader= NULL;
    NodeHeader *EndHeader= NULL;
    bool IsEmpty();
    NodeHeader * New_Header(int Header);
    void InsertHeader(int Header);
    void InsertHeader2(NodeHeader *Header);
    void InsertHeaderStart(NodeHeader *Header);
    void InsertHeaderBetween(NodeHeader *Header);
    void InsertHeaderInEnd(NodeHeader *Header);
    void CoverHeader();
    NodeHeader * SearchHeader(int Header);
    bool IsHeader(int Header);
    void PrintHeader();
    string DotHeader();
};


#endif //P1CLASES_CABECERA_H
