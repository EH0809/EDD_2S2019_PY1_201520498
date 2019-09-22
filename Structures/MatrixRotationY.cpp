//
// Created by edgarh on 14/09/19.
//

#include "MatrixRotationY.h"
#include <iostream>
#include <fstream>

using  namespace std;

void MatrixRotationY::AddMatrixC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    CreateCabeceraC(Col);
    CreateHeadersC(Fil);
    AddMatrixCabeceraC(Col,Fil,ColorR,ColorG,ColorB);
    AddMatrixHeaderC(Col,Fil,ColorR,ColorG,ColorB);

}

void MatrixRotationY::CreateCabeceraC(int Col) {
    if (HeadNode->RightNodeMatrix == NULL){
        NodeRotateY *Aux1 = new NodeRotateY(Col,0,0,0,0);
        HeadNode->RightNodeMatrix = Aux1;
        Aux1->LeftNodeMatrix = HeadNode;
    }else{
        NodeRotateY *Aux = HeadNode;
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col < Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            NodeRotateY *New_Node = new NodeRotateY(Col,0,0,0,0);
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col != Col){
            NodeRotateY *New_Node =  new NodeRotateY(Col,0,0,0,0);
            NodeRotateY *AuxRight = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxRight;
            AuxRight->LeftNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationY::CreateHeadersC(int Fil) {
    if (HeadNode->DownNodeMatrix == NULL){
        NodeRotateY * New_Node = new NodeRotateY(0,Fil,0,0,0);
        HeadNode->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = HeadNode;
    }else{
        NodeRotateY *AuxHeaders = HeadNode;
        while(AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil > Fil){
            AuxHeaders = AuxHeaders->DownNodeMatrix;
        }
        if(AuxHeaders->DownNodeMatrix == NULL){
            NodeRotateY * New_Node = new NodeRotateY(0,Fil,0,0,0);
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
        }else if (AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil != Fil){
            NodeRotateY * New_Node = new NodeRotateY(0,Fil,0,0,0);
            NodeRotateY * AuxUp = AuxHeaders->DownNodeMatrix;
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
            New_Node->DownNodeMatrix = AuxUp;
            AuxUp->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationY::AddMatrixCabeceraC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeRotateY *New_Node = new NodeRotateY(Col, Fil, ColorR,ColorG,ColorB);
    NodeRotateY *Aux = HeadNode;
    while(Aux->Col != Col){
        Aux = Aux->RightNodeMatrix;
    }
    if (Aux->DownNodeMatrix == NULL){
        Aux->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = Aux;
    }else{
        while(Aux->DownNodeMatrix != NULL && Aux->DownNodeMatrix->Fil > Fil){
            Aux = Aux->DownNodeMatrix;
        }
        if(Aux->DownNodeMatrix == NULL){
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
        }else if (Aux->DownNodeMatrix != NULL){
            NodeRotateY *Aux2 = Aux->DownNodeMatrix;
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
            New_Node->DownNodeMatrix = Aux2;
            Aux2->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixRotationY::AddMatrixHeaderC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeRotateY *New_Node = new NodeRotateY(Col, Fil, ColorR, ColorG,ColorB);
    NodeRotateY * Aux = HeadNode;
    while(Aux->Fil != Fil){
        Aux = Aux->DownNodeMatrix;
    }
    if (Aux->RightNodeMatrix == NULL){
        Aux->RightNodeMatrix = New_Node;
        New_Node->LeftNodeMatrix = Aux;
    }else{
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col < Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL){
            NodeRotateY *AuxHeader = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxHeader;
            AuxHeader->LeftNodeMatrix = New_Node;
        }
    }
}

string MatrixRotationY::DotMatirx2C(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
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
        NodeRotateY *aux2 = temp2;
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
        NodeRotateY *aux = temp;
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


string MatrixRotationY::DotGrayScape(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
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
        NodeRotateY *aux2 = temp2;
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
        NodeRotateY *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            int R = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            int G = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            int B = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            Dot +="n"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
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
        int R = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
        int G = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
        int B = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
        if(temp->Fil==0){
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="n"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";

    return Dot;
}

string MatrixRotationY::DotNegative(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    // headers Y
    Dot += "Terminal -> Y" + to_string(temp2->Fil) + " [dir=both];\n";
    while (temp2->DownNodeMatrix != NULL) {
        Dot += "Y" + to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \" , group =" +
               to_string(0) + "];\n";
        Dot += "Y" + to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeRotateY *aux2 = temp2;
        while (aux2->RightNodeMatrix != NULL) {
            if (aux2->Col == 0) {
                //Dot += "Y"+ to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                //Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
                Dot += "Y" + to_string(aux2->Fil) + "-> n" + to_string(aux2->RightNodeMatrix->Col) + "_" +
                       to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot += "{ rank = same; Y" + to_string(temp2->Fil) + "; n" + to_string(aux2->RightNodeMatrix->Col) +
                       "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            } else {
                Dot += "n" + to_string(aux2->Col) + "_" + to_string(aux2->Fil) + "-> n" +
                       to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) +
                       "[dir=both];\n";
                Dot += "{ rank = same; n" + to_string(aux2->Col) + "_" + to_string(aux2->Fil) + "; n" +
                       to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }
            aux2 = aux2->RightNodeMatrix;
        }
        temp2 = temp2->DownNodeMatrix;
    }
    Dot += "Y" + to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \" ,group =" + to_string(0) +
           "];\n";
    while (temp2->RightNodeMatrix != NULL) {
        if (temp2->Col == 0) {
            Dot += "Y" + to_string(temp2->Fil) + "-> n" + to_string(temp2->RightNodeMatrix->Col) + "_" +
                   to_string(temp2->Fil) + "[dir=both];\n";
            Dot += "{ rank = same; Y" + to_string(temp2->Fil) + "; n" + to_string(temp2->RightNodeMatrix->Col) + "_" +
                   to_string(temp2->Fil) + " }\n";
        } else {
            Dot += "n" + to_string(temp2->Col) + "_" + to_string(temp2->Fil) + "-> n" +
                   to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot += "{ rank = same; n" + to_string(temp2->Col) + "_" + to_string(temp2->Fil) + "; n" +
                   to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }
        temp2 = temp2->RightNodeMatrix;
    }
    Dot += "Terminal -> X" + to_string(temp->Col) + " [dir=both];\n";
    while (temp->RightNodeMatrix != NULL) {
        Dot += "X" + to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \"  , group =" +
               to_string(temp->Col) + "];\n";
        Dot += "X" + to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot += "{ rank = same; Terminal; X" + to_string(temp->Col) + " }\n";
        NodeRotateY *aux = temp;
        while (aux->DownNodeMatrix != NULL) {
            int R = (255 - aux->DownNodeMatrix->ColorR);
            int G = (255 - aux->DownNodeMatrix->ColorG);
            int B = (255 - aux->DownNodeMatrix->ColorB);
            Dot += "n" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" +
                   to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" +
                   to_string(aux->Col) + "];\n";
            if (aux->Fil == 0) {
                Dot += "X" + to_string(aux->Col) + "->n" + to_string(aux->Col) + "_" +
                       to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            } else {
                Dot += "n" + to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> n" + to_string(aux->Col) + "_" +
                       to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot += "X" + to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \" , group =" +
           to_string(temp->Col) + "];\n";
    Dot += "{ rank = same; Terminal; X" + to_string(temp->Col) + " }\n";
    while (temp->DownNodeMatrix != NULL) {
        int R = (255 - temp->DownNodeMatrix->ColorR);
        int G = (255 - temp->DownNodeMatrix->ColorG);
        int B = (255 - temp->DownNodeMatrix->ColorB);
        if (temp->Fil == 0) {
            Dot += "n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[label = \"" +
                   to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" +
                   to_string(temp->Col) + "];\n";
            Dot += "X" + to_string(temp->Col) + "-> n" + to_string(temp->Col) + "_" +
                   to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        } else {
            Dot += "n" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[label = \"" +
                   to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" +
                   to_string(temp->Col) + "];\n";
            Dot += "n" + to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> n" + to_string(temp->Col) + "_" +
                   to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot += "}";

    return Dot;

}

void MatrixRotationY::GraficarCompleta() {
    string a ="";
    ofstream fd4("Completa.dot");
    //a += Temp->PunteroMatrix.Dot3(a);
    a += DotMatirx2C(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN  \n";
    string ab = "dot -Tpng Completa.dot -o Completa.png";
    const char *command = ab.c_str();
    system(command);
}




/*
string MatrixRotationY::DotMatirx2C(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    // headers Y
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix != NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "Row: " + to_string(temp2->Fil) + " \"   width = 1.5 style = filled, group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeRotateY *aux2 = temp2;
        while (aux2->RightNodeMatrix != NULL){
            if(aux2->Col == 0){
                Dot += "Y"+ to_string(aux2->Fil) + "-> N" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; N" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }else{
                Dot +="N"+ to_string(aux2->Col) + "" + to_string(aux2->Fil) + "-> N" + to_string(aux2->RightNodeMatrix->Col) + "" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; N" + to_string(aux2->Col) + "" + to_string(aux2->Fil)+ "; N" + to_string(aux2->RightNodeMatrix->Col) + "" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }
            aux2 = aux2->RightNodeMatrix;
        }
        temp2 = temp2->DownNodeMatrix;
    }
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "Row: " +  to_string(temp2->Fil) + " \"   width = 1.5 style = filled,group =" + to_string(0) + "];\n";
    while (temp2->RightNodeMatrix != NULL){
        if(temp2->Col==0) {
            Dot +="Y" + to_string(temp2->Fil) + "-> N" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; Y" + to_string(temp2->Fil) + "; N" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }else{
            Dot +="N"+ to_string(temp2->Col) + "" + to_string(temp2->Fil) + "-> N" + to_string(temp2->RightNodeMatrix->Col) + "" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; N" + to_string(temp2->Col) + "" + to_string(temp2->Fil)+ "; N" + to_string(temp2->RightNodeMatrix->Col) + "" + to_string(temp2->Fil) + " }\n";
        }
        temp2 = temp2->RightNodeMatrix;
    }
    Dot +="Terminal -> X" + to_string(temp->Col) +  " [dir=both];\n";
    while(temp->RightNodeMatrix!=NULL){
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "Col: " +to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeRotateY *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            Dot +="N"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(aux->DownNodeMatrix->ColorR) + "," + to_string(aux->DownNodeMatrix->ColorG) + "," + to_string(aux->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "-> N" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="N"+ to_string(aux->Col) + "" + to_string(aux->Fil) + "-> N" + to_string(aux->Col) + "" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "Col: " + to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            Dot +="N"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> N" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot +="N"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="N"+ to_string(temp->Col) + "" + to_string(temp->Fil) + "-> N" + to_string(temp->Col) + "" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";

    return Dot;
}

string MatrixRotationY::DotGrayScape(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \" , group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeRotateY *aux2 = temp2;
        while (aux2->RightNodeMatrix != NULL){
            if(aux2->Col==0){
                Dot += "Y"+ to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }else{
                Dot +="X"+ to_string(aux2->Col) + "_" + to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; X" + to_string(aux2->Col) + "" + to_string(aux2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }
            aux2 = aux2->RightNodeMatrix;
        }
        temp2 = temp2->DownNodeMatrix;
    }
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \" ,group =" + to_string(0) + "];\n";
    while (temp2->RightNodeMatrix != NULL){
        if(temp2->Col==0) {
            Dot +="Y" + to_string(temp2->Fil) + "-> X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; Y" + to_string(temp2->Fil) + "; X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }else{
            Dot +="X"+ to_string(temp2->Col) + "_" + to_string(temp2->Fil) + "-> X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; X" + to_string(temp2->Col) + "_" + to_string(temp2->Fil)+ "; X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }
        temp2 = temp2->RightNodeMatrix;
    }
    Dot +="Terminal -> X" + to_string(temp->Col) +  " [dir=both];\n";
    while(temp->RightNodeMatrix!=NULL){
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \" , group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeRotateY *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            int R = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            int G = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            int B = (aux->DownNodeMatrix->ColorR *0.3)+(aux->DownNodeMatrix->ColorG *0.59)+(aux->DownNodeMatrix->ColorB *0.11);
            Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \", group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            int R = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            int G = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            int B = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            int R = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            int G = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            int B = (temp->DownNodeMatrix->ColorR *0.3)+(temp->DownNodeMatrix->ColorG *0.59)+(temp->DownNodeMatrix->ColorB *0.11);
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";
    return Dot;
}

string MatrixRotationY::DotNegative(string Dot) {
    NodeRotateY *temp = HeadNode->RightNodeMatrix;
    NodeRotateY *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \", group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeRotateY *aux2 = temp2;
        while (aux2->RightNodeMatrix != NULL){
            if(aux2->Col==0){
                Dot += "Y"+ to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot += "{ rank = same; Y" + to_string(temp2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }else{
                Dot +="X"+ to_string(aux2->Col) + "_" + to_string(aux2->Fil) + "-> X" + to_string(aux2->RightNodeMatrix->Col) + "_" + to_string(aux2->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; X" + to_string(aux2->Col) + "" + to_string(aux2->Fil)+ "; X" + to_string(aux2->RightNodeMatrix->Col) + "" + to_string(aux2->RightNodeMatrix->Fil) + " }\n";
            }
            aux2 = aux2->RightNodeMatrix;
        }
        temp2 = temp2->DownNodeMatrix;
    }
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \",group =" + to_string(0) + "];\n";
    while (temp2->RightNodeMatrix != NULL){
        if(temp2->Col==0) {
            Dot +="Y" + to_string(temp2->Fil) + "-> X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; Y" + to_string(temp2->Fil) + "; X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }else{
            Dot +="X"+ to_string(temp2->Col) + "_" + to_string(temp2->Fil) + "-> X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + "[dir=both];\n";
            Dot +="{ rank = same; X" + to_string(temp2->Col) + "_" + to_string(temp2->Fil)+ "; X" + to_string(temp2->RightNodeMatrix->Col) + "_" + to_string(temp2->Fil) + " }\n";
        }
        temp2 = temp2->RightNodeMatrix;
    }
    Dot +="Terminal -> X" + to_string(temp->Col) +  " [dir=both];\n";
    while(temp->RightNodeMatrix!=NULL){
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \", group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeRotateY *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            int R = (255-aux->DownNodeMatrix->ColorR);
            int G = (255- aux->DownNodeMatrix->ColorG);
            int B = (255- aux->DownNodeMatrix->ColorB);
            Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \", group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            int R = (255- temp->DownNodeMatrix->ColorR);
            int G = (255- temp->DownNodeMatrix->ColorG);
            int B = (255- temp->DownNodeMatrix->ColorB);
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            int R = (255- temp->DownNodeMatrix->ColorR);
            int G = (255- temp->DownNodeMatrix->ColorG);
            int B = (255- temp->DownNodeMatrix->ColorB);
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(R) + "," + to_string(G) + "," + to_string(B) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";
    return Dot;
}
 */