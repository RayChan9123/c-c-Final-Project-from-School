#include <iostream>
#include "header.h"
#include "functions.h"

using namespace std;

int main()
{
    User user1("Ray", "1111");      //create initial user
    User account[100] = {user1};
    int numOfAccount = 1;
    writeUserFile(numOfAccount, account);
    authorInfo();

    Student stu1(5, "ray", "ECT", "ray@myseneca.ca", 23232, 30, 4.0);
    Student stu2(3, "ray", "TTT", "ray@myseneca.ca", 23232, 30, 4.0);
    Student list[] = {stu1, stu2};
    writeStudentFile(list);

    while(1)
    {
        int opt;

        showMenu();                 //show student database menu

        opt = askUserOption1();
        if (errorChecking(opt)) {continue;}      //loop if received invalid input
        
        switch (opt)
        {
            case 1:
                if(checkUserInfo(numOfAccount, account))
                {
                    while(1)
                    {
                        showMenu2();
                        opt = askUserOption2();
                        if (errorChecking(opt)) {continue;}      //loop if received invalid input
                        menuOption2(opt, list);
                        
    
                        if(continueOrNot()) { continue; }
                        break;
                    }
                    
                }
                else
                {
                    cout << "\n\n\nAccount Info Incorrect!";
                    continue;
                }
                break;
            
            case 2:
                createAccount(numOfAccount, account);
                cout << "Account created successfully";
                continue;
                
            default:
                cout << "You have input a number that is not in the options available\n";
                break;
        }
        
        break;
    }

    cout << "Thank you for using this program! It is time to sleep.\n";
    
    return 0;
}
