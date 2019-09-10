//
// Created by edgarh on 22/08/19.
//

#ifndef P1_MATRIX_H
#define P1_MATRIX_H

#include "string"
using namespace std;
struct MatrixNode{
    int RowMatrix;
    int ColMatrix;
    int ColorR;
    int ColorG;
    int ColorB;
    int Total;
    MatrixNode *UpMatrix;
    MatrixNode *DownMatrix;
    MatrixNode *RightMatrix;
    MatrixNode *LeftMatrix;
};

class VerticalList {
public:
    MatrixNode *FirstNodeCentralV=NULL;
    MatrixNode *EndNodeCentralV=NULL;
    bool IsEmpty();
    void AddLateral(MatrixNode *& Node);
    void AddLateralStart(MatrixNode *& Node);
    void AddLateralBetween(MatrixNode *& Node);
    void AddLateralInEnd(MatrixNode *& Node);
    void GoVerticalList();

};

struct NodeHeader{
    int Header;
    NodeHeader *NextHeader;
    NodeHeader *PreviousHeader;
    VerticalList Colum ;
};

class HorizontalList {
public:
    MatrixNode *FirstNodeCentralH=NULL;
    MatrixNode *EndNodeCentralH=NULL;
    bool IsEmpty();
    void AddHorizontal(MatrixNode *& Node);
    void AddHorizontalStart(MatrixNode *& Node);
    void AddHorizontalBetween(MatrixNode *& Node);
    void AddHorizontalInEnd(MatrixNode *& Node);
    void GoHorizontalList();
};

struct NodeLateral{
    int Lateral;
    NodeLateral *NextLateral;
    NodeLateral *PreviousLateral;
    HorizontalList Fila;

};


class Matrix {
public:

    //**********************CABECERA**********************************//
    NodeHeader *FirstHeader= NULL;
    NodeHeader *EndHeader= NULL;
    bool IsEmptyCabecera();
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

    //**************************LATERAL*************************************//

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
    bool IsEmptyLateral();

    //*********************NODO CENTRAL************************************//


    MatrixNode *Create_NodeMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB);
    //void ADDMatrix(int layer_number,int Header, int Lateral, int ColorR, int ColorG, int ColorB);
    void InsertMatrix(int Header, int Lateral,int ColorR, int ColorG, int ColorB);
    int Max_Headers();
    int Max_Laterales();
    //void FillInMatrix(string Ruta);
    MatrixNode *IsNode(int Header, int Lateral);
    MatrixNode *IsCoordinate(int Header, int Lateral);
    void Graph();
    string Dot(string dot);
    string Dot2(string dot);
    string Dot3(string dot);
    string TotalRGBaHexa(MatrixNode *& Temp);
    //******************************************************/////////////////////
};


#endif //P1_MATRIX_H
