#include "SelfAdjustingTable.h"

SelfAdjustingTable::SelfAdjustingTable(int c)
    : container(nullptr), capacity(c), start(c) {
  container = new int[c];
}
SelfAdjustingTable::~SelfAdjustingTable() { delete[] container; }
int SelfAdjustingTable::Find(int value) {
  for (int i = start; i < capacity; i++) {
    if (container[i] == value) {
      std::cout << "the value " << value << " index is " << i << std::endl;
      if (i != start) {
        int u = i;
        while (u != start) {
          int temp = container[u];
          container[u] = container[u - 1];
          container[u - 1] = temp;
          u--;
        }
      }
      return start;
    }
  }
  std::cout << "the value is not in table" << std::endl;
  return -1;
}
void SelfAdjustingTable::Push(int value) {
  if (start - 1 >= 0) {
    container[--start] = value;
    return;
  }
  std::cout << "the table is full" << std::endl;
}
void SelfAdjustingTable::Print() {
  int count = 1;
  std::cout << "[ ";
  for (int i = start; i < capacity; i++) {
    std::cout << container[i] << ", ";
  }
  std::cout << "]" << std::endl;
}