#include "SearchTree.h"
Node::Node(int value) : value(value), left(nullptr), right(nullptr) {}

SearchTree::SearchTree(int value) { root = new Node(value); }
SearchTree::SearchTree() : root(nullptr){};
void inOrder(Node *root,int level) {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left,level+1);
  // for(int i=0;i<level;i++){
  //   std::cout<<" ";
  // }
  std::cout << root->value<<" ";
  inOrder(root->right,level+1);
  // std::cout<<std::endl;
}
void SearchTree::InOrder() {
  std::cout << "InOrder SearchTree:" << std::endl;
  inOrder(root,0);
  std::cout << std::endl;
}
void DeleteProcess(Node *root) {
  if (root == nullptr)
    return;
  DeleteProcess(root->left);
  DeleteProcess(root->right);
  delete root;
}
SearchTree::~SearchTree() { DeleteProcess(root); }
void SearchTree::Insert(int value) {
  if (root == nullptr) {
    root = new Node(value);
    return;
  }
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
  if (root == nullptr) {
    return nullptr;
  }
  Node *cur = root;
  while (cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}
Node *SearchTree::FindMax() {
  if (root == nullptr) {
    return nullptr;
  }
  Node *cur = root;
  while (cur->right != nullptr) {
    cur = cur->right;
  }
  return cur;
}
void deleteNode(Node* root,int value){
  if(root==nullptr){
    std::cout<<"node not found"<<std::endl;
    return;
  }else if(value>root->value){
  
  }
}
void SearchTree::Delete(int value) {
  deleteNode(root,value);
}
void testSearchTree() {
  SearchTree st;
}