//
// Created by edgarh on 30/08/19.
//

#ifndef P1_LISTMATIX_H
#define P1_LISTMATIX_H
#include "iostream"
#include "MatrixB.h"
#include "LinearizeMatrix.h"
#include "MatrixRotationY.h"
#include "MatrixRotationX.h"

using namespace std;
struct MatrixList{
    int Id;
    string Name;
    string Archivo;
    MatrixB PunteroMatrixB;
    LinearizeMatrix Linalizador;
    MatrixRotationY RotacionY;
    MatrixRotationX RotacionX;
    MatrixList *NextMatrix;
    MatrixList *PreviousMatrix;
};
class ListMatix {
public:
    MatrixList *FirstMatrixList=NULL;
    MatrixList *EndMatrixList= NULL;
    MatrixList *Create_Matrix(int Id, string Name);
    bool IsEmptyP();
    void AddMatrixList(int Id, string Name);
    void AddMatrixListStart(MatrixList *& Node);
    void AddMatrixListBetween(MatrixList *& Node);
    void AddMatrixListInEnd(MatrixList *& Node);
    MatrixList *SearchHeader(int Id);
    bool IsMatrix(int Id);
    void Graph();

    void ADDMatrix();
    void DesEncapar(MatrixList *& Node);
    void PrintList();
    MatrixList* MandarAGraficar(int Id);
    void GraficaCompleta();
    string GCompleta();
    void GraphCapas(int Id);
    void MostarCapas();
    void ConvertRGBaHex();
    void MandarCompleta(int id);
    void GraficarMatizCompleta();
    void AgregarMatrixCompleta();

    void GraficarLFilas();
    void MandarHtml(string name);
    //void MandarHtml(int WidthC, int HeightC, int WidthP, int HeightP, string name);
    void MandarCSS(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    void MandarTamanio(int WidthM, int HeightM);
    string IntentoMandarHtml(int Image_width, int Image_height);
    void IntentoMandarHtml1(string name,int Image_width, int Image_height);
    string IntentoMandarHtml2(string html, string nombre, int Image_width, int Image_height);

    string IntentoMandarCSS();
    void IntentoMandarCSS1(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string IntentoMandarCSS2(string html,int WidthC, int HeightC, int WidthP, int HeightP);

    void UpdateNodeLinealizar(int Col, int Fil, int ColoR, int ColorG, int ColorB);
    void UpdateNodeLinealizar2(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB);


    string IntentoMandarCss();
    //*****************Mandar GRAYSCALE ******//////////
    void EnviarAConvertirGRAYSCALE();
    void MandarHtmGRAYSCALEl(string name,int Image_width, int Image_height);
    string MandarHtmGRAYSCALE2(string html, string nombre,int Image_width, int Image_height);
    string MandarHtmGRAYSCALE3(int Image_width, int Image_height);
    void MandarCSSGRAYSCALEl(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSGRAYSCALE2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSGRAYSCALE3();
    bool IsEmptyGrayScale();
    void SentToGraph();
    //***********************MANDAR NEGATIVE **********
    void EnviarAConvertirNEGATIVE();
    void MandarHTMLNEGATIVE(string name,int Image_width, int Image_height);
    string MandarHtmNEGATIVE(string html, string nombre,int Image_width, int Image_height);
    string MandarHtmNEGATIVE3(int Image_width, int Image_height);
    void MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSNEGATIVE2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSNEGATIVE3();
    bool IsEmptyNegative();

    //***********************MANDAR ROTACIONY ***********
    void EnviarAConvertirROTACIONY(int WidthC, int HeightC);
    void MandarHTMLROTACIONY(string name,int Image_width, int Image_height);
    string MandarHtMLROTACIONY2(string html, string nombre,int Image_width, int Image_height);
    string MandarHtmROTACIONY3(int Image_width, int Image_height);
    void MandarCSSROTACIONY(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSROTACIONY2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSROTACIONY3();
    bool IsEmptyMRY();
    bool IsEmptyMRX();
    //************************NEW MATRIX ESPEJO Y*******************///
    void ADDMatrixY();
    void DesEncaparMatrixY(MatrixList *&Node);
    void MandarAGraficarY(int Id);


    //************************MANDAR ROTACIONES X*************
    void EnviarAConvertirROTACIONESX(int WidthC, int HeightC);
    void ADDMatrixX();
    void DesEncaparMatrixX(MatrixList *&Node);
    void MandarAGraficarX(int Id);

    //*******************************CAPAS**************************
    //*****************************MANDAR CAPA GRAYSCALE
    void MandarGRAYCAPA(int id);

    string MandarCSSGrayCApa(int Id);
    void MandarHtmGRAYSCALElCAPA(string name,int Image_width, int Image_height);
    string MandarHtmGRAYSCALE2CAPA(string html, string nombre,int Image_width, int Image_height);
    string MandarHtmGRAYSCALE3CAPA(int Image_width, int Image_height);
    void MandarCSSGRAYSCALElCAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSGRAYSCALE2CAPA(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSGRAYSCALE3CAPA();

    void GraphLayers(int a);
    //***************************MANDAR CAPA NEGATIVE **********

    void MandarNEGATIVECAPA(int Id);
    string MandarCSSNEGATIVECApa(int Id);
    void MandarHtmNEGATIVElCAPA(string name,int Image_width, int Image_height);
    string MandarHtmNEGATIVE2CAPA(string html, string nombre,int Image_width, int Image_height);
    string MandarHtmNEGATICE3CAPA(int Image_width, int Image_height);
    void MandarCSSNEGATIVECAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSNEGATIVE2CAPA(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSNEGATIVECAPA();
    void GraphLayersNegative(int a);
    //**********************************EDIT LAYER ************

    void EditNodeMatrix(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB);
    void EditNodeMatrixGrayScale(int Id, int Col,int Fil, int ColorR, int ColorG, int ColorB);


};


#endif //P1_LISTMATIX_H
