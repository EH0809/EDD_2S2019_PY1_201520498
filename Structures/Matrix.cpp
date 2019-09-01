//
// Created by edgarh on 22/08/19.
//

#include <iostream>
#include "Matrix.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <malloc.h>

using namespace std;


VerticalList Vertical;
HorizontalList Horizontal;

MatrixNode *Matrix::Create_NodeMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB) {
    MatrixNode *New_Node = new MatrixNode;
    New_Node->ColMatrix = Header;
    New_Node->RowMatrix = Lateral;
    New_Node->ColorR = ColorR;
    New_Node->ColorG = ColorG;
    New_Node->ColorB = ColorB;
    return New_Node;

}

void Matrix::InsertMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB) {
    NodeHeader *Cabecera;
    NodeLateral *Laterales;
    MatrixNode *New_Node = Create_NodeMatrix(Header, Lateral, ColorR, ColorG, ColorB);
    if (!IsHeader(Header)) {
        InsertHeader(Header);
    }
    if (!IsLateral(Lateral)) {
        AddLateral(Lateral);
    }
    Cabecera = SearchHeader(Header);
    Laterales = SearchLateral(Lateral);
    Cabecera->Colum.AddLateral(New_Node);
    //Vertical.AddLateral((New_Node));
    Laterales->Fila.AddHorizontal(New_Node);
    //Horizontal.AddHorizontal(New_Node);
}

int Matrix::Max_Headers() {
    NodeHeader *Cabe = EndHeader;
    return Cabe->Header;
}

int Matrix::Max_Laterales() {
    NodeLateral *Late = EndLateral;
    return Late->Lateral;
}

MatrixNode *Matrix::IsNode(int Header, int Lateral) {
    NodeHeader *Cabecera = SearchHeader(Header);
    if (Cabecera->Header != -1) {
        MatrixNode *Node = SearchHeader(Header)->Colum.FirstNodeCentralV;
        while (Node->RowMatrix != Lateral) {
            if (Node->DownMatrix == NULL) {
                return Create_NodeMatrix(-1, -1, -1, -1, -1);
            }
            Node = Node->DownMatrix;
        }
        return Node;
    } else {
        return Create_NodeMatrix(-1, -1, -1, -1, -1);
    }
}

MatrixNode *Matrix::IsCoordinate(int Header, int Lateral) {
    NodeHeader *Cabe = SearchHeader(Header);
    cout << "Esta Coordenad Existe";
    if (Cabe->Header != -1) {
        MatrixNode *Node = SearchHeader(Header)->Colum.FirstNodeCentralV;
        while (Node->RowMatrix != Lateral) {
            if (Node->DownMatrix == NULL) {
                return Create_NodeMatrix(-1, -1, -1, -1, -1);
            }
            Node = Node->DownMatrix;
        }
    } else {
        return Create_NodeMatrix(-1, -1, -1, -1, -1);
    }
}

void Matrix::Graph() {

    string a = "";
    //a = "digraph G { \n";
    ofstream fd4("Matrix.dot");
    a += Dot3(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN Matrix \n";
    system("dot -Tpng Matrix.dot -o Matrix.png");
}

string Matrix::Dot(string dot) {
    string NameAnt, Enlaces = "", Nombres = "";
    string grafo = "\n ranksep=.50; \n rankdir=TB; \n node [shape=box]; graph[nodesep = 0.5];\n";
    string Rank = "{ rank = same; ";
    string Elances2 = "";
    NodeHeader *Cabecera1 = FirstHeader;
    NodeLateral *Lateral1 = FirstLateral;
    NameAnt = "Terminal";
    while (Cabecera1 != NULL) {
        Rank += NameAnt + ";";
        Enlaces += NameAnt + "->" + "X" + std::to_string(Cabecera1->Header) + "[dir=both];\n";
        NameAnt = "X" + std::to_string(Cabecera1->Header);
        Enlaces += NameAnt + "-> n" + std::to_string(Cabecera1->Colum.FirstNodeCentralV->ColMatrix) +
                   std::to_string(Cabecera1->Colum.FirstNodeCentralV->RowMatrix) + "[dir=both]; \n";
        Rank += NameAnt + ";";
        Cabecera1 = Cabecera1->NextHeader;
    }
    Rank += "}";
    string Rank2 = "";
    NameAnt = "Terminal";
    string Rank3 = "{ rank = same; ";
    while (Lateral1 != NULL) {
        Elances2 += NameAnt + " -> Y" + std::to_string(Lateral1->Lateral) + "[dir=both];\n";
        NameAnt = "Y" + std::to_string(Lateral1->Lateral);
        Rank3 += NameAnt + ";";
        MatrixNode *temp = Lateral1->Fila.FirstNodeCentralH;
        if (temp != NULL) {
            Elances2 += NameAnt + " -> ";

        }
        while (temp != NULL) {
            Nombres += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "[label=\"" +
                       std::to_string(temp->ColorR) + "-" + std::to_string(temp->ColorG) + "-" +
                       std::to_string(temp->ColorB) + "\"];\n";
            if (temp->RightMatrix != NULL) {
                Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->RightMatrix->ColMatrix) +
                            std::to_string(temp->RightMatrix->RowMatrix), "[dir=both];\n";
                //  Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " -> ";
                Rank2 += "{rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "}";

            }
            if (temp->LeftMatrix != NULL) {
                Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->LeftMatrix->ColMatrix) + std::to_string(temp->LeftMatrix->RowMatrix) +
                            "[dir=both];\n";
                //Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->";
                Rank2 += "{rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "}";
            }
            if (temp->UpMatrix != NULL) {
                Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->UpMatrix->ColMatrix) + std::to_string(temp->UpMatrix->RowMatrix) +
                            "[dir=both];\n";
                //Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->";
                Rank2 += "{rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "}";
            }
            if (temp->DownMatrix != NULL) {
                Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " -> n" +
                            std::to_string(temp->DownMatrix->ColMatrix) + std::to_string(temp->DownMatrix->RowMatrix) +
                            "[dir=both];\n";
                //Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->";
                Rank2 += "{rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "}";
            }
            Elances2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "[dir=both]; \n";
            Rank2 += "{rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                     std::to_string(temp->RowMatrix) + "}";
            temp = temp->RightMatrix;
        }//fin while

        // grafo += " }\n";
        Lateral1 = Lateral1->NextLateral;

    }
    Rank3 += "}";
    grafo += Nombres + "\n" + Enlaces + "\n";
    grafo += Elances2 + "\n" + Rank + "\n" + Rank2 + "\n" + Rank3 + "\n";
    grafo += "}";
    return grafo;
}

string Matrix::Dot2(string dot) {
    string NameAnt, Enlaces = "", Nombres = "";
    string grafo = "\n ranksep=.50; \n node [shape=box];\n";
    NodeHeader *Cabecera1 = FirstHeader;
    NodeLateral *Lateral1 = FirstLateral;
    string Subgrafo = "";
    NameAnt = "Terminal";
    string Rank = "{ rank = same; ";
    while (Cabecera1 != NULL) {
        Enlaces += NameAnt + "->" + "X" + std::to_string(Cabecera1->Header) + "\n";
        NameAnt = "X" + std::to_string(Cabecera1->Header);
        Subgrafo += "{ rank = same; Terminal ;X" + std::to_string(Cabecera1->Header) + "}\n";
        Enlaces += NameAnt + "-> n" + std::to_string(Cabecera1->Colum.FirstNodeCentralV->ColMatrix) +
                   std::to_string(Cabecera1->Colum.FirstNodeCentralV->RowMatrix) + "[dir=both]; \n";
        Rank += NameAnt + ";";
        Cabecera1 = Cabecera1->NextHeader;
    }
    Rank += "}";
    string Rank2 = "";
    string Rank3 = " {rank = same;";
    string Enlaces2 = "";
    string Rnck4 = "";
    string SubGrafoY = "";
    string SubGrafoY2 = "";
    string SubGrafoY3 = "";
    string AuxY3 = "";
    string Ranck5 = " {rank = same;";
    string ABS = "Terminal [ label = \"Terminal\", width = 1.5, style = filled,group = 0];\n";
    NameAnt = "Terminal";
    while (Lateral1 != NULL) {
        Rank2 = " {rank = same;";
        SubGrafoY3 = "";
        Enlaces2 += NameAnt + " -> Y" + std::to_string(Lateral1->Lateral) + "[dir=both];\n";
        NameAnt = "Y" + std::to_string(Lateral1->Lateral);
        SubGrafoY2 += "{rank = same;Terminal; " + NameAnt + "}\n";
        SubGrafoY += "Y" + std::to_string(Lateral1->Lateral) + "[group =0;]" + "\n";
        Rank3 += NameAnt + ";";
        Ranck5 += NameAnt + ";";
        Rank2 += NameAnt + ";";
        //SubGrafoY3 += NameAnt+";";
        MatrixNode *temp = Lateral1->Fila.FirstNodeCentralH;
        if (temp != NULL) {
            Enlaces2 += NameAnt + " ->  n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) +
                        "[dir=both];\n";
            SubGrafoY3 += " {rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                          std::to_string(temp->RowMatrix) + "; }\n";
        }
        while (temp != NULL) {
            Nombres += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "[label=\"" +
                       std::to_string(temp->ColorR) + "-" + std::to_string(temp->ColorG) + "-" +
                       std::to_string(temp->ColorB) + "\"];\n";
            if (temp->RightMatrix != NULL) {
                Enlaces2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->RightMatrix->ColMatrix) +
                            std::to_string(temp->RightMatrix->RowMatrix) + "[dir=both];\n";
                Enlaces2 += " {rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                            std::to_string(temp->RowMatrix) + ";}\n";
            }
            if (temp->LeftMatrix != NULL) {
                Enlaces2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->LeftMatrix->ColMatrix) + std::to_string(temp->LeftMatrix->RowMatrix) +
                            "[dir=both];\n";
                Enlaces2 += " {rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                            std::to_string(temp->RowMatrix) + ";}\n";
            }
            if (temp->UpMatrix != NULL) {
                Enlaces2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " ->  n" +
                            std::to_string(temp->UpMatrix->ColMatrix) + std::to_string(temp->UpMatrix->RowMatrix) +
                            "[dir=both];\n";
                Enlaces2 += " {rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                            std::to_string(temp->RowMatrix) + ";} \n";

            }
            if (temp->DownMatrix != NULL) {
                Enlaces2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + " -> n" +
                            std::to_string(temp->DownMatrix->ColMatrix) + std::to_string(temp->DownMatrix->RowMatrix) +
                            "[dir=both];\n";
                Enlaces2 += " {rank = same;" + NameAnt + "; n" + std::to_string(temp->ColMatrix) +
                            std::to_string(temp->RowMatrix) + ";}\n";

            }
            // Rank2 += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix )+"[dir=both];";
            //SubGrafoY3 +="n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix )+";";
            temp = temp->RightMatrix;

        }//fin while
        Rank2 += "} \n";
        //SubGrafoY3 += "}";
        AuxY3 += SubGrafoY3 + "\n";
        Rnck4 += Rank2;

        //grafo += " }\n";
        Lateral1 = Lateral1->NextLateral;

    }

    Rank3 += "}";
    Ranck5 += "}";
    grafo += ABS + "\n" + Nombres + "\n" + Enlaces2 + "\n";
    grafo += Subgrafo + "\n" + Enlaces + "\n";

    grafo += "}";
    return grafo;
}

string Matrix::Dot3(string dot) {
    NodeHeader *Cabecera1 = FirstHeader;
    NodeLateral *Lateral1 = FirstLateral;
    string grafo = "digraph { \n";
    grafo += "node [shape=box]\n";
    grafo += "graph[nodesep = 0.5];\n";
    grafo += "Terminal[ label = \"Terminal \", width = 1.5 style = filled ,group = 0 ];\n";
    grafo += "e0[ shape = point, width = 0 ]\n";
    grafo += "e1[ shape = point, width = 0 ]\n";
    grafo += "Terminal -> Y" + to_string(Lateral1->Lateral) + "[dir=both]; \n";

    while (Lateral1 != NULL) {
        grafo += "Y" + to_string(Lateral1->Lateral) + "[width = 1.5 style = filled , group =" + to_string(0) + "];\n";
        if (Lateral1->NextLateral != NULL) {
            grafo += "Y" + to_string(Lateral1->Lateral) + "-> Y" + to_string(Lateral1->NextLateral->Lateral) +
                     "[dir=both];\n";
            //grafo +="{ rank = same; Y" + to_string(Lateral1->Lateral) +";Y"+ to_string(Lateral1->NextLateral->Lateral)+"}\n";
        }
        MatrixNode *temp = Lateral1->Fila.FirstNodeCentralH;
        int cont = 0;
        while (temp != NULL) {
            grafo += "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "[label=\"" +
                     std::to_string(temp->ColorR) + "-" + std::to_string(temp->ColorG) + "-" +
                     std::to_string(temp->ColorB) + "\"  width = 1.5, group = " + to_string(temp->ColMatrix) + " ];\n";

            if (temp->RightMatrix != NULL) {
                grafo +=
                        "Y" + to_string(Lateral1->Lateral) + "-> n" + std::to_string(temp->ColMatrix) +
                        std::to_string(temp->RowMatrix) + "[dir=both];\n";

                grafo +=
                        "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "-> n" +
                        std::to_string(temp->RightMatrix->ColMatrix) +
                        std::to_string(temp->RightMatrix->RowMatrix) +
                        "[dir=both];\n";

                grafo += "{ rank = same; n" + to_string(Lateral1->Lateral) + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "} \n";
            }

            if (temp->DownMatrix != NULL) {
                grafo +=
                        "n" + std::to_string(temp->ColMatrix) + std::to_string(temp->RowMatrix) + "-> n" +
                        std::to_string(temp->DownMatrix->ColMatrix) +
                        std::to_string(temp->DownMatrix->RowMatrix) +
                        "[dir=both];\n";

                grafo += "{ rank = same; Y" + to_string(Lateral1->Lateral) + "; n" + std::to_string(temp->ColMatrix) +
                         std::to_string(temp->RowMatrix) + "} \n";

            }

            temp = temp->RightMatrix;
        }
        Lateral1 = Lateral1->NextLateral;
    }

    grafo += "Terminal ->X" + to_string(Cabecera1->Header) + "[dir=both]; \n";
    grafo += "{ rank = same;Terminal; X" + to_string(Cabecera1->Header) + " }\n";
    while (Cabecera1 != NULL) {
        grafo += "X" + to_string(Cabecera1->Header) + "[width = 1.5 style = filled , group =" +
                 to_string(Cabecera1->Header) + "];\n";
        if (Cabecera1->NextHeader != NULL) {
            grafo += "X" + to_string(Cabecera1->Header) + "-> X" + to_string(Cabecera1->NextHeader->Header) +
                     "[dir=both];\n";
            grafo += "{ rank = same; X" + to_string(Cabecera1->Header) + ";X" +
                     to_string(Cabecera1->NextHeader->Header) + " }\n";
        }
        grafo += "X" + to_string(Cabecera1->Header) + "-> n" +
                 std::to_string(Cabecera1->Colum.FirstNodeCentralV->ColMatrix) +
                 std::to_string(Cabecera1->Colum.FirstNodeCentralV->RowMatrix) + "[dir=both]; \n";
        Cabecera1 = Cabecera1->NextHeader;
    }


    grafo += "}";
    return grafo;

}
//*********************************** VERTICAL LIST *************************///////////

bool VerticalList::IsEmpty() {
    return FirstNodeCentralV == NULL;
}

void VerticalList::AddLateral(MatrixNode *&Node) {
    if (FirstNodeCentralV == NULL) {
        FirstNodeCentralV = EndNodeCentralV = Node;
    } else {
        if (Node->RowMatrix < FirstNodeCentralV->RowMatrix) {
            AddLateralStart(Node);
        } else if (Node->RowMatrix > FirstNodeCentralV->RowMatrix) {
            AddLateralInEnd(Node);
        } else {
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
    MatrixNode *Aux, *Aux2;
    Aux = FirstNodeCentralV;
    while (Aux->RowMatrix < Node->RowMatrix) {
        Aux = Aux->DownMatrix;
    }
    Aux2 = Aux->UpMatrix;
    Aux2->DownMatrix = Node;
    Aux->UpMatrix = Node;
    Node->DownMatrix = Aux;
    Node->UpMatrix = Aux2;
}

void VerticalList::GoVerticalList() {
    if (!IsEmpty()) {
        MatrixNode *Aux = FirstNodeCentralV;
        while (Aux != NULL) {
            cout << "Y = " + Aux->RowMatrix;
            Aux = Aux->DownMatrix;
        }
    }
}


//*********************************     HORIZONTAL LIST *************************///////////////
bool HorizontalList::IsEmpty() {
    return FirstNodeCentralH == NULL;
}


void HorizontalList::AddHorizontal(MatrixNode *&Node) {
    if (IsEmpty()) {
        FirstNodeCentralH = EndNodeCentralH = Node;
    } else {
        if (Node->ColMatrix < FirstNodeCentralH->ColMatrix) {
            AddHorizontalStart(Node);
        } else if (Node->ColMatrix > FirstNodeCentralH->ColMatrix) {
            AddHorizontalInEnd(Node);
        } else {
            AddHorizontalBetween(Node);
        }
    }
}

void HorizontalList::AddHorizontalStart(MatrixNode *&Node) {
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
    MatrixNode *Aux, *Aux2;
    Aux = FirstNodeCentralH;
    while (Aux->ColMatrix < Node->ColMatrix) {
        Aux = Aux->RightMatrix;
    }
    Aux2 = Aux->LeftMatrix;
    Aux2->RightMatrix = Node;
    Aux->LeftMatrix = Node;
    Node->RightMatrix = Aux;
    Node->LeftMatrix = Aux2;
}

void HorizontalList::GoHorizontalList() {
    if (!IsEmpty()) {
        MatrixNode *Aux = FirstNodeCentralH;
        while (Aux != NULL) {
            cout << "X = " + Aux->ColMatrix;
            Aux = Aux->RightMatrix;
        }
    }
}


//*******************************     CABEREA      *****************************///


bool Matrix::IsEmptyCabecera() {
    return FirstHeader == NULL;
}

NodeHeader *Matrix::New_Header(int Header) {

    NodeHeader *New_Header = new NodeHeader;
    New_Header->Header = Header;
    New_Header->NextHeader = NULL;
    New_Header->PreviousHeader = NULL;
    return New_Header;
}

void Matrix::InsertHeader(int Header) {
    NodeHeader *New_Node = New_Header(Header);
    if (FirstHeader == NULL) {
        FirstHeader = EndHeader = New_Node;
    } else {
        if (New_Node->Header < FirstHeader->Header) {
            InsertHeaderStart(New_Node);
        } else if (New_Node->Header > EndHeader->Header) {
            InsertHeaderInEnd(New_Node);
        } else {
            InsertHeaderBetween(New_Node);
        }
    }
}

void Matrix::InsertHeader2(NodeHeader *Header) {
    NodeHeader *New_Node = Header;
    if (FirstHeader == NULL) {
        FirstHeader = EndHeader = New_Node;
    } else {
        if (New_Node->Header < FirstHeader->Header) {
            InsertHeaderStart(New_Node);
        } else if (New_Node->Header > EndHeader->Header) {
            InsertHeaderInEnd(New_Node);
        } else {
            InsertHeaderBetween(New_Node);
        }
    }

}

void Matrix::InsertHeaderStart(NodeHeader *Header) {
    FirstHeader->PreviousHeader = Header;
    Header->NextHeader = FirstHeader;
    FirstHeader = FirstHeader->PreviousHeader;
}

void Matrix::InsertHeaderInEnd(NodeHeader *New_Header) {
    EndHeader->NextHeader = New_Header;
    New_Header->PreviousHeader = EndHeader;
    EndHeader = EndHeader->NextHeader;
}

void Matrix::InsertHeaderBetween(NodeHeader *New_Header) {
    NodeHeader *Aux, *Aux2;
    Aux = FirstHeader;
    while (Aux->Header < New_Header->Header) {
        Aux = Aux->NextHeader;
    }
    Aux2 = Aux->PreviousHeader;
    Aux2->NextHeader = New_Header;
    Aux->PreviousHeader = New_Header;
    New_Header->NextHeader = Aux;
    New_Header->PreviousHeader = Aux2;
}

void Matrix::CoverHeader() {
    if (FirstHeader != NULL) {
        NodeHeader *Aux = FirstHeader;
        while (Aux != NULL) {
            cout << "First Header" << Aux->Header << "\n";
            Aux = Aux->NextHeader;
        }
    }
}

bool Matrix::IsHeader(int Header) {
    if (FirstHeader == NULL) {
        return false;
    } else {
        NodeHeader *Aux = FirstHeader;
        while (Aux != NULL) {
            if (Aux->Header == Header) {
                return true;
            } else if (Aux->NextHeader == NULL) {
                return false;
            }
            Aux = Aux->NextHeader;
        }
        return false;
    }
}


NodeHeader *Matrix::SearchHeader(int Header) {
    if (IsHeader(Header)) {
        NodeHeader *Aux = FirstHeader;
        while (Aux->Header != Header) {
            Aux = Aux->NextHeader;
        }
        //cout << "Si se Encuentra Matrix \n";
        return Aux;
    } else {
        cout << "No se ha Encontrado";
        return New_Header(-1);
    }
}

void Matrix::PrintHeader() {
    NodeHeader *Aux = FirstHeader;
    while (Aux != NULL) {
        cout << Aux->Header << "->";
        Aux = Aux->NextHeader;
    }
}

string Matrix::DotHeader() {
    NodeHeader *Aux = FirstHeader;
    string Dot = "";
    string Rank = "rank =\"same\" terminal;";
    Dot += "subgraph cluster_0 {  \n";
    Dot += " rankdir=LR \n";
    Dot += "style=filled; \n";
    Dot += "color=lightgrey; \n";
    Dot += "node [style=filled,color=white]; \n";

    do {
        Dot += "n" + std::to_string(Aux->Header) + "[label=\"C: " + std::to_string(Aux->Header) + "\"];\n";
        if (Aux->NextHeader != NULL) {
            Rank += "n" + std::to_string(Aux->Header) + " ;";
            Dot += "n" + std::to_string(Aux->Header) + " -> n" + std::to_string(Aux->NextHeader->Header) + ";\n";
            Dot += "n" + std::to_string(Aux->NextHeader->Header) + " -> n" + std::to_string(Aux->Header) + ";\n";

        }
        Aux = Aux->NextHeader;
    } while (Aux != NULL && Aux != FirstHeader);
    Dot += Rank;
    Dot += "label = \"Headers \";\n";
    Dot += "} \n";
    return Dot;
}


//*********************************LATERAL*****************************************//////
bool Matrix::IsEmptyLateral() {
    bool a = false;
    if (FirstLateral == NULL) {
        a = true;
    } else {
        a = false;
    }
    return a;
}


NodeLateral *Matrix::Create_Lateral(int Lateral) {
    NodeLateral *New = new NodeLateral;
    New->Lateral = Lateral;
    New->NextLateral = NULL;
    New->PreviousLateral = NULL;
    return New;
}


void Matrix::AddLateral(int Lateral) {
    NodeLateral *New_Lateral = Create_Lateral(Lateral);
    if (FirstLateral == NULL) {
        FirstLateral = EndLateral = New_Lateral;
    } else {
        if (New_Lateral->Lateral < FirstLateral->Lateral) {
            AddLateralStart(New_Lateral);
        } else if (New_Lateral->Lateral > EndLateral->Lateral) {
            AddLateralInEnd(New_Lateral);
        } else {
            AddLateralBetween(New_Lateral);
        }
    }
}

void Matrix::AddLateral2(NodeLateral *&Lateral) {
    NodeLateral *New_Lateral = Lateral;
    if (FirstLateral == NULL) {
        FirstLateral = EndLateral = New_Lateral;
    } else {
        if (New_Lateral->Lateral < FirstLateral->Lateral) {
            AddLateralStart(New_Lateral);
        } else if (New_Lateral->Lateral > EndLateral->Lateral) {
            AddLateralInEnd(New_Lateral);
        } else {
            AddLateralBetween(New_Lateral);
        }
    }
}

void Matrix::AddLateralStart(NodeLateral *&New_Lateral) {
    FirstLateral->PreviousLateral = New_Lateral;
    New_Lateral->NextLateral = FirstLateral;
    FirstLateral = FirstLateral->PreviousLateral;
}

void Matrix::AddLateralInEnd(NodeLateral *&New_Lateral) {
    EndLateral->NextLateral = New_Lateral;
    New_Lateral->PreviousLateral = EndLateral;
    EndLateral = EndLateral->NextLateral;
}

void Matrix::AddLateralBetween(NodeLateral *&New_Lateral) {
    NodeLateral *Aux, *Aux2;
    Aux = FirstLateral;
    while (Aux->Lateral < New_Lateral->Lateral) {
        Aux = Aux->NextLateral;
    }
    Aux2 = Aux->PreviousLateral;
    Aux2->NextLateral = New_Lateral;
    Aux->PreviousLateral = New_Lateral;
    New_Lateral->NextLateral = Aux;
    New_Lateral->PreviousLateral = Aux2;
}

void Matrix::CoverLaterales() {
    if (FirstLateral != NULL) {
        NodeLateral *Aux = FirstLateral;
        while (Aux != NULL) {
            cout << "F: " << Aux->Lateral << "\n";
            Aux = Aux->NextLateral;
        }
    }
}

bool Matrix::IsLateral(int Lateral) {
    if (FirstLateral == NULL) {
        return false;
    } else {
        NodeLateral *Aux = FirstLateral;
        while (Aux != NULL) {
            if (Aux->Lateral == Lateral) {
                return true;
            } else if (Aux->NextLateral == NULL) {
                return false;
            }
            Aux = Aux->NextLateral;
        }
        return false;
    }
}

NodeLateral *Matrix::SearchLateral(int Lateral) {
    if (IsLateral(Lateral)) {
        NodeLateral *Aux = FirstLateral;
        while (Aux->Lateral != Lateral) {
            Aux = Aux->NextLateral;
        }
        return Aux;
    } else {
        return Create_Lateral(-1);
    }
}

void Matrix::PrintLaterales() {
    NodeLateral *Aux = FirstLateral;
    do {
        cout << "F: " << Aux->Lateral << "\n";
        Aux = Aux->NextLateral;
    } while (Aux != NULL && Aux != FirstLateral);
}

string Matrix::DotLaterales() {
    NodeLateral *Aux = FirstLateral;
    string Dot = "subgraph cluster_1 {  \n";
    Dot += "style=filled; \n";
    Dot += "color=lightgrey; \n";
    Dot += "node [style=filled,color=red]; \n";
    do {
        Dot += "n" + std::to_string(Aux->Lateral) + "[label=\"F: " + std::to_string(Aux->Lateral) + "\"];\n";
        if (Aux->NextLateral != NULL) {
            Dot += "n" + std::to_string(Aux->Lateral) + " -> n" + std::to_string(Aux->NextLateral->Lateral) + ";\n";
            Dot += "n" + std::to_string(Aux->NextLateral->Lateral) + " -> n" + std::to_string(Aux->Lateral) + ";\n";
        }
        Aux = Aux->NextLateral;
    } while (Aux != NULL && Aux != FirstLateral);

    Dot += "label = \"Laterales \";\n";
    Dot += "} \n";
    return Dot;
}


//********************************CONVERTIR DE RGB A HEXA **************//////
string Matrix::TotalRGBaHexa(MatrixNode *&Temp) {
   /* std::stringstream ss;
    ss << "#";
    ss << std::hex << (Temp->ColorR << 16 | Temp->ColorG << 8 | Temp->ColorB);
    return  ss.c_str();
*/
}
