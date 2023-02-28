#include "student.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Student::Student(string id, string first, string last, string email, int age, int day_one, int day_two, int day_three, degree_program program){
    student_id = id;
    first_name = first;
    last_name = last;
    email_addy = email;
    student_age = age;
    class_days[0] = day_one;
    class_days[1] = day_two;
    class_days[2] = day_three;
    degreeprogram = program;
}

string Student::get(string val){
    
    if(val == "student_id"){
        return student_id;
    } else if(val == "first_name"){
        return first_name;
    } else if(val == "last_name"){
        return last_name;
    } else if(val == "email"){
        return email_addy;
    } else if(val == "age"){
        return to_string(student_age);
    } else if(val == "first_day"){
        return to_string(class_days[0]);
    }else if(val == "second_day"){
        return to_string(class_days[1]);
    }else if(val == "third_day"){
        return to_string(class_days[0]);
    }else if(val == "days_to_complete"){
        return "{" + to_string(class_days[0]) + ", " + to_string(class_days[1]) + ", " + to_string(class_days[2]) + "}";
    } else if(val == "degree_program"){
        return to_string(degreeprogram);
    } else{
        return "input proper value";
    }
}

void Student::set(string location, string val){
    
    if(location == "student_id"){
        student_id = val;
    } else if(location == "first_name"){
        first_name = val;
    } else if(location == "last_name"){
        last_name = val;
    } else if(location == "email"){
        email_addy = val;
    } else if(location == "age"){
        student_age = stoi(val);
    } else if(location == "days_in_course_one"){
        class_days[0] = stoi(val);
    } else if(location == "days_in_course_two"){
        class_days[1] = stoi(val);
    } else if(location == "days_in_course_three"){
        class_days[2] = stoi(val);
    } else if(location == "degree_program"){
        if(val == "SECURITY"){
        degreeprogram = SECURITY;
        }else if(val == "SOFTWARE"){
        degreeprogram = SOFTWARE;
    } else if(val == "NETWORK"){
        degreeprogram = NETWORK;
    }
    }
}

void Student::print(){

    string degree;
    if (degreeprogram == SOFTWARE){
        degree = "SOFTWARE";
    } else if(degreeprogram == NETWORK){
        degree = "NETWORK";
    } else if(degreeprogram == SECURITY){
        degree = "SECURITY";
    }

    string days = "{" + to_string(class_days[0]) + ", " + to_string(class_days[1]) + ", " + to_string(class_days[2]) + "}";

    cout << student_id << "\t First Name: " << first_name << "\t  Last Name: " << last_name << "\t Age: " << student_age << "\t daysInCourse: " <<  days << " \t Degree Program: " << degree << endl;

}

degree_program Student::get_degree_program(){
    return degreeprogram;
};
