//
// Created by edgarh on 7/09/19.
//

#include <fstream>
#include <sstream>
#include "LinearizeMatrix.h"

bool LinearizeMatrix::IsEmptyP() {
    return FirstLinearize == NULL;
}
Linearize *LinearizeMatrix::Create_Node(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB, string ColorHexa) {
    Linearize *New_Nodo = new Linearize;
    New_Nodo->Id = Id;
    New_Nodo->Col = Col;
    New_Nodo->Fil = Fil;
    New_Nodo->ColorR = ColorR;
    New_Nodo->ColorG = ColorG;
    New_Nodo->ColorB = ColorB;
    New_Nodo->ColorHexa = ColorHexa;
    New_Nodo->NextLinearize = NULL;
    return New_Nodo;

}

void LinearizeMatrix::AddLinearize(int Id, int Col, int Fil, int ColorR, int ColorG, int ColorB) {
    string ColorHexa = ConvertirAHexa(ColorR,ColorG,ColorB,true);
   // string ColorHexa = Conversor(ColorR,ColorG,ColorB);
    Linearize *New_Nodo = Create_Node(Id, Col, Fil, ColorR, ColorG, ColorB, ColorHexa);
    if (IsEmptyP()) {
        FirstLinearize = EndLinearize = New_Nodo;
    } else {
        if (New_Nodo->Id < FirstLinearize->Id) {
            AddLinearizeStart(New_Nodo);
        } else if (New_Nodo->Id > EndLinearize->Id) {
            AddLinearizeInEnd(New_Nodo);
        }else {
            AddLinearizeBetween(New_Nodo);
        }
    }
}

void LinearizeMatrix::AddLinearizeStart(Linearize *&Node) {
    FirstLinearize->PreviuosLinearize = Node;
    Node->NextLinearize = FirstLinearize;
    FirstLinearize = FirstLinearize->PreviuosLinearize;
}

void LinearizeMatrix::AddLinearizeInEnd(Linearize *&Node) {
    EndLinearize->NextLinearize = Node;
    Node->PreviuosLinearize = EndLinearize;
    EndLinearize = EndLinearize->NextLinearize;
}

void LinearizeMatrix::AddLinearizeBetween(Linearize *&Node) {
    Linearize *Aux, *Aux2;
    Aux = FirstLinearize;
    while (Aux->Id < Node->Id) {
        Aux = Aux->NextLinearize;

    }/*
    Aux = Aux->NextLinearize;
    Aux2 = Aux->NextLinearize;
    Aux2->PreviuosLinearize = Node;
    Aux->NextLinearize = Node;
    Node->PreviuosLinearize = Aux;
    Node->NextLinearize = Aux2;
    */
    Aux2 = Aux->PreviuosLinearize;
    Aux2->NextLinearize = Node;
    Aux->PreviuosLinearize = Node;
    Node->NextLinearize = Aux;
    Node->PreviuosLinearize = Aux2;

}


Linearize *LinearizeMatrix::SearchHeader(int Id) {
    if (IsMatrix(Id)) {
        Linearize *Aux = FirstLinearize;
        while (Aux->Id != Id) {
            Aux = Aux->NextLinearize;
        }
        cout << "Si se Encuentra en la ListaMatrix \n";
        return Aux;
    } else {
        cout << "No se ha Encontrado en la Lista";
        return Create_Node(0, 0, 0, 0, 0, 0, "");
    }
}

bool LinearizeMatrix::IsMatrix(int Id) {
    if (FirstLinearize == NULL) {
        return false;
    } else {
        Linearize *Aux = FirstLinearize;
        while (Aux != NULL) {
            if (Aux->Id == Id) {
                return true;
            } else if (Aux->NextLinearize == NULL) {
                return false;
            }
            Aux = Aux->NextLinearize;
        }
        return false;
    }
}

void LinearizeMatrix::PrintList() {
    Linearize *tem = FirstLinearize;
    while (tem != NULL) {
        cout << "Id: " + to_string(tem->Id) + " Color:" +tem->ColorHexa << "\n";
        tem = tem->NextLinearize;
    }
}
int Tama =0;

void LinearizeMatrix::Tamanio(int WidthM, int HeightM) {
    int j = WidthM * HeightM;
    Tama = j;
}

void LinearizeMatrix::CreateHTML() {
    string a = "";
    ofstream fd4("Imagen.html");
    a += Html(a);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

void LinearizeMatrix::CreateCSS(int WidthC, int HeightC, int WidthP, int HeightP) {
    string a = "";
    ofstream fd4("Css.css");
    a += Css(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string LinearizeMatrix::Html(string html) {
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\"Css.css\"> \n";
    html += "</head> \n <body> \n";
    html += "<div class=\"canvas\"> \n";
    int tam = Tama;
    cout << tam + "\n";
    for (int i = 1; i <= tam; i++) {
        html += "<div class=\"pixel\"></div> \n";
    }
    html += "</div>\n";
    html += "</body> \n";
    html += "</html> \n";
    return html;
}

string LinearizeMatrix::Css(string css, int WidthC, int HeightC, int WidthP, int HeightP) {
    int TCanvasW = WidthP * WidthC;
    int TConvasH = HeightP * HeightC;
    Linearize *Aux = FirstLinearize;
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
        Aux = Aux->NextLinearize;
    }
    return css;
}

string LinearizeMatrix::ConvertirAHexa(int ColorR, int ColorG, int ColorB, bool Con) {
    stringstream ss;
    if(Con){
        ss<<"#";
    }
    ss<< std::hex<< (ColorR << 16 |ColorG<< 8| ColorB);
    return  ss.str();

}

//***************************GRAYSCALE*********************////
void LinearizeMatrix::Convertir() {
    Linearize *LNew = FirstLinearize;
    while(LNew != NULL){
        GrayS(LNew);
        LNew = LNew->NextLinearize;
    }
}

void LinearizeMatrix::GrayS(Linearize *& Node) {
    int R = (Node->ColorR *0.3)+(Node->ColorG *0.59)+(Node->ColorB *0.11);
    int G = (Node->ColorR *0.3)+(Node->ColorG *0.59)+(Node->ColorB *0.11);
    int B = (Node->ColorR *0.3)+(Node->ColorG *0.59)+(Node->ColorB *0.11);
    /*int R = (255 - Node->ColorR);
    int G = (255- Node->ColorG);
    int B =  (255-Node->ColorB);
     */
    string Hexa = ConvertirAHexa(R,G,B,true);
    GNode.AddGRAYSCALE(Node->Id,Node->Col,Node->Fil,R,G,B,Hexa);
}

void LinearizeMatrix::CreateHTMLGRAYSCALE() {
    GNode.Tamanio(Tama);
    GNode.CreateHTML();
}
void LinearizeMatrix::CreateCSSGRAYSCALE(int WidthC, int HeightC, int WidthP, int HeightP) {
    GNode.CreateCSS(WidthC,HeightC,WidthP,HeightP);
}

string LinearizeMatrix::Conversor(int ColorR, int ColorG, int ColorB) {
    int dec_num, r;
    string hexdec_num="";
    string Total ="";
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    dec_num = ColorR;
    while(dec_num>0)
    {
        r = dec_num % 16;
        hexdec_num = hex[r] + hexdec_num;
        dec_num = dec_num/16;
    }
    Total = hexdec_num;

    int dec_numG, rG;
    string hexdec_numG="";
    dec_numG = ColorG;
    while(dec_numG>0)
    {
        rG = dec_numG % 16;
        hexdec_numG = hex[rG] + hexdec_numG;
        dec_numG = dec_numG/16;
    }
    Total += hexdec_numG;

    int dec_numB, rB;
    string hexdec_numB="";
    dec_numB = ColorB;
    while(dec_numB>0)
    {
        rB = dec_numB % 16;
        hexdec_numB = hex[rB] + hexdec_numB;
        dec_numB = dec_numB/16;
    }
    Total += hexdec_numB;
    string to = "#"+Total;

    return to;
}
//****************************** NEGATIVE **********************//////////
void LinearizeMatrix::ConvertirNEGATIVE() {
    Linearize *LNew = FirstLinearize;
    while(LNew != NULL){
        NEGATIVES(LNew);
        LNew = LNew->NextLinearize;
    }
}

void LinearizeMatrix::NEGATIVES(Linearize *& Node) {
    int R = (255 - Node->ColorR);
    int G = (255- Node->ColorG);
    int B =  (255-Node->ColorB);
    string Hexa = ConvertirAHexa(R,G,B,true);
    NNode.AddNEGATIVE(Node->Id,Node->Col,Node->Fil,R,G,B,Hexa);
}

void LinearizeMatrix::CreateHTMLNEGATIVE() {
    NNode.Tamanio(Tama);
    NNode.CreateHTML();
}
void LinearizeMatrix::CreateCSSNEGATIVE(int WidthC, int HeightC, int WidthP, int HeightP) {
    NNode.CreateCSS(WidthC,HeightC,WidthP,HeightP);
}


