//
// Created by edgarh on 9/09/19.
//

#include <fstream>
#include "Negative.h"


bool Negative::IsEmptyP() {
    return FirstNode == NULL;
}
NegativeNode *Negative::Create_Node(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    NegativeNode *New_Nodo = new NegativeNode;
    New_Nodo->Id = Id;
    New_Nodo->Col = Col;
    New_Nodo->Fil = Fil;
    New_Nodo->ColorR = ColorR;
    New_Nodo->ColorG = ColorG;
    New_Nodo->ColorB = ColorB;
    New_Nodo->ColorHexa = ColorHexa;
    New_Nodo->NextGray = NULL;
    return New_Nodo;

}

void Negative::AddNEGATIVE(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    NegativeNode *New_Nodo = Create_Node(Id, Col, Fil, ColorR, ColorG, ColorB, ColorHexa);
    if (IsEmptyP()) {
        FirstNode = EndNode = New_Nodo;
    } else {
        if (New_Nodo->Id < FirstNode->Id) {
            AddNEGATIVEEStart(New_Nodo);
        } else if (New_Nodo->Id > EndNode->Id) {
            AddNEGATIVEInEnd(New_Nodo);
        }else {
            AddNEGATIVEBetween(New_Nodo);
        }
    }
}

void Negative::AddNEGATIVEEStart(NegativeNode *&Node) {
    FirstNode->PreviuosGray = Node;
    Node->NextGray = FirstNode;
    FirstNode = FirstNode->PreviuosGray;
}

void Negative::AddNEGATIVEInEnd(NegativeNode *&Node) {
    EndNode->NextGray = Node;
    Node->PreviuosGray = EndNode;
    EndNode = EndNode->NextGray;
}

void Negative::AddNEGATIVEBetween(NegativeNode *&Node) {
    NegativeNode *Aux, *Aux2;
    Aux = FirstNode;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextGray;
    }
    Aux2 = Aux->PreviuosGray;
    Aux2->NextGray = Node;
    Aux->PreviuosGray= Node;
    Node->NextGray = Aux;
    Node->PreviuosGray = Aux2;

}

void Negative::Recibir(int WidthC, int HeightC, int WidthP, int HeightP) {
    WidthC = WidthC;
    HeightC = HeightC;
    WidthP= WidthP;
    HeightP = HeightP;
}
int Tamanio1;
void Negative::Tamanio(int Tama) {
    Tamanio1 = Tama;
}


void Negative::CreateHTML() {
    string a = "";
    ofstream fd4("Negative.html");
    a += Html(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

void Negative::CreateCSS(int WidthC, int HeightC, int WidthP, int HeightP) {
    string a = "";
    ofstream fd4("CssNegative.css");
    a += Css(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string Negative::Html(string html) {
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\"CssNegative.css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    int tam = Tamanio1;
    cout << tam + "\n";
    for (int i = 1; i <= tam; i++) {
        html += "<div class=\"pixel\"></div> \n";
    }
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string Negative::Css(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    NegativeNode *Aux = FirstNode;
    css += "body {\n"
           "  background: #333333;      /* Background color of the whole page */\n"
           "  height: 100vh;            /* 100 viewport heigh units */\n"
           "  display: flex;            /* defines a flex container */\n"
           "  justify-content: center;  /* centers the canvas horizontally */\n"
           "  align-items: center;      /* centers the canvas vertically */\n"
           "} \n";

    css += ".canvas {\n"
           "  width:" + to_string(TCanvasW) + "px;   /* Width of the canvas */\n"
                                              "  height:" + to_string(TConvasH) + "px;  /* Height of the canvas */\n"
                                                                                  "} \n";
    css += ".pixel {\n"
           "  width:" + to_string(WidthP) + "px;    /* Width of each pixel */\n"
                                            "  height:" + to_string(HeightP) + "px;   /* Height of each pixel */\n"
                                                                               "  float: left;    /* Everytime it fills the canvas div it will begin a new line */\n"
                                                                               "  box-shadow: 0px 0px 1px #fff;  /* Leave commented, showing the pixel boxes */\n"
                                                                               "} \n";
    while (Aux != NULL) {
        //css += Agrupar(Aux->ColorHexa);
        css += ".pixel:nth-child("+to_string(Aux->Id)+"){\n";
        css += "background:"+Aux->ColorHexa+";} \n";
        Aux = Aux->NextGray;
    }
    return css;
}


string Negative::MandarCSSNEgativo() {
    NegativeNode *Aux = FirstNode;
    string css ="";
    while (Aux != NULL) {
        css += ".pixel:nth-child("+to_string(Aux->Id)+"){\n";
        css += "background:"+Aux->ColorHexa+";} \n";
        Aux = Aux->NextGray;
    }
    return css;
}
/*
void Negative::MandarMatrix(int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    NegativeMatrix.AddMatrixC(Col,Fil,ColorR,ColorG,ColorB);
}

void Negative::GraphMatrix() {
    NegativeMatrix.GraficarMatrixC();
}
 */