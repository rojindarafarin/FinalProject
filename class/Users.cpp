#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class User
{
    public:
        
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
    

        
};