//This program is designed for teachers to manage students' information.

//When the program is running, a program will create two files, user.txt and students.txt
//Thena menu will pop up to ask for user's account information and allow login if input matches data in the user.txt file.
//The default account for user is Account Name: Ray, Password : 1111
//The program will prompt to ask again if received garbage input.
//New user can create new account and then login as the program will write new data into the user.txt.

//If login success, user have 7 choices.
//1. show a list of all Students in the file students.txt
//2. allow user to show students with a specific program
//3. add new student into the student.txt file
//4. allow user to show students with a specfic ID
//5. allow user to modify a student's data( program, email, phone no., attendance and CGPA)
//6. Delete a student that is listed in the file

//After that if user input any other number, the program will stop




//  Header.h
//  prg355FinalProject
//  A student record management system using File I/o operations on objects
//  Created by Ray Chan on 26/11/2022.
//

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using namespace std;

//create a Student class contains required members
class Student
{
private:
    static int sizeTotal; // to count the num of objects in an array
    int studentId, phoneNum, attendance;
    std::string name, program, email;
    double cgpa;

public:
    //create constructor /  assign object default value
    Student(int studentIdPara = 0, std::string namePara = "unknown" , std::string programPara = "unknown", std::string emailPara = "unknown",
            int phoneNumPara = 0, int attendancePara = 0, double cgpaPara = 0.0)
    {
        studentId = studentIdPara;
        name = namePara;
        program = programPara;
        email = emailPara;
        phoneNum = phoneNumPara;
        attendance = attendancePara;
        cgpa = cgpaPara;
        sizeTotal++;
    }
    
    int getSize() { return sizeTotal;}

    //create getter function to access members
    int getId() { return studentId;}
    std::string getName() { return name;}
    std::string getProgram() { return program;}
    std::string getEmail() { return email;}
    int getPhoneNum() { return phoneNum;}
    int getAttend() { return attendance;}
    double getCgpa() { return cgpa;}

    //setter functions
    void setID(int id) {studentId = id; }
    void setName(std::string namePara) {name = namePara; }
    void setProgram(std::string programPara) {program = programPara; }
    void setEmail(std::string emailPara) {email = emailPara; }
    void setPhoneNum(int phoneNumPara) {phoneNum = phoneNumPara; }
    void setAttendance(int attendancePara) {attendance = attendancePara; }
    void setCgpa(double cgpaPara) {cgpa = cgpaPara; }
    void sizeDown() {sizeTotal--;}

    friend istream& operator>>(istream & input, Student &obj)
    {
        cout << "What is the id of the student? (int) : ";
        input >> obj.studentId;
        cout << "What is the name of the student? (string) : ";
        input >> obj.name;
        cout << "What is the program of the student? (string) : ";
        input >> obj.program;
        cout << "What is the email of the student? (string) : ";
        input >> obj.email;
        cout << "What is the phone number of the student? (int) : ";
        input >> obj.phoneNum;
        cout << "What is the attendance of the student? (int) : ";
        input >> obj.attendance;
        cout << "What is the CGPA of the student? (double) : ";
        input >> obj.cgpa;

        return input;
    }
};

int Student::sizeTotal = 0;

//create user object
class User
{
private:
    std::string name, password;

public:
    //create constructor to assign object's value
    User(std::string namePara = "unknown", std::string passwordPara = "unknown")
    {
        name = namePara;
        password = passwordPara;
    }
    
    //create get function to access private member
    std::string getName() { return name;}
    std::string getPassword() { return password;}
};


#endif


// can the length of object array be determined during run time? vector?


//Algorithm
//create a Student class contains required members
//create getter function to access members





//show student database menu
//allow user choose the option
//loop to check if login info match with existing user
//display menu if match
//create new user(account) object and put into an array
//append / write the data of user objects into a file

//list all students by reading a file
//show error if file cant open

//read the file, list students base on the object's member(program)

//create new student object and add into an array to store data
//re-write / trunc the updated array of object into the file

//read the file , list students base on the object's member(id)


//modify data of a specific object(student)
//get the student id (member of an object)
//display menu to ask the data that need to be modified
//search which object in the array has the matching member
//ask and set the modified value
//re-write / trunc the updated array of object into the file

//delete an object in an array
//get the student id (member of an object)
//search which object in the array has the matching member
//delete the object in the array
//re-write / trunc the updated array of object into the file
