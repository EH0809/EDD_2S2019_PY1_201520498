//
// Created by edgarh on 7/09/19.
//

#ifndef P1_LINEARIZEMATRIX_H
#define P1_LINEARIZEMATRIX_H
#include "iostream"
#include "Grayscale.h"
#include "Negative.h"

using namespace std;
struct Linearize{
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;
    Linearize *NextLinearize;
    Linearize *PreviuosLinearize;
};

class LinearizeMatrix {
public:
    Grayscale GNode;
    Negative NNode;
    Linearize *FirstLinearize = NULL;
    Linearize *EndLinearize = NULL;
    bool IsEmptyP();
    Linearize *Create_Node(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB, string ColorHexa);
    void AddLinearize(int Pixel, int Col, int Fil, int ColorR, int ColorG,int ColorB);
    void AddLinearizeStart(Linearize *& Node);
    void AddLinearizeBetween(Linearize *& Node);
    void AddLinearizeInEnd(Linearize *& Node);
    void PrintList();
    Linearize *SearchHeader(int Pixel);
    bool IsMatrix(int Pixel);
    void Tamanio(int WidthM, int HeightM);
    void CreateHTML();
    void CreateCSS(int WidthC, int HeightC,int WidthP, int HeightP);
    string Html(string html);
    string Css(string css,int WidthC, int HeightC,int WidthP, int HeightP);
    void EnviarConvertir();
    string  ConvertirAHexa(int ColorR, int ColorG,int ColorB, bool Con);
    string Agrupar(string ColorHexa);


    //******************GRAYSCALE************************************//
    void Convertir();
    void GrayS(Linearize *& Node);
    void MandarTamanio(int WidthC, int HeightC,int WidthP, int HeightP);
    void CreateHTMLGRAYSCALE();
    void CreateCSSGRAYSCALE(int WidthC, int HeightC,int WidthP, int HeightP);
    string HtmlGRAYSCALE(string html);
    string CssGRAYSCALE(string css,int WidthC, int HeightC,int WidthP, int HeightP);
    string Conversor(int ColorR, int ColorG, int ColorB);

    //******************NEGATIVE****************************/
    void ConvertirNEGATIVE();
    void NEGATIVES(Linearize *& Node);
    void MandarTamanioNEGATIVE(int WidthC, int HeightC,int WidthP, int HeightP);
    void CreateHTMLNEGATIVE();
    void CreateCSSNEGATIVE(int WidthC, int HeightC,int WidthP, int HeightP);


};


#endif //P1_LINEARIZEMATRIX_H
