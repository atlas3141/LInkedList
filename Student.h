#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string.h>


//Student class, it has four different variables for the name, student id, and gpa......
class Student{
 public:
  Student();
  ~Student();
  void printStudent();
  int getId();
  float getGpa();
 private:
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

#endif
