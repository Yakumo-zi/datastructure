#include <iostream>
struct Node {
  int value;
  Node *left;
  Node *right;
  Node(int);
};
class SearchTree {
private:
  Node *root;

public:
  SearchTree(int);
  ~SearchTree();
  Node* Find(int);
  Node* FindMin();
  Node* FindMax();
  void Insert(int);
  void Delete(int);
};