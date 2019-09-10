//
// Created by edgarh on 9/09/19.
//

#ifndef P1_NEGATIVE_H
#define P1_NEGATIVE_H

#include "iostream"
using  namespace std;

struct  NegativeNode{
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;
    NegativeNode *NextGray;
    NegativeNode *PreviuosGray;
};

class Negative {
public:
    NegativeNode *FirstNode=NULL;
    NegativeNode *EndNode = NULL;
    bool IsEmptyP();
    NegativeNode *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB, string ColorHexa);
    void AddNEGATIVE(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB, string ColorHexa);
    void AddNEGATIVEEStart(NegativeNode *& Node);
    void AddNEGATIVEBetween(NegativeNode *& Node);
    void AddNEGATIVEInEnd(NegativeNode *& Node);
    string  ConvertirAHexa(int ColorR, int ColorG,int ColorB, bool Con);
    void Recibir(int WidthC, int HeightC,int WidthP, int HeightP);
    void Tamanio(int Tama);
    void CreateHTML();
    void CreateCSS(int WidthC, int HeightC,int WidthP, int HeightP);
    string Html(string html);
    string Css(string css,int WidthC, int HeightC,int WidthP, int HeightP);
};


#endif //P1_NEGATIVE_H
