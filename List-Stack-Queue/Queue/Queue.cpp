#include "Queue.h"
Queue::Queue(int c) : container(nullptr), front(0), back(0), capacity(c) {
  container = new int[capacity];
}
Queue::~Queue() { delete[] container; }
int Queue::Front() { return container[front]; }
void Queue::Push(int value) {
  if (IsFull()) {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  if (back + 1 == capacity) {
    if (front - 1 != 0) {
      back = 0;
    }
  }
  container[back++] = value;
}
bool Queue::IsFull() {
  if (back == capacity - 1) {
    if (front == 0) {
      return true;
    }
  } else if (back == front - 1) {
    return true;
  }
  return false;
}
void Queue::BackAndFront(){
  std::cout<<"front:"<<front<<" "<<"back:"<<back<<std::endl;
}
bool Queue::IsEmpty() { return back == front; }
int Queue::Pop() {
  if(IsEmpty()){
    std::cout<<"Queue is empty"<<std::endl;
    return -1;
  }
  if (front + 1 == capacity) {
    front = 0;
  }
  return container[front++];
}
int Queue::Capacity() { return capacity; }
void testQueue() {
  Queue q(5);
  std::cout << "capacity:" << q.Capacity() << std::endl;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  q.Push(5);
  q.Push(6);
  q.BackAndFront();
  std::cout << "capacity:" << q.Capacity() << std::endl;
  int count = 1;
  while (!q.IsEmpty()) {
    std::cout << "element " << count << " is " << q.Pop() << std::endl;
    count++;
  }
  q.BackAndFront();
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.BackAndFront();
  count=0;
  while (!q.IsEmpty()) {
    std::cout << "element " << count << " is " << q.Pop() << std::endl;
    count++;
  }
  q.Push(1);
  q.Pop();
  q.BackAndFront();
  q.Push(2);
  q.Push(3);
  q.BackAndFront();
}