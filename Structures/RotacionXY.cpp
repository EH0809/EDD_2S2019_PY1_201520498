//
// Created by edgarh on 21/09/19.
//

#include "RotacionXY.h"

RotacionNodeXY *RotacionXY::Create_Node(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    RotacionNodeXY *New_Nodo = new RotacionNodeXY;
    New_Nodo->Id = Id;
    New_Nodo->Col = Col;
    New_Nodo->Fil = Fil;
    New_Nodo->ColorR = ColorR;
    New_Nodo->ColorG = ColorG;
    New_Nodo->ColorB = ColorB;
    New_Nodo->ColorHexa = ColorHexa;
    New_Nodo->NextRotacion = NULL;
    New_Nodo->PreviousRotacion = NULL;
    return New_Nodo;

}

bool RotacionXY::IsEmptyP() {
    return  FirstRotation == NULL;
}
void RotacionXY::AddROTACIONY(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    RotacionNodeXY *New_Nodo = Create_Node(Id, Col, Fil, ColorR, ColorG, ColorB, ColorHexa);
    if (IsEmptyP()) {
        FirstRotation = EndRotation = New_Nodo;
    } else {
        if (New_Nodo->Id < FirstRotation->Id) {
            AddROTACIONYStart(New_Nodo);
        } else if (New_Nodo->Id > EndRotation->Id) {
            AddROTACIONYInEnd(New_Nodo);
        }else {
            AddROTACIONYBetween(New_Nodo);
        }
    }
}

void RotacionXY::AddROTACIONYStart(RotacionNodeXY *&Node) {
    FirstRotation->PreviousRotacion= Node;
    Node->NextRotacion = FirstRotation;
    FirstRotation = FirstRotation->PreviousRotacion;
}

void RotacionXY::AddROTACIONYInEnd(RotacionNodeXY *&Node) {
    EndRotation->NextRotacion = Node;
    Node->PreviousRotacion = EndRotation;
    EndRotation = EndRotation->NextRotacion;
}

void RotacionXY::AddROTACIONYBetween(RotacionNodeXY *&Node) {
    RotacionNodeXY *Aux, *Aux2;
    Aux = FirstRotation;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextRotacion;

    }
    Aux2 = Aux->PreviousRotacion;
    Aux2->NextRotacion = Node;
    Aux->PreviousRotacion= Node;
    Node->NextRotacion = Aux;
    Node->PreviousRotacion = Aux2;
}
int TAa;
void RotacionXY::T(int Tama) {
    TAa = Tama;
}

void RotacionXY::HTMLY() {
    string a = "";
    ofstream fd4("ROTATIONY.html");
    a += HtmlRY(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

void RotacionXY::CCSSY(int WidthC, int HeightC, int WidthP, int HeightP) {
    string a = "";
    ofstream fd4("CSSROTATIONY.css");
    a += CssRY(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string RotacionXY::HtmlRY(string html) {
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\"CSSROTATIONY.css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    int tam = TAa;
    for (int i = 1; i <= tam; i++) {
        html += "<div class=\"pixel\"></div> \n";
    }
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string RotacionXY::CssRY(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    RotacionNodeXY *Aux = FirstRotation;
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
        Aux = Aux->NextRotacion;
    }
    return css;
}

string RotacionXY::Rotacion() {
    RotacionNodeXY *Aux = FirstRotation;
    string css ="";
    while (Aux != NULL) {
        css += ".pixel:nth-child("+to_string(Aux->Id)+"){\n";
        css += "background:"+Aux->ColorHexa+";} \n";
        Aux = Aux->NextRotacion;
    }
    return css;
}
