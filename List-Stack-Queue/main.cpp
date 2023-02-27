#include <iostream>
#include <utility>
#include "practice.h"
int main(){
  List l;
  List p;
  for(int i=1;i<10;i+=2){
    l.PushBack(i);
  }
  for(int i=5;i<10;i++){
    p.PushBack(i);
  }
  TwoListUnionSet(std::move(l),std::move(p));
  return 0;
}