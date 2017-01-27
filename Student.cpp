#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

//constructor
Student::~Student(){

}
//deconstructor
Student::Student(){
  cout << "New ID" << endl;
  cin >> id;
  cin.ignore();
  cout << "New First Name?" << endl;
  cin.get(firstName,30);
  cin.ignore();
  cout << "New Last Name" << endl;
  cin.get(lastName,30);
  cin.ignore();
  cout << "New GPA?" << endl;
  cin >> gpa;
  cin.ignore();
  cout << "Added student with info" << endl;
  cout << "Name: " << firstName << " " << lastName << ", ID: " << id << ", GPA: " << setprecision(2) <<fixed << gpa << endl;
}
int Student::getId(){
  return id;
}
float Student::getGpa(){
  return gpa;
}
void Student::printStudent() {
  cout << "Student: " << firstName << " " << lastName << ", " << id << ", " << gpa << endl;
}
