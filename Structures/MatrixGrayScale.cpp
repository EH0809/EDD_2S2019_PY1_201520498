//
// Created by edgarh on 14/09/19.
//

#include "MatrixGrayScale.h"
void MatrixGrayScale::ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    PunteroMatriz.AddMatrixC(Col,Fil,ColorR,ColorG,ColorB);
}


void MatrixGrayScale::GraficarCompleta() {
    string a ="";
    ofstream fd4("CompleteGrayScale.dot");
    a += PunteroMatriz.DotGrayScape(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN  \n";
    string ab = "dot -Tpng CompleteGrayScale.dot -o CompleteGrayScale.png";
    const char *command = ab.c_str();
    system(command);
}


void MatrixGrayScale::UpdateMatrixGrayScale(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    PunteroMatriz.EditNodeMatrix(Col,Fil,ColorR, ColorG, ColorB);
}