//
// Created by edgarh on 17/09/19.
//

#include "MatrixRotationX.h"

#include <iostream>
#include <fstream>

using  namespace std;

void MatrixRotationX::AddMatrixC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    CreateCabeceraC(Col);
    CreateHeadersC(Fil);
    AddMatrixCabeceraC(Col,Fil,ColorR,ColorG,ColorB);
    AddMatrixHeaderC(Col,Fil,ColorR,ColorG,ColorB);

}

void MatrixRotationX::CreateCabeceraC(int Col) {
    if (HeadNode->RightNodeMatrix == NULL){
        NodeRotateX *Aux1 = new NodeRotateX(Col,0,0,0,0);
        HeadNode->RightNodeMatrix = Aux1;
        Aux1->LeftNodeMatrix = HeadNode;
    }else{
        NodeRotateX *Aux = HeadNode;
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col > Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            NodeRotateX *New_Node = new NodeRotateX(Col,0,0,0,0);
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col != Col){
            NodeRotateX *New_Node =  new NodeRotateX(Col,0,0,0,0);
            NodeRotateX *AuxRight = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxRight;
            AuxRight->LeftNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationX::CreateHeadersC(int Fil) {
    if (HeadNode->DownNodeMatrix == NULL){
        NodeRotateX * New_Node = new NodeRotateX(0,Fil,0,0,0);
        HeadNode->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = HeadNode;
    }else{
        NodeRotateX *AuxHeaders = HeadNode;
        while(AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil < Fil){
            AuxHeaders = AuxHeaders->DownNodeMatrix;
        }
        if(AuxHeaders->DownNodeMatrix == NULL){
            NodeRotateX * New_Node = new NodeRotateX(0,Fil,0,0,0);
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
        }else if (AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil != Fil){
            NodeRotateX * New_Node = new NodeRotateX(0,Fil,0,0,0);
            NodeRotateX * AuxUp = AuxHeaders->DownNodeMatrix;
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
            New_Node->DownNodeMatrix = AuxUp;
            AuxUp->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationX::AddMatrixCabeceraC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeRotateX *New_Node = new NodeRotateX(Col, Fil, ColorR,ColorG,ColorB);
    NodeRotateX *Aux = HeadNode;
    while(Aux->Col != Col){
        Aux = Aux->RightNodeMatrix;
    }
    if (Aux->DownNodeMatrix == NULL){
        Aux->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = Aux;
    }else{
        while(Aux->DownNodeMatrix != NULL && Aux->DownNodeMatrix->Fil < Fil){
            Aux = Aux->DownNodeMatrix;
        }
        if(Aux->DownNodeMatrix == NULL){
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
        }else if (Aux->DownNodeMatrix != NULL){
            NodeRotateX *Aux2 = Aux->DownNodeMatrix;
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
            New_Node->DownNodeMatrix = Aux2;
            Aux2->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationX::AddMatrixHeaderC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeRotateX *New_Node = new NodeRotateX(Col, Fil, ColorR, ColorG,ColorB);
    NodeRotateX * Aux = HeadNode;
    while(Aux->Fil != Fil){
        Aux = Aux->DownNodeMatrix;
    }
    if (Aux->RightNodeMatrix == NULL){
        Aux->RightNodeMatrix = New_Node;
        New_Node->LeftNodeMatrix = Aux;
    }else{
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col > Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL){
            NodeRotateX *AuxHeader = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxHeader;
            AuxHeader->LeftNodeMatrix = New_Node;
        }
    }
}

string MatrixRotationX::DotMatirx2C(string Dot) {
    NodeRotateX *temp = HeadNode->RightNodeMatrix;
    NodeRotateX *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    // headers Y
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \" , group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeRotateX *aux2 = temp2;
        while (aux2->RightNodeMatrix != NULL){
            if(aux2->Col == 0){
                //Dot += "Y"+ to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                //Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
                Dot += "Y"+ to_string(aux2->Fil) + "-> n" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; n" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }else{
                Dot +="n"+ to_string(aux2->Col) + "_" + to_string(aux2->Fil) + "-> n" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; n" + to_string(aux2->Col) + "_" + to_string(aux2->Fil)+ "; n" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }
            aux2 = aux2->RightNodeMatrix;
        }
        temp2 = temp2->DownNodeMatrix;
    }
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \" ,group =" + to_string(0) + "];\n";
    while (temp2->RightNodeMatrix != NULL){
        if(temp2->Col==0) {
            Dot +="Y" + to_string(temp2->Fil) + "-> n" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; Y" + to_string(temp2->Fil) + "; n" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }else{
            Dot +="n"+ to_string(temp2->Col) + "_" + to_string(temp2->Fil) + "-> n" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; n" + to_string(temp2->Col) + "_" + to_string(temp2->Fil)+ "; n" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }
        temp2 = temp2->RightNodeMatrix;
    }
    Dot +="Terminal -> X" + to_string(temp->Col) +  " [dir=both];\n";
    while(temp->RightNodeMatrix!=NULL){
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \"  , group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeRotateX *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            Dot +="n"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(aux->DownNodeMatrix->ColorR) + "," + to_string(aux->DownNodeMatrix->ColorG) + "," + to_string(aux->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "->n" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="n"+ to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> n" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \" , group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";

    return Dot;
}

