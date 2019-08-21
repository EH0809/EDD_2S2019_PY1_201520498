//
// Created by edgarh on 20/08/19.
//

#ifndef P1CLASES_NODEMATRIX_H
#define P1CLASES_NODEMATRIX_H
using namespace std;

struct MatrixNode{
    int RowMatrix;
    int ColMatrix;
    int NumLayer;
    int ColorR;
    int ColorG;
    int ColorB;
    MatrixNode *UpMatrix;
    MatrixNode *DownMatrix;
    MatrixNode *RightMatrix;
    MatrixNode *LeftMatrix;
    MatrixNode *FrontMatrix;
    MatrixNode *UnderMatrix;
};
class NodeMatrix {
public:

    MatrixNode *Create_NodeMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB);
    //void ADDMatrix(int layer_number,int Header, int Lateral, int ColorR, int ColorG, int ColorB);
    void InsertMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB);
    int Max_Headers();
    int Max_Laterales();
    //void FillInMatrix(string Ruta);
    MatrixNode *IsNode(int Header, int Lateral);
    MatrixNode *IsCoordinate(int Header, int Lateral);
    void Graph();
    string Dot(string dot);



};


#endif //P1CLASES_NODEMATRIX_H
