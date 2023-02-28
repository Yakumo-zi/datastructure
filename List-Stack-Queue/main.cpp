#include <iostream>
#include <utility>
#include "SelfAdjustingTable/SelfAdjustingTable.h"
int main(){
  SelfAdjustingTable t(5);
  for(int i=1;i<=5;i++){
    t.Push(i);
  }
  t.Print();
  t.Find(3);
  t.Print();
  t.Find(5);
  t.Print();
  t.Find(1);
  t.Print();
  return 0;
}