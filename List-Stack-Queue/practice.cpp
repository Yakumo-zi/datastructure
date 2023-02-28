#include "practice.h"

void PrintAllListElement() {
  List l;
  for (int i = 0; i < 10; i++) {
    std::cout << "push back " << i << std::endl;
    l.PushBack(i);
  }
  Node *cur = l.First();
  int count = 1;
  while (cur != nullptr) {
    std::cout << "element " << count++ << " is " << cur->value << std::endl;
    cur = cur->next;
  }
}
void PrintLots(List &&L, List &&P) {
  Node *curl = L.First();
  Node *curp = P.First();
  int now_count = 1;
  while (curp != nullptr) {
    int count = curp->value;
    while (count - now_count != 0) {
      if (curl == nullptr) {
        std::cout << "don't have enough element" << std::endl;
        return;
      }
      curl = curl->next;
      now_count++;
    }
    std::cout << curp->value << "th element in L is " << curl->value
              << std::endl;
    curp = curp->next;
  }
}
void TwoListIntersection(List &&L, List &&P) {
  List i;
  Node *curl = L.First();
  Node *curp = P.First();
  while (curl != nullptr && curp != nullptr) {
    if (curl->value == curp->value) {
      i.PushBack(curl->value);
    } else if (curl->value < curp->value) {
      curl = curl->next;
      continue;
    } else if (curl->value > curp->value) {
      curp = curp->next;
      continue;
    }
    curl = curl->next;
    curp = curp->next;
  }
  if (i.IsEmpty()) {
    std::cout << "The intersection of L and P is empty" << std::endl;
    return;
  }
  i.Print();
}
void TwoListUnionSet(List &&L, List &&P) {
  List u;
  Node *curp = P.First();
  Node *curl = L.First();
  // P.Print();
  // L.Print();
  int last_value = 0;
  while (curl != nullptr || curp != nullptr) {
    if (curl != nullptr && curp != nullptr) {
      // std::cout << "curl:" << curl << " curl->value:" << curl->value
      //           << " curl->next:" << curl->next << std::endl;
      // std::cout << "curp:" << curp << " curp->value:" << curp->value
      //           << " curp->next:" << curp->next << std::endl;
      if (curl->value == curp->value) {
        // std::cout << "equal" << std::endl;
        u.PushBack(curl->value);
        last_value = curl->value;
        curl = curl->next;
        curp = curp->next;
        continue;
      } else if (curl->value < curp->value) {
        // std::cout << "less" << std::endl;
        u.PushBack(curl->value);
        last_value = curl->value;
        curl = curl->next;
        continue;
      } else if (curl->value > curp->value) {
        // std::cout << "greater" << std::endl;
        u.PushBack(curp->value);
        last_value = curp->value;
        curp = curp->next;
        continue;
      }
    }
    if (curp == nullptr) {
      while (curl != nullptr) {
        if (curl->value > last_value) {
          u.PushBack(curl->value);
          last_value = curl->value;
        } else {
          Node *find = u.Find(curl->value);
          if (find == nullptr) {
            u.PushBack(curl->value);
          }
        }
        curl = curl->next;
      }
    } else {
      while (curp != nullptr) {
        if (curp->value > last_value) {
          u.PushBack(curp->value);
          last_value = curp->value;
        } else {
          Node *find = u.Find(curp->value);
          if (find == nullptr) {
            u.PushBack(curp->value);
          }
        }
        curp = curp->next;
      }
    }
  }
  if (u.IsEmpty()) {
    std::cout << "both of list P and L is empty" << std::endl;
    return;
  }
  u.Print();
}

Node *ReverseProcess(Node *cur) {
  if (cur->next == nullptr) {
    return cur;
  }
  Node *res = ReverseProcess(cur->next);
  Node *curR = res;
  while (curR->next != nullptr) {
    curR=curR->next;
  }
  cur->next=nullptr;
  curR->next=cur;
  return res;
}
void ReverseRecursive(List &&l) {
  Node* header=ReverseProcess(l.First());
  l.Header()->next=header;
  l.Print();
}
void Reverse(List &&list) {
  Node *header = nullptr;
  Node *cur = list.First();
  while (cur != nullptr) {
    Node *next = cur->next;
    cur->next = header;
    header = cur;
    cur = next;
  }
  list.Header()->next = header;
  list.Print();
}
Node *FindElementProcess(Node *cur, int value) {
  if (cur == nullptr) {
    return nullptr;
  }
  if (cur->value == value) {
    return cur;
  }
  return FindElementProcess(cur->next, value);
}
void FindElementRecursive(List &&list, int value) {
  Node *find = FindElementProcess(list.First(), value);
  if (find) {
    std::cout << "find element " << value << " address:" << find << std::endl;
    return;
  }
  std::cout << "don't find the element " << value << std::endl;
}
