#include <string>

using namespace std;

struct NodeLateral{
    int Lateral;
    NodeLateral *NextLateral;
    NodeLateral *PreviousLateral;
};

class Lateral{
public:
  Lateral();
  NodeLateral *Create_Lateral(int Lateral);
  void AddLateral(int Lateral);
  void AddLateralStart(NodeLateral *& New_Lateral);
  void AddLateralBetween(NodeLateral *& New_Lateral);
  void AddLateralInEnd(NodeLateral *& New_Lateral);
  void CoverLaterales();
  bool IsLateral (int Lateral);
  NodeLateral *SearchLateral(int Lateral);
  void PrintLaterales();
  string DotLaterales();
};
