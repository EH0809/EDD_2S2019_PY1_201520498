#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>
#include <string.h>

using namespace std;

NodeBB *ATree = NULL;
string Pre = "";
string NameTree = "";
ListaNodeBB *HeadList = NULL;
ListaNodeBB *EndList = NULL;
ListaNodeBB *HeadListPreOrden = NULL;
ListaNodeBB *EndListPreOrden = NULL;
ListaNodeBB *HeadListPostOrden = NULL;
ListaNodeBB *EndListPostOrden = NULL;

NodeBB *BinaryTree::Create_Node(string Name) {
    NodeBB *New_Nodo = new NodeBB;
    New_Nodo->Name = Name;
    New_Nodo->SonLeft = NULL;
    New_Nodo->SonRight = NULL;
    return New_Nodo;
}

void BinaryTree::SendInsert(string Name) {
    InsertNode(ATree, Name);
}

int BinaryTree::Compare(string Name, string Name2) {
    int a = 0;
    if (Name.compare(Name2) == 0) {
        cout << "Usuario ya Existe";
    } else if (Name.compare(Name2) < 0) {
        a = -1;
    } else if (Name.compare(Name2) > 0) {
        a = 1;
    }
}

int BinaryTree::IdName(string Name) {
    int Suma = 0;
    string a = Name;
    char buffer[100];
    strcpy(buffer, a.c_str());
    int ab = a.size();
    int q = 0;
    int suma = 0;
    while (q <= ab) {
        suma = suma + buffer[q];
        q++;
    }
    return suma;
}


void BinaryTree::InsertNode(NodeBB *&Tree, string Name) {

    if (Tree == NULL) {
        NodeBB *New_Nodo = Create_Node(Name);
        Tree = New_Nodo;
    } else {

        string a = Name;
        char bufferName[100];
        strcpy(bufferName, a.c_str());
        string b = Tree->Name;
        char bufferTree[100];
        strcpy(bufferTree, b.c_str());

        if (strcmp(bufferName, bufferTree) < 0) {
            InsertNode(Tree->SonLeft, Name);
        } else {
            InsertNode(Tree->SonRight, Name);
        }
    }
}

/*
void BinaryTree::InsertNode(NodeBB *&Tree, string Name) {
    int Id = IdName(Name);
    if (Tree == NULL) {
        NodeBB *New_Nodo = Create_Node(Name, Id);
        Tree = New_Nodo;
    } else {
        int ValueTree = Tree->Id;
        string a = Tree->Name;
        if (Id < Tree->Id) {
            InsertNode(Tree->SonLeft, Name);
        } else {
            InsertNode(Tree->SonRight, Name);
        }
    }
}
*/


string Te = "";

string BinaryTree::InOrder(NodeBB *&Tree, string grafica) {
    if (Tree != NULL) {
        if (Te == "left") {
            grafica += "Node_" + Tree->Name + ":f1;";
        } else if (Te == "right") {
            grafica += "Node_" + Tree->Name + ":f1;";
        }
        grafica += "Node_" + Tree->Name + "[label= \" <f0> | <f1> " + Tree->Name + " | <f2> \" shape = \"record\"] ;\n";

        if (Tree->SonLeft != NULL) {
            grafica += "Node_" + Tree->Name + ":f0";
            grafica += "->";
            Te = "left";
            grafica = InOrder(Tree->SonLeft, grafica);

        }

        if (Tree->SonRight != NULL) {
            grafica += "Node_" + Tree->Name + ":f2";
            grafica += "->";
            Te = "right";
            grafica = InOrder(Tree->SonRight, grafica);
        }

    }
    return grafica;
}

void BinaryTree::Graph() {
    string a = "";
    a += "digraph G { \n";
    ofstream fd4("ArbolBB.dot");
    a = InOrder(ATree, a);
    a += "}";
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN \n";
    system("dot -Tpng ArbolBB.dot -o ArbolBB.png");
    //system("ArbolBB.png");
}

NodeBB *BinaryTree::Moretoleft(NodeBB *&Tree) {

    NodeBB *temp = Tree;

    while (temp->SonLeft != NULL) {
        temp = temp->SonLeft;
    }
    return temp;
}
/*
void BinaryTree::SentDelete(string Name) {

    DeleteNode(ATree, Name);
}

NodeBB *BinaryTree::DeleteNode(NodeBB *&Tree, string Name) {
    int Id = IdName(Name);
    if (Tree == NULL) {
        return Tree;
    }
    if (Id < Tree->Id) {

        Tree->SonLeft = DeleteNode(Tree->SonLeft, Name);
    } else if (Id > Tree->Id) {
        Tree->SonRight = DeleteNode(Tree->SonRight, Name);

    } else {

        if (Tree->SonLeft == NULL) {

            NodeBB *temp = Tree->SonRight;
            free(Tree);
            return temp;
        } else if (Tree->SonRight == NULL) {
            NodeBB *temp = Tree->SonLeft;
            free(temp);
            return temp;
        }
        NodeBB *temp = Moretoleft(Tree->SonRight);
        Tree->Name = temp->Name;
        Tree->SonRight = DeleteNode(Tree->SonRight, temp->Name);

    }

    return Tree;
}
*/
string BinaryTree::InOrderE(NodeBB *&Tree, string grafica) {
    if (Tree != NULL) {
        grafica += "Nodo_" + Tree->Name + ";";
        grafica += "\n";
        grafica += "Nodo_" + Tree->Name + " [label=\"Nombre:" + Tree->Name + " \",shape=box]; \n";

        if (Tree->SonLeft != NULL) {
            grafica += "Nodo_" + Tree->Name;
            grafica += "->";
            grafica = InOrderE(Tree->SonLeft, grafica);
        }

        if (Tree->SonRight != NULL) {
            grafica += "Nodo_" + Tree->Name;
            grafica += "->";
            grafica = InOrderE(Tree->SonRight, grafica);
        }

    }
    return grafica;
}


void BinaryTree::PrintPreOrder2() {

    PrintPreOrder(ATree);

}

void BinaryTree::PrintPreOrder(NodeBB *&Tree) {
    if (Tree != NULL) {
        cout << Tree->Name + "\n";
        PrintPreOrder(Tree->SonLeft);
        PrintPreOrder(Tree->SonRight);
    }
}

void BinaryTree::PrintPostOrder() {
    PrintPostOrder2(ATree);
}

void BinaryTree::PrintPostOrder2(NodeBB *&Tree) {
    if (Tree != NULL) {
        PrintPreOrder(Tree->SonLeft);
        PrintPreOrder(Tree->SonRight);
        cout << Tree->Name + "\n";
    }
}


int Contador = 1;

void BinaryTree::PrintNode() {
    PrintNode2(ATree);
}

void BinaryTree::PrintNode2(NodeBB *&Tree) {
    if (Tree != NULL) {
        PrintNode2(Tree->SonLeft);
        cout << std::to_string(Contador) + " " + Tree->Name + "\n";
        Contador++;
        InsertListNode(Contador, Tree->Name);
        PrintNode2(Tree->SonRight);
    }
}

string BinaryTree::SentFor(string Name) {

    NodeBB *Temp = SentFor2(ATree, Name);
    return Temp->Name;
}

NodeBB *Aux = NULL;

NodeBB *BinaryTree::SentFor2(NodeBB *&Tree, string Name) {
    if (Tree != NULL) {
        if (Tree->Name == Name) {
            Aux = Tree;
            User= Tree->Name;
            cout<<"Se encontro a:" +User+"\n";
        }
        if (Tree->SonLeft != NULL) {
            SentFor2(Tree->SonLeft, Name);
        }
        if (Tree->SonRight != NULL) {
            SentFor2(Tree->SonRight, Name);
        }
    }
    return Aux;
}

ListaNodeBB *BinaryTree::Create_NodeList(int Id, string Name) {
    ListaNodeBB *AuxL = new ListaNodeBB;
    AuxL->Id = Id;
    AuxL->Name = Name;
    AuxL->NextNodeBB = NULL;
    return AuxL;
}


void BinaryTree::PrintList() {
    ListaNodeBB *AuxList = HeadList;
    while (AuxList != NULL) {
        cout << std::to_string(AuxList->Id) + "-" + AuxList->Name + "\n";
        AuxList = AuxList->NextNodeBB;
    }
}

void BinaryTree::SelectList(int id) {
    ListaNodeBB *AuxL = HeadList;
    while (AuxL != NULL) {
        if (AuxL->Id == id) {
            cout << "Se Encontron " + AuxL->Name + " \n";
            User = AuxL->Name;
        }
        AuxL = AuxL->NextNodeBB;
    }
}

void BinaryTree::RestValues() {
    Contador = 0;
}

string Io = "";

void BinaryTree::InOrder2() {
    ListaNodeBB *Aux1 = HeadList;
    while (Aux1 != NULL) {
        if (Aux1->NextNodeBB != NULL) {
            Io += Aux1->Name + "->";
        } else {
            Io += Aux1->Name;
        }
        Aux1 = Aux1->NextNodeBB;
    }
}

void BinaryTree::GraphInOrder() {
    string a = "";
    a += "digraph G { rankdir = \"LR\" \n";
    ofstream fd4("InOrder.dot");
    InOrder2();
    a += Io;
    a += "}";
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN InOrder\n";
    system("dot -Tjpg InOrder.dot -o InOrder.jpg");
}

int Contador1 = 1;

void BinaryTree::PN() {
    PN2(ATree);
}

void BinaryTree::PN2(NodeBB *&Tree) {
    if (Tree != NULL) {
        PN2(Tree->SonLeft);
        Contador1++;
        InsertListNode(Contador, Tree->Name);
        PN2(Tree->SonRight);
    }
}

void BinaryTree::InsertListNode(int Id, string Name) {
    ListaNodeBB *New_Node = Create_NodeList(Id, Name);
    if (HeadList == NULL) {
        HeadList = EndList = New_Node;
    } else {
        EndList->NextNodeBB = New_Node;
        EndList = EndList->NextNodeBB;
    }
}

string ab = "";

void BinaryTree::PreOrder() {
    ListaNodeBB *Aux1 = HeadListPreOrden;
    while (Aux1 != NULL) {
        if (Aux1->NextNodeBB != NULL) {
            ab += Aux1->Name + "->";
        } else {
            ab += Aux1->Name;
        }
        Aux1 = Aux1->NextNodeBB;
    }
}

void BinaryTree::GraphPreOrder() {
    string a = "";
    a += "digraph G { rankdir = \"LR\" \n";
    ofstream fd4("Preorder.dot");
    PreOrder();
    a += ab;
    a += "}";
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN PreOrder\n";
    system("dot -Tjpg Preorder.dot -o Preorder.jpg");
}

int ContadorPre = 1;

void BinaryTree::PNPre() {
    PN2Pre(ATree);
}

void BinaryTree::PN2Pre(NodeBB *&Tree) {
    if (Tree != NULL) {
        ContadorPre++;
        InsertListNodePre(ContadorPre, Tree->Name);
        PN2Pre(Tree->SonLeft);
        PN2Pre(Tree->SonRight);
    }
}

void BinaryTree::InsertListNodePre(int Id, string Name) {
    ListaNodeBB *New_Node = Create_NodeList(Id, Name);
    if (HeadListPreOrden == NULL) {
        HeadListPreOrden = EndListPreOrden = New_Node;
    } else {
        EndListPreOrden->NextNodeBB = New_Node;
        EndListPreOrden = EndListPreOrden->NextNodeBB;
    }
}


string PO = "";

void BinaryTree::PostOrder() {
    ListaNodeBB *Aux1 = HeadListPostOrden;
    while (Aux1 != NULL) {
        if (Aux1->NextNodeBB != NULL) {
            PO += Aux1->Name + "->";
        } else {
            PO += Aux1->Name;
        }
        Aux1 = Aux1->NextNodeBB;
    }
}

void BinaryTree::GraphPostOrder() {
    string a = "";
    a += "digraph G { rankdir = \"LR\" \n";
    ofstream fd4("PostOrder.dot");
    PostOrder();
    a += PO;
    a += "}";
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN PostOrder\n";
    system("dot -Tjpg PostOrder.dot -o PostOrder.jpg");
}

int ContadorPost = 1;

void BinaryTree::PNPost() {
    PN2Post(ATree);
}

void BinaryTree::PN2Post(NodeBB *&Tree) {

    if (Tree != NULL) {
        PN2Post(Tree->SonLeft);
        PN2Post(Tree->SonRight);
        ContadorPost++;
        InsertListNodePost(ContadorPre, Tree->Name);
    }
}

void BinaryTree::InsertListNodePost(int Id, string Name) {
    ListaNodeBB *New_Node = Create_NodeList(Id, Name);
    if (HeadListPostOrden == NULL) {
        HeadListPostOrden = EndListPostOrden = New_Node;
    } else {
        EndListPostOrden->NextNodeBB = New_Node;
        EndListPostOrden = EndListPostOrden->NextNodeBB;
    }
}