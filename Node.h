#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

//Definition of node class. It has two variables which point to the node and student classes.....................
class Node{
 public:
  Node* getNext();
  Node(Student* s);
  ~Node();
  Student* getStudent();
  void setNext(Node* n);
 private:
  Student* studentpointer;
  Node* next;
};
