#include <iostream>
#include <vector>
#include <sstream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"
#include "Structures/ListFilters.h"
#include "fstream"

Matrix MATRIX;
BinaryTree BTree;
ListFilters Filters;

using namespace std;

void MenuReports();

void Agregar();

void ADDFilters();

void ReadFirstArchive();

void ArchiveConfig(string Ruta);

void ReadCapa(string Ruta, string Profundidad);

void ReadCapa1(string Archivo);

void EnviarAMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB);

void ArchiveCapa(string Ruta);

int ContadorCapas;
int MaxCol;
int MaxFil;
string GeneralUser;
string Capas = "";

void DesEncapar(string Archivo);


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
                //Agregar();
                //ReadFirstArchive();
                ReadCapa("capad1.csv", "1");
                DesEncapar(Capas);
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
                GeneralUser = BTree.User;
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
    while (ab != 9) {
        cout << "1. Binary Search Tree \n";
        cout << "2. InOrder Traversal \n";
        cout << "3. PreOrder Traversal \n";
        cout << "4. PostOrder Traversal \n";
        cout << "5. Image Layer Report \n";
        cout << "6. Linear Matrix Report \n";
        cout << "7. Filters Report \n";
        cout << "8. Matix Report\n";
        cout << "9. Exit \n";
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
                MATRIX.Graph();
                break;
            case 9:
                ab = 9;
                break;
        }
    }
}

void Agregar() {
    cout << "Node Matrix \n";
    /*
    MATRIX.InsertMatrix(15, 10, 255, 229, 204);
    MATRIX.InsertMatrix(3, 6, 255, 229, 204);
    MATRIX.InsertMatrix(5, 2, 255, 229, 204);
    MATRIX.InsertMatrix(16, 11, 255, 229, 204);
    MATRIX.InsertMatrix(4, 1, 255, 229, 204);
    MATRIX.InsertMatrix(1, 1, 255, 229, 204);
    MATRIX.InsertMatrix(2, 2, 255, 229, 204);
    MATRIX.InsertMatrix(2, 3, 255, 229, 204);
    MATRIX.InsertMatrix(15, 1, 255, 229, 204);
    MATRIX.InsertMatrix(15, 2, 255, 229, 204);
    MATRIX.InsertMatrix(15, 3, 255, 229, 204);
    MATRIX.InsertMatrix(15, 10, 255, 229, 204);
    MATRIX.InsertMatrix(3, 6, 255, 229, 204);
    MATRIX.InsertMatrix(5, 2, 255, 229, 204);
    MATRIX.InsertMatrix(16, 11, 255, 229, 204);
*/
    MATRIX.InsertMatrix(4, 2, 225, 268, 251);
    MATRIX.InsertMatrix(5, 2, 228, 147, 369);
    MATRIX.InsertMatrix(6, 2, 147, 369, 258);
    MATRIX.InsertMatrix(7, 2, 789, 456, 123);
    MATRIX.InsertMatrix(4, 3, 789, 999, 888);
    MATRIX.InsertMatrix(5, 3, 777, 888, 444);
    MATRIX.InsertMatrix(6, 3, 888, 555, 777);
    MATRIX.InsertMatrix(7, 3, 888, 222, 333);
    MATRIX.InsertMatrix(4, 4, 456, 777, 888);
    MATRIX.InsertMatrix(5, 4, 555, 666, 777);
    MATRIX.InsertMatrix(6, 4, 111, 555, 999);
    MATRIX.InsertMatrix(7, 4, 777, 444, 666);
    MATRIX.InsertMatrix(2, 5, 111, 222, 333);
    MATRIX.InsertMatrix(3, 5, 777, 888, 999);
    MATRIX.InsertMatrix(4, 5, 222, 666, 444);
    MATRIX.InsertMatrix(5, 5, 456, 465, 456);
    MATRIX.InsertMatrix(6, 5, 852, 741, 456);
    MATRIX.InsertMatrix(7, 5, 741, 852, 741);
    MATRIX.InsertMatrix(8, 5, 123, 741, 148);
    MATRIX.InsertMatrix(9, 5, 357, 15, 852);
    MATRIX.InsertMatrix(4, 6, 666, 888, 999);
    MATRIX.InsertMatrix(5, 6, 123, 456, 852);
    MATRIX.InsertMatrix(6, 6, 852, 741, 632);
    MATRIX.InsertMatrix(7, 6, 852, 963, 741);
    MATRIX.InsertMatrix(4, 7, 666, 999, 444);
    MATRIX.InsertMatrix(5, 7, 789, 456, 147);
    MATRIX.InsertMatrix(6, 7, 456, 796, 632);
    MATRIX.InsertMatrix(7, 7, 852, 456, 753);
    MATRIX.InsertMatrix(4, 8, 777, 888, 222);
    MATRIX.InsertMatrix(5, 8, 123, 147, 852);
    MATRIX.InsertMatrix(6, 8, 456, 789, 154);
    MATRIX.InsertMatrix(7, 8, 741, 789, 541);
    //MATRIX.Graph();
    cout << "En teoria si se agrego \n";
    cout << "Arbol Binario \n";
    BTree.SendInsert("Edgar");
    BTree.SendInsert("Maria");
    BTree.SendInsert("Alejandra");
    BTree.SendInsert("Lucia");
    BTree.SendInsert("Mario2");


}

void ADDFilters() {
    if (GeneralUser != " ") {
        int a = 0;
        while (a != 8) {
            cout << "Image:" + GeneralUser + "\n";
            cout << "1.  NEGATIVE\n";
            cout << "2.  GRAYSCALE\n";
            cout << "3. X-MIRROR\n";
            cout << "4. Y-MIRROR\n";
            cout << "5. DOUBLE MIRROR\n";
            cout << "6. COLLAGE\n";
            cout << "7. MOSAIC\n";
            cout << "8. EXIT\n";
            cout << "Insert your choise \n";
            cin >>
                a;
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
}

void ReadFirstArchive() {
    std::ifstream Archivo("prueba.csv");
    if (!Archivo.is_open()) cout << "Error \n";
    string Layer;
    string File;
    while (Archivo.good()) {
        getline(Archivo, Layer, ',');
        getline(Archivo, File, '\n');
        if (Layer != "Layer") {
            if (Layer == "0") {
                // ArchiveConfig(File);
            } else {
                ReadCapa(File, Layer);
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
    cout << "Archivo de Configuracion \n";
    cout << "image_width:" << Image_width << "\n";
    cout << "image_height:" << Image_height << "\n";
    cout << "Pixel_width:" << Pixel_width << "\n";
    cout << "Pixel_height:" << Pixel_height << "\n";
    Archivo.close();
}


void ReadCapa(string Ruta, string Profundidad) {
    ifstream file(Ruta);
    if (!file) {
        cout << "Error \n";
    }
    string linea, archivo;
    while (getline(file, linea)) {
        archivo += linea + "\n";
    }
    cout << archivo;
    ReadCapa1(archivo);
}

void ReadCapa1(string Archivo) {
    std::stringstream ss(Archivo);
    string aux;
    string aux2;
    string aux6;
    string Temp = "";
    string ColorR = "";
    string ColorG = "";
    string ColorB = "";
    string aux4 = "";
    int ContadorFilas = 1;
    int ContadorColumnas = 1;
    int ContadorMaxCol;
    while (ss.good()) {
        while (getline(ss, aux, ',')) {
            if (aux != "x") {
                if (aux != "x\nx") {
                    if (ContadorColumnas == ContadorMaxCol) {
                        stringstream aux5(aux);
                        getline(aux5, aux6, '\n');
                        getline(aux5, ColorR, '-');
                        getline(aux5, ColorG, '-');
                        getline(aux5, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());
                        aux4 += "Col:" + to_string(ContadorColumnas) + " Fil:" + to_string(ContadorFilas) +
                                " ColorR: " + to_string(R) + " ColorG: " + to_string(G) + " ColorB:" + to_string(B) +
                                "\n";
                        Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                "," + to_string(G) + "," + to_string(B) + "\n";
                        ContadorColumnas = 1;
                    } else {
                        stringstream aux7(aux);
                        getline(aux7, ColorR, '-');
                        getline(aux7, ColorG, '-');
                        getline(aux7, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());

                        aux4 += "Col:" + to_string(ContadorColumnas) + " Fil:" + to_string(ContadorFilas) +
                                " ColorR: " + to_string(R) + " ColorG: " + to_string(G) + " ColorB:" + to_string(B) +
                                "\n";

                        Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                "," + to_string(G) + "," + to_string(B) + "\n";
                    }
                } else {
                    ContadorMaxCol = ContadorColumnas;
                    ContadorColumnas = 1;
                    ContadorFilas++;
                }
            }
            ContadorColumnas++;

        }
    }
    cout << Temp;
    Capas = Temp;
   // DesEncapar(Capas);
}

void DesEncapar(string Archivo) {
    string Col;
    string Fil;
    string R;
    string G;
    string B;
    stringstream Aux(Archivo);
    while (!Aux.fail()) {
        getline(Aux, Col, ',');
        getline(Aux, Fil, ',');
        getline(Aux, R, ',');
        getline(Aux, G, ',');
        getline(Aux, B, '\n');
        int Columna = atoi(Col.c_str());
        int Fila = atoi(Fil.c_str());
        int ColorR = atoi(R.c_str());
        int ColorG = atoi(G.c_str());
        int ColorB = atoi(B.c_str());
        MATRIX.InsertMatrix(Columna,Fila,ColorR,ColorG,ColorG);
    }
}


void ArchiveCapa(string Ruta) {
    std::ifstream Archivo(Ruta);
    std::ifstream Archivo1(Ruta);
    if (!Archivo.is_open()) cout << "Error \n";
    string Valor;
    string ValorR;
    string ValorG;
    string ValorB;
    ContadorCapas++;
    int ContadorFilas = -1;
    int ContadorColumnas = 0;
    int ColorR;
    int ColorG;
    int ColorB;
    int Co = 0;
    while (Archivo.good()) {
        getline(Archivo, ValorB, '\n');
        if (Co == 0) {
            for (int i = 1; i <= ValorB.length(); i += 2) {
                ContadorColumnas++;
                Co = i;
            }
        }
    }
    Archivo.close();
    while (Archivo1.good()) {
        getline(Archivo1, ValorG, '\n');
        ContadorFilas++;
    }
    Archivo1.close();
    cout << "Tam fil:" + to_string(ContadorFilas) + "\n";
    cout << "Tam Col:" + to_string(ContadorColumnas) + "\n";
    MaxCol = ContadorColumnas;
    MaxFil = ContadorFilas;

}