#include <iostream>

struct Node {
  int value;
  Node *next;
  Node(int val);
};

class List {
private:
  Node *head;

public:
  List();
  bool IsEmpty();
  bool IsLast(Node *);
  Node *Find(int);
  void Delte(int);
  Node *FindPreviouse(int);
  void Insert(Node *, int);
  Node *Header();
  void Print();
  Node *First();
  void PushFront(int);
  void PushBack(int);
  ~List();
};

void listTest();

void findAllElementFromSotedList(const List&,const List&);