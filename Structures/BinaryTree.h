//
// Created by edgarh on 22/08/19.
//

#ifndef P1_BINARYTREE_H
#define P1_BINARYTREE_H
#include <string>
#include <iostream>
#include "ListMatix.h"
#include "CompleteMatrix.h"
#include "ListFilters.h"
#include "MatrixGrayScale.h"
#include "MatrixRotationY.h"
#include "MatrixRotationX.h"
using namespace std;

struct NodeBB{
    string Name;
    string Ruta;
    ListMatix ListadeCapas;
    CompleteMatrix CM;
    int Image_width;
    int Image_height;
    int Pixel_width;
    int Pixel_height;
    MatrixNegative MNegative;
    MatrixGrayScale MGrayScale;
    MatrixRotationY MRotationY;
    MatrixRotationX MRotationX;
    ListFilters LFilters;
    NodeBB *SonLeft;
    NodeBB *SonRight;
};

struct ListaNodeBB{
    int Id;
    string Name;
    ListaNodeBB* NextNodeBB;
};

class BinaryTree {
public:

    int IdName(string Name);
    NodeBB* Create_Node(string Name, string ruta);
    void SendInsert(string Name, string Ruta);
    void InsertNode(NodeBB *&Tree,string Name, string ruta);
    void InsertNode2(NodeBB *&Tree,string Name);
    int Compare(string Name1 , string NameTree);
    void PrintNode();
    void PrintNode2(NodeBB *&Tree);
    string InOrder(NodeBB * &Tree,string Graph);
    string InOrder2();
    void PreOrder();
    void PostOrder();
    void Graph();
    void GraphInOrder();
    void GraphPreOrder();
    void GraphPostOrder();
    void PrintPreOrder2();
    void PrintPreOrder(NodeBB *&Tree);
    void PrintPostOrder();
    void PrintPostOrder2(NodeBB *&Tree);
    string InOrderE(NodeBB *&Tree,string Graph);
    void GraphE();
    NodeBB * Moretoleft(NodeBB *&Tree);
    NodeBB * DeleteNode(NodeBB *&Tree, string Name);
    void SentDelete(string Name);
    NodeBB* ModifyNode(NodeBB *&Tree,string Name, string Nombre2);
    void SentModify(string Name, string Nombre2);
    NodeBB * SentFor(string Name);
    //string * SentFor(string Name);
    NodeBB *SentFor2(NodeBB *&Tree, string Name);
    string SentGraph();
    string User ="";

    //*********************** LIST ************///////

    ListaNodeBB *Create_NodeList(int Id, string Name);
    void InsertListNode(int Id, string Name);
    void PrintList();
    void SelectList(int id);
    ListaNodeBB *SelectL(int id);
    ListaNodeBB *SelectL2(string Name);
    void RestValues();

    void PN();
    void PN2(NodeBB *&Tree);

    void PNPre();
    void PN2Pre(NodeBB *&Tree);
    void InsertListNodePre(int Id, string Name);

    void PNPost();
    void PN2Post(NodeBB *&Tree);
    void InsertListNodePost(int Id, string Name);
};


#endif //P1_BINARYTREE_H
