//
// Created by edgarh on 13/09/19.
//

#include "RotacionX.h"


RotacionNodeX *RotacionX::Create_Node(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    RotacionNodeX *New_Nodo = new RotacionNodeX;
    New_Nodo->Id = Id;
    New_Nodo->Col = Col;
    New_Nodo->Fil = Fil;
    New_Nodo->ColorR = ColorR;
    New_Nodo->ColorG = ColorG;
    New_Nodo->ColorB = ColorB;
    New_Nodo->ColorHexa = ColorHexa;
    New_Nodo->NextRotacion = NULL;
    New_Nodo->PreviousRotacion = NULL;
    return New_Nodo;

}

bool RotacionX::IsEmptyP() {
    return  FirstRotation == NULL;
}
void RotacionX::AddROTACIONX(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    RotacionNodeX *New_Nodo = Create_Node(Id, Col, Fil, ColorR, ColorG, ColorB, ColorHexa);
    if (IsEmptyP()) {
        FirstRotation = EndRotation = New_Nodo;
    } else {
        if (New_Nodo->Id < FirstRotation->Id) {
            AddROTACIONXStart(New_Nodo);
        } else if (New_Nodo->Id > EndRotation->Id) {
            AddROTACIONXInEnd(New_Nodo);
        }else {
            AddROTACIONXBetween(New_Nodo);
        }
    }
}

void RotacionX::AddROTACIONXStart(RotacionNodeX *&Node) {
    FirstRotation->PreviousRotacion= Node;
    Node->NextRotacion = FirstRotation;
    FirstRotation = FirstRotation->PreviousRotacion;
}

void RotacionX::AddROTACIONXInEnd(RotacionNodeX *&Node) {
    EndRotation->NextRotacion = Node;
    Node->PreviousRotacion = EndRotation;
    EndRotation = EndRotation->NextRotacion;
}

void RotacionX::AddROTACIONXBetween(RotacionNodeX *&Node) {
    RotacionNodeX *Aux, *Aux2;
    Aux = FirstRotation;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextRotacion;
    }
    Aux2 = Aux->PreviousRotacion;
    Aux2->NextRotacion = Node;
    Aux->PreviousRotacion= Node;
    Node->NextRotacion = Aux;
    Node->PreviousRotacion = Aux2;
}
string RotacionX::Rotacion() {
    RotacionNodeX *Aux = FirstRotation;
    string css ="";
    while (Aux != NULL) {
        css += ".pixel:nth-child("+to_string(Aux->Id)+"){\n";
        css += "background:"+Aux->ColorHexa+";} \n";
        Aux = Aux->NextRotacion;
    }
    return css;
}