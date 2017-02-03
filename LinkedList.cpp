//StudentLIst Josh Howell Sept 16
//A simple list manager, lets you add, remoe and list a bunch of students

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

void printStudents(Node* head);
void addStudent(Node* head, Student* newStudent);
void deleteStudent(Node* current, Node* previous, int deleteId);
float getAverage(Node* head, int level, float runningTotal);
void wipe(Node* head);

int main(){
  Node* head = new Node(NULL);
  char input[20];
  bool running = true;
  while (running == true){ //command line loop
    cin.get(input,20);
    cin.ignore();
    if (!strcmp(input,"PRINT")){
      printStudents(head->getNext());
    }
    else if (!strcmp(input, "ADD")){
      addStudent(head,new Student);
    }
    else if (!strcmp(input, "DELETE")){
      bool deleted = false;//ask witch student to delte
      int deleteId;
      cout << "Give Me an ID to delete" << endl;
      cin >> deleteId;
      cin.ignore();
      deleteStudent(head->getNext(), head, deleteId);
    }
    else if (!strcmp(input, "HELP")){
      cout << "Commands: \nPRINT\nADD\nDELETE\nAVERAGE" << endl;
    }
    else if (!strcmp(input, "AVERAGE")){
      cout << "The average GPA is: " << setprecision(2) <<fixed << getAverage(head->getNext(),0,0) << endl;
    }
    else if (!strcmp(input, "EXIT")){
      running = false;
    }
    else{
      cout << "No such command: " <<  input << endl;
      cout << "Type HELP for a list of commands" << endl;
    }
  }
  //cleanup
  wipe(head);
}
void printStudents(Node* head){ //go throught the list and print out thier info
  if (!head){return;}
  head->getStudent()->printStudent();
  if (head->getNext()){
    printStudents(head->getNext());
  }
}
void addStudent(Node* head, Student* newStudent ){
  if (!head->getNext()){
    head->setNext(new Node(newStudent));
  }
  else if(head->getNext()->getStudent()->getId() > newStudent->getId()){
    Node* temp = head->getNext();
    head->setNext(new Node(newStudent)); //create the new student and put them on the list
    head->getNext()->setNext(temp);
  }
  else{
    addStudent(head->getNext(),newStudent);
  }
}
void deleteStudent(Node* current, Node* previous, int deleteId){
  if (current->getStudent()->getId() == deleteId){
    previous->setNext(current->getNext());
    delete current;
  }
  else if(current->getNext()){
    deleteStudent(current->getNext(),current, deleteId);
  }
  else{
    cout << "No entries with ID: " << deleteId << endl;
  }
} 
float getAverage(Node* head, int level, float runningTotal){
  runningTotal += head->getStudent()->getGpa();
  level++;
  if(head->getNext()){
    return getAverage(head->getNext(), level, runningTotal);
  }
  else{
    return runningTotal/level;
  }
}
void wipe(Node* head){
  if (head->getNext()){
    wipe(head->getNext());
  }
  delete head;
}
