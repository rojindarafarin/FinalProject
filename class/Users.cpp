#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
using namespace std;
class User
{
    public:
        void signUpForm
        (
            string userName,
            string password,
            string firstName,
            string lastName ,
            string birthDate
        )
        {
        ofstream myFile;
        myFile.open("./txt/users.txt");

        myFile<<userName+password<<"\n"<<
        firstName<<"\n"<<
        lastName<<"\n"<<
        birthDate<<"\n";
        myFile.close();
        };
        bool checkUser(string userName , string password)
        {
            ifstream myFile;
            string chk = userName + password;
            myFile.open("./txt/users.txt");
            string line ;
            while (getline(myFile , line))
            {
                if(line == chk)
                {
                    myFile.close();
                    return 1;
                }

            }
            myFile.close();
            return 0;
        }
};