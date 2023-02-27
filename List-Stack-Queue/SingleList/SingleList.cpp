#include "SingleList.h"

Node::Node(int val) : value(val), next(nullptr) {}

List::List() : head(new Node(-1)) {
}
List::~List() {
  Node *cur = head->next;
  delete head;
  while (cur != nullptr) {
    Node *next = cur->next;
    delete cur;
    cur = next;
  }
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
  Node *prev = FindPreviouse(value);
  if (prev == nullptr) {
    std::cout << "This value is not in list" << std::endl;
    return nullptr;
  }
  return prev->next;
}
void List::Delete(int value) {
  if (IsEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  Node *prev = FindPreviouse(value);
  if (prev == nullptr) {
    std::cout << "This element is not in list" << std::endl;
    return;
  }
  Node *cur = prev->next;
  Node *next = cur->next;
  std::cout<<"Delete element "<<cur->value<<" success"<<std::endl;
  delete cur;
  prev->next = next;
}
Node *List::FindPreviouse(int value) {
  if (IsEmpty()) {
    std::cout << "List is empty" << std::endl;
    return nullptr;
  }
  Node *cur = head->next;
  Node *pre = head;
  while (cur != nullptr) {
    if (cur->value == value) {
      return pre;
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
  Node *prev = FindPreviouse(pos->value);
  if (prev != nullptr) {
    Node *next = prev->next;
    Node *node = new Node(value);
    prev->next = node;
    node->next = next;
    std::cout << "Insert element " << value << " success" << std::endl;
    return;
  }
  std::cout << "Insert element " << value << " failure" << std::endl;
}
void List::Print() {
  Node *cur = head->next;
  int count = 1;
  while (cur != nullptr) {
    std::cout << "element " << count << " is " << cur->value << std::endl;
    cur = cur->next;
    count++;
  }
}

void List::PushFront(int value) {
  Node *node = new Node(value);
  Node *next = head->next;
  head->next = node;
  node->next = next;
}
void List::PushBack(int value) {
  Node *node = new Node(value);
  Node *cur = head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  cur->next = node;
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
  list.Delete(3);
  std::cout << "print list" << std::endl;
  list.Print();
  std::cout << "list test end" << std::endl;
}
