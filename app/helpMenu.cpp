#include <iostream>
#include <string>

using namespace std;

class helpMenu {
    private:
        string prblm[] = {"Adding Favourite items", "Comparing items" };
        string solution[] = {"To add favourites..." , "To compare items ..."};

    public:
        //constructors
        help();
        help(String[], String[]);
        //destructor
        ~help(){};

        void setprblm(String[], String[]);
        void setSolution(String[]);
};

help::help ()
{
    prblm []={};
    answer []={};
}

help::help (String[] Prblm, String[] Solution)
{
prblm = Prblm;
solution=Solution;
}

public void getprblm (String[]Prblm, String[]Solution){

e

