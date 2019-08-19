#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
#include <string>
#include "Cabecera.h"
#include "Lateral.h"


using namespace std;

NodeABB * AuxTree;
Cabecera * LHeaders;
Lateral * LLaterales;

int contador =0;

int main()
{
  cout<<"insertar \n";
    AuxTree->SendInsert("Edgar");
    AuxTree->SendInsert("A");
    AuxTree->SendInsert("Edgar5");
    cout<<"InOrder \n";
    AuxTree->Graph();
    //Aux2->GraphPreOrder();
    cout<<"PreOrder \n";
    AuxTree->PrintPreOrder2();
    //AuxTree->GraphPreOrder();
    cout<<"PostOrder\n";
    AuxTree->PrintPostOrder();
    //Aux2->GraphPostOrder();

    cout<<"Cabeceras \n";
    LHeaders->InsertHeader(5);
    LHeaders->InsertHeader(10);
    LHeaders->InsertHeader(3);
    LHeaders->InsertHeader(1);
    LHeaders->InsertHeader(15);
    cout<<"Imprimiendo Cabeceras \n";
    LHeaders->PrintHeader();

    cout<<"Laterales \n";
    LLaterales->AddLateral(5);
    LLaterales->AddLateral(10);
    LLaterales->AddLateral(3);
    LLaterales->AddLateral(8);
    cout<<"Imprimiendo Laterales \n";
    LLaterales->PrintLaterales();




   return 0;
}
