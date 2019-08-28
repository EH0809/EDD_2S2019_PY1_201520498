#include <iostream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"
#include "Structures/ListFilters.h"

Matrix Matrix;
BinaryTree BTree;
ListFilters Filters;

using namespace std;

void MenuReports();

void Agregar();

void ADDFilters();

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
                cout << "Insert your choise \n";
                cin >> aaa;
                BTree.SelectList(aaa + 1);
                BTree.RestValues();
                break;
            case 3:
                ADDFilters();
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
                a = 7;
                break;
        }
    }


    return 0;
}

void MenuReports() {
    int ab = 0;
    while (ab != 8) {
        cout << "1. Binary Search Tree \n";
        cout << "2. InOrder Traversal \n";
        cout << "3. PreOrder Traversal \n";
        cout << "4. PostOrder Traversal \n";
        cout << "5. Image Layer Report \n";
        cout << "6. Linear Matrix Report \n";
        cout << "7. Filters Report \n";
        cout << "8. Exit \n";
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
                break;
            case 7:
                Filters.GraphList();
                break;
            case 8:
                ab = 8;
                break;
        }
    }
}

void Agregar() {
    cout << "Node Matrix \n";
    Matrix.InsertMatrix(15, 10, 255, 229, 204);
    Matrix.InsertMatrix(3, 6, 255, 229, 204);
    Matrix.InsertMatrix(5, 2, 255, 229, 204);
    Matrix.InsertMatrix(16, 11, 255, 229, 204);
    Matrix.InsertMatrix(4, 1, 255, 229, 204);
    Matrix.InsertMatrix(1, 1, 255, 229, 204);
    Matrix.InsertMatrix(2, 2, 255, 229, 204);
    Matrix.InsertMatrix(2, 3, 255, 229, 204);
    Matrix.InsertMatrix(15, 1, 255, 229, 204);
    Matrix.InsertMatrix(15, 2, 255, 229, 204);
    Matrix.InsertMatrix(15, 3, 255, 229, 204);
    Matrix.Graph();
    cout << "En teoria si se agrego \n";
    cout << "Arbol Binario \n";
    BTree.SendInsert("Mario1");
    BTree.SendInsert("Geoff");
    BTree.SendInsert("Boo");
    BTree.SendInsert("Pickachu");
    BTree.SendInsert("Mario2");
    BTree.SendInsert("Mushroom");


}

void ADDFilters() {
    int a = 0;
    while (a != 8) {
        cout << "1.  NEGATIVE\n";
        cout << "2.  GRAYSCALE\n";
        cout << "3. X-MIRROR\n";
        cout << "4. Y-MIRROR\n";
        cout << "5. DOUBLE MIRROR\n";
        cout << "6. COLLAGE\n";
        cout << "7. MOSAIC\n";
        cout << "8. EXIT\n";
        cout << "Insert your choise \n";
        cin >> a;
        switch (a) {
            case 1:
                cout << "NEGATIVE \n";
                Filters.InsertNodeFilter("NEGATIVE");
                break;
            case 2:
                cout << "GRAYSCALE \n";
                Filters.InsertNodeFilter("GRAYSCALE");
                break;
            case 3:
                cout << "X-MIRROR \n";
                Filters.InsertNodeFilter("X_MIRROR");
                break;
            case 4:
                cout << "Y-MIRROR \n";
                Filters.InsertNodeFilter("Y_MIRROR");
                break;
            case 5:
                cout << "DOUBLE MIRROR \n";
                Filters.InsertNodeFilter("DOUBLE MIRROR");
                break;
            case 6:
                cout << "COLLAGE\n";
                Filters.InsertNodeFilter("COLLAGE");
                break;
            case 7:
                cout << "MOSAIC\n";
                Filters.InsertNodeFilter("MOSAIC");
                break;
            case 8:
                a = 8;
                break;
        }
    }
}
