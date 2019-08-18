#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

NodeABB * Aux2;
int contador =0;

int main()
{
  cout<<"insertar \n";
    Aux2->SendInsert("Edgar");
    Aux2->SendInsert("A");
    Aux2->SendInsert("Edgar5");
    Aux2->Graph();
    Aux2->PrintNode(contador);
   return 0;
}
