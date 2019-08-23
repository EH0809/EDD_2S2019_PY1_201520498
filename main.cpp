#include <iostream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"

Matrix Matrix;
BinaryTree BTree;

using namespace std;
int main() {
    int aux = 0;
    cout<<"Node Matrix \n";
    Matrix.InsertMatrix(15,10,255,229,204);
    Matrix.InsertMatrix(3,6,255,229,204);
    Matrix.InsertMatrix(5,2,255,229,204);
    Matrix.InsertMatrix(16,11,255,229,204);
    Matrix.InsertMatrix(4,1,255,229,204);
    Matrix.InsertMatrix(1,1,255,229,204);
    Matrix.InsertMatrix(2,2,255,229,204);
    Matrix.InsertMatrix(2,3,255,229,204);
    Matrix.InsertMatrix(15,1,255,229,204);
    Matrix.InsertMatrix(15,2,255,229,204);
    Matrix.InsertMatrix(15,3,255,229,204);
    Matrix.Graph();
    cout<<"En teoria si se agrego \n";
    cout<<"Arbol Binario \n";
    BTree.SendInsert("Edgar");
    BTree.SendInsert("Aldair");
    BTree.SendInsert("Adriana");
    BTree.SendInsert("Sofia");
    BTree.SendInsert("Herrera");
    BTree.SendInsert("Hueco");
    BTree.SendInsert("Cerote");
    BTree.SendInsert("Malparido");



    BTree.Graph();

    return 0;
}