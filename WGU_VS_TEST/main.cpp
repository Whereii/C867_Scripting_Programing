#include <stdio.h>
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main(){
    
    Roster my_roster;
    
    string student_data[] = {
        
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Joshua,McCausey,joshuamccausey@gmail.com,21,14,7,8,SOFTWARE"
    };
    
    my_roster.parse(student_data, 5);
    
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010129937" << endl;
    cout << "Name: Joshua McCausey \n" << endl;
    cout << "Displaying all students:" << endl;
    my_roster.print_all();
    
    cout << " \n Displaying invalid emails: \n" << endl;
    my_roster.print_invalid_emails();
    cout << "" << endl;
    my_roster.print_average_days_in_course();
    
    my_roster.print_by_degree_program("SOFTWARE");
    
    cout << "\n Removing A3:" << endl;
    
    my_roster.remove("A3");
    
    cout << "" << endl;
    
    my_roster.print_all();
    
    cout << "\n Removing A3 again \n" << endl;
    
    my_roster.remove("A3");
    
}
