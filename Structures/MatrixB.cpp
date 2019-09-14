//
// Created by edgarh on 6/09/19.
//

#include "MatrixB.h"
#include <iostream>
#include <fstream>

using  namespace std;
/*
NodeMatrixB *MatrixB::CreateNode(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeMatrixB *New_Node = new NodeMatrixB;
    New_Node->Col = Col;
    New_Node->Fil = Fil;
    New_Node->ColorR = ColorR;
    New_Node->ColorG = ColorG;
    New_Node->ColorR = ColorB;
    New_Node->RightNodeMatrix = NULL;
    New_Node->LeftNodeMatrix = NULL;
    New_Node->UpNodeMatrix = NULL;
    New_Node->DownNodeMatrix = NULL;
    return  New_Node;
}
void MatrixB::AddMatrix(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    //NodeMatrixB * New_Node = CreateNode(Col, Fil, ColorR, ColorG, ColorB);
    CreateCabecera(Col);
    CreateHeaders(Fil);
    AddMatrixCabecera(Col,Fil,ColorR,ColorG,ColorB);
    AddMatrixHeader(Col,Fil,ColorR,ColorG,ColorB);

}
void MatrixB::CreateCabecera(int Col) {
    if (FirstNode->RightNodeMatrix == NULL){
        NodeMatrixB *Aux = CreateNode(Col,0,0,0,0);
        FirstNode->RightNodeMatrix = Aux;
        Aux->LeftNodeMatrix = FirstNode;
    }else{
        NodeMatrixB *Aux = FirstNode;
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col < Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            NodeMatrixB *New_Node = CreateNode(Col,0,0,0,0);
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col != Col){
            NodeMatrixB *New_Node = CreateNode(Col,0,0,0,0);
            NodeMatrixB *AuxRight = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxRight;
            AuxRight->LeftNodeMatrix = New_Node;
        }
    }
}

void MatrixB::CreateHeaders(int Fil) {
    if (FirstNode->DownNodeMatrix == NULL){
        NodeMatrixB * New_Node = CreateNode(0,Fil,0,0,0);
        FirstNode->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = FirstNode;
    }else{
        NodeMatrixB *AuxHeaders = FirstNode;
        while(AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil < Fil){
            AuxHeaders = AuxHeaders->DownNodeMatrix;
        }
        if(AuxHeaders->DownNodeMatrix == NULL){
            NodeMatrixB * New_Node = CreateNode(0,Fil,0,0,0);
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
        }else{
            NodeMatrixB * New_Node = CreateNode(0,Fil,0,0,0);
            NodeMatrixB * AuxUp = AuxHeaders->DownNodeMatrix;
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
            New_Node->DownNodeMatrix = AuxUp;
            AuxUp->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixB::AddMatrixCabecera(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeMatrixB *New_Node = CreateNode(Col, Fil, ColorR,ColorG,ColorB);
    NodeMatrixB *Aux = FirstNode;
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
            NodeMatrixB *Aux2 = Aux->DownNodeMatrix;
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
            New_Node->DownNodeMatrix = Aux2;
            Aux2->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixB::AddMatrixHeader(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeMatrixB *New_Node = CreateNode(Col, Fil, ColorR, ColorG,ColorB);
    NodeMatrixB * Aux = FirstNode;
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
            NodeMatrixB *AuxHeader = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxHeader;
            AuxHeader->LeftNodeMatrix = New_Node;
        }
    }
}

void MatrixB::GraficarMatrix() {
    string a = "digraph G {";
    ofstream fd4("Matrix.dot");
    a += DotMatrix(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Matrix \n";
    system("dot -Tpng Matrix.dot -o Matrix.png");
}

string MatrixB::DotMatrix(string Dot) {
    NodeMatrixB *AuxRigth = FirstNode->RightNodeMatrix;
    NodeMatrixB *AuxDown = FirstNode->DownNodeMatrix;
    Dot +="digraph{\n";
    Dot +="node [shape=box]\n";
    Dot +="graph[nodesep = 0.5];\n";
    Dot += "Terminal[ label = \"Matrix\", width = 1.5, group = 0 ];\n";
    Dot +="e0[ shape = point, width = 0 ]\n";
    Dot +="e1[ shape = point, width = 0 ]\n";
    // HEADERS
    Dot += "Terminal -> Y" + to_string(AuxDown->Fil) +  " [dir=both];\n";
    while(AuxDown->DownNodeMatrix !=NULL){
        Dot += "Y"+ to_string(AuxDown->Fil) + "[label = \"" + "Y" + to_string(AuxDown->Fil) + " \"   width = 1.5 , group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(AuxDown->Fil) + "-> Y" + to_string(AuxDown->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeMatrixB *AuxTemp = AuxDown;
        while (AuxTemp->RightNodeMatrix != NULL){
            if(AuxTemp->Col==0){
                Dot += "Y"+ to_string(AuxTemp->Fil) + "-> X" + to_string(AuxTemp->RightNodeMatrix->Col) + "_" + to_string(AuxTemp->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; Y" + to_string(AuxDown->Fil)+ "; X" + to_string(AuxTemp->RightNodeMatrix->Col) + "_" + to_string(AuxTemp->RightNodeMatrix->Fil) + " }\n";
            }else{
                Dot += "X"+ to_string(AuxTemp->Col) +"_"+ to_string(AuxTemp->Fil) + "-> X" + to_string(AuxTemp->RightNodeMatrix->Col) + "" + to_string(AuxTemp->RightNodeMatrix->Fil) + "[dir=both];\n";
                Dot +="{ rank = same; X" + to_string(AuxTemp->Col) + to_string(AuxTemp->Fil)+ "; X" + to_string(AuxTemp->RightNodeMatrix->Col) + "" + to_string(AuxTemp->RightNodeMatrix->Fil) + " }\n";
            }
            AuxTemp = AuxTemp->RightNodeMatrix;
        }
        AuxDown = AuxDown->DownNodeMatrix;
    }
    Dot +="Y"+ to_string(AuxDown->Fil) + "[label = \"" + "Y" +  to_string(AuxDown->Fil) + " \"   width = 1.5, group =" + to_string(0) + "];\n";
    while (AuxDown->RightNodeMatrix != NULL){
        if(AuxDown->Col==0) {
            Dot += "Y" + to_string(AuxDown->Fil) + "-> X" + to_string(AuxDown->RightNodeMatrix->Col) + "_" + to_string(AuxDown->Fil) + "[dir=both];\n";
            Dot += "{ rank = same; Y" + to_string(AuxDown->Fil) + "; X" + to_string(AuxDown->RightNodeMatrix->Col) + "_" + to_string(AuxDown->Fil) + " }\n";
        }else{
            Dot += "X"+ to_string(AuxDown->Col) + "" + to_string(AuxDown->Fil) + "-> X" + to_string(AuxDown->RightNodeMatrix->Col) + "" + to_string(AuxDown->Fil) + "[dir=both];\n";
            Dot += "{ rank = same; X" + to_string(AuxDown->Col) + "" + to_string(AuxDown->Fil)+ "; X" + to_string(AuxDown->RightNodeMatrix->Col) + "" + to_string(AuxDown->Fil) + " }\n";
        }
        AuxDown = AuxDown->RightNodeMatrix;
    }
    Dot += "Terminal -> X" + to_string(AuxRigth->Col) +  " [dir=both];\n";
    while(AuxRigth->RightNodeMatrix !=NULL){
        Dot += "X"+ to_string(AuxRigth->Col) + "[label = \"" + "X" +to_string(AuxRigth->Col) + " \"   width = 1.5, group =" + to_string(AuxRigth->Col) + "];\n";
        Dot += "X"+ to_string(AuxRigth->Col) + "-> X" + to_string(AuxRigth->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot += "{ rank = same; Terminal; X" + to_string(AuxRigth->Col)+ " }\n";
        NodeMatrixB * Aux2Right = AuxRigth;
        while (Aux2Right->DownNodeMatrix != NULL){
            Dot += "X"+ to_string(Aux2Right->Col) + "_" + to_string(Aux2Right->DownNodeMatrix->Fil) + "[label = \"" + to_string(Aux2Right->DownNodeMatrix->ColorR) + "," + to_string(Aux2Right->DownNodeMatrix->ColorG) + "," + to_string(Aux2Right->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(Aux2Right->Col) + "];\n";
            if(Aux2Right ->Fil==0){
                Dot += "X"+ to_string(Aux2Right->Col) + "-> X" + to_string(Aux2Right->Col) + "_" + to_string(Aux2Right->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot += "X"+ to_string(Aux2Right->Col) + "" + to_string(Aux2Right->Fil) + "-> X" + to_string(Aux2Right->Col) + "" + to_string(Aux2Right->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            Aux2Right = Aux2Right->DownNodeMatrix;
        }
        AuxRigth = AuxRigth->RightNodeMatrix;
    }
    Dot += "X"+ to_string(AuxRigth->Col) + "[label = \"" + "X" + to_string(AuxRigth->Col) + " \"   width = 1.5 , group =" + to_string(AuxRigth->Col) + "];\n";
    Dot += "{ rank = same; Terminal; X" + to_string(AuxRigth->Col)+ " }\n";
    while (AuxRigth->DownNodeMatrix != NULL){
        if(AuxRigth->Fil==0){
            Dot += "X"+ to_string(AuxRigth->Col) + "_" + to_string(AuxRigth->DownNodeMatrix->Fil)  + "[label = \"" + to_string(AuxRigth->DownNodeMatrix->ColorR) + "," + to_string(AuxRigth->DownNodeMatrix->ColorG) + "," + to_string(AuxRigth->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(AuxRigth->Col) + "];\n";
            Dot += "X"+ to_string(AuxRigth->Col) + "-> X" + to_string(AuxRigth->Col) + "_" + to_string(AuxRigth->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot += "X"+ to_string(AuxRigth->Col) + "_" + to_string(AuxRigth->DownNodeMatrix->Fil)  + "[label = \"" + to_string(AuxRigth->DownNodeMatrix->ColorR) + "," + to_string(AuxRigth->DownNodeMatrix->ColorG) + "," + to_string(AuxRigth->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(AuxRigth->Col) + "];\n";
            Dot += "X"+ to_string(AuxRigth->Col) + "" + to_string(AuxRigth->Fil) + "-> X" + to_string(AuxRigth->Col) + "" + to_string(AuxRigth->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        AuxRigth = AuxRigth->DownNodeMatrix;
    }
    Dot +="}";
    return  Dot;
}

string MatrixB::DotMatirx2(string Dot) {
    NodeMatrixB *temp = FirstNode->RightNodeMatrix;
    NodeMatrixB *temp2 = FirstNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Mt[ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    // headers Y
    Dot += "Mt -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \"   width = 1.5 style = filled, group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeMatrixB *aux2 = temp2;
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
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \"   width = 1.5 style = filled,group =" + to_string(0) + "];\n";
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
    Dot +="Mt -> X" + to_string(temp->Col) +  " [dir=both];\n";
    while(temp->RightNodeMatrix!=NULL){
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Mt; X" + to_string(temp->Col)+ " }\n";
        NodeMatrixB *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(aux->DownNodeMatrix->ColorR) + "," + to_string(aux->DownNodeMatrix->ColorG) + "," + to_string(aux->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Mt; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";

    return Dot;
}
*/
//*****************************************CLASE**********************************///

void MatrixB::AddMatrixC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    //NodeMatrixB * New_Node = CreateNode(Col, Fil, ColorR, ColorG, ColorB);
    CreateCabeceraC(Col);
    CreateHeadersC(Fil);
    AddMatrixCabeceraC(Col,Fil,ColorR,ColorG,ColorB);
    AddMatrixHeaderC(Col,Fil,ColorR,ColorG,ColorB);

}
void MatrixB::CreateCabeceraC(int Col) {
    if (HeadNode->RightNodeMatrix == NULL){
        //NodeMatrixB2 *Aux = new NodeMatrixB2(Col,0,0,0,0);
        NodeMatrixB2 *Aux1 = new NodeMatrixB2(Col,0,0,0,0);
        HeadNode->RightNodeMatrix = Aux1;
        Aux1->LeftNodeMatrix = HeadNode;
    }else{
        NodeMatrixB2 *Aux = HeadNode;
        while(Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col < Col){
            Aux = Aux->RightNodeMatrix;
        }
        if (Aux->RightNodeMatrix == NULL){
            NodeMatrixB2 *New_Node = new NodeMatrixB2(Col,0,0,0,0);
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
        }else if (Aux->RightNodeMatrix != NULL && Aux->RightNodeMatrix->Col != Col){
            NodeMatrixB2 *New_Node =  new NodeMatrixB2(Col,0,0,0,0);
            NodeMatrixB2 *AuxRight = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxRight;
            AuxRight->LeftNodeMatrix = New_Node;
        }
    }
}

void MatrixB::CreateHeadersC(int Fil) {
    if (HeadNode->DownNodeMatrix == NULL){
        NodeMatrixB2 * New_Node = new NodeMatrixB2(0,Fil,0,0,0);
        HeadNode->DownNodeMatrix = New_Node;
        New_Node->UpNodeMatrix = HeadNode;
    }else{
        NodeMatrixB2 *AuxHeaders = HeadNode;
        while(AuxHeaders->DownNodeMatrix != NULL && AuxHeaders->DownNodeMatrix->Fil < Fil){
            AuxHeaders = AuxHeaders->DownNodeMatrix;
        }
        if(AuxHeaders->DownNodeMatrix == NULL){
            NodeMatrixB2 * New_Node = new NodeMatrixB2(0,Fil,0,0,0);
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
        }else{
            NodeMatrixB2 * New_Node = new NodeMatrixB2(0,Fil,0,0,0);
            NodeMatrixB2 * AuxUp = AuxHeaders->DownNodeMatrix;
            AuxHeaders->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = AuxHeaders;
            New_Node->DownNodeMatrix = AuxUp;
            AuxUp->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixB::AddMatrixCabeceraC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeMatrixB2 *New_Node = new NodeMatrixB2(Col, Fil, ColorR,ColorG,ColorB);
    NodeMatrixB2 *Aux = HeadNode;
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
            NodeMatrixB2 *Aux2 = Aux->DownNodeMatrix;
            Aux->DownNodeMatrix = New_Node;
            New_Node->UpNodeMatrix = Aux;
            New_Node->DownNodeMatrix = Aux2;
            Aux2->UpNodeMatrix = New_Node;
        }
    }
}

void MatrixB::AddMatrixHeaderC(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NodeMatrixB2 *New_Node = new NodeMatrixB2(Col, Fil, ColorR, ColorG,ColorB);
    NodeMatrixB2 * Aux = HeadNode;
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
            NodeMatrixB2 *AuxHeader = Aux->RightNodeMatrix;
            Aux->RightNodeMatrix = New_Node;
            New_Node->LeftNodeMatrix = Aux;
            New_Node->RightNodeMatrix = AuxHeader;
            AuxHeader->LeftNodeMatrix = New_Node;
        }
    }
}
string MatrixB::DotMatirx2C(string Dot) {
    NodeMatrixB2 *temp = HeadNode->RightNodeMatrix;
    NodeMatrixB2 *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    // headers Y
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \"   width = 1.5 style = filled, group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeMatrixB2 *aux2 = temp2;
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
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \"   width = 1.5 style = filled,group =" + to_string(0) + "];\n";
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
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeMatrixB2 *aux = temp;
        while (aux->DownNodeMatrix != NULL){
            Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[label = \"" + to_string(aux->DownNodeMatrix->ColorR) + "," + to_string(aux->DownNodeMatrix->ColorG) + "," + to_string(aux->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(aux->Col) + "];\n";
            if(aux->Fil==0){
                Dot +="X"+ to_string(aux->Col) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }else{
                Dot +="X"+ to_string(aux->Col) + "_" + to_string(aux->Fil) + "-> X" + to_string(aux->Col) + "_" + to_string(aux->DownNodeMatrix->Fil) + "[dir=both];\n";
            }
            aux = aux->DownNodeMatrix;
        }
        temp = temp->RightNodeMatrix;
    }
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
    Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
    while (temp->DownNodeMatrix != NULL){
        if(temp->Fil==0){
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }else{
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil)  + "[label = \"" + to_string(temp->DownNodeMatrix->ColorR) + "," + to_string(temp->DownNodeMatrix->ColorG) + "," + to_string(temp->DownNodeMatrix->ColorB) + " \"   width = 1.5, group =" + to_string(temp->Col) + "];\n";
            Dot +="X"+ to_string(temp->Col) + "_" + to_string(temp->Fil) + "-> X" + to_string(temp->Col) + "_" + to_string(temp->DownNodeMatrix->Fil) + "[dir=both];\n";
        }
        temp = temp->DownNodeMatrix;
    }
    Dot +="}";

    return Dot;
}


string MatrixB::DotGrayScape(string Dot) {
    NodeMatrixB2 *temp = HeadNode->RightNodeMatrix;
    NodeMatrixB2 *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph Sparse_Matrix{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \"   width = 1.5 style = filled, group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeMatrixB2 *aux2 = temp2;
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
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \"   width = 1.5 style = filled,group =" + to_string(0) + "];\n";
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
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeMatrixB2 *aux = temp;
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
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
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

string MatrixB::DotNegative(string Dot) {
    NodeMatrixB2 *temp = HeadNode->RightNodeMatrix;
    NodeMatrixB2 *temp2 = HeadNode->DownNodeMatrix;
    Dot += "digraph{\n";
    Dot += "node [shape=box]\n";
    Dot += "graph[nodesep = 0.5];\n";
    Dot += "Terminal [ label = \"Matrix\", width = 1.5, style = filled, group = 0 ];\n";
    Dot += "e0[ shape = point, width = 0 ]\n";
    Dot += "e1[ shape = point, width = 0 ]\n";
    Dot += "Terminal -> Y" + to_string(temp2->Fil) +  " [dir=both];\n";
    while(temp2->DownNodeMatrix!=NULL){
        Dot += "Y"+ to_string(temp2->Fil) + "[label = \"" + "F" + to_string(temp2->Fil) + " \"   width = 1.5 style = filled, group =" + to_string(0) + "];\n";
        Dot += "Y"+ to_string(temp2->Fil) + "-> Y" + to_string(temp2->DownNodeMatrix->Fil) + "[dir=both];\n";
        NodeMatrixB2 *aux2 = temp2;
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
    Dot +="Y"+ to_string(temp2->Fil) + "[label = \"" + "F" +  to_string(temp2->Fil) + " \"   width = 1.5 style = filled,group =" + to_string(0) + "];\n";
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
        Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" +to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
        Dot +="X"+ to_string(temp->Col) + "-> X" + to_string(temp->RightNodeMatrix->Col) + "[dir=both];\n";
        Dot +="{ rank = same; Terminal; X" + to_string(temp->Col)+ " }\n";
        NodeMatrixB2 *aux = temp;
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
    Dot +="X"+ to_string(temp->Col) + "[label = \"" + "C" + to_string(temp->Col) + " \"   width = 1.5 style = filled, group =" + to_string(temp->Col) + "];\n";
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