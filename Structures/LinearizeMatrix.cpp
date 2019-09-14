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
    //string ColorHexa = Conversor(ColorR,ColorG,ColorB);
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

    }
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

void LinearizeMatrix::CreateHTML(string name) {
    string a = "";
    string nombre = name+".html";
    ofstream fd4(nombre);
    a += Html(a,name);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

void LinearizeMatrix::CreateCSS(int WidthC, int HeightC, int WidthP, int HeightP, string name) {
    string a = "";
    string nombre = name+".css";
    ofstream fd4(nombre);
    a += Css(a, WidthC, HeightC, WidthP, HeightP);
    fd4 << a;
    fd4.flush();
    fd4.close();
}

string LinearizeMatrix::Html(string html, string nombre) {
    html += "<!DOCTYPE html > \n";
    html += "<html> \n";
    html += "<head> \n";
    html += "<link rel=\"stylesheet\" href=\""+nombre+".css\"> \n";
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
string LinearizeMatrix::H1() {
    string html ="";
    for (int i = 1; i <= Tama; i++) {
        html += "<div class=\"pixel\"></div> \n";
    }
    return  html;
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

string LinearizeMatrix::C1() {
    string temp ="";
    Linearize *Aux = FirstLinearize;
    while (Aux != NULL) {
        //css += Agrupar(Aux->ColorHexa);
        temp += ".pixel:nth-child("+to_string(Aux->Id)+"){\n";
        temp += "background:"+Aux->ColorHexa+";} \n";
        Aux = Aux->NextLinearize;
    }
    return temp;
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
    Node->GNode.AddGRAYSCALE(Node->Id,Node->Col,Node->Fil,R,G,B,Hexa);
}

string LinearizeMatrix::TraerCSSGRAYSACLE() {
    Linearize *Aux = FirstLinearize;
    string a="";
    while(Aux != NULL){
        a += Aux->GNode.MandarCSS();
        Aux = Aux->NextLinearize;
    }
    return  a;
}

string LinearizeMatrix::Conversor(int ColorR, int ColorG, int ColorB) {
    int dec_num, r;
    string hexdec_num="";
    string Total ="";
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    dec_num = ColorR;
    if (dec_num ==0 ){
        Total ="00";
    }else{
        while(dec_num > 0)
        {
            r = dec_num % 16;
            Total = hex[r] + dec_num;
            dec_num = dec_num / 16;
        }
        if (Total == "1" | Total == "2" | Total == "3" | Total == "4" | Total == "5" | Total == "6" | Total == "7" | Total == "8" | Total == "9" | Total == "A" | Total == "B" | Total == "C" | Total == "D" | Total == "E" | Total == "F"){
            Total = "0" + dec_num;
        }else{
            Total = dec_num;
        }
    }
    int dec_numG, rG;
    string hexdec_numG="";
    dec_numG = ColorG;
    if (dec_numG ==0){
        Total = "00";
    }else{
        while(dec_numG > 0)
        {
            r = dec_numG % 16;
            Total = hex[r] + dec_numG;
            dec_numG = dec_numG / 16;
        }
        if (Total == "1" | Total == "2" | Total == "3" | Total == "4" | Total == "5" | Total == "6" | Total == "7" | Total == "8" | Total == "9" | Total == "A" | Total == "B" | Total == "C" | Total == "D" | Total == "E" | Total == "F"){
            Total += "0" + hexdec_numG;
        }else{
            Total += hexdec_numG;
        }
    }

    int dec_numB, rB;
    string hexdec_numB="";
    dec_numB = ColorB;
    if(dec_numB == 0){
        Total = "00";
    }else{
        while(dec_numB > 0)
        {
            r = dec_numB % 16;
            Total = hex[r] + dec_numB;
            dec_numB = dec_numB / 16;
        }
        if (Total == "1" | Total == "2" | Total == "3" | Total == "4" | Total == "5" | Total == "6" | Total == "7" | Total == "8" | Total == "9" | Total == "A" | Total == "B" | Total == "C" | Total == "D" | Total == "E" | Total == "F"){
            Total += "0" + dec_numB;
        }else{
            Total += dec_numB;
        }
    }
    string to = "#"+Total;
    return to;
}

//**************************NEGATIVE*************************
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
    Node->NNode.AddNEGATIVE(Node->Id,Node->Col,Node->Fil,R,G,B,Hexa);
    Node->NNode.MandarMatrix(Node->Col,Node->Fil,Node->ColorR,Node->ColorG,Node->ColorB);
}

string LinearizeMatrix::MandarAtraerNegativos() {
    Linearize *Aux = FirstLinearize;
    string a = "";
    while(Aux != NULL){
        a += Aux->NNode.MandarCSSNEgativo();
        Aux = Aux->NextLinearize;
    }
    return a ;
}

void LinearizeMatrix::SentGraph() {
    Linearize *Aux = FirstLinearize;
    string a = "";
    while(Aux != NULL){
        Aux->NNode.GraphMatrix();
        Aux = Aux->NextLinearize;
    }
}

//**********************ROTATION Y *****************************
int ContadorIds = 1;
int ContadorIds2 = 1;
int IdN = 1;

void LinearizeMatrix::ChangeId(int WidthC, int HeightC) {
    Linearize * Aux = FirstLinearize;
    string a ="";
    while(Aux != NULL){
        ChangeId2(Aux, WidthC, HeightC);

        Aux = Aux->NextLinearize;
    }
}

void LinearizeMatrix::ChangeId2(Linearize *&Node, int WidthC, int HeightC) {
    int a= WidthC *HeightC;
    int TempId = Node->Id;
    int TempCol = Node->Col;
    int TempFil = Node->Fil;
    int Total = a - (TempId-1);
    Node->RNode.AddROTACIONY(Total,TempFil,TempCol,Node->ColorR,Node->ColorG,Node->ColorB,Node->ColorHexa);
}

string LinearizeMatrix::MandarAtraerRotacionY() {
    Linearize *Temp = FirstLinearize;
    string a = "";
    while(Temp != NULL){
        a += Temp->RNode.Rotacion();
        Temp = Temp->NextLinearize;
    }
    return a;
}

void LinearizeMatrix::MostrarChange() {
    Linearize * temp = FirstLinearize;
    while(temp != NULL){
        cout<<"Id: "+to_string(temp->Id)+" Col: "+to_string(temp->Col) +" Fil: "+ to_string(temp->Fil) +"\n";
        temp = temp->NextLinearize;
    }
}

//***********************ROTACION X ***************************
void LinearizeMatrix::ChangeIdx(int WidthC, int HeightC) {
    Linearize * Aux = FirstLinearize;
    string a ="";
    while(Aux != NULL){
        ChangeId2x(Aux, WidthC, HeightC);
        Aux = Aux->NextLinearize;
    }
}

void LinearizeMatrix::ChangeId2x(Linearize *&Node, int WidthC, int HeightC) {
    int a= WidthC *HeightC;
    int TempId = Node->Id;
    int TempCol = Node->Col;
    int TempFil = Node->Fil;
    int Total = a - (TempCol);
    cout<<"ID:" +to_string(Total)+"\n";
    //Node->RNodeX.AddROTACIONX(Total,TempFil,TempCol,Node->ColorR,Node->ColorG,Node->ColorB,Node->ColorHexa);
}


/*
void LinearizeMatrix::CreateHTMLGRAYSCALE() {
    GNode.Tamanio(Tama);
    GNode.CreateHTML();
}
void LinearizeMatrix::CreateCSSGRAYSCALE(int WidthC, int HeightC, int WidthP, int HeightP) {
    GNode.CreateCSS(WidthC,HeightC,WidthP,HeightP);
}


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

void LinearizeMatrix::AgregarRotacionY() {
    Linearize *Temp = FirstLinearize;
    while(Temp != NULL){
        RNode.AddROTACIONY(Temp->Id,Temp->Fil,Temp->Col,Temp->ColorR,Temp->ColorG,Temp->ColorB,Temp->ColorHexa);
        Temp = Temp->NextLinearize;
    }
}

void LinearizeMatrix::EnviarTamanioRotacionY(int WidthM, int HeightM) {
    int a = WidthM * HeightM;
    RNode.T(a);
}

void LinearizeMatrix::CreateHTMLROTATIONY() {
    RNode.HTMLY();
}

void LinearizeMatrix::CreateCSSROTATIONY(int WidthC, int HeightC, int WidthP, int HeightP) {
    RNode.CCSSY(WidthC,HeightC,WidthP,HeightP);
}

*/