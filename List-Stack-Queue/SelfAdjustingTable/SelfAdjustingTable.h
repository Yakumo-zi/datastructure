#include <iostream>

class SelfAdjustingTable {
private:
  int *container;
  int capacity;
  int start;

public:
  SelfAdjustingTable(int c);
  ~SelfAdjustingTable();
  int Find(int);
  void Push(int);
  void Print();
};