#include "BinaryTree.h"
#include <stack>
Node::Node(char v) : value(v), left(nullptr), right(nullptr) {}
void PreOrder(Node *root) {
  if (root == nullptr)
    return;
  std::cout << root->value;
  PreOrder(root->left);
  PreOrder(root->right);
}
void InOrder(Node *root) {
  if (root == nullptr)
    return;
  InOrder(root->left);
  std::cout << root->value;
  InOrder(root->right);
}
void PostOrder(Node *root) {
  if (root == nullptr)
    return;
  PostOrder(root->left);
  PostOrder(root->right);
  std::cout << root->value;
}

void ComposeNode(std::stack<Node *>& stack, char x) {
  Node *lhs = nullptr;
  Node *rhs = nullptr;
  Node *op = nullptr;
  lhs = stack.top();
  stack.pop();
  rhs = stack.top();
  stack.pop();
  op = new Node(x);
  op->left = lhs;
  op->right = rhs;
  stack.push(op);
}
Node *ConstructExpressionTree(std::string exp) {
  std::stack<Node *> stack;
  for (auto x : exp) {
    switch (x) {
    case '+':
      ComposeNode(stack, x);
      break;
    case '-':
      ComposeNode(stack, x);
      break;
    case '*':
      ComposeNode(stack, x);
      break;
    case '/':
      ComposeNode(stack, x);
      break;
    default:
      stack.push(new Node(x));
    }
  }
  return stack.top();
}
