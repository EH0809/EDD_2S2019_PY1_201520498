#include "Lateral.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

NodeLateral *FirstLateral=NULL;
NodeLateral *EndLateral=NULL;

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
