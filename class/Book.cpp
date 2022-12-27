#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
using namespace std;

class Book
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
        int searchByName()
        {
            cout<<"enter name book\n";
            string Name;
            cin>>Name;
            ifstream myBooks;
            myBooks.open("./txt/books.txt");
            string name;
            while(getline(myBooks,name) )
            {
                if(Name==name)
                {
                    cout<<"Find!!!";
                    return 1;
                }

            }
            cout<<"Not found!!\n"<<
            "u can try other ways to search:\n\n";

            searchBook();


        }
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
        void showUserBooks()
        {
            cout<<"users book show ";
        }
        void giveBack()
        {
            showUserBooks();
            cout<<"give back this books?\n"<<
            "1.YES\n"<<
            "2.NO\n";
            int Button;
            cin>>Button;
            if(Button==1)
            {
                

            }
            else if(Button==2)
            {

            }
            else{
                giveBack();
            }

            
        }
        int searchBook()
        {
            cout<<"1.search by name\n"<<
            "2.search by authors\n"<<
            "3.search by publisher\n"<<
            "4.search by search Year\n";
            int Button;
            cin>>Button;
            if(Button==1)
            {
                int result =searchByName();
                return result;

            }
            else if(Button==2)
            {
                int result =searchByAuthors();
                return result;

            }
            else if(Button==3)
            {
                int result =searchByPublisher();
                return result;

            }
            else if(Button==4)
            {
                int result =searchByYear();
                return result;

            }


        };
};
