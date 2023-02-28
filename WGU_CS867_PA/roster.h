#ifndef roster_h
#define roster_h

#include <stdio.h>
#include "student.h"
#include <string>

class Roster{
private:
    int roster_counter;
    
    Student s1();
    Student s2();
    Student s3();
    Student s4();
    Student s5();
    
public:

    Student *class_roster_array[5];

    ~Roster();

    void parse(const string array[], int size);
    
    void add(string student_id, string first_name, string last_name, string email_addy, int age, int days_in_course_one, int days_in_course_two, int days_in_course_three, degree_program degreeprogram);
    
    void remove(string student_id);
    
    void print_all();
    
    void print_average_days_in_course(string student_id);
    
    void print_invalid_emails();
    
    bool is_char(char c);
    
    bool is_digit(char c);
    
    bool is_valid(string email);
    
    void print_by_degree_program(degree_program degree);
    
    Roster();
};

#endif /* roster_hpp */
