#include <iostream>
#include "BinaryTree/BinaryTree.h"
int main(){
  std::string exp{"ab+cde+**"};
  Node* root=ConstructExpressionTree(exp);
  PostOrder(root);
  return 0;
}