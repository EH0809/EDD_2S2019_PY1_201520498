//
// Created by edgarh on 1/09/19.
//

#include <fstream>
#include "CompleteMatrix.h"


void CompleteMatrix::ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    PunteroMatriz.AddMatrixC(Col,Fil,ColorR,ColorG,ColorB);
}

void CompleteMatrix::GraficarCompleta() {
    string a ="";
    ofstream fd4("Completa.dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += PunteroMatriz.DotMatirx2C(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN  \n";
    string ab = "dot -Tpng Completa.dot -o Completa.png";
    const char *command = ab.c_str();
    system(command);
}








/*
CompleteM *CompleteMatrix::Create_Matrix(int Id) {
    CompleteM *New_Nodo  = new CompleteM;
    New_Nodo->Id = Id;
    New_Nodo->NextComplete = NULL;
    New_Nodo->PreviousComplete = NULL;
    return  New_Nodo;
}

bool CompleteMatrix::IsEmptyP() {
    return FirstMatrixC == NULL;
}

void CompleteMatrix::AddMatrixC(int Id) {
    CompleteM * New_Nodo = Create_Matrix(Id);
    if(IsEmptyP()){
        FirstMatrixC = EndMatrixC = New_Nodo;
    }else{
        if(New_Nodo->Id < FirstMatrixC->Id){
            AddMatrixCStart(New_Nodo);
        }else if (New_Nodo->Id > EndMatrixC->Id){
            AddMatrixCInEnd(New_Nodo);
        }else{
            AddMatrixCBetween(New_Nodo);
        }
    }
}

void CompleteMatrix::AddMatrixCStart(CompleteM *&Node) {
    FirstMatrixC->PreviousComplete = Node;
    Node->NextComplete = FirstMatrixC;
    FirstMatrixC = FirstMatrixC->PreviousComplete;
}

void CompleteMatrix::AddMatrixCInEnd(CompleteM *&Node) {
    EndMatrixC->NextComplete = Node;
    Node->PreviousComplete = EndMatrixC;
    EndMatrixC = EndMatrixC->NextComplete;
}

void CompleteMatrix::AddMatrixCBetween(CompleteM *&Node) {
    CompleteM *Aux, *Aux2;
    Aux = FirstMatrixC;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextComplete;
    }
    Aux2 = Aux->PreviousComplete;
    Aux2->NextComplete = Node;
    Aux->PreviousComplete = Node;
    Node->NextComplete = Aux;
    Node->PreviousComplete = Aux2;
}

CompleteM *CompleteMatrix::SearchHeader(int Id) {
    if (IsMatrixC(Id)) {
        CompleteM *Aux = FirstMatrixC;
        while (Aux->Id != Id) {
            Aux = Aux->NextComplete;
        }
        cout << "Si se Encuentra Matrix Completa \n";
        return Aux;
    } else {
        cout << "No se ha Encontrado Matriz Completa \n";
        return Create_Matrix(-1);
    }
}

bool CompleteMatrix::IsMatrixC(int Id) {
    if (FirstMatrixC == NULL) {
        return false;
    } else {
        CompleteM *Aux = FirstMatrixC;
        while (Aux != NULL) {
            if (Aux->Id == Id) {
                return true;
            } else if (Aux->NextComplete == NULL) {
                return false;
            }
            Aux = Aux->NextComplete;
        }
        return false;
    }
}

void CompleteMatrix::PrintList() {
    CompleteM *tem = FirstMatrixC;
    while(tem != NULL){
        cout<<"Id: "+to_string(tem->Id)<<"\n";
        tem = tem->NextComplete;
    }

}
CompleteM* CompleteMatrix::MandarCompleta(int Id) {
        CompleteM *Aux = FirstMatrixC;
        while(Aux!= NULL){
            if (Aux->Id == Id){
                return Aux;
            }
            Aux = Aux->NextComplete;
        }
}
*/