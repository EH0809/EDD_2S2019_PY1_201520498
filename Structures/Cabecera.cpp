#include "Cabecera.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>
#include <bits/stdc++.h>


using namespace std;

NodeHeader *FirstHeader= NULL;
NodeHeader *EndHeader= NULL;


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
