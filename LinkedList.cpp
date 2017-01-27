//STudentLIst Josh Howell Sept 16
//A simple list manager, lets you add, remoe and list a bunch of students

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

void printStudents(Node* head);
void newStudent(Node* head);
void deleteStudent(Node* head);
void getAverage(Node* head);

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
      newStudent(head);
    }
    else if (!strcmp(input, "DELETE")){
      deleteStudent(head);
    }
    else if (!strcmp(input, "HELP")){
      cout << "Commands: \nPRINT\nADD\nDELETE\nAVERAGE" << endl;
    }
    else if (!strcmp(input, "AVERAGE")){
      getAverage(head->getNext());
    }
    else if (!strcmp(input, "EXIT")){
      running = false;
    }
    else{
      cout << "No such command: " <<  input << endl;
      cout << "Type HELP for a list of commands" << endl;
    }
  }
}
void printStudents(Node* head){ //go throught the list and print out thier info
  head->getStudent()->printStudent();
  if (head->getNext()){
    printStudents(head->getNext());
  }
}
void newStudent(Node* head){
  Node* currentNode = head;
  while (currentNode->getNext()){
    currentNode = currentNode->getNext();
  }
  currentNode->setNext(new Node(new Student)); //create the new student and put them on the list
}
void deleteStudent(Node* head){
  bool deleted = false;//ask witch student to delte
  int deleteId;
  cout << "Give Me an ID to delte" << endl;
  cin >> deleteId;
  cin.ignore();
  Node* lastNode;
  Node* currentNode = head;
  while (currentNode->getNext()){
    lastNode = currentNode;
    currentNode = currentNode->getNext();
    if(currentNode->getStudent()->getId() == deleteId){
      lastNode->setNext(currentNode->getNext());
      delete currentNode;
      deleted = true;
    }
  }
  if (deleted == false){
    cout << "No entries with Id " << deleteId << endl;
  }
} 
void getAverage(Node* head){
  Node* currentNode = head;
  float totalGpa = 0;
  int count = 0;
  while (currentNode){
    totalGpa += currentNode->getStudent()->getGpa();
    count++;
    currentNode = currentNode->getNext();
  }
  cout << "Average GPA: " << setprecision(2) <<fixed << totalGpa/count << endl;
}
