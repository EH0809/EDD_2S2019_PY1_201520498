#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>

using namespace std;

struct NodeBB{
  std::string Name;
  int Id;
  NodeBB *SonLeft;
  NodeBB *SonRight;
};

class NodeABB{
public:
  NodeABB();
     int IdName(std::string Name);
     NodeBB* Create_Node(std::string Name, int Id);
     void InsertNode(NodeBB *&Tree,std::string Name);
     void SendInsert(std::string Name);
     void PrintNode(int Aux);
     void PrintNode2(NodeBB *&Tree, int Aux);

     std::string InOrder(NodeBB *& Tree,std::string Graph);
     void Graph();

     std::string InOrderE(NodeBB *&Tree,std::string Graph);
     void GraphE();

     NodeBB * Moretoleft(NodeBB *& Tree);
     NodeBB * DeleteNode(NodeBB *& Tree, std::string Name);
     void SentDelete(string Name);

     NodeBB* ModifyNode(NodeBB *&Tree,string Name, std::string Nombre2);
     void SentModify(std::string Name, std::string Nombre2);
     NodeBB *SentFor(std::string Name);
     NodeBB *SentFor2(NodeBB *&Tree, std::string Name);

     std::string SentGraph();
};
#endif // BINARYTREE_H
