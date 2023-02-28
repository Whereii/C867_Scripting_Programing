#include <stdio.h>
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main(){
    //Initiating Roster
    Roster* my_roster = new Roster;

    //Entering data set
    const string student_data[] = {
        
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Joshua,McCausey,joshuamccausey@gmail.com,21,14,7,8,SOFTWARE"
    };
    

    //Parse the data set to create our needed student objects
    my_roster->parse(student_data, 5);
    
    //Print out the initial entrys
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010129937" << endl;
    cout << "Name: Joshua McCausey \n" << endl;
    cout << "Displaying all students:" << endl;

    //Print all students
    my_roster->print_all();
    
    //Print invalid emails
    cout << " \n Displaying invalid emails: \n" << endl;
    my_roster->print_invalid_emails();
    cout << "" << endl;

    //Print average days in course
    my_roster->print_average_days_in_course();
    
    //Print student objects in the SOFTWARE program
    my_roster->print_by_degree_program("SOFTWARE");
    
    //Remove student object with the id A3
    cout << "\n Removing A3:" << endl;
    my_roster->remove("A3");
    cout << "" << endl;
    
    //Print remaining students
    my_roster->print_all();

    //Print A3 again to show that object doesn't exist
    cout << "\n Removing A3 again: \n" << endl;
    my_roster->remove("A3");

    //Using destructor to release allocated memory for my_roster
    delete my_roster;
    
}
