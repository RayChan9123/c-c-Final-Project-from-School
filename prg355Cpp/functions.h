//
//  functions.cpp
//  prg355FinalProject
//
//  Created by Ray Chan on 27/11/2022.
//
#ifndef Functions_H
#define Functions_H
#include <iostream>
#include <iomanip>
#include "header.h"
#include <fstream>
#include <array>

using namespace std;

//function prototyping
void authorInfo();
void showMenu();
int continueOrNot();
int errorChecking (int member);
int askUserOption1();
int checkUserInfo(int &numOfAccount, User account[]);
void writeUserFile(int &numOfAccount, User account[]);
void createAccount(int &numOfAccount, User account[]);
void showMenu2();
void menuOption2(int opt, Student list[]);
void showStudentList();
void showByProgram ();
void addNewStudent(Student list[]);
void writeStudentFile(Student list[]);
void showInfoType();
int askUserOption2();
void searchStudent();
void modifyData(Student list[]);
int showMenu3();
int searchById(Student list[], int id);
void modifyValue(int opt, int position, Student list[]);
void deleteAStudent(Student list[]);

void authorInfo()
{
    //display author info
    cout << setfill('*') << setw(98) << "\n"
         << "*\t This lab assignment is submitted by Ray Chan with student id: 157209214 on 27th Nov, 2022\t*\n"
         << setfill('*') << setw(98) << "\n" <<  setfill(' ') << "\n\n";
}

void showMenu()
{
    cout << "\n"
         << " " << setfill('-') << setw(48) << std::right << " " << "\n"
         << "|"<< setfill(' ')  << "\t\t\t\t\tMenu\t\t\t\t\t\t" << "|" << "\n"
         << "|" << setw(48) << setfill('-') << std::right<< "|" << "\n"
         << setw(48) << setfill(' ') << std::left << "|1- Existing User" << "|" << "\n"
         << setw(48) << "|2- New User" << "|" << "\n"
         << setfill('-') << setw(48) << " " << "\n";
}

//allow user to choose the option
int askUserOption1()
{
    int opt;
    cout << "Please enter an option: ";
    cin >> opt;

    return opt == 1 || opt == 2 ? opt: 0 ;
}

//loop to check if login info match with existing user
int checkUserInfo(int &numOfAccount, User account[])
{
    std::string name, password;

    cout << "Please enter your User Name without any space: ";
    cin >> name;
    cout << "Please enter your Password without any space: ";
    cin >> password;

    for (int i = 0; i < numOfAccount; i++)
    {
        if (account[i].getName() == name && account[i].getPassword() == password)
        {
            cout << "\n\nLogin Successful\n\n";
            return 1;
        }
    }
    return 0;
}

void writeUserFile(int &numOfAccount, User account[])
{
    ofstream output_file("user.txt", ios::out);            //write object's data into file

    if(output_file.fail())
    {
        cout << "Something wrong with opening the file, file may not exist\n";
    }

    for (int i = 0; i < numOfAccount; i++)
    {
        output_file << setw(20) << account[i].getName()
                    << setw(20) << account[i].getPassword()
                    << endl;
    }

    numOfAccount++;
    output_file.close();
}

//create new user(account) object and put into an array
void createAccount(int &numOfAccount, User account[])
{
    std::string name, password;

    cout << "Enter your User Name without any space to create new account please: ";
    cin >> name;
    cout << "Enter your Password without any space to create new account please: ";
    cin >> password;

    User tempAccount(name, password);
    account[numOfAccount - 1 ] = tempAccount;

    //append / write the data of user objects into a file
    writeUserFile(numOfAccount, account);
}

void showMenu2()
{
    cout << "\n"
         << " " << setfill('-') << setw(48) << std::right << " " << "\n"
         << "|"<< setfill(' ')  << "\t\t\t\t\tMenu\t\t\t\t\t\t" << "|" << "\n"
         << "|" << setw(48) << setfill('-') << std::right<< "|" << "\n"
         << setw(48) << setfill(' ') << std::left << "|1- Show list of all Students." << "|" << "\n"
         << setw(48) << "|2- List student by program" << "|" << "\n"
         << setw(48) << "|3- Add a new student" << "|" << "\n"
         << setw(48) << "|4- Search a student" << "|" << "\n"
         << setw(48) << "|5- Modify data of a student" << "|" << "\n"
         << setw(48) << "|6- Delete a student" << "|" << "\n"
         << setw(48) << "|-- Enter other number can stop the program" << "|" << "\n"
         << setfill('-') << setw(48) << " " << "\n";
}

int askUserOption2()
{
    int opt;
    cout << "Please enter an option: ";
    cin >> opt;

    return opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5 || opt == 6 ? opt: 0 ;
}

void menuOption2(int opt, Student list[])
{
    switch (opt)
    {
        case 1:
            showStudentList();
            break;
        
        case 2:
            showByProgram();
            break;

        case 3:
            addNewStudent(list);
            writeStudentFile(list);
            showStudentList();
            break;

        case 4:
            searchStudent();
            break;

        case 5:
            showStudentList();
            modifyData(list);
            //re-write / trunc the updated array of object into the file
            writeStudentFile(list);
            showStudentList();
            break;

        case 6:
            showStudentList();
            deleteAStudent(list);
            //re-write / trunc the updated array of object into the file
            writeStudentFile(list);
            showStudentList();
            break;
        
        default:
            cout << "You did not input a valid option\n\n";
            break;
    }
}

void showInfoType()
{
    cout << "Student List is:\n\n"
         << setw(15) << std::right << setfill(' ') << "Student ID"
         << setw(20) << "Name"
         << setw(20) << "Program"
         << setw(30) << "Email"
         << setw(20) << "Phone No:"
         << setw(20) << "Attendance"
         << setw(10) << "CGPA"  << endl; // use endl to remove space and start new line
}

//show list of objects from the file
void showStudentList()
{
    showInfoType();

    ifstream input_file("students.txt",ios::in);    //input file object is created using constructor and open taxi.txt in input mode

    if(input_file.fail())                       //show list of objects from the file
    {
        cout << "Something wrong with opening the file, file may not exist\n";
    }
    else
    {
        std::string line;                      // create medium to store data

        while (getline(input_file, line))      // print data in the file to console by specifying input stream and store in medium(variable)
        {
            cout << line << endl;
        }
    }
    input_file.close();                    //close file when finish reading
}

//list students base on the object's member(program)
void showByProgram ()
{
    std::string id, name, programInFile, email, phoneNo, attend, cgpa;
    std::string program;

    cout << "Please input the program you want: ";
    cin >> program;
    showInfoType();

    //read file list students base on the object's member(program)
    ifstream fin("students.txt");

    if(!fin) { cout << "Error in opening the file by program\n";}
    else
    {
        while(fin >> id >> name >> programInFile >> email >> phoneNo >> attend >> cgpa)
        {
            if (programInFile == program)
            {
                cout << setw(15) << id
                     << setw(20) << name
                     << setw(20) << programInFile
                     << setw(30) << email
                     << setw(20) << phoneNo
                     << setw(20) << attend
                     << setw(10) << cgpa << endl;
            }
        }
    }
    fin.close();
}

//create new student object and add into an array to store data
void addNewStudent(Student list[])
{
    Student student;
    int len = list[0].getSize() - 1;
    cin >> student;                 //call overloaded operator
    list[len] = student;            // inserting newly created object into array
}

void writeStudentFile(Student list[])
{
    ofstream output_file("students.txt", ios::out);            //write object's data into file

    if(output_file.fail())
    {
        cout << "Something wrong with opening the file, file may not exist\n";
    }

    for (int i = 0; i < list[0].getSize(); i++)         //error to get len@@
    {
        output_file << setw(15) << list[i].getId()
                    << setw(20) << list[i].getName()
                    << setw(20) << list[i].getProgram()
                    << setw(30) << list[i].getEmail()
                    << setw(20) << list[i].getPhoneNum()
                    << setw(20) << list[i].getAttend()
                    << setw(10) << list[i].getCgpa()
                    << endl; // use endl to remove space and start new line
    }

    output_file.close();
}

//read the file , list students base on the object's member(id)
void searchStudent()
{
    std::string idInFile, name, program, email, phoneNo, attend, cgpa;
    std::string id;

    cout << "Please input the student id you are searching: ";
    cin >> id;
    showInfoType();

    //read file list students base on the object's member(id)
    ifstream fin("students.txt");

    if(!fin) { cout << "Error in opening the file by id\n";}
    else
    {
        while(fin >> idInFile >> name >> program >> email >> phoneNo >> attend >> cgpa)
        {
            if (idInFile == id)
            {
                cout << setw(15) << id
                     << setw(20) << name
                     << setw(20) << program
                     << setw(30) << email
                     << setw(20) << phoneNo
                     << setw(20) << attend
                     << setw(10) << cgpa << endl;
            }
        }
    }
    fin.close();
}

//modify data of a specific object(student)
void modifyData(Student list[])
{
    int id, opt, position;

    while(1)
    {
        //get the student id (member of an object)
        cout << "Please enter the student ID for which you want to modify: ";
        cin >> id;
        if (errorChecking(id)) { continue;}

        //search which object in the array has the matching member
        position = searchById(list, id);
        if (position < 0) { break;}
    
        //display menu to ask the data that needs to be modified
        opt = showMenu3();
       
        // set the modified value
        modifyValue(opt, position, list);
        break;
    }
    
}

//search which object in the array has the matching member(id)
int searchById(Student list[], int id)
{
    int len;

    len = list[0].getSize();
    
    for (int i = 0; i < len; i++)
    {
        if (list[i].getId() == id)
        {
            return i;
        }
    }

    return -1;
}
int showMenu3()
{
    int opt;

    while(1)
    {
        cout << "\n"
             << " " << setfill('-') << setw(48) << std::right << " " << "\n"
             << "|"<< setfill(' ')  << "\t\t\t\t\tMenu\t\t\t\t\t\t" << "|" << "\n"
             << "|" << setw(48) << setfill('-') << std::right<< "|" << "\n"
             << setw(48) << setfill(' ') << std::left << "|1-  Modify Program" << "|" << "\n"
             << setw(48) << "|2- Modify Email" << "|" << "\n"
             << setw(48) << "|3- Modify Phone number" << "|" << "\n"
             << setw(48) << "|4-  Modify attendance" << "|" << "\n"
             << setw(48) << "|5- Modify CGPA" << "|" << "\n"
             << setfill('-') << setw(48) << " " << "\n\n"
             << "Please enter your option: ";
        
        cin >> opt;
        if (errorChecking(opt)) { continue;}
        break;
    }
    return opt;
}

// set the modified value base on the data type (should have made them all string@@)
void modifyValue(int opt, int position, Student list[])
{
    int phoneNum, attendance;
    std::string program, email;
    double cgpa;

    cout << "Please enter the value you want it to be: ";

    while(1)
    {
        switch (opt)
        {
            case 1:
                cin >> program;
                list[position].setProgram(program);
                break;

            case 2:
                cin >> email;
                list[position].setEmail(email);
                break;

            case 3:
                cin >> phoneNum;
                list[position].setPhoneNum(phoneNum);
                break;
            
            case 4:
                cin >> attendance;
                list[position].setAttendance(attendance);
                break;
            
            case 5:
                cin >> cgpa;
                list[position].setCgpa(cgpa);
                break;

            default:
                cout << "NO modify option available\n";
                break;
        }
        break;
    }
}

//delete an object in an array
void deleteAStudent(Student list[])
{
    int id, len, found = 0;
    len = list[0].getSize();

    while(1)
    {
        //get the student id (member of an object)
        cout << "Please enter the student ID for which you want to delete: ";
        cin >> id;
        if (errorChecking(id)) { continue;}

        //delete the object element in the array
        for (int i = 0; i < len; i++)
        {
            //search which object in the array has the matching member
            if(list[i].getId() == id)
            {
                for(int j = i; j < len - 1; j++)
                {
                    //put the following elements 1 place forward
                    list[j] = list[j + 1];
                }
                //adjust array size by -1
                list[0].sizeDown();
                found = 1;
            }
        }
        if(!found) { cout << "Element for deletion not found\n";}
        else
        {
            cout << "\nStudent Object Deleted Successfully!\n";
        }
        break;
    }
    
}

int continueOrNot()
{
    char yesOrNo = 'n';

    cout << "Do you have another operation to perform? (Please input Y/N other characters can stop the program.) ";
    cin >> yesOrNo;
    return tolower(yesOrNo) == 'y' ?  1 :  0;    // return 1 / 0 if condition meet
}

//check if input is valid number
inline int errorChecking (int member)
{
    if(!cin || member < 0) //if cin receive false input
    {
        cout << "Invalid input ! Please enter a valid number\n\n";
        cin.clear(); // reset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif
