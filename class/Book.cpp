#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include "users.cpp"
#include <cstdlib>
using namespace std;


class Book:public User
{
    private:
        string Title ;
        string ShelfNumber;
        vector<string> Authors;
        string Edition;
        string Publisher;
        string PublishedYear;
        string ISBN;
        string Length;
        vector<string> Subjects;
       
    public:
        void firstStep()
        {
            cout<<"1.search Book"<<"\n"<<
            "2.give back Books\n";
            int Button;
            cin>>Button;
            if(Button==1)
            {
                searchBook();

            }
            else if(Button==2)
            {
                giveBack();
            }
        
        }
     
        void searchBook()
        {
            cout<<"choise way of search:\n"<<
            "1-Title \n 2-Author \n 3-publisher \n 4-published year \n";
            int Button , res , i;
            cin>>Button;
            cout<<"enter phrase: \n";
            string f ;
            cin>>f;
            ifstream myBooks ;
            myBooks.open("./txt/books.txt");
            string line ;
            vector<string > Book ;
            res=0;
            while(getline(myBooks , line ))
            {
                Book = split(line );
                if(Button==1)
                {
                    if(Book[0]==f)
                        res=1;
                        int i = 0;

                }
                else if(Button==2)
                {
                    if(Book[2]==f)
                        res=1;
                        int i = 2;
                }
                else if(Button == 3)
                {
                    if(Book[4]==f)
                        res=1;
                        int i = 4;
                }
                else if(Button==4)
                {
                    if(Book[5]==f)
                        res=1;
                        int i = 5;
                }


            }
            int a;
            if(res==1)
            {   cout<<"FIND";
                showBook(f , i);

                
            }
            else
                cout<<"NOT FOUND!";
                searchBook();

            myBooks.close();
            
        }


        void showBook(string f , int i)
        {
            string title ;
            string userName;
            ifstream myBooks ;
            myBooks.open("./txt/books.txt");
            string book;
            vector<string> Book;
            int res=0;
            int btn ;
            while(getline(myBooks , book))
            {
                Book = split(book);
                if(Book[i] == f)
                {
                    if(Book[10]=="0")
                    {
                        cout<<"Book is available! \n"<<
                        "Title:     "<<Book[0]<<"\n shelfNumber :       "<<Book[1];
                        int res =1;
                        cout<<"1-bring the book \n\n 2-quit \n\n";
                        title = Book[0];
                        cin>>btn;
                    }
                    else
                    {
                        cout<<"Not Available ! \n try again! \n " ;
                        searchBook();
                    }
                }

            }
            if(btn==1){
                cout<<"please enter your useer name again !! \n\n";
                cin>>userName;
                string book;
                vector<string> Book;
                ifstream myBooks{"./txt/books.txt"};
                ofstream myBooks2{"./txt/books2.txt"};
                if(myBooks2 && myBooks){
                    while(getline(myBooks ,book ))
                    {
                        Book = split(book);
                        if(Book[i]==f)
                        {
                            myBooks2<<Book[0]<<","<<Book[1]<<","<<Book[2]<<","<<Book[3]<<","<<Book[4]<<","<<
                            Book[5]<<","<<Book[6]<<","<<Book[7]<<","<<Book[8]<<","<<userName<<","<<1;

                        }
                        else    
                            myBooks2<<book<<"\n";
                    }
                }
                myBooks.close();
                myBooks2.close();
                string line ;
                ifstream myBook2{"./txt/books2.txt"};
                ofstream myBook{"./txt/books.txt"};
                while(getline(myBook2 , line))
                {
                    myBook<<line<<"\n";
                };
                
            }
            string lin ;
            vector<string > User ;
            ifstream ini_file{
		        "./txt/users.txt"
	        };
	        ofstream out_file{ "./txt/users2.txt" };
	        if (ini_file && out_file) {

		        while (getline(ini_file, lin)) {
                    User = split(lin);
                    if(User[0] == userName && User[5]=="0" )
                    {
                        out_file<<User[0]<<","<<User[1]<<","<<User[2]<<","<<User[3]<<","<<User[4]<<","<<title<<","<<User[6]<<","<<User[7]<<"\n";
                    }
                    else if(User[0] == userName && User[5] != "0" && User[6]=="0" )
                    {
                        out_file<<User[0]<<","<<User[1]<<","<<User[2]<<","<<User[3]<<","<<User[4]<<","<<User[5]<<","<<title<<","<<User[7]<<"\n";
                    }
                    else if(User[0] == userName && User[5] != "0" && User[6] !="0" && User[7] =="0" )
                    {
                        out_file<<User[0]<<","<<User[1]<<","<<User[2]<<","<<User[3]<<","<<User[4]<<","<<User[5]<<","<<User[6]<<","<<title<<"\n";
                    }
                    else if(User[0] == userName && User[5] != "0" && User[6]!="0" && User[7] !="0" )
                    {
                        cout<<"you can not bring any book becouse u have 3 book \n";
                        firstStep();
                    }
                    
			        else if(User[0] != userName)
                    {
                        out_file << lin << "\n";
                    }
                       
		        }


	        };
            ini_file.close();
            out_file.close();
            ifstream in {
                "./txt/users2.txt"
            };
            ofstream out{"./txt/users.txt"};
            if(in && out)
            {
                while(getline(in , lin))
                {
                    out<<lin<<"\n";
                }
            }
            out.close();
            in.close();
            cout<<"SignUp seccussfully!!!! \n\n";
        
        };
    



        void giveBack()
        {
            cout<<"please enter your username again? \n";
            ifstream myUsers;
            ofstream myBooks;
            myBooks.open("./txt/books.txt");
            myUsers.open("./txt/users.txt");
            string username;
            string user;
            string book;
            cin>>username;
            vector<string> Book ;
            vector<string> User;
            string title1;
            string title2;
            string title3;
            
            while(getline(myUsers , user))
            {
                User =split(user);

                if(User[0] == username)
                {
                    title1 = User[5];
                    title2 = User[6];
                    title3 = User[7];
                    if(title1 =="0" && title2 == "0" && title3=="0")
                    {
                        cout<<"you have not already any books \n";
                        firstStep();

                    }
                    
                    else
                    {
                        cout<<"give back your books?\n"<<
                        "1.YES\n"<<
                        "2.NO\n";
                        int Button;
                        cin>>Button;
                        if(Button==1)
                        {
                            cout<<"give back all!";
                

                        }
                        else if(Button==2)
                        {
                            firstStep();
                        }
                        if(title1 != "0" || title2!="0" || title3!="0")
                        {
                            ifstream in{"./txt/books.txt"};
                            ofstream out{"./txt/books2.txt"};
                            while(getline(in , book))
                            {
                                Book=split(book);
                                if(Book[0] == title1 || Book[0]==title2 || Book[0]==title3)
                                {
                                    out<<Book[0]<<","<<Book[1]<<","<<Book[2]<<","<<Book[3]<<","<<Book[4]<<","<<Book[5]<<","<<Book[6]<<
                                    ","<<Book[7]<<","<<Book[8]<<","<<"0"<<","<<"0";
                                    cout<<title1<<"\n"<<title2<<"\n"<<title3<<endl;
                                }
                                else
                                    out<<book;
                            }


                            ifstream in2{"./txt/users.txt"};
                            ofstream out2{"./txt/users2.txt"};
                            while(getline(in2 , user))
                            {
                                User = split(user);
                                if(User[0]==username)
                                {
                                    out2<<User[0]<<","<<User[1]<<","<<User[2]<<","<<User[3]<<","<<User[4]<<","<<"0"<<","<<"0"<<
                                    ","<<"0\n";
                                }
                                else
                                {
                                    out2<<user;
                                }
                            }
                            in.close();
                            out.close();
                            in2.close();
                            out2.close();
                            
                            ofstream out1{"./txt/books.txt"};
                            ifstream in1{"./txt/books2.txt"};
                            while(getline(in1 , book))
                            {
                                out1<<book<<"\n";

                            }
                            out1.close();
                            in1.clear();
                            ifstream in22{"./txt/users2.txt"};
                            ofstream out22{"./txt/users.txt"};
                            while(getline(in22 , user))
                            {
                                out22<<user<<"\n";
                            }
                            in22.close();
                            out22.close();




                        }
                    }
                        
                        
                



            }
            }
            
    
           
        };
};
