#include "SingleList.h"

Node::Node(int val) : value(val), next(nullptr) {}

List::List() : head(new Node(-1)) {
  std::cout << "List constructing" << std::endl;
}
List::~List() {
  std::cout << "Destructing begin..." << std::endl;
  Node *cur = head->next;
  delete head;
  while (cur != nullptr) {
    Node *next = cur->next;
    delete cur;
    cur = next;
  }
  std::cout << "Destructing end！" << std::endl;
}
bool List::IsEmpty() { return head->next == nullptr; }
bool List::IsLast(Node *node) {
  if (node == head) {
    std::cout << "This node is header!!" << std::endl;
    return false;
  }
  return node->next == nullptr;
}
Node *List::Find(int value) {
  if (IsEmpty()) {
    std::cout << "List is empty" << std::endl;
    return nullptr;
  }
  Node *cur = head->next;
  while (cur != nullptr) {
    if (cur->value == value) {
      return cur;
    }
    cur = cur->next;
  }
  return nullptr;
}
void List::Delte(int value) {
  if (IsEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  Node *cur = head->next;
  Node *pre = head;
  while (cur != nullptr) {
    if (cur->value == value) {
      pre->next = cur->next;
      delete cur;
      return;
    }
    cur = cur->next;
    pre = pre->next;
  }
  std::cout << "This element is not in list" << std::endl;
}
Node *List::FindPreviouse(int value) {
  if (IsEmpty()) {
    std::cout << "List is empty" << std::endl;
    return nullptr;
  }
  Node *cur = head->next;
  Node *pre = head;
  while (cur != nullptr) {
    if (cur->value == value && pre != head) {
      return cur;
    }
    cur = cur->next;
    pre = pre->next;
  }
  std::cout << "This element is not in list" << std::endl;
  return nullptr;
}
void List::Insert(Node *pos, int value) {
  if (pos == head->next) {
    Node *node = new Node(value);
    head->next = node;
    node->next = pos;
    std::cout << "Insert element " << value << " success" << std::endl;
    return;
  }
  Node *prev = head;
  Node *cur = head->next;
  while (cur != nullptr) {
    if (cur == pos) {
      Node *node = new Node(value);
      node->next = cur;
      prev->next = node;
      std::cout << "Insert element " << value << " success" << std::endl;
      return;
    }
    cur = cur->next;
    prev = prev->next;
  }
  std::cout << "Insert element " << value << " failure" << std::endl;
}
void List::Print(){
  Node* cur=head->next;
  int count=0;
  while(cur!=nullptr){
    std::cout<<"element "<<count<<" is "<<cur->value<<std::endl;
    cur=cur->next;
  }
}

void List::PushFront(int value){
  Node* node=new Node(value);
  Node* next=head->next;
  head->next=node;
  node->next=next;
}
void List::PushBack(int value){
  Node* node=new Node(value);
  Node* cur=head->next;
  while(cur->next!=nullptr){
    cur=cur->next;
  }
  cur->next=node;
}
Node *List::Header() { return head; }
Node *List::First() { return head->next; }
void listTest() {
  std::cout << "list test begin" << std::endl;
  List list;
  Node *head = list.Header();
  std::cout << "header:" << head << std::endl;
  Node *first = list.First();
  std::cout << "first:" << first << std::endl;
  list.Insert(first, 1);
  Node *pos = list.Find(1);
  std::cout << "1 pos:" << pos << std::endl;
  list.Insert(pos, 2);
  list.Insert(pos, 3);
  std::cout << "print list" << std::endl;
  Node *cur = list.First();
  int count = 1;
  while (cur != nullptr) {
    std::cout << "element " << count << " is " << cur->value << std::endl;
    cur = cur->next;
    count++;
  }
  std::cout << "list test end" << std::endl;
}

