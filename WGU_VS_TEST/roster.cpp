#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Roster::Roster() {
    Student *s1 = new Student("id", "first", "last", "email", 0,0,0,0, SOFTWARE);
    Student *s2 = new Student("id", "first", "last", "email", 0,0,0,0, SOFTWARE);
    Student *s3 = new Student("id", "first", "last", "email", 0,0,0,0, SOFTWARE);
    Student *s4 = new Student("id", "first", "last", "email", 0,0,0,0, SECURITY);
    Student *s5 = new Student("id", "first", "last", "email", 0,0,0,0, SOFTWARE );
    class_roster_array[0] = s1;
    class_roster_array[1] = s2;
    class_roster_array[2] = s3;
    class_roster_array[3] = s4;
    class_roster_array[4] = s5;
    
    
    
    roster_counter = 0;
};

void Roster::add(string student_id, string first_name, string last_name, string email_addy, int age, int days_in_course_one, int days_in_course_two, int days_in_course_three, degree_program degreeprogram){
    
    class_roster_array[roster_counter]->set("student_id", student_id);
    class_roster_array[roster_counter]->set("first_name", first_name);
    class_roster_array[roster_counter]->set("last_name", last_name);
    class_roster_array[roster_counter]->set("email", email_addy);
    class_roster_array[roster_counter]->set("age", to_string(age));
    class_roster_array[roster_counter]->set("days_in_course_one", to_string(days_in_course_one));
    class_roster_array[roster_counter]->set("days_in_course_two", to_string(days_in_course_two));
    class_roster_array[roster_counter]->set("days_in_course_three", to_string(days_in_course_three));
    class_roster_array[roster_counter]->set("degree_program", to_string(degreeprogram));
    roster_counter++;
};

void Roster::remove(string student_id){
    for(int i = 0; i < roster_counter; i++){
        if(class_roster_array[i]->get("student_id") == student_id){
            delete class_roster_array[i];
            if(i == roster_counter-1){
                roster_counter--;
                return;
            } else{
                for(int j = i; j < roster_counter - 1; j++){
                    class_roster_array[j] = class_roster_array[j+1];
                }
                roster_counter--;
                return;
            }
        }
    } cout << "The student with the ID: " << student_id << " was not found." << endl;
};

void Roster::print_all(){
    for (int i = 0; i < roster_counter; i++) {
        class_roster_array[i]->print("student_id");
        cout << "\t";
        class_roster_array[i]->print("first_name");
        cout << "\t";
        class_roster_array[i]->print("last_name");
        cout << "\t";
        class_roster_array[i]->print("email");
        cout << "\t";
        class_roster_array[i]->print("age");
        cout << "\t";
        class_roster_array[i]->print("days_to_complete");
        cout << "\t";
        class_roster_array[i]->print("degree_program");
        cout << "" << endl;
        
    }
};

void Roster::print_average_days_in_course(){
    for (int i = 0; i < roster_counter; i++) {
        int avg_days = (class_roster_array[i]->first_day + class_roster_array[i]->second_day + class_roster_array[i]->third_day)/3;
        cout << "Student ID: " << class_roster_array[i]->student_id << ", average days in course is: " << avg_days << endl;
    }
};

void Roster::parse(string array[], int size){
    for (int i = 0; i < size; i++) {
        string entry;
        string current_student = array[i];
        int content_counter = 0;
        for(int j = 0; j <= current_student.length(); j++){
            if(current_student[j] == ',' || entry == "SOFTWARE" || entry == "NETWORK" || entry == "SECURITY"){
                if(content_counter == 0){
                    class_roster_array[i]->set("student_id", entry);
                    entry = "";
                    content_counter++;
                } else if (content_counter == 1){
                    class_roster_array[i]->set("first_name", entry);
                    entry = "";
                    content_counter++;
                } else if (content_counter == 2){
                    class_roster_array[i]->set("last_name", entry);
                    entry = "";
                    content_counter++;
                } else if (content_counter == 3){
                    class_roster_array[i]->set("email", entry);
                    entry = "";
                    content_counter++;
                } else if(content_counter == 4){
                    class_roster_array[i]->set("age", entry);
                    entry = "";
                    content_counter++;
                } else if(content_counter == 5){
                    class_roster_array[i]->set("days_in_course_one", entry);
                    entry = "";
                    content_counter++;
                } else if(content_counter == 6){
                    class_roster_array[i]->set("days_in_course_two", entry);
                    entry = "";
                    content_counter++;
                } else if(content_counter == 7){
                    class_roster_array[i]->set("days_in_course_three", entry);
                    entry = "";
                    content_counter++;
                } else if(content_counter == 8){
                    if(entry == "SOFTWARE" || entry == "NETWORK" || entry == "SECURITY"){
                        class_roster_array[i]->set("degree_program", entry);
                    } continue;
                }
            } else {
                entry = entry + current_student[j];
            }
        }
        roster_counter++;
    }
};

bool Roster::is_char(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
};

bool Roster::is_digit(char c){
    return (c >= '0' && c <= '0');
};

bool Roster::is_valid(string email){
    if (!is_char(email[0])){
        return 0;
    }
    
    int At = -1, Dot = -1;
    
    for (int i = 0; i <email.length(); i++){
        if(isspace(email[i])){
            return 0;
        }
        if(email[i] == '@'){
            At = i;
        } else if(email[i] == '.') {
            Dot = i;
        }
    }
    if (At == -1 || Dot == -1){
        return 0;
    }
    if(At > Dot){
        return 0;
    }
    return !(Dot >= (email.length() - 1));
};

void Roster::print_invalid_emails(){
    for(int i = 0; i < roster_counter; i++){
        if(!is_valid(class_roster_array[i]->email_addy)){
            class_roster_array[i]->print("email");
            cout << " - is invalid."  << endl;
        }
    }
};

void Roster::print_by_degree_program(string degree){
    degree_program checker = SOFTWARE;
    if(degree == "SOFTWARE"){
        checker = SOFTWARE;
    } else if(degree == "SECURITY"){
        checker = SECURITY;
    } else if(degree == "NETWORK"){
        checker = SECURITY;
    }
    cout << " \n Showing students in degree program " << degree << endl;
    cout << "" << endl;
    
    for (int i = 0; i < roster_counter; i++) {
        if(class_roster_array[i]->get_degree_program() == checker){
            class_roster_array[i]->print("student_id");
            cout << "\t";
            class_roster_array[i]->print("first_name");
            cout << "\t";
            class_roster_array[i]->print("last_name");
            cout << "\t";
            class_roster_array[i]->print("age");
            cout << "\t";
            class_roster_array[i]->print("days_to_complete");
            cout << "\t";
            class_roster_array[i]->print("degree_program");
            cout << "" << endl;
        }
    }
};
