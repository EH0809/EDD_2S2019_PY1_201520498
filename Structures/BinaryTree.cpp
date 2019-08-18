#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>
#include <BinaryTree.h>
#include <bits/stdc++.h>

using namespace std;


NodeBB *Tree = NULL;

NodeBB* NodeABB::Create_Node(std::string Name, int Id){
    NodeBB *New_Nodo = new NodeBB;
    New_Nodo->Name = Name;
    New_Nodo->Id = Id;
    New_Nodo->SonRight = NULL;
    New_Nodo->SonRight = NULL;
    return New_Nodo;
}

void NodeABB::SendInsert(std::string Name){
    InsertNode(Tree,Name);
}

int NodeABB::IdName(std::string Name){
  int Suma= 0;
  string a = Name;
  char buffer[100];
  strcpy(buffer,a.c_str());
  int ab = a.size();
  int q=0;
  int suma =0;
  while(q<=ab){
    suma = suma +buffer[q];
    q++;
  }
  //cout<<suma;
  return suma;
}

void NodeABB::InsertNode(NodeBB *&Tree, std::string Name){
    int Id = IdName(Name);

    if(Tree == NULL)
    {
        NodeBB * New_Nodo = Create_Node(Name,Id);
        Tree = New_Nodo;
    }else
    {
        int ValueTree = Tree->Id;
        if(Id < ValueTree)
        {
            InsertNode(Tree->SonLeft,Name);
        }else
        {
            InsertNode(Tree->SonRight,Name);
        }
    }

}

void NodeABB::PrintNode(int Aux){

    PrintNode2(Tree,Aux);
}

void NodeABB::PrintNode2(NodeBB *&Tree ,int Aux){
if(Tree == NULL)
    {
        return;
    }else
    {
        PrintNode2(Tree->SonRight,Aux+1);
        for(int i=0;i<Aux;i++)
        {
            cout<<"   ";
        }
        cout<<Tree->Name<<endl;
        PrintNode2(Tree->SonLeft, Aux+1);
}

}

string NodeABB::InOrder(NodeBB *&Tree, std::string grafica){
    if(Tree!=NULL)
    {

        grafica += "Nodo_"+Tree->Name+";";
        grafica += "\n";
        grafica += "Nodo_"+Tree->Name+" [label=\" Nombre:"+Tree->Name +" \",shape=box]; \n";

        if(Tree->SonLeft!=NULL)
        {
            grafica += "Nodo_"+Tree->Name;
            grafica += "->";
            grafica = InOrder(Tree->SonLeft,grafica);
        }

        if(Tree->SonRight!=NULL)
        {
            grafica += "Nodo_"+Tree->Name;
            grafica += "->";
            grafica = InOrder(Tree->SonRight,grafica);
        }

    }
    return grafica;
}

void NodeABB::Graph(){
        std::string a = "";
        a +="digraph G { \n";
        ofstream fd4("ArbolBB.dot");
        a = InOrder(Tree,a);
        a += "}";
        fd4<<a;
        fd4.flush();
        fd4.close();
        cout<<" GENERANDO IMAGEN \n";
    system("dot -Tpng ArbolBB.dot -o ArbolBB.png");
    //system("ArbolBB.png");
}

NodeBB* NodeABB::Moretoleft(NodeBB *& Tree){

     NodeBB *temp = Tree;

     while(temp->SonLeft != NULL)
{
        temp=temp->SonLeft;
}
    return temp;
}

void NodeABB::SentDelete(string Name){

    DeleteNode(Tree,Name);
}

NodeBB* NodeABB::DeleteNode(NodeBB *&Tree, std::string Name){
  int Id = IdName(Name);
    if(Tree == NULL){
            return Tree;
    }
    if(Id < Tree->Id){

        Tree->SonLeft = DeleteNode(Tree->SonLeft,Name);
    }
    else if (Id > Tree->Id){
        Tree->SonRight = DeleteNode(Tree->SonRight,Name);

    }

    else{

                if(Tree->SonLeft == NULL){

                    NodeBB * temp=Tree->SonRight;
                    free(Tree);
                    return temp;
                }
                else if (Tree->SonRight == NULL){
                    NodeBB *temp = Tree->SonLeft;
                    free(temp);
                    return temp;
                }
                NodeBB *temp = Moretoleft(Tree->SonRight);
                Tree->Name=temp->Name;
                Tree->SonRight=DeleteNode(Tree->SonRight,temp->Name);

    }

    return Tree;
}

std::string NodeABB::InOrderE(NodeBB *&Tree, std::string grafica){
    if(Tree!=NULL)
    {

        grafica += "Nodo_"+Tree->Name+";";
        grafica += "\n";
        grafica += "Nodo_"+Tree->Name+" [label=\"Nombre:"+Tree->Name +" \",shape=box]; \n";

        if(Tree->SonLeft!=NULL)
        {
            grafica += "Nodo_"+Tree->Name;
            grafica += "->";
            grafica = InOrderE(Tree->SonLeft,grafica);
        }

        if(Tree->SonRight!=NULL)
        {
            grafica += "Nodo_"+Tree->Name;
            grafica += "->";
            grafica = InOrderE(Tree->SonRight,grafica);
        }

    }
    return grafica;
}

void NodeABB::GraphE(){
  std::string a = "";
  a +="digraph G { \n";
  ofstream fd4("ArbolBBEliminado.dot");
  a = InOrderE(Tree,a);
  a += "}";
  fd4<<a;
  fd4.flush();
  fd4.close();
  cout<<" GENERANDO IMAGEN Eliminados\n";

system("dot -Tjpg ArbolBBEliminado.dot -o ArbolBBEliminado.jpg");
system("ArbolBBEliminado.jpg");
}
