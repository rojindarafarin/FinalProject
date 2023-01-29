#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include "Book.cpp"
using namespace std;


class Library: public Book
{
    
    public:
        Library()
        {
            cout<<
            "Welcome to our library\n"<<
            "Press any key you want:\n"<<
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
                signUp();
            }
            else
            {
                Library();
                cout<<"Try again!";
            }
                
        };
         vector<string> split(string str)
        {

            vector<string> usr;
	        string word = "";
	        for (auto x : str)
	        {
		        if (x == ',')
		        {
                    usr.push_back(word);
			        word = "";
		        }
		        else 
                {
			        word = word + x;
		        }
	        }
	        usr.push_back(word);
            return usr;
        };
    
        int checkUser(string userName , string password)
        {
            ifstream myFile;
            vector<string> usr;
            myFile.open("./txt/users.txt");
            string line ;
            int i = 0;
            while (getline(myFile , line))
            {
                usr = split(line);
                if((usr[0]==userName) && (usr[1]==password ))
                {
                    i++;
                    myFile.close();
                    return 1;
                    
                   

                }
                
            }

           
        };

        void signUpForm
        (
            string userName,
            string password,
            string firstName,
            string lastName ,
            string birthDate
        )
        {
            string line ;
            ifstream ini_file{
		        "./txt/users.txt"
	        };
	        ofstream out_file{ "./txt/users2.txt" };
	        if (ini_file && out_file) {

		        while (getline(ini_file, line)) {
                
			        out_file << line << "\n";
		        }
            out_file<<userName<<","<<
            password<<","<<
            firstName<<","<<
            lastName<<","<<
            birthDate<<","<<"0"<<","<<"0"<<","<<"0";

	        };
            ini_file.close();
            out_file.close();
            ifstream in {
                "./txt/users2.txt"
            };
            ofstream out{"./txt/users.txt"};
            if(in && out)
            {
                while(getline(in , line))
                {
                    out<<line<<"\n";
                }
            }
            out.close();
            in.close();
            cout<<"SignUp seccussfully!!!! \n\n";
        
            };
        void signIn()
        {
            string userName;
            string password;
            cout<<"User Name:\n";
            cin>>userName;
            cout<<"Password:\n";
            cin>>password;
         
            
            if(checkUser(userName ,password )==0)
            {
                cout<<"not correct ;\n try again!\n";
                signIn();
            }
            else if(checkUser(userName , password) == 1)
            {
                cout<<"welcome!\n";
                firstStep();
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
            signUpForm(userName,password,firstName,lastName ,birthDate);
            firstStep();
        }
        };


