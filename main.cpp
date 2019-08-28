#include <iostream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"
#include "Structures/ListFilters.h"
#include "fstream"

Matrix Matrix;
BinaryTree BTree;
ListFilters Filters;

using namespace std;

void MenuReports();

void Agregar();

void ADDFilters();

void ReadFirstArchive();

void ArchiveConfig(string Ruta);


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
               // ReadFirstArchive();
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
    BTree.SendInsert("Edgar");
    BTree.SendInsert("Maria");
    BTree.SendInsert("Alejandra");
    BTree.SendInsert("Lucia");
    BTree.SendInsert("Mario2");



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

void ReadFirstArchive() {
    std::ifstream Archivo("prueba.csv");
    if (!Archivo.is_open()) cout << "Error \n";
    string Layer;
    string File;

    while (Archivo.good()) {
        getline(Archivo, Layer, ';');
        getline(Archivo, File, '\n');
        if (Layer != "File") {
            if (Layer == "0") {
                ArchiveConfig(File);
            }
        }
    }
    Archivo.close();
}

void ArchiveConfig(string Ruta) {
    std::ifstream Archivo(Ruta);
    if (!Archivo.is_open()) cout << "Error \n";
    string Config;
    string Value;
    int Image_width;
    int Image_height;
    int Pixel_width;
    int Pixel_height;
    while (Archivo.good()) {
        getline(Archivo, Config, ';');
        getline(Archivo, Value, '\n');
        if (Config != "Confing" && Value != "Value") {
            if (Config == "image_width") {
                Image_width = stoi(Value);
            } else if (Config == "image_height") {
                Image_height = stoi(Value);
            } else if (Config == "pixel_width") {
                Pixel_width = stoi(Value);
            } else if (Config == "pixel_height") {
                Pixel_height = stoi(Value);
            }
        }

    }
    cout<<"Archivo de Configuracion \n";
    cout<<"image_width:" <<Image_width<<"\n";
    cout<<"image_height:" <<Image_height<<"\n";
    cout<<"Pixel_width:" <<Pixel_width<<"\n";
    cout<<"Pixel_height:" <<Pixel_height<<"\n";
    Archivo.close();
}