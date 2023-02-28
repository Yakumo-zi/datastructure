#include <iostream>
struct Node{
  char value;
  Node* left;
  Node* right;
  Node(char v);
};
Node* ConstructExpressionTree(std::string);

void PreOrder(Node*);
void InOrder(Node*);
void PostOrder(Node*);
