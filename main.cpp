#include <iostream>
#include <vector>
#include <sstream>
#include "Structures/Matrix.h"
#include "Structures/BinaryTree.h"
#include "Structures/ListFilters.h"
#include "Structures/ListMatix.h"
#include "Structures/MatrixB.h"
#include "Structures/Grayscale.h"
#include "fstream"
#include <sys/stat.h>

Matrix MATRIX;
BinaryTree BTree;
ListFilters Filters;
ListMatix LMatrix;
//CompleteMatrix CMatrix;
MatrixB MatrixB;
Grayscale Grayscale;


int Image_width;
int Image_height;
int Pixel_width;
int Pixel_height;
int contadorLineal = 0;


using namespace std;

void MenuReports();

void Agregar();

void ADDFilters();

void ReadFirstArchive();

void ArchiveConfig(string Ruta);

void ReadCapa(string Ruta);

void ReadCapa1(string Archivo);

void EnviarAMatrix(int Header, int Lateral, int ColorR, int ColorG, int ColorB);

void ArchiveCapa(string Ruta);

void ReadCapas(string Ruta);

void ADDListMatix(int Id, string Name);

void MenuCapas();

void MenuCapasFiltros();

void MenuFiltros();

void InsertTree(string Name, string Ruta);

void GuardarNodeTree(string Name);

void ADDFiltrosCapas();

void EditMatrix();

int ContadorCapas;
int MaxCol;
int MaxFil;
string GeneralUser;
string Capas = "";
MatrixList *TempMatrix;
ListaNodeBB *TempNodeBB;
NodeBB *TempInsert;
int ContadorImagen = 1;

void MandarAMatriz();

void DesEncapar();

void All();

void Individual();

void AllFilters();

void EditMatrixFilter();

void MenuEdit();

void Export();

string Name;
int Tamanio;

void EnviarTamanio();

void MenuExport();

void MenuExportCapas();

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
                //
                TempInsert = NULL;
                ReadFirstArchive();
                /*LMatrix.PrintList();
                LMatrix.ADDMatrix();
                LMatrix.MandarTamanio(Image_width, Image_height);
                LMatrix.GraficarLFilas();
                LMatrix.MandarHtml();
                LMatrix.MandarCSS(Image_width, Image_height, Pixel_width, Pixel_height);
                 */
                MandarAMatriz();
                BTree.PN();
                BTree.PNPre();
                BTree.PNPost();
                TempInsert = NULL;
                break;
            case 2:
                cout << "Select Image \n";
                BTree.PrintNode();
                cout << "Insert the name of your choice \n";
                cin >> Name;
                TempInsert = BTree.SentFor(Name);
                EnviarTamanio();
                BTree.RestValues();
                break;
            case 3:
                //ADDFilters();
                MenuFiltros();
                break;
            case 4:
                MenuEdit();
                break;
            case 5:
                Export();
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
                MenuCapas();
                break;
            case 6:
                break;
            case 7:
                TempInsert->LFilters.GraphList();
                break;
            case 8:
                AllFilters();
                break;
            case 9:
                ab = 9;
                break;
        }
    }
}


void EnviarTamanio() {
    Tamanio = TempInsert->Image_width * TempInsert->Image_height;
    Image_width = TempInsert->Image_width;
    Image_height = TempInsert->Image_height;
    Pixel_height = TempInsert->Pixel_height;
    Pixel_width = TempInsert->Pixel_width;
}

void MenuFiltros() {
    bool a = false;
    int ab = 0;
    while (a != true) {
        cout << "Insert your Option \n";
        cout << "1. Complete Image \n";
        cout << "2. Layers \n";
        cout << "3. Exit \n";
        cin >> ab;
        switch (ab) {
            case 1:
                ADDFilters();
                break;
            case 2:
                ADDFiltrosCapas();
                break;
            case 3:
                a = true;
                break;
        }
    }
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
                    TempInsert->LFilters.InsertNodeFilter("NEGATIVE");
                    TempInsert->ListadeCapas.EnviarAConvertirNEGATIVE();
                    //TempInsert->MNegative.GraficarCompleta();
                    break;
                case 2:
                    cout << "GRAYSCALE \n";
                    TempInsert->LFilters.InsertNodeFilter("GRAYSCALE");
                    TempInsert->ListadeCapas.EnviarAConvertirGRAYSCALE();

                    //TempInsert->MGrayScale.GraficarCompleta();
                    break;
                case 3:
                    cout << "X-MIRROR \n";
                    TempInsert->LFilters.InsertNodeFilter("X_MIRROR");
                    TempInsert->ListadeCapas.EnviarAConvertirROTACIONESX(Image_width, Image_height);
                    break;
                case 4:
                    cout << "Y-MIRROR \n";
                    TempInsert->LFilters.InsertNodeFilter("Y_Mirror");
                    TempInsert->ListadeCapas.ADDMatrixY();
                    TempInsert->ListadeCapas.EnviarAConvertirROTACIONY(Image_width, Image_height);

                    //TempInsert->MRotationY.GraficarCompleta();
                    break;
                case 5:
                    cout << "DOUBLE MIRROR \n";
                    TempInsert->LFilters.InsertNodeFilter("DOUBLE MIRROR");
                    TempInsert->ListadeCapas.ADDMatrixY();
                    TempInsert->ListadeCapas.EnviarAConvertirROTACIONY(Image_width, Image_height);
                    break;
                case 6:
                    cout << "COLLAGE\n";
                    TempInsert->LFilters.InsertNodeFilter("COLLAGE");
                    break;
                case 7:
                    cout << "MOSAIC\n";
                    TempInsert->LFilters.InsertNodeFilter("MOSAIC");
                    break;
                case 8:
                    a = 8;
                    break;
            }
        }
    }
}

void MandarAMatriz() {

    TempInsert->ListadeCapas.PrintList();
    TempInsert->ListadeCapas.ADDMatrix();
    TempInsert->ListadeCapas.MandarTamanio(Image_width, Image_height);
    //TempInsert->ListadeCapas.GraficarLFilas();
    //TempInsert->ListadeCapas.MandarHtml(TempInsert->Name);
    cout << "***************************\n";

}

void ReadFirstArchive() {
    string a = "";
    string b = "";
    cout << "Insert the Name file \n";
    cin >> a;
    std::ifstream Archivo(a);
    if (!Archivo.is_open()) cout << "Error al Abrir Primer Archivo \n";
    cout << "Insert the Name of Image\n";
    cin >> b;
    InsertTree(b, a);
    string Layer;
    string File;
    //BTree.InsertListNode(ContadorImagen,b);
    while (!Archivo.fail()) {
        getline(Archivo, Layer, ',');
        getline(Archivo, File, '\n');
        if (Layer != "Layer") {
            if (Layer == "0") {
                ArchiveConfig(File);
            } else if (Layer != "") {
                int Capa = atoi(Layer.c_str());
                ADDListMatix(Capa, File);
            }

        }
    }
    Archivo.close();
}

void InsertTree(string Name, string Ruta) {
    BTree.SendInsert(Name, Ruta);
    TempInsert = BTree.SentFor(Name);
}

void AllFilters() {
    bool a = false;
    int num;
    while (a != true) {
        cout << "1. All Filters Report \n";
        cout << "2. Individual Filter Report \n";
        cout << "3. Exit \n";
        cin >> num;

        switch (num) {
            case 1:
                All();
                break;
            case 2:
                Individual();
            case 3:
                a = true;
                break;

        }
    }
}

void All() {
    TempInsert->LFilters.PrintFilters();
}

void Individual() {
    int ab = 0;
    bool var1 = false;
    string var2;
    while (var1 != true) {
        if (TempInsert->LFilters.IsEmpety()) {
            cout << "No Filters Applied \n";
            var1 = true;
        } else {
            int ab;
            cout << "1. Negative \n";
            cout << "2. GrayScale \n";
            cout << "3. Mirror X \n";
            cout << "4. Mirror Y \n";
            cout << "5. Mirror XY \n";
            cout << "6. Exit \n";
            cin >> ab;
            int abcd;
            switch (ab) {
                case 1:
                    if (TempInsert->ListadeCapas.IsEmptyNegative() == false) {
                        TempInsert->ListadeCapas.MostarCapas();
                        cout << "Insert your Choise \n";
                        cin >> abcd;
                        TempInsert->ListadeCapas.GraphLayersNegative(abcd);

                    } else {
                        cout << "No Filters Applied \n ";
                    }
                    break;
                case 2:
                    if (TempInsert->ListadeCapas.IsEmptyGrayScale() == false) {
                        TempInsert->ListadeCapas.MostarCapas();
                        cout << "Insert your Choise \n";
                        cin >> abcd;
                        TempInsert->ListadeCapas.GraphLayers(abcd);
                    } else {
                        cout << "No Filters Applied \n ";
                    }
                    break;
                case 3:
                    if (TempInsert->ListadeCapas.IsEmptyMRX() == false) {
                        TempInsert->ListadeCapas.MostarCapas();
                        cout << "Insert your Choise \n";
                        cin >> abcd;
                        //TempInsert->ListadeCapas.GraphLayersNegative(abcd);
                    } else {
                        cout << "No Filters Applied \n ";
                    }
                    break;
                case 4:
                    if (TempInsert->ListadeCapas.IsEmptyMRY() == false) {
                        TempInsert->ListadeCapas.MostarCapas();
                        cout << "Insert your Choise \n";
                        cin >> abcd;
                        TempInsert->ListadeCapas.MandarAGraficarY(abcd);
                    } else {
                        cout << "No Filters Applied \n ";
                    }
                    break;
                case 5:
                    if (TempInsert->ListadeCapas.IsEmptyMRY() == false) {
                        TempInsert->ListadeCapas.MostarCapas();
                        cout << "Insert your Choise \n";
                        cin >> abcd;
                        TempInsert->ListadeCapas.MandarAGraficarYX(abcd);
                    } else {
                        cout << "No Filters Applied \n ";
                    }
                    break;
                case 6:
                    var1 = true;
                    break;

            }
        }
    }
}

/*
void ADDListMatix(int Id, string Name) {
    LMatrix.AddMatrixList(Id, Name);
    TempMatrix = LMatrix.SearchHeader(Id);
    ReadCapa(Name);
    TempMatrix->Archivo = Capas;
    Capas = "";
    //TempMatrix = NULL;
}
 */
void ADDListMatix(int Id, string Name) {
    TempInsert->ListadeCapas.AddMatrixList(Id, Name);
    TempMatrix = TempInsert->ListadeCapas.SearchHeader(Id);
    ReadCapa(Name);
    TempMatrix->Archivo = Capas;
    Capas = "";
    //TempMatrix = NULL;
}

void ArchiveConfig(string Ruta) {
    std::ifstream Archivo(Ruta);
    if (!Archivo.is_open()) cout << "Error Archivo Config \n";
    string Config;
    string Value;

    while (!Archivo.fail()) {
        getline(Archivo, Config, ',');
        getline(Archivo, Value, '\n');
        if (Config != "Confing" && Value != "Value") {
            if (Config == "image_width") {
                Image_width = stoi(Value);
                TempInsert->Image_width = Image_width;
            } else if (Config == "image_height") {
                Image_height = stoi(Value);
                TempInsert->Image_height = Image_height;
            } else if (Config == "pixel_width") {
                Pixel_width = stoi(Value);
                TempInsert->Pixel_width = Pixel_width;
            } else if (Config == "pixel_height") {
                Pixel_height = stoi(Value);
                TempInsert->Pixel_height = Pixel_height;
            }
        }

    }
    cout << "Configuration File \n";
    cout << "image_width:" << Image_width << "\n";
    cout << "image_height:" << Image_height << "\n";
    cout << "Pixel_width:" << Pixel_width << "\n";
    cout << "Pixel_height:" << Pixel_height << "\n";
    cout << "****************************\n";
    Archivo.close();
}

void ReadCapa(string Ruta) {
    ifstream file(Ruta);
    if (!file) {
        cout << "Error Leer Capa \n";
    }
    string linea, archivo;
    while (getline(file, linea)) {
        archivo += linea + "\n";
    }

    ReadCapas(archivo);
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
    string aux77 = "";
    string aux9 = "";
    int ContadorFilas = 1;
    int ContadorColumnas = 1;
    int ContadorMaxCol;
    while (!ss.fail()) {
        while (getline(ss, aux, ',')) {
            if (aux != "x") {
                //if (aux != "x\nx") {
                if (ContadorColumnas <= Image_width) {
                    if (ContadorColumnas == Image_width) {
                        //if (ContadorColumnas == ColMAix) {
                        stringstream aux5(aux);
                        getline(aux5, aux6, '\n');
                        getline(aux5, ColorR, '-');
                        getline(aux5, ColorG, '-');
                        getline(aux5, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());
                        if (R != 0) {
                            aux4 += "Col:" + to_string(ContadorColumnas) + " Fil:" + to_string(ContadorFilas) +
                                    " ColorR: " + to_string(R) + " ColorG: " + to_string(G) + " ColorB:" +
                                    to_string(B) +
                                    "\n";
                            Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                    "," + to_string(G) + "," + to_string(B) + "\n";

                        }
                        ContadorColumnas = 0;
                        ContadorFilas++;
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

                        //   TempMatrix->PunteroMatrix.InsertMatrix(ContadorColumnas,ContadorFilas,R,G,B);
                    }
                } else {
                    //ContadorMaxCol = ContadorColumnas;
                    ContadorColumnas = 1;
                    ContadorFilas++;
                }
            }
            ContadorColumnas++;
        }
    }
    Capas = Temp;
    cout << "Hola";
    cout << Capas;
}

void ReadCapas(string Archivo) {
    std::stringstream ss(Archivo);
    string aux;
    string aux2;
    string aux6;
    string Temp = "";
    string ColorR = "";
    string ColorG = "";
    string ColorB = "";
    string aux4 = "";
    string aux9 = "";
    int contadorL = 0;
    int ContadorFilas = 1;
    int ContadorColumnas = 1;
    while (getline(ss, aux)) {
        stringstream aux777(aux);
        while (!aux777.fail()) {
            while (getline(aux777, aux, ',')) {
                contadorL++;
                if (aux != "x") {
                    if (ContadorColumnas != Image_width) {
                        stringstream aux5(aux);
                        getline(aux5, ColorR, '-');
                        getline(aux5, ColorG, '-');
                        getline(aux5, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());

                        Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                "," + to_string(G) + "," + to_string(B) + "," + to_string(contadorL) + "\n";

                        //   TempInsert->CM.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //   TempInsert->MNegative.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //   TempInsert->MGrayScale.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //  TempInsert->MRotationY.AddMatrixC(ContadorColumnas,ContadorFilas,R,G,B);
                        //  TempInsert->MRotationX.AddMatrixC(ContadorColumnas,ContadorFilas,R,G,B);


                    } else if (ContadorColumnas == Image_width) {
                        stringstream aux7(aux);
                        getline(aux7, ColorR, '-');
                        getline(aux7, ColorG, '-');
                        getline(aux7, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());
                        Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                "," + to_string(G) + "," + to_string(B) + "," + to_string(contadorL) + "\n";

                        //  TempInsert->CM.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //  TempInsert->MNegative.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //  TempInsert->MGrayScale.ADDCompleta(ContadorColumnas,ContadorFilas,R,G,B);
                        //  TempInsert->MRotationY.AddMatrixC(ContadorColumnas,ContadorFilas,R,G,B);
                    }
                }
                if (ContadorColumnas == Image_width) {
                    ContadorColumnas = 1;
                    ContadorFilas++;
                } else {
                    ContadorColumnas++;
                }
            }
        }
    }

    Capas = Temp;
    contadorL = 0;
}

void MenuCapas() {
    int ab = 0;
    TempInsert->ListadeCapas.MostarCapas();
    cout << "20. All Layers \n";
    cout << "Insert your Choise \n";
    cin >> ab;
    if (ab != 20) {
        TempInsert->ListadeCapas.GraphCapas(ab);
    } else {
        TempInsert->ListadeCapas.AllLayers();
    }
}

void MenuCapasFiltros() {
    int ab = 0;
    TempInsert->ListadeCapas.MostarCapas();
    cout << "Insert your Choise \n";
    cin >> ab;
    //LMatrix.GrayscapeCapas(ab);
//    LMatrix.NegativeCapas(ab);

}

void ADDFiltrosCapas() {
    if (GeneralUser != " ") {
        int a = 0;
        int ab = 0;
        TempInsert->ListadeCapas.MostarCapas();
        cout << "Insert your Choise \n";
        cin >> ab;
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
                    TempInsert->ListadeCapas.MandarNEGATIVECAPA(ab);
                    TempInsert->ListadeCapas.MandarCSSNEGATIVECApa(ab);
                    TempInsert->ListadeCapas.MandarHtmNEGATIVElCAPA(TempInsert->Name, TempInsert->Image_width,
                                                                    TempInsert->Image_height);
                    TempInsert->ListadeCapas.MandarCSSNEGATIVECAPA(Image_width, Image_height, Pixel_width, Pixel_height,
                                                                   TempInsert->Name);

                    //TempInsert->ListadeCapas.GraphLayersNegative(ab);
                    break;
                case 2:
                    cout << "GRAYSCALE \n";
                    Filters.InsertNodeFilter("GRAYSCALE");
                    TempInsert->ListadeCapas.MandarGRAYCAPA(ab);
                    TempInsert->ListadeCapas.MandarCSSGrayCApa(ab);
                    TempInsert->ListadeCapas.MandarHtmGRAYSCALElCAPA(TempInsert->Name, TempInsert->Image_width,
                                                                     TempInsert->Image_height);
                    TempInsert->ListadeCapas.MandarCSSGRAYSCALElCAPA(Image_width, Image_height, Pixel_width,
                                                                     Pixel_height, TempInsert->Name);
                    //TempInsert->ListadeCapas.GraphLayers(ab);
                    break;
                case 3:
                    cout << "X-MIRROR \n";
                    Filters.InsertNodeFilter("X_MIRROR");
                    break;
                case 4:
                    cout << "Y-MIRROR \n";
                    Filters.InsertNodeFilter("Y_MIRROR");
                    TempInsert->ListadeCapas.MandarAGraficarY(2);
                    //  LMatrix.MandarRotacionY();
                    //  LMatrix.CreatHTMLRY();
                    //  LMatrix.CSSRY(Image_width,Image_height,Pixel_width,Pixel_height);
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


void MenuEdit() {
    bool var1 = false;
    int var2;
    while (var1 != true) {
        cout << "1. Original Image \n";
        cout << "2. Filters Image \n";
        cout << "3. Exit \n";
        cin >> var2;
        switch (var2) {
            case 1:
                cout << "Original Image \n";
                EditMatrix();
                break;
            case 2:
                cout << "Filters Image \n";
                EditMatrixFilter();
                break;
            case 3:
                var1 = true;
                break;
        }
    }

}

void EditMatrix() {
    int ab;
    int EditRow;
    int EditCol;
    int EditColorR;
    int EditColorG;
    int EditColorB;
    TempInsert->ListadeCapas.MostarCapas();
    cout << "Insert your Choise \n";
    cin >> ab;
    cout << "Insert Col \n";
    cin >> EditCol;
    cout << "Insert Row \n";
    cin >> EditRow;
    cout << "Insert Color R \n";
    cin >> EditColorR;
    cout << "Insert Color G \n";
    cin >> EditColorG;
    cout << "Insert Color B \n";
    cin >> EditColorB;
    TempInsert->ListadeCapas.EditNodeMatrix(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
    TempInsert->ListadeCapas.UpdateNodeLinealizar2(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
    TempInsert->ListadeCapas.IntentoMandarHtml1("M" + TempInsert->Name, TempInsert->Image_width,
                                                TempInsert->Image_height);
    TempInsert->ListadeCapas.IntentoMandarCSS1(Image_width, Image_height, Pixel_width, Pixel_height,
                                               "M" + TempInsert->Name);

}

void EditMatrixFilter() {
    int ab;
    if (TempInsert->LFilters.IsEmpety() == false) {
        TempInsert->LFilters.PrintFilters();
        cout << "Write your Choise \n";
        string choise;
        cin >> choise;
        TempInsert->ListadeCapas.MostarCapas();
        cout << "Insert your Choise \n";
        cin >> ab;
        int EditRow;
        int EditCol;
        int EditColorR;
        int EditColorG;
        int EditColorB;
        cout << "Insert Col \n";
        cin >> EditCol;
        cout << "Insert Row \n";
        cin >> EditRow;
        cout << "Insert Color R \n";
        cin >> EditColorR;
        cout << "Insert Color G \n";
        cin >> EditColorG;
        cout << "Insert Color B \n";
        cin >> EditColorB;
        if (choise == "NEGATIVE") {
            TempInsert->ListadeCapas.EditNodeMatrix(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
            TempInsert->ListadeCapas.UpdateNodeLinealizar2(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
            TempInsert->ListadeCapas.MandarHtmNEGATIVElCAPA("EditNegative"+TempInsert->Name, TempInsert->Image_width,
                                                            TempInsert->Image_height);
            TempInsert->ListadeCapas.MandarCSSNEGATIVECAPA(Image_width, Image_height, Pixel_width, Pixel_height,
                                                           "EditNegative"+TempInsert->Name);

        } else if (choise == "GRAYSCALE"|| choise == "grayscale") {
            TempInsert->ListadeCapas.EditNodeMatrix(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
            TempInsert->ListadeCapas.UpdateNodeLinealizar2(ab, EditCol, EditRow, EditColorR, EditColorG, EditColorB);
            TempInsert->ListadeCapas.MandarHtmGRAYSCALEl("EditGrayScale"+TempInsert->Name, TempInsert->Image_width,
                                                         TempInsert->Image_height);
            TempInsert->ListadeCapas.MandarCSSGRAYSCALEl(Image_width, Image_height, Pixel_width, Pixel_height,
                                                         "EditGrayScale"+TempInsert->Name);


        } else if (choise == "X_MIRROR") {

        } else if (choise == "Y_MIRROR") {

        }

    } else {
        cout << "No Filters Applied \n ";
    }
}


void Export() {
    TempInsert->ListadeCapas.IntentoMandarHtml1(TempInsert->Name, Image_width, Image_height);
    TempInsert->ListadeCapas.IntentoMandarCSS1(Image_width, Image_height, Pixel_width, Pixel_height, TempInsert->Name);
    if (TempInsert->ListadeCapas.IsEmptyNegative() == false) {
        TempInsert->ListadeCapas.MandarHTMLNEGATIVE(TempInsert->Name, TempInsert->Image_width,
                                                    TempInsert->Image_height);
        TempInsert->ListadeCapas.MandarCSSNEGATIVE(Image_width, Image_height, Pixel_width, Pixel_height,
                                                   TempInsert->Name);

    } else if (TempInsert->ListadeCapas.IsEmptyGrayScale() == false) {
        TempInsert->ListadeCapas.MandarHtmGRAYSCALEl(TempInsert->Name, TempInsert->Image_width,
                                                     TempInsert->Image_height);
        TempInsert->ListadeCapas.MandarCSSGRAYSCALEl(Image_width, Image_height, Pixel_width, Pixel_height,
                                                     TempInsert->Name);

    } else if (TempInsert->ListadeCapas.IsEmptyMRY() == false) {
        TempInsert->ListadeCapas.MandarHTMLROTACIONY(TempInsert->Name, TempInsert->Image_width,
                                                     TempInsert->Image_height);
        TempInsert->ListadeCapas.MandarCSSROTACIONY(Image_width, Image_height, Pixel_width, Pixel_height,
                                                    TempInsert->Name);
    }

}
/*
void ReadCapas(string Archivo) {
    std::stringstream ss(Archivo);
    string aux;
    string aux2;
    string aux6;
    int contadorLineal =1;
    string Temp = "";
    string ColorR = "";
    string ColorG = "";
    string ColorB = "";
    string aux4 = "";
    string aux9 = "";
    int ContadorFilas = 1;
    int ContadorColumnas = 1;
    while (getline(ss, aux)) {
        stringstream aux777(aux);
        while (!aux777.fail()) {
            while (getline(aux777, aux, ',')) {
                if (aux != "x") {
                    if (ContadorColumnas != Image_width) {
                        stringstream aux5(aux);
                        //getline(aux5, aux6, '\n');
                        getline(aux5, ColorR, '-');
                        getline(aux5, ColorG, '-');
                        getline(aux5, ColorB, '-');
                        int R = std::atoi(ColorR.c_str());
                        int G = std::atoi(ColorG.c_str());
                        int B = std::atoi(ColorB.c_str());
                        if (R != 0) {
                            aux4 += "Col:" + to_string(ContadorColumnas) + " Fil:" + to_string(ContadorFilas) +
                                    " ColorR: " + to_string(R) + " ColorG: " + to_string(G) + " ColorB:" +
                                    to_string(B) +
                                    "\n";
                            Temp += to_string(ContadorColumnas) + "," + to_string(ContadorFilas) + "," + to_string(R) +
                                    "," + to_string(G) + "," + to_string(B) + ","+to_string(contadorLineal)+"\n";

                        }


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
                                "," + to_string(G) + "," + to_string(B) +","+to_string(contadorLineal)+ "\n";

                        //   TempMatrix->PunteroMatrix.InsertMatrix(ContadorColumnas,ContadorFilas,R,G,B);
                        ContadorColumnas = 0;
                        ContadorFilas++;
                        contadorLineal++;
                    }
                }
                if (ContadorColumnas == Image_width) {
                    ContadorColumnas = 1;
                    ContadorFilas++;
                    contadorLineal++;
                } else {
                    ContadorColumnas++;
                }
            }
        }
    }

    Capas = Temp;
}
*/

/*
void DesEncapar() {

    string Archivo = Capas;
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
        if (TempMatrix->PunteroMatrix.IsEmptyLateral() == true && TempMatrix->PunteroMatrix.IsEmptyCabecera() == true) {
            cout << "Nombre Matrix: " + TempMatrix->Name << "\n";
        }
        TempMatrix->PunteroMatrix.InsertMatrix(Columna, Fila, ColorR, ColorG, ColorB);
    }

    Capas = "";
}
*/

