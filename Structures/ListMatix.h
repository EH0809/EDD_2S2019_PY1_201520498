//
// Created by edgarh on 30/08/19.
//

#ifndef P1_LISTMATIX_H
#define P1_LISTMATIX_H
#include "iostream"
#include "MatrixB.h"
#include "LinearizeMatrix.h"
using namespace std;
struct MatrixList{
    int Id;
    string Name;
    string Archivo;
    MatrixB PunteroMatrixB;
    LinearizeMatrix Linalizador;
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
    string IntentoMandarHtml();
    void IntentoMandarHtml1(string name, int tamanio);
    string IntentoMandarHtml2(string html, string nombre, int tamanio);

    string IntentoMandarCSS();
    void IntentoMandarCSS1(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string IntentoMandarCSS2(string html,int WidthC, int HeightC, int WidthP, int HeightP);



    string IntentoMandarCss();
    //*****************Mandar GRAYSCALE ******//////////
    void EnviarAConvertirGRAYSCALE();
    void MandarHtmGRAYSCALEl(string name,int tamanio);
    string MandarHtmGRAYSCALE2(string html, string nombre);
    string MandarHtmGRAYSCALE3();
    void MandarCSSGRAYSCALEl(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSGRAYSCALE2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSGRAYSCALE3();
    void SentToGraph();
    //***********************MANDAR NEGATIVE **********
    void EnviarAConvertirNEGATIVE();
    void MandarHTMLNEGATIVE(string name);
    string MandarHtmNEGATIVE(string html, string nombre);
    string MandarHtmNEGATIVE3();
    void MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSNEGATIVE2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSNEGATIVE3();

    //***********************MANDAR ROTACIONY ***********
    void EnviarAConvertirROTACIONY(int WidthC, int HeightC);
    void MandarHTMLROTACIONY(string name);
    string MandarHtMLROTACIONY2(string html, string nombre);
    string MandarHtmROTACIONY3();
    void MandarCSSROTACIONY(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSROTACIONY2(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSROTACIONY3();

    //************************MANDAR ROTACIONES X*************
    void EnviarAConvertirROTACIONESX(int WidthC, int HeightC);


    //*******************************CAPAS**************************
    //*****************************MANDAR CAPA GRAYSCALE
    void MandarGRAYCAPA(int id);

    string MandarCSSGrayCApa(int Id);
    void MandarHtmGRAYSCALElCAPA(string name);
    string MandarHtmGRAYSCALE2CAPA(string html, string nombre);
    string MandarHtmGRAYSCALE3CAPA();
    void MandarCSSGRAYSCALElCAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSGRAYSCALE2CAPA(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSGRAYSCALE3CAPA();

    //***************************MANDAR CAPA NEGATIVE **********

    void MandarNEGATIVECAPA(int Id);
    string MandarCSSNEGATIVECApa(int Id);
    void MandarHtmNEGATIVElCAPA(string name);
    string MandarHtmNEGATIVE2CAPA(string html, string nombre);
    string MandarHtmNEGATICE3CAPA();
    void MandarCSSNEGATIVECAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name);
    string MandarCSSNEGATIVE2CAPA(string css,int WidthC, int HeightC, int WidthP, int HeightP);
    string MandarCSSNEGATIVECAPA();










    void MandarCSSGRAYSCALE(int WidthC, int HeightC, int WidthP, int HeightP);
    //******************MANDAR NEGATIVE *********////////
    void MandarHtmlNEGATIVE();
    void MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP);

    //***********************MANDAR POR CAPAS *****///////////
    void GrayscapeCapas(int Id);
    void NegativeCapas(int Id);


    //************************MANDAR ROTACION Y************************/////
    void MandarRotacionY();
    void CreatHTMLRY();
    void CSSRY(int WidthC, int HeightC, int WidthP, int HeightP);
    void EnviarTRotacionY(int WidthM, int HeightM);




};


#endif //P1_LISTMATIX_H
