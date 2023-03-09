#include <iostream>
#include <ctime>
#include <cstdlib>
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
  SearchTree();
  ~SearchTree();
  Node* Find(int);
  Node* FindMin();
  Node* FindMax();
  void InOrder();
  void Insert(int);
  void Delete(int);
};
void testSearchTree();