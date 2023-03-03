#include "SearchTree.h"
Node::Node(int value) : value(value), left(nullptr), right(nullptr) {}

SearchTree::SearchTree(int value) { root = new Node(value); }
void DeleteProcess(Node *root) {
  if (root == nullptr)
    return;
  DeleteProcess(root->left);
  DeleteProcess(root->right);
  delete root;
}
SearchTree::~SearchTree() { DeleteProcess(root); }
void SearchTree::Insert(int value) {
  Node *cur = root;
  while (cur != nullptr) {
    if (value >= cur->value) {
      if (cur->right != nullptr) {
        cur = cur->right;
        continue;
      }
      cur->right = new Node(value);
      break;
    } else {
      if (cur->left != nullptr) {
        cur = cur->left;
        continue;
      }
      cur->left = new Node(value);
      break;
    }
  }
}
Node *SearchTree::Find(int value) {
  Node *cur = root;
  while (cur != nullptr) {
    if (value > cur->value) {
      if (cur->right != nullptr)
        cur = cur->right;
      else
        return nullptr;
    } else if (value < cur->value) {
      if (cur->left != nullptr)
        cur = cur->left;
      else
        return nullptr;
    } else {
      return cur;
    }
  }
  return nullptr;
}

Node *SearchTree::FindMin() {
  Node *cur = root;
  while (cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}
Node *SearchTree::FindMax() {

  Node *cur = root;
  while (cur->right != nullptr) {
    cur = cur->right;
  }
  return cur;
}
void SearchTree::Delete(int value) {
  Node *cur = root;
  Node *parent = nullptr;
  while (cur->value != value) {
    if (value > cur->value) {
      if (cur->right != nullptr) {
        parent = cur;
        cur = cur->right;
      } else
        return;
    } else if (value < cur->value) {
      if (cur->left != nullptr) {
        parent = cur;
        cur = cur->left;
      } else
        return;
    }
  }
  if(parent==nullptr){
    Node* leftMax=root;
    while(leftMax->right!=nullptr){
      leftMax=leftMax->right;
    }
    if(leftMax->left==nullptr){
      leftMax->left=root->left;
      leftMax->right=root->right;
    }else{
      
    }
  }
}