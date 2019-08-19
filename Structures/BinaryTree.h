#include <string>
#include <iostream>

using namespace std;

struct NodeBB{
  std::string Name;
  int Id;
  NodeBB *SonLeft;
  NodeBB *SonRight;
};

class NodeABB
{
    public:
        NodeABB();
        int IdName(std::string Name);
        NodeBB* Create_Node(string Name, int Id);
        void InsertNode(NodeBB *&Tree,string Name);
        void SendInsert(string Name);
        void PrintNode(int Aux);
        void PrintNode2(NodeBB *&Tree, int Aux);

        string InOrder(NodeBB *& Tree,string Graph);
        string PreOrder(NodeBB *& Tree,string Graph);
        string PostOrder(NodeBB *& Tree,string Graph);

        void Graph();
        void GraphPreOrder();
        void GraphPostOrder();

        void PrintPreOrder2();
        void PrintPreOrder(NodeBB *& Tree);
        void PrintPostOrder();
        void PrintPostOrder2(NodeBB *& Tree);


        string InOrderE(NodeBB *&Tree,string Graph);
        void GraphE();

        NodeBB * Moretoleft(NodeBB *& Tree);
        NodeBB * DeleteNode(NodeBB *& Tree, string Name);
        void SentDelete(string Name);

        NodeBB* ModifyNode(NodeBB *&Tree,string Name, string Nombre2);
        void SentModify(string Name, string Nombre2);
        NodeBB *SentFor(string Name);
        NodeBB *SentFor2(NodeBB *&Tree, string Name);

        string SentGraph();
};
