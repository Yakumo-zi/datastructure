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
void SearchTree::Delete(int value) {
  if(root==nullptr){
    std::cout<<"node not found"<<std::endl;
    return;
  }
  Node* res=Find(value);
  std::cout<<"res:"<<res->value<<std::endl;
  std::cout<<"res->left:"<<res->left<<std::endl;
  std::cout<<"res->right:"<<res->right<<std::endl;
  if(res->left==nullptr&&res->right==nullptr){
    delete res;
    res=nullptr;
    return;
  }
  if(res->right==nullptr){
    Node* left=res->left;
    res->value=left->value;
    res->right=left->right;
    res->left=left->left;
    delete left;
    return;
  }
  Node* parent=res;
  Node* cur=res->right;
  while(cur->left!=nullptr){
    parent=cur;
    cur=cur->left;
  }
  res->value=cur->value;
  parent->left=cur->left;
  parent->right=cur->right;
  delete cur;
  cur=nullptr;
}
void testSearchTree() {
  SearchTree st;
  st.Insert(1);
  st.Insert(2);
  st.Insert(9);
  st.Insert(0);
  st.Insert(3);
  st.Insert(4);
  st.Insert(2);
  st.Insert(1);
  st.InOrder();
  st.Delete(4);
  st.InOrder();
}