#include <iostream>

class Stack {
private:
  int *container;
  int capacity;
  int top;
  int len;

public:
  Stack(int c);
  ~Stack();
  void Push(int);
  int Top();
  int Pop();
  bool IsEmpty();
  int Capacity();
};

void testStack();