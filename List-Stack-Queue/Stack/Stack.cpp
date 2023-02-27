#include "Stack.h"

Stack::Stack(int c) : container(nullptr), capacity(c), top(-1) {
  container = new int[capacity];
}

bool Stack::IsEmpty() { return top == -1; }
int Stack::Top() { return container[top]; }
int Stack::Pop() { return container[top--]; }
void Stack::Push(int value) {
  if (top == capacity) {
    int *old = container;
    container = new int[capacity * 2];
    capacity *= 2;
    for (int i = 0; i <= top; i++) {
      container[i] = old[i];
    }
    delete[] old;
  }
  container[++top] = value;
}
int Stack::Capacity() { return capacity; }
Stack::~Stack(){
  delete[] container;
}
void testStack() {
  Stack s(5);
  std::cout << "capacity:" << s.Capacity() << std::endl;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Push(4);
  s.Push(5);
  std::cout << "capacity:" << s.Capacity() << std::endl;
  std::cout << "top :" << s.Top() << std::endl;
  s.Pop();
  std::cout << "top:" << s.Top() << std::endl;
  s.Push(6);
  s.Push(7);
  std::cout<<"capacity:"<<s.Capacity()<<std::endl;
  std::cout<<"Print Stack!"<<std::endl;
  int count=1;
  while(!s.IsEmpty()){
    std::cout<<"element "<<count++<<" is "<<s.Pop()<<std::endl;
  }
  std::cout<<"Print Stack End"<<std::endl;
}
