//
// Created by edgarh on 30/08/19.
//

#include "ListMatix.h"
#include "iostream"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>
#include <sstream>
#include "fstream"
#include "string.h"

using namespace std;

string Dot = "";
int Contador852 = 1;
LinearizeMatrix LinealizarMatriz;

MatrixList *ListMatix::Create_Matrix(int Id, string Name) {
    MatrixList *New_Nodo = new MatrixList;
    New_Nodo->Id = Id;
    New_Nodo->Name = Name;
    New_Nodo->NextMatrix = NULL;
    New_Nodo->PreviousMatrix = NULL;
    return New_Nodo;
}

bool ListMatix::IsEmptyP() {
    return FirstMatrixList == NULL;
}

void ListMatix::AddMatrixList(int Id, string Name) {
    MatrixList *New_Nodo = Create_Matrix(Id, Name);
    if (IsEmptyP()) {
        FirstMatrixList = EndMatrixList = New_Nodo;
    } else {
        if (New_Nodo->Id < FirstMatrixList->Id) {
            AddMatrixListStart(New_Nodo);
        } else if (New_Nodo->Id > EndMatrixList->Id) {
            AddMatrixListInEnd(New_Nodo);
        } else {
            AddMatrixListBetween(New_Nodo);
        }
    }
}

void ListMatix::AddMatrixListStart(MatrixList *&Node) {
    FirstMatrixList->PreviousMatrix = Node;
    Node->NextMatrix = FirstMatrixList;
    FirstMatrixList = FirstMatrixList->PreviousMatrix;
}

void ListMatix::AddMatrixListInEnd(MatrixList *&Node) {
    EndMatrixList->NextMatrix = Node;
    Node->PreviousMatrix = EndMatrixList;
    EndMatrixList = EndMatrixList->NextMatrix;
}

void ListMatix::AddMatrixListBetween(MatrixList *&Node) {
    MatrixList *Aux, *Aux2;
    Aux = FirstMatrixList;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextMatrix;
    }
    Aux2 = Aux->PreviousMatrix;
    Aux2->NextMatrix = Node;
    Aux->PreviousMatrix = Node;
    Node->NextMatrix = Aux;
    Node->PreviousMatrix = Aux2;
}

MatrixList *ListMatix::SearchHeader(int Id) {
    if (IsMatrix(Id)) {
        MatrixList *Aux = FirstMatrixList;
        while (Aux->Id != Id) {
            Aux = Aux->NextMatrix;
        }
      //  cout << "Si se Encuentra en la ListaMatrix \n";
        return Aux;
    } else {
        //cout << "No se ha Encontrado en la Lista";
        return Create_Matrix(-1, "");
    }
}

bool ListMatix::IsMatrix(int Id) {
    if (FirstMatrixList == NULL) {
        return false;
    } else {
        MatrixList *Aux = FirstMatrixList;
        while (Aux != NULL) {
            if (Aux->Id == Id) {
                return true;
            } else if (Aux->NextMatrix == NULL) {
                return false;
            }
            Aux = Aux->NextMatrix;
        }
        return false;
    }
}

void ListMatix::PrintList() {
    MatrixList *tem = FirstMatrixList;
    while (tem != NULL) {
        cout << "Id: " + to_string(tem->Id) + " Nombre:" + tem->Name << "\n";
        tem = tem->NextMatrix;
    }
}

void ListMatix::ADDMatrix() {
    MatrixList *Aux741 = FirstMatrixList;
    while (Aux741 != NULL) {
        //cout << "***************************\n";
        //cout << "Nombre: " + Aux741->Name + "\n";
        DesEncapar(Aux741);
        //cout << Aux741->Archivo << "\n";
        //cout << "******CAPA COMPLETA" + Aux741->Name + "********\n";
        //cout << "***************************\n";
        //MatrixB();
        Aux741 = Aux741->NextMatrix;
    }


}

void ListMatix::DesEncapar(MatrixList *&Node) {
    string Archivo = Node->Archivo;
    string Col;
    string Fil;
    string R;
    string G;
    string B;
    string PiL;
    stringstream AuxLectura(Archivo);
    while (!AuxLectura.fail()) {
        getline(AuxLectura, Col, ',');
        getline(AuxLectura, Fil, ',');
        getline(AuxLectura, R, ',');
        getline(AuxLectura, G, ',');
        getline(AuxLectura, B, ',');
        getline(AuxLectura, PiL, '\n');
        int Columna = atoi(Col.c_str());
        int Fila = atoi(Fil.c_str());
        int ColorR = atoi(R.c_str());
        int ColorG = atoi(G.c_str());
        int ColorB = atoi(B.c_str());
        int Pixel = atoi(PiL.c_str());
        if (Node->PunteroMatrixB.HeadNode == NULL) {
            cout << "Matrix Vacia para" + Node->Name << "\n";
        }
        if (Col != "") {
            Node->PunteroMatrixB.AddMatrixC(Columna, Fila, ColorR, ColorG, ColorB);
            Node->Linalizador.AddLinearize(Pixel,Columna,Fila,ColorR,ColorG,ColorB);
        }

    }
}

MatrixList *ListMatix::MandarAGraficar(int Id) {
    MatrixList *Aux = FirstMatrixList;
    while (Aux != NULL) {
        if (Aux->Id == Id) {
            return Aux;
        }
        Aux = Aux->NextMatrix;
    }
}

void ListMatix::GraphCapas(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = "";
    string Capa = "Capa" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += Temp->PunteroMatrixB.DotMatirx2C(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}
//*****************************GrayScale************

void ListMatix::GraphLayers(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = "";
    string Capa = "GrayCapa" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += Temp->PunteroMatrixB.DotGrayScape(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}

void ListMatix::GraphLayersNegative(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = "";
    string Capa = "NegativeCapa" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += Temp->PunteroMatrixB.DotNegative(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}

void ListMatix::GraficarMatizCompleta() {

    string a ="";
    ofstream fd4("Completa.dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += GCompleta();
    fd4 << a;
    cout<<a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng Completa.dot -o Completa.png";
    const char *command = ab.c_str();
    system(command);
}

string ListMatix::GCompleta() {
    MatrixList * Aux = FirstMatrixList;
    string a="" ;
    while(Aux != NULL){
        a += Aux->PunteroMatrixB.DotMatirx2C(a);
        Aux = Aux->NextMatrix;
    }
    return a;
}

void ListMatix::MostarCapas() {
    MatrixList *Aux = FirstMatrixList;
    while (Aux != NULL) {
        cout << to_string(Aux->Id) + " " + Aux->Name << "\n";
        Aux = Aux->NextMatrix;
    }
}


void ListMatix::GraficarLFilas() {
    cout << "///************MATRIX******** \n";
    LinealizarMatriz.PrintList();
}

void ListMatix::IntentoMandarHtml1(string name,int Image_width, int Image_height) {
    string a = "";
    int b = Image_width *Image_height;
    string nombre = name+".html";
    ofstream fd4(nombre);
    a += IntentoMandarHtml2(a,name,Image_width, Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}


string ListMatix::IntentoMandarHtml2(string html, string nombre,int Image_width, int Image_height) {
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\""+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += IntentoMandarHtml(Image_width , Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::IntentoMandarHtml(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width, Image_height);
    return temp;
}

void ListMatix::IntentoMandarCSS1(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 = name+".css";
    ofstream fd4(nombre1);
    a += IntentoMandarCSS2(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::IntentoMandarCSS2(string css,int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += IntentoMandarCSS();
    return css;

}

string ListMatix::IntentoMandarCSS(){
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    while (Aux != NULL) {
        temp += Aux->Linalizador.C1();
        Aux = Aux->NextMatrix;
    }
    return temp;
}

void ListMatix::UpdateNodeLinealizar(int Col, int Fil, int ColoR, int ColorG, int ColorB) {
    MatrixList *Temp = FirstMatrixList;
    while(Temp!= NULL){
        Temp->Linalizador.UpdateNodeLinealizar(Col, Fil, ColoR,ColorG, ColorB);
        Temp = Temp->NextMatrix;
    }
}


void ListMatix::UpdateNodeLinealizar2(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    MatrixList *Temp = MandarAGraficar(Id);
    Temp->Linalizador.UpdateNodeLinealizar(Col, Fil, ColorR, ColorG, ColorB);
}
//***************************FILTROS COMPLETOS********************************


//*******************************GRAYSCALE*********************************
void ListMatix::MandarHtmGRAYSCALEl(string name, int Image_width, int Image_height){
    string a = "";
    string nombre = "N"+name+".html";
    ofstream fd4(nombre);
    a += MandarHtmGRAYSCALE2(a,name, Image_width,Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarHtmGRAYSCALE2(string html, string nombre,int Image_width, int Image_height){
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\" N"+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += MandarHtmGRAYSCALE3(Image_width, Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::MandarHtmGRAYSCALE3(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width, Image_height);
    return temp;
}

void ListMatix::MandarCSSGRAYSCALEl(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 ="N"+name+".css";
    ofstream fd4(nombre1);
    a += MandarCSSGRAYSCALE2(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();

}

string ListMatix::MandarCSSGRAYSCALE2(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += MandarCSSGRAYSCALE3();
    return css;
}

string ListMatix::MandarCSSGRAYSCALE3() {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    while (Aux != NULL) {
        temp += Aux->Linalizador.TraerCSSGRAYSACLE();
        Aux = Aux->NextMatrix;
    }
    return temp;
}

void ListMatix::EnviarAConvertirGRAYSCALE() {
    MatrixList *Aux = FirstMatrixList;
    while(Aux != NULL){
        Aux->Linalizador.Convertir();
        Aux = Aux->NextMatrix;
    }
}

bool ListMatix::IsEmptyGrayScale() {
    MatrixList *Aux = FirstMatrixList;
    bool a = Aux->Linalizador.isEmptyGrayScale();
    return a;
}

bool ListMatix::IsEmptyNegative() {
    MatrixList *Aux = FirstMatrixList;
    bool a = Aux->Linalizador.isEmptyNegative();
    return a;
}

bool ListMatix::IsEmptyMRX() {
    MatrixList *Aux = FirstMatrixList;
    bool a = Aux->Linalizador.isEmptyMRX();
    return a;
}

bool ListMatix::IsEmptyMRY() {
    MatrixList *Aux = FirstMatrixList;
    bool a = Aux->Linalizador.isEmptyMRY();
    return a;
}


//****************************NEGATIVE**************************************

void ListMatix::EnviarAConvertirNEGATIVE() {
    MatrixList *Aux = FirstMatrixList;
    while(Aux != NULL){
        Aux->Linalizador.ConvertirNEGATIVE();
        Aux = Aux->NextMatrix;
    }
}

void ListMatix::MandarHTMLNEGATIVE(string name,int Image_width, int Image_height){
    string a = "";
    string nombre = "Neg"+name+".html";
    ofstream fd4(nombre);
    a += MandarHtmNEGATIVE(a,name, Image_width, Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarHtmNEGATIVE(string html, string nombre,int Image_width, int Image_height){
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\" Neg"+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += MandarHtmNEGATIVE3(Image_width,Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::MandarHtmNEGATIVE3(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width, Image_height);
    return temp;
}

void ListMatix::MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 ="Neg"+name+".css";
    ofstream fd4(nombre1);
    a += MandarCSSNEGATIVE2(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarCSSNEGATIVE2(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += MandarCSSNEGATIVE3();
    return css;
}

string ListMatix::MandarCSSNEGATIVE3() {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    while (Aux != NULL) {
        temp += Aux->Linalizador.MandarAtraerNegativos();
        Aux = Aux->NextMatrix;
    }
    return temp;
}

void ListMatix::SentToGraph() {
    MatrixList *Aux = FirstMatrixList;
    while(Aux != NULL){
        Aux->Linalizador.ConvertirNEGATIVE();
        Aux = Aux->NextMatrix;
    }
}


//************************ROTACION Y************************************


void ListMatix::ADDMatrixY() {
    MatrixList *Aux741 = FirstMatrixList;
    while (Aux741 != NULL) {
        DesEncaparMatrixY(Aux741);
        Aux741 = Aux741->NextMatrix;
    }
}

void ListMatix::DesEncaparMatrixY(MatrixList *&Node) {
    string Archivo = Node->Archivo;
    string Col;
    string Fil;
    string R;
    string G;
    string B;
    string PiL;
    stringstream AuxLectura(Archivo);
    while (!AuxLectura.fail()) {
        getline(AuxLectura, Col, ',');
        getline(AuxLectura, Fil, ',');
        getline(AuxLectura, R, ',');
        getline(AuxLectura, G, ',');
        getline(AuxLectura, B, ',');
        getline(AuxLectura, PiL, '\n');
        int Columna = atoi(Col.c_str());
        int Fila = atoi(Fil.c_str());
        int ColorR = atoi(R.c_str());
        int ColorG = atoi(G.c_str());
        int ColorB = atoi(B.c_str());
        int Pixel = atoi(PiL.c_str());
        if (Node->PunteroMatrixB.HeadNode == NULL) {
            cout << "Matrix Vacia para" + Node->Name << "\n";
        }
        if (Col != "") {
            Node->RotacionY.AddMatrixC(Columna, Fila, ColorR, ColorG, ColorB);
        }

    }
}

void  ListMatix::MandarAGraficarY(int ID){
    MatrixList *Temp = MandarAGraficar(ID);
    string a = "";
    string Capa = "CapaRY" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += Temp->RotacionY.DotMatirx2C(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}


void ListMatix::EnviarAConvertirROTACIONY(int WidthC, int HeightC) {
    MatrixList *Aux = FirstMatrixList;
    while(Aux != NULL){
        Aux->Linalizador.ChangeId(WidthC, HeightC);
        Aux = Aux->NextMatrix;
    }
}

void ListMatix::MandarHTMLROTACIONY(string name,int Image_width, int Image_height){
    string a = "";
    string nombre = "RY"+name+".html";
    ofstream fd4(nombre);
    a += MandarHtMLROTACIONY2(a,name, Image_width, Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarHtMLROTACIONY2(string html, string nombre,int Image_width, int Image_height){
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\" RY"+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += MandarHtmROTACIONY3( Image_width, Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::MandarHtmROTACIONY3(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width,Image_height);
    return temp;
}

void ListMatix::MandarCSSROTACIONY(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 ="RY"+name+".css";
    ofstream fd4(nombre1);
    a += MandarCSSROTACIONY2(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarCSSROTACIONY2(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += MandarCSSROTACIONY3();
    return css;
}

string ListMatix::MandarCSSROTACIONY3() {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    while (Aux != NULL) {
        temp += Aux->Linalizador.MandarAtraerRotacionY();
        Aux = Aux->NextMatrix;
    }
    return temp;
}


//*************************ROTACIONES X ******************************

void ListMatix::EnviarAConvertirROTACIONESX(int WidthC, int HeightC) {
    MatrixList *Aux = FirstMatrixList;
    while(Aux != NULL){
        Aux->Linalizador.ChangeIdx(WidthC, HeightC);
        Aux = Aux->NextMatrix;
    }
}


void ListMatix::ADDMatrixX() {
    MatrixList *Aux741 = FirstMatrixList;
    while (Aux741 != NULL) {
        DesEncaparMatrixX(Aux741);
        Aux741 = Aux741->NextMatrix;
    }
}

void ListMatix::DesEncaparMatrixX(MatrixList *&Node) {
    string Archivo = Node->Archivo;
    string Col;
    string Fil;
    string R;
    string G;
    string B;
    string PiL;
    stringstream AuxLectura(Archivo);
    while (!AuxLectura.fail()) {
        getline(AuxLectura, Col, ',');
        getline(AuxLectura, Fil, ',');
        getline(AuxLectura, R, ',');
        getline(AuxLectura, G, ',');
        getline(AuxLectura, B, ',');
        getline(AuxLectura, PiL, '\n');
        int Columna = atoi(Col.c_str());
        int Fila = atoi(Fil.c_str());
        int ColorR = atoi(R.c_str());
        int ColorG = atoi(G.c_str());
        int ColorB = atoi(B.c_str());
        int Pixel = atoi(PiL.c_str());
        if (Node->PunteroMatrixB.HeadNode == NULL) {
            cout << "Matrix Vacia para" + Node->Name << "\n";
        }
        if (Col != "") {
            Node->RotacionX.AddMatrixC(Columna, Fila, ColorR, ColorG, ColorB);
        }

    }
}

void  ListMatix::MandarAGraficarX(int ID){
    MatrixList *Temp = MandarAGraficar(ID);
    string a = "";
    string Capa = "CapaRX" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    a += Temp->RotacionX.DotMatirx2C(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}
//*************************POR CAPAS *************************************
//*******************GRAYSCALE**********

void ListMatix::MandarGRAYCAPA(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    Temp->Linalizador.Convertir();
}

string VariableCapa ="";

string ListMatix::MandarCSSGrayCApa(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = Temp->Linalizador.TraerCSSGRAYSACLE();
    VariableCapa = a;
    return  VariableCapa;
}

void ListMatix::MandarHtmGRAYSCALElCAPA(string name,int Image_width, int Image_height){
    string a = "";
    string nombre = "GC"+name+".html";
    ofstream fd4(nombre);
    a += MandarHtmGRAYSCALE2CAPA(a,name, Image_width,Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarHtmGRAYSCALE2CAPA(string html, string nombre,int Image_width, int Image_height){
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\" GC"+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += MandarHtmGRAYSCALE3CAPA(Image_width,Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::MandarHtmGRAYSCALE3CAPA(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width, Image_height);
    return temp;
}

void ListMatix::MandarCSSGRAYSCALElCAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 ="GC"+name+".css";
    ofstream fd4(nombre1);
    a += MandarCSSGRAYSCALE2CAPA(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarCSSGRAYSCALE2CAPA(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += IntentoMandarCSS();

    css += VariableCapa;
    return css;
}

//**********************NEGATIVE****************************

string VariableCapaNegative ="";

void ListMatix::MandarNEGATIVECAPA(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    Temp->Linalizador.ConvertirNEGATIVE();
}

string ListMatix::MandarCSSNEGATIVECApa(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = Temp->Linalizador.MandarAtraerNegativos();
    VariableCapaNegative = a;
    return  VariableCapaNegative;
}

void ListMatix::MandarHtmNEGATIVElCAPA(string name,int Image_width, int Image_height){
    string a = "";
    string nombre = "NC"+name+".html";
    ofstream fd4(nombre);
    a += MandarHtmNEGATIVE2CAPA(a,name, Image_width, Image_height);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarHtmNEGATIVE2CAPA(string html, string nombre,int Image_width, int Image_height){
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\" NC"+nombre+".css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    html += MandarHtmNEGATICE3CAPA(Image_width,Image_height);
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string ListMatix::MandarHtmNEGATICE3CAPA(int Image_width, int Image_height) {
    MatrixList *Aux = FirstMatrixList;
    string temp ="";
    temp += Aux->Linalizador.H1(Image_width, Image_height);
    return temp;
}

void ListMatix::MandarCSSNEGATIVECAPA(int WidthC, int HeightC, int WidthP, int HeightP,string name) {
    string a = "";
    string nombre1 ="NC"+name+".css";
    ofstream fd4(nombre1);
    a += MandarCSSNEGATIVE2CAPA(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string ListMatix::MandarCSSNEGATIVE2CAPA(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    css += IntentoMandarCSS();

    css += VariableCapaNegative;
    return css;

}


//**************************EDITAR

void ListMatix::EditNodeMatrix(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    MatrixList *Temp = MandarAGraficar(Id);
    while(Temp != NULL){
        Temp->PunteroMatrixB.EditNodeMatrix(Col, Fil, ColorR , ColorG , ColorB);
        Temp = Temp->NextMatrix;
    }
}

void ListMatix::EditNodeMatrixGrayScale(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB){


}



void ListMatix::MandarTamanio(int WidthM, int HeightM) {
    LinealizarMatriz.Tamanio(WidthM,HeightM);
}
/*




void ListMatix::MandarHtmGRAYSCALEl() {
    LinealizarMatriz.Convertir();
    LinealizarMatriz.CreateHTMLGRAYSCALE();
}
void ListMatix::MandarCSSGRAYSCALE(int WidthC, int HeightC, int WidthP, int HeightP) {
    LinealizarMatriz.CreateCSSGRAYSCALE(WidthC,HeightC,WidthP,HeightP);
}

void ListMatix::MandarHtmlNEGATIVE() {
    LinealizarMatriz.ConvertirNEGATIVE();
    LinealizarMatriz.CreateHTMLNEGATIVE();
}
void ListMatix::MandarCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP) {
    LinealizarMatriz.CreateCSSNEGATIVE(WidthC,HeightC,WidthP,HeightP);
}



void ListMatix::GrayscapeCapas(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = "";
    string Capa = "CapaGRAYSCAPE" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    a += Temp->PunteroMatrixB.DotGrayScape(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa FILTRO \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}


void ListMatix::NegativeCapas(int Id) {
    MatrixList *Temp = MandarAGraficar(Id);
    string a = "";
    string Capa = "CapaNegative" + to_string(Temp->Id);
    ofstream fd4(Capa + ".dot");
    a += Temp->PunteroMatrixB.DotNegative(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Capa FILTRO  NEGATIVO \n";
    string ab = "dot -Tpng " + Capa + ".dot -o " + Capa + ".png";
    const char *command = ab.c_str();
    system(command);
}



void ListMatix::MandarRotacionY() {
    LinealizarMatriz.AgregarRotacionY();
}
void ListMatix::CreatHTMLRY() {
    LinealizarMatriz.CreateHTMLROTATIONY();
}
void ListMatix::CSSRY(int WidthC, int HeightC, int WidthP, int HeightP) {
    LinealizarMatriz.CreateCSSROTATIONY(WidthC,HeightC,WidthP,WidthP);
}

void ListMatix::EnviarTRotacionY(int WidthM, int HeightM) {
    LinealizarMatriz.EnviarTamanioRotacionY(WidthM , HeightM);
}
*/