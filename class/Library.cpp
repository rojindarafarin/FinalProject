#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include "Users.cpp"
#include "Book.cpp"
using namespace std;


class Library:public User
{
    private:
        void signIn()
        {
            string userName;
            string password;
            cout<<"User Name:\n";
            cin>>userName;
            cout<<"Password:\n";
            cin>>password;
            if(checkUser(userName , password)==0)
            {
                cout<<"not correct ; try again!";
                signIn();
            }
            else
            {
                cout<<"welcome!";
            } 
    
        }
        void signUp()
        {
            string userName;
            string password;
            string firstName;
            string lastName ;
            string birthDate;
            cout<<"User Name:\n";
            cin>>userName;
            cout<<"Password:\n";
            cin>>password;
            cout<<"First Name:\n";
            cin>>firstName;
            cout<<"Last Name:\n";
            cin>>lastName;
            cout<<"Birth Date:\n";
            cin>>birthDate;
            // signUpForm(userName,password,firstName,lastName ,birthDate);
           

        };

    public:
        Library()
        {
            cout<<
            "welcome to our library\n"<<
            "press any key you want:\n"<<
            "   1.signIn\n"<<
            "   2.signUp\n";
            int button ;
            cin>>button;
            if(button == 1)
            {
               signIn();
            }
            else if (button==2)
            {
                cout<<"signUp function";
                signUp();
            }
            else
            {
                Library();
                cout<<"try again!";
            }
                
        };
};


