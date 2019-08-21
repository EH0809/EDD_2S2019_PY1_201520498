#include <iostream>
#include "Structures/Lateral.h"
#include "Structures/Cabecera.h"
#include "Structures/HorizontalList.h"
#include "Structures/VerticalList.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>


using namespace std;

Cabecera LHeaders;
Lateral  LLaterales;
NodeMatrix Matrix;
VerticalList Vertical;
HorizontalList Horizontal;

/*
 * /////////TERMINAL
 *
 */
MatrixNode * NodeMatrix::Create_NodeMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB) {
    MatrixNode *New_Node = new MatrixNode;
    New_Node->ColMatrix = Header;
    New_Node->RowMatrix = Lateral;
    New_Node->ColorR = ColorR;
    New_Node->ColorG = ColorG;
    New_Node->ColorB = ColorB;
    return  New_Node;

}
void NodeMatrix::InsertMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB) {
    NodeHeader *Cabecera;
    NodeLateral *Laterales;
    MatrixNode *New_Node = Create_NodeMatrix(Header,Lateral,ColorR,ColorG,ColorB);
    if(!LHeaders.IsHeader(Header)){
        LHeaders.InsertHeader(Header);
    }
    if(!LLaterales.IsLateral(Lateral)){
        LLaterales.AddLateral(Lateral);
    }
    Cabecera = LHeaders.SearchHeader(Header);
    Laterales =LLaterales.SearchLateral(Lateral);
    Cabecera->Colum.AddLateral(New_Node);
    //Vertical.AddLateral((New_Node));
    Laterales->Fila.AddHorizontal(New_Node);
    //Horizontal.AddHorizontal(New_Node);
}

int NodeMatrix::Max_Headers() {
    NodeHeader *Cabe = LHeaders.EndHeader;
    return Cabe->Header;
}
int NodeMatrix::Max_Laterales() {
    NodeLateral *Late=LLaterales.EndLateral;
    return  Late->Lateral;
}

MatrixNode *NodeMatrix::IsNode(int Header, int Lateral) {
    NodeHeader *Cabecera = LHeaders.SearchHeader(Header);
    if (Cabecera->Header != -1){
        MatrixNode *Node = LHeaders.SearchHeader(Header)->Colum.FirstNodeCentralV;
        while(Node->RowMatrix != Lateral){
            if(Node->DownMatrix == NULL){
                return Create_NodeMatrix(-1,-1,-1,-1,-1);
            }
            Node = Node->DownMatrix;
        }
        return Node;
    }else{
        return Create_NodeMatrix(-1,-1,-1,-1,-1);
    }
}
MatrixNode *NodeMatrix::IsCoordinate(int Header, int Lateral) {
    NodeHeader *Cabe = LHeaders.SearchHeader(Header);
    cout<<"Esta Coordenad Existe";
    if(Cabe->Header != -1){
        MatrixNode *Node = LHeaders.SearchHeader(Header)->Colum.FirstNodeCentralV;
        while(Node->RowMatrix != Lateral){
            if(Node->DownMatrix == NULL){
                return Create_NodeMatrix(-1,-1,-1,-1,-1);
            }
            Node = Node->DownMatrix;
        }
    }else{
        return Create_NodeMatrix(-1,-1,-1,-1,-1);
    }
}

void  NodeMatrix::Graph() {
    string a = "";
    a ="digraph G { \n";
    ofstream fd4("Matrix.dot");
    a += Dot(a);
    fd4<<a;
    fd4.flush();
    fd4.close();
    cout<<" GENERANDO IMAGEN Matrix \n";
    system("dot -Tpng Matrix.dot -o Matrix.png");
}

string NodeMatrix::Dot(string dot) {
    string NameAnt,Enlaces ="",Nombres="";
    string grafo ="\n ranksep=.50; \nnode [shape=box];\n";
    string Rank="{ rank = same; ";
    NodeHeader *Cabecera = LHeaders.FirstHeader;
    NodeLateral *Lateral=LLaterales.FirstLateral;
    NameAnt = "Terminal";
    while(Cabecera != NULL){
        Enlaces += NameAnt +"->"+"X"+std::to_string(Cabecera->Header)+"\n";
        NameAnt = "X"+std::to_string(Cabecera->Header)+"\n";
        Enlaces += NameAnt +"-> n"+ std::to_string(Cabecera->Colum.FirstNodeCentralV->ColMatrix)+std::to_string(Vertical.FirstNodeCentralV->RowMatrix)+"; \n";
        Rank += NameAnt+";";
        Cabecera = Cabecera->NextHeader;
    }
    grafo += "\n" + Enlaces + "\n" + Nombres + "\n"+ Rank+"\n";
    grafo += "}";
    return grafo;
}

/*
 *
 * //////////////////////VERTICAL LIST
 */


bool VerticalList::IsEmpty() {
    return NULL == FirstNodeCentralV;
}

void VerticalList::AddLateral(MatrixNode *&Node) {
    if(IsEmpty()){
        FirstNodeCentralV = EndNodeCentralV = Node;
    }else{
        if (Node->RowMatrix < FirstNodeCentralV->RowMatrix){
            AddLateralStart(Node);
        }else if (Node->RowMatrix > FirstNodeCentralV->RowMatrix){
            AddLateralInEnd(Node);
        }else{
            AddLateralBetween(Node);
        }
    }
}
void VerticalList::AddLateralStart(MatrixNode *&Node) {
    FirstNodeCentralV->UpMatrix = Node;
    Node->DownMatrix = FirstNodeCentralV;
    FirstNodeCentralV = FirstNodeCentralV->UpMatrix;
}

void VerticalList::AddLateralInEnd(MatrixNode *&Node) {
    EndNodeCentralV->DownMatrix = Node;
    Node->UpMatrix = EndNodeCentralV;
    EndNodeCentralV = EndNodeCentralV->DownMatrix;
}

void VerticalList::AddLateralBetween(MatrixNode *&Node) {
    MatrixNode *Aux,*Aux2;
    Aux = FirstNodeCentralV;
    while(Aux->RowMatrix < Node->RowMatrix){
        Aux = Aux->DownMatrix;
    }
    Aux2 = Aux->UpMatrix;
    Aux2->DownMatrix =Node;
    Aux->UpMatrix = Node;
    Node->DownMatrix = Aux;
    Node->UpMatrix= Aux2;
}

void VerticalList::GoVerticalList() {
    if(!IsEmpty()){
        MatrixNode *Aux =FirstNodeCentralV;
        while(Aux != NULL){
            cout<<"Y = "+ Aux->RowMatrix;
            Aux = Aux->DownMatrix;
        }
    }
}


/*
 * ///////////////////////////HORIZONTAL LIST
 */

bool HorizontalList::IsEmpty() {
    return FirstNodeCentralH == NULL;
}


void HorizontalList::AddHorizontal(MatrixNode *&Node)  {
    if(IsEmpty()){
        FirstNodeCentralH = EndNodeCentralH = Node;
    }else{
        if (Node->ColMatrix < FirstNodeCentralH->ColMatrix){
            AddHorizontalStart(Node);
        }else if (Node->ColMatrix > FirstNodeCentralH->ColMatrix){
            AddHorizontalInEnd(Node);
        }else{
            AddHorizontalBetween(Node);
        }
    }
}
void HorizontalList::AddHorizontalStart(MatrixNode *&Node){
    FirstNodeCentralH->LeftMatrix = Node;
    Node->RightMatrix = FirstNodeCentralH;
    FirstNodeCentralH = FirstNodeCentralH->LeftMatrix;
}

void HorizontalList::AddHorizontalInEnd(MatrixNode *&Node) {
    EndNodeCentralH->RightMatrix = Node;
    Node->LeftMatrix = EndNodeCentralH;
    EndNodeCentralH = EndNodeCentralH->RightMatrix;
}

void HorizontalList::AddHorizontalBetween(MatrixNode *&Node) {
    MatrixNode *Aux,*Aux2;
    Aux = FirstNodeCentralH;
    while(Aux->ColMatrix < Node->ColMatrix){
        Aux = Aux->RightMatrix;
    }
    Aux2 = Aux->LeftMatrix;
    Aux2->RightMatrix =Node;
    Aux->LeftMatrix = Node;
    Node->RightMatrix = Aux;
    Node->LeftMatrix= Aux2;
}

void HorizontalList::GoHorizontalList() {
    if(!IsEmpty()){
        MatrixNode *Aux =FirstNodeCentralH;
        while(Aux != NULL){
            cout<<"X = "+ Aux->ColMatrix;
            Aux = Aux->RightMatrix;
        }
    }
}

/*
 *
 * ///////////////////////////CABECERAA//////////////////////////
 */

bool Cabecera::IsEmpty() {
    return  FirstHeader == NULL;
}
NodeHeader * Cabecera::New_Header(int Header){

    NodeHeader * New_Header = new NodeHeader;
    New_Header->Header = Header;
    New_Header->NextHeader = NULL;
    New_Header->PreviousHeader = NULL;
    return New_Header;
}

void Cabecera::InsertHeader(int Header){
    NodeHeader * New_Node = New_Header(Header);
    if (FirstHeader == NULL){
        FirstHeader = EndHeader = New_Node;
    }else{
        if (New_Node->Header < FirstHeader->Header){
            InsertHeaderStart(New_Node);
        }else if (New_Node->Header > EndHeader->Header){
            InsertHeaderInEnd(New_Node);
        }else{
            InsertHeaderBetween(New_Node);
        }
    }
}

void Cabecera::InsertHeader2(NodeHeader *Header) {
    NodeHeader * New_Node = Header;
    if (FirstHeader == NULL){
        FirstHeader = EndHeader = New_Node;
    }else{
        if (New_Node->Header < FirstHeader->Header){
            InsertHeaderStart(New_Node);
        }else if (New_Node->Header > EndHeader->Header){
            InsertHeaderInEnd(New_Node);
        }else{
            InsertHeaderBetween(New_Node);
        }
    }

}

void Cabecera::InsertHeaderStart(NodeHeader *Header){
    FirstHeader->PreviousHeader = Header;
    Header->NextHeader = FirstHeader;
    FirstHeader=FirstHeader->PreviousHeader;
}

void Cabecera::InsertHeaderInEnd(NodeHeader * New_Header){
    EndHeader->NextHeader = New_Header;
    New_Header->PreviousHeader=EndHeader;
    EndHeader=EndHeader->NextHeader;
}

void Cabecera::InsertHeaderBetween(NodeHeader *New_Header){
    NodeHeader *Aux  , *Aux2;
    Aux = FirstHeader;
    while(Aux->Header < New_Header->Header){
        Aux =Aux->NextHeader;
    }
    Aux2 = Aux->PreviousHeader;
    Aux2->NextHeader = New_Header;
    Aux->PreviousHeader = New_Header;
    New_Header->NextHeader = Aux;
    New_Header->PreviousHeader = Aux2;
}

void Cabecera::CoverHeader(){
    if (FirstHeader != NULL){
        NodeHeader *Aux = FirstHeader;
        while(Aux != NULL){
            cout<<"First Header"<<Aux->Header<<"\n";
            Aux = Aux->NextHeader;
        }
    }
}

bool Cabecera::IsHeader(int Header){
    if (FirstHeader == NULL){
        return false;
    }
    else{
        NodeHeader *Aux = FirstHeader;
        while(Aux != NULL){
            if(Aux->Header == Header){
                return true;
            }else if (Aux->NextHeader == NULL){
                return false;
            }
            Aux = Aux->NextHeader;
        }
        return false;
    }
}


NodeHeader *Cabecera::SearchHeader(int Header){
    if(IsHeader(Header)){
        NodeHeader *Aux =FirstHeader;
        while(Aux->Header != Header){
            Aux = Aux->NextHeader;
        }
        cout<<"Si se Encuentra Cabecera";
        return Aux;
    }else{
        cout<<"No se ha Encontrado";
        return New_Header(-1);
    }
}

void Cabecera::PrintHeader(){
    NodeHeader *Aux = FirstHeader;
    while(Aux != NULL){
        cout<<Aux->Header<<"->";
        Aux = Aux->NextHeader;
    }
}

string Cabecera::DotHeader(){
    NodeHeader *Aux = FirstHeader;
    string Dot = "";
    string Rank = "rank =\"same\" terminal;";
    Dot +="subgraph cluster_0 {  \n";
    Dot +=" rankdir=LR \n";
    Dot += "style=filled; \n";
    Dot += "color=lightgrey; \n";
    Dot += "node [style=filled,color=white]; \n";

    do{
        Dot += "n"+std::to_string(Aux->Header)+"[label=\"C: "+std::to_string(Aux->Header)+ "\"];\n";
        if (Aux->NextHeader != NULL){
            Rank += "n"+std::to_string(Aux->Header)+" ;";
            Dot += "n"+std::to_string(Aux->Header)+ " -> n"  +std::to_string(Aux->NextHeader->Header)+ ";\n";
            Dot += "n"+std::to_string(Aux->NextHeader->Header)+" -> n"+std::to_string(Aux->Header)+ ";\n";

        }
        Aux = Aux->NextHeader;
    }while(Aux != NULL && Aux != FirstHeader);
    Dot += Rank;
    Dot += "label = \"Headers \";\n";
    Dot += "} \n";
    return Dot;
}



/*//metodo laterales
 * /////////////////////////////LATERALES////////////////////////////
 *
 * */
bool Lateral::IsEmpty() {
    bool a = false;
    if (FirstLateral == NULL){
        a= true;
    }else{
        a=  false;
    }
    return a;
}


NodeLateral *Lateral::Create_Lateral(int Lateral){
    NodeLateral *New = new NodeLateral;
    New->Lateral = Lateral;
    New->NextLateral = NULL;
    New->PreviousLateral = NULL;
    return New;
}


void Lateral::AddLateral(int Lateral){
    NodeLateral *New_Lateral = Create_Lateral(Lateral);
    if (FirstLateral == NULL){
        FirstLateral = EndLateral = New_Lateral;
    }else{
        if(New_Lateral->Lateral < FirstLateral->Lateral){
            AddLateralStart(New_Lateral);
        }else if (New_Lateral->Lateral > EndLateral->Lateral){
            AddLateralInEnd(New_Lateral);
        }else{
            AddLateralBetween(New_Lateral);
        }
    }
}

void Lateral::AddLateral2(NodeLateral *& Lateral){
    NodeLateral *New_Lateral = Lateral;
    if (FirstLateral == NULL){
        FirstLateral = EndLateral = New_Lateral;
    }else{
        if(New_Lateral->Lateral < FirstLateral->Lateral){
            AddLateralStart(New_Lateral);
        }else if (New_Lateral->Lateral > EndLateral->Lateral){
            AddLateralInEnd(New_Lateral);
        }else{
            AddLateralBetween(New_Lateral);
        }
    }
}

void Lateral::AddLateralStart(NodeLateral *& New_Lateral){
    FirstLateral->PreviousLateral = New_Lateral;
    New_Lateral->NextLateral = FirstLateral;
    FirstLateral = FirstLateral->PreviousLateral;
}

void Lateral::AddLateralInEnd(NodeLateral *& New_Lateral){
    EndLateral->NextLateral = New_Lateral;
    New_Lateral->PreviousLateral=EndLateral;
    EndLateral= EndLateral->NextLateral;
}

void Lateral::AddLateralBetween(NodeLateral *& New_Lateral){
    NodeLateral *Aux, *Aux2;
    Aux= FirstLateral;
    while(Aux->Lateral < New_Lateral->Lateral){
        Aux = Aux->NextLateral;
    }
    Aux2 = Aux->PreviousLateral;
    Aux2->NextLateral = New_Lateral;
    Aux->PreviousLateral= New_Lateral;
    New_Lateral->NextLateral =Aux;
    New_Lateral->PreviousLateral=Aux2;
}

void Lateral::CoverLaterales(){
    if(FirstLateral != NULL){
        NodeLateral *Aux = FirstLateral;
        while(Aux != NULL){
            cout<<"F: "<<Aux->Lateral<<"\n";
            Aux = Aux->NextLateral;
        }
    }
}

bool Lateral::IsLateral(int Lateral){
    if(FirstLateral== NULL){
        return false;
    }else{
        NodeLateral *Aux = FirstLateral;
        while(Aux != NULL){
            if(Aux->Lateral == Lateral){
                return true;
            }else if(Aux->NextLateral == NULL){
                return false;
            }
            Aux = Aux->NextLateral;
        }
        return false;
    }
}

NodeLateral *Lateral::SearchLateral(int Lateral){
    if (IsLateral(Lateral)){
        NodeLateral *Aux = FirstLateral;
        while(Aux->Lateral != Lateral){
            Aux = Aux->NextLateral;
        }
        return Aux;
    }else{
        return Create_Lateral(-1);
    }
}

void Lateral::PrintLaterales(){
    NodeLateral * Aux = FirstLateral;
    do{
        cout<<"F: "<<Aux->Lateral<<"\n";
        Aux = Aux->NextLateral;
    }while(Aux != NULL && Aux != FirstLateral);
}

string Lateral:: DotLaterales(){
    NodeLateral *Aux = FirstLateral;
    string  Dot ="subgraph cluster_1 {  \n";
    Dot += "style=filled; \n";
    Dot += "color=lightgrey; \n";
    Dot += "node [style=filled,color=red]; \n";
    do{
        Dot += "n"+std::to_string(Aux->Lateral)+"[label=\"F: "  +std::to_string(Aux->Lateral)+ "\"];\n";
        if(Aux->NextLateral != NULL){
            Dot += "n"  +std::to_string(Aux->Lateral)+ " -> n"  +std::to_string(Aux->NextLateral->Lateral)+";\n";
            Dot += "n"  +std::to_string(Aux->NextLateral->Lateral) +" -> n"  +std::to_string(Aux->Lateral)+";\n";
        }
        Aux= Aux->NextLateral;
    }while(Aux!= NULL && Aux!= FirstLateral);

    Dot += "label = \"Laterales \";\n";
    Dot += "} \n";
    return Dot;
}

int main() {
    cout<<"Node Matrix \n";
    Matrix.InsertMatrix(15,10,255,229,204);
    Matrix.InsertMatrix(3,6,255,229,204);
    Matrix.InsertMatrix(5,2,255,229,204);
    Matrix.InsertMatrix(16,11,255,229,204);
    //Matrix.Graph();
    cout<<"En teoria si se agrego";
    return 0;
}
