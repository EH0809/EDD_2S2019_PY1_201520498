#include <string>
#include <iostream>
using namespace std;


struct NodeHeader{
    int Header;
    NodeHeader *NextHeader;
    NodeHeader *PreviousHeader;

};

class Cabecera{
public:
  NodeHeader * New_Header(int Header);
  void InsertHeader(int Header);
  void InsertHeaderStart(NodeHeader *Header);
  void InsertHeaderBetween(NodeHeader *Header);
  void InsertHeaderInEnd(NodeHeader *Header);
  void CoverHeader();
  NodeHeader * SearchHeader(int Header);
  bool IsHeader(int Header);
  void PrintHeader();
  string DotHeader();

};
