#include <iostream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"

Matrix Matrix;
BinaryTree BTree;

using namespace std;

void MenuReports();
void Agregar();
void Select(int Id);
void SChoise();

int main() {
    int a = 0;
    while (a != 7) {
        cout << "1. Insert Image \n";
        cout << "2. Select Image\n";
        cout << "3. Apply Filters\n";
        cout << "4. Manual Editing\n";
        cout << "5. Export Image\n";
        cout << "6. Reports\n";
        cout << "7. Exit\n";
        cin >> a;
        switch (a) {
            case 1:
                cout << "File Upload \n";
                Agregar();
                BTree.PN();
                BTree.PNPre();
                BTree.PNPost();
                break;
            case 2:
                int aaa;
                cout << "Select Image \n";
                BTree.PrintNode();
                cout<<"Insert your choise \n";
                cin>>aaa;
                BTree.SelectList(aaa+1);
                BTree.RestValues();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Reports\n";
                MenuReports();
                a = 0;
                break;
            case 7:
                a =7;
                break;
        }
    }


    return 0;
}

void MenuReports() {
    int ab = 0;
    while (ab != 6) {
        cout << "1. Binary Search Tree \n";
        cout << "2. InOrder Traversal \n";
        cout << "3. PreOrder Traversal \n";
        cout << "4. PostOrder Traversal \n";
        cout << "5. Image Layer Report \n";
        cout << "6. Linear Matrix Report \n";
        cout << "7. Filters Report \n";
        cout << "6. Exit \n";
        cin >> ab;
        switch (ab) {
            case 1://Arbol
                BTree.Graph();
                break;
            case 2://InOrden
                BTree.GraphInOrder();
                break;
            case 3://PreOrden
                BTree.GraphPreOrder();
                break;
            case 4://PostOrden
                BTree.GraphPostOrder();
                break;
            case 5:
                break;
            case 6:
                ab = 6;
                break;
        }
    }
}

void Agregar(){
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
    BTree.SendInsert("Alejandra");
    BTree.SendInsert("Lucia");


}


