#include <iostream>

class Queue {
private:
  int *container;
  int front;
  int back;
  int capacity;

public:
  Queue(int);
  ~Queue();
  int Front();
  bool IsEmpty();
  bool IsFull();
  void Push(int);
  int Pop();
  int Capacity();
  void BackAndFront();
};
void testQueue();