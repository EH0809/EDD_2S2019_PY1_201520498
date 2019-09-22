//
// Created by edgarh on 27/08/19.
//

#include "ListFilters.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>

NodeFilter *FirstListFilters = NULL;
NodeFilter *EndListFilters = NULL;

bool ListFilters::IsEmpety() {
    return FirstListFilters == NULL;
}

NodeFilter * ListFilters::CreateNode(string Name) {
    NodeFilter * New_Node = new NodeFilter;
    New_Node->Name = Name;
    New_Node->NextFilter = NULL;
    New_Node->PreviousFilter = NULL;
}
void ListFilters::InsertNodeFilter(string Name) {
    NodeFilter *New_Node = CreateNode(Name);

    if(FirstListFilters == NULL){
        FirstListFilters = EndListFilters = New_Node;
        FirstListFilters->NextFilter = FirstListFilters;
        FirstListFilters->PreviousFilter = EndListFilters;
    }else{
        EndListFilters->NextFilter = New_Node;
        New_Node->PreviousFilter = EndListFilters;
        New_Node->NextFilter = FirstListFilters;
        EndListFilters = New_Node;
        FirstListFilters->PreviousFilter = EndListFilters;
    }
}
int contador = 1;
void ListFilters::PrintFilters() {
    NodeFilter *Aux = FirstListFilters;
    if (FirstListFilters != NULL){
        do{
            cout<<"No.: "+to_string(contador)+" Filters: "+Aux->Name+"->";
            Aux= Aux->NextFilter;
            contador++;
        }while (Aux != FirstListFilters);
    }
}

void ListFilters::GraphList() {
    string a = "";
    a ="digraph G { \n";
    ofstream fd4("ListFilters.dot");
    a += Dot(a);
    fd4<<a;
    fd4.flush();
    fd4.close();
    cout<<" GENERANDO IMAGEN List Filters \n";
    system("dot -Tpng ListFilters.dot -o ListFilters.png");
    //system("ListFilters.png");
}
string ListFilters::Dot(string Dot) {
    NodeFilter *Aux = FirstListFilters;
    string grafo ="ranksep=.50; \n rankdir=TB; \n";
    if (FirstListFilters != NULL){
        do{
            grafo += "Node_"+Aux->Name +"-> Node_"+Aux->NextFilter->Name+"\n";
            grafo += "Node_"+Aux->NextFilter->Name +"-> Node_"+Aux->Name+"\n";
          if (Aux == EndListFilters){
              grafo += "Node_"+Aux->Name;
          }
            Aux = Aux->NextFilter;
        }while(Aux != FirstListFilters);
    }
    grafo +="}";
    return grafo;
}