//
// Created by edgarh on 14/09/19.
//

#include "MatrixNegative.h"


void MatrixNegative::ADDCompleta(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    PunteroMatriz.AddMatrixC(Col,Fil,ColorR,ColorG,ColorB);
}


void MatrixNegative::GraficarCompleta() {
    string a ="";
    ofstream fd4("CompleteNegative.dot");
    a += PunteroMatriz.DotNegative(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
    cout << " GENERANDO IMAGEN  \n";
    string ab = "dot -Tpng CompleteNegative.dot -o CompleteNegative.png";
    const char *command = ab.c_str();
    system(command);
}

