//
// Created by edgarh on 9/09/19.
//

#ifndef P1_GRAYSCALE_H
#define P1_GRAYSCALE_H

#include "iostream"
#include "fstream"
using namespace std;
struct  GrayNode{
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;
    GrayNode *NextGray;
    GrayNode *PreviuosGray;
};
class Grayscale {
public:
    GrayNode *FirstNode=NULL;
    GrayNode *EndNode = NULL;
    bool IsEmptyP();
    GrayNode *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB, string ColorHexa);
    void AddGRAYSCALE(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB, string ColorHexa);
    void AddGRAYSCALEStart(GrayNode *& Node);
    void AdDGRAYSCALEBetween(GrayNode *& Node);
    void AddGRAYSCALEInEnd(GrayNode *& Node);
    string  ConvertirAHexa(int ColorR, int ColorG,int ColorB, bool Con);
    void Recibir(int WidthC, int HeightC,int WidthP, int HeightP);
    void Tamanio(int Tama);
    void CreateHTML();
    void CreateCSS(int WidthC, int HeightC,int WidthP, int HeightP);
    string Html(string html);
    string Css(string css,int WidthC, int HeightC,int WidthP, int HeightP);
    string MandarCSS();

    void UpdateMatrixGrayScale(int Col, int Fil, int ColorR, int ColorG, int ColorB);
};




#endif //P1_GRAYSCALE_H
