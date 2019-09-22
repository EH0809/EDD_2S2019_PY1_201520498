//
// Created by edgarh on 7/09/19.
//

#ifndef P1_LINEARIZEMATRIX_H
#define P1_LINEARIZEMATRIX_H
#include "iostream"
#include "Grayscale.h"
#include "Negative.h"
#include "LinearizeMatrix.h"
#include "RotacionY.h"
#include "RotacionX.h"
#include "RotacionXY.h"

using namespace std;
struct Linearize{
    int Id;
    int Col;
    int Fil;
    int ColorR;
    int ColorG;
    int ColorB;
    string ColorHexa;
    Grayscale GNode;
    Negative NNode;
    RotacionY RNode;
    RotacionX RNodeX;
    RotacionXY RNodeXY;
    Linearize *NextLinearize;
    Linearize *PreviuosLinearize;

};

class LinearizeMatrix {
public:

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
    void CreateHTML(string name);
    void CreateCSS(int WidthC, int HeightC,int WidthP, int HeightP, string name);
    string Html(string html, string name);
    string Css(string css,int WidthC, int HeightC,int WidthP, int HeightP);
    void EnviarConvertir();
    string  ConvertirAHexa(int ColorR, int ColorG,int ColorB, bool Con);
    string Agrupar(string ColorHexa);


    void UpdateNodeLinealizar(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void UpdateNodeCSSGrayScale(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void UpdateNodeMatrixGrayScale(int Col, int Fil, int ColorR, int ColorG, int ColorB);
    string H1(int Image_width, int Image_height);
    string C1();


    //******************GRAYSCALE************************************//
    void Convertir();
    void GrayS(Linearize *& Node);
    void MandarTamanio(int WidthC, int HeightC,int WidthP, int HeightP);
    void CreateHTMLGRAYSCALE();
    void CreateCSSGRAYSCALE(int WidthC, int HeightC,int WidthP, int HeightP);
    string HtmlGRAYSCALE(string html);
    string CssGRAYSCALE(string css,int WidthC, int HeightC,int WidthP, int HeightP);
    string Conversor(int ColorR, int ColorG, int ColorB);
    string TraerCSSGRAYSACLE();
    bool isEmptyGrayScale();
    //******************NEGATIVE****************************/
    void ConvertirNEGATIVE();
    void NEGATIVES(Linearize *& Node);
    string MandarAtraerNegativos();
    void SentGraph();
    bool isEmptyNegative();
    //***************ROTACION Y******************************/
   void ChangeId(int WidthC, int HeightC);
    void ChangeId2(Linearize *&Node, int WidthC, int HeightC);
    void MostrarChange();
    string MandarAtraerRotacionY();
    bool isEmptyMRY();
    //**************ROTACION X********************************
    void ChangeIdx(int WidthC, int HeightC);
    void ChangeId2x(Linearize *&Node, int WidthC, int HeightC);
    string MandarAtraerRotacionX();
    bool isEmptyMRX();
    //**********ROTACION XY************
    void ChangeIdXY(int WidthC, int HeightC);
    void ChangeId2XY(Linearize *&Node, int WidthC, int HeightC);
    void MostrarChangeXY();
    string MandarAtraerRotacionXY();
    bool isEmptyRXY();




};


#endif //P1_LINEARIZEMATRIX_H
