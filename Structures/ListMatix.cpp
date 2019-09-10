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
CompleteM *Completa;
CompleteMatrix MatrizCompleta;
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
        cout << "Si se Encuentra en la ListaMatrix \n";
        return Aux;
    } else {
        cout << "No se ha Encontrado en la Lista";
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

void ListMatix::AgregarMatrixCompleta() {
    MatrizCompleta.AddMatrixC(1);
}

void ListMatix::ADDMatrix() {
    MatrixList *Aux741 = FirstMatrixList;
    while (Aux741 != NULL) {
        cout << "***************************\n";
        cout << "Nombre: " + Aux741->Name + "\n";
        DesEncapar(Aux741);
       // cout << Aux->Archivo << "\n";
        cout << "******CAPA COMPLETA" + Aux741->Name + "********\n";
        cout << "***************************\n";
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
            //cout << "Col:" + Col + " Fil: " + Fil + " R: " + R + " G: " + G + " B: " + B + "\n";
            LinealizarMatriz.AddLinearize(Pixel,Columna,Fila,ColorR,ColorG,ColorB);
           //cout << "/////////****************Linealizar \n";
           // cout << "Id: " + to_string(Pixel) + " Col:" + to_string(Columna) + " Fil: " + to_string(Fila) + " R: " + to_string(ColorR) + " G: " + to_string(ColorG) + " B: " +
           //         to_string(ColorB) + "\n";
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

void ListMatix::MostarCapas() {
    MatrixList *Aux = FirstMatrixList;
    while (Aux != NULL) {
        cout << to_string(Aux->Id) + " " + Aux->Name << "\n";
        Aux = Aux->NextMatrix;
    }
}


void ListMatix::GraficarMatizCompleta() {
    MatrizCompleta.PrintList();
    CompleteM *Aux = MatrizCompleta.MandarCompleta(1);
    string a = "";
    ofstream fd4("MatrizCompleta.dot");
    a += Aux->PunteroMatriz.Dot3(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Matriz \n";
    system("dot -Tpng MatrizCompleta.dot -o MatrizCompleta.png");
}

void ListMatix::GraficarLFilas() {
    cout << "///************Matriz Linealizada******** \n";
    LinealizarMatriz.PrintList();
}

void ListMatix::MandarHtml() {
    LinealizarMatriz.CreateHTML();
}
void ListMatix::MandarCSS(int WidthC, int HeightC, int WidthP, int HeightP) {
    LinealizarMatriz.CreateCSS(WidthC,HeightC,WidthP,HeightP);
}
//***************************FILTROS COMPLETOS********************************
void ListMatix::MandarTamanio(int WidthM, int HeightM) {
    LinealizarMatriz.Tamanio(WidthM,HeightM);
}

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

//******************FILTROS CAPAS **********************////////////////

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
