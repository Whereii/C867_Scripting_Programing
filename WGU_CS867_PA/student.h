#ifndef student_h
#define student_h

#include <stdio.h>
#include "degree.h"
#include <string>

using namespace std;



class Student{
private:
    string first_name;
    string last_name;
    string email_addy;
    int student_age;
    int class_days[3];
    degree_program degreeprogram;
    string student_id;
public:
    string get(string val);
    
    void set(string location, string val);
    
    void print();
    
    degree_program get_degree_program();
    
    Student(string id, string first, string last, string email, int age, int day_one, int day_two, int day_three, degree_program program);
};

#endif /* student_hpp */
