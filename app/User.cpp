#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string firstName;
    string lastName;
    string email;
    string password;
public:
    User();
    User(string, string, string, string);
    string getFirstName();
    string getLastName();
    string getEmail();
    string getPassword();

    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setPassword(string);
};

string User::getFirstName() {
    string copy = firstName;
    return copy;
}

string User::getLastName() {
    string copy = lastName;
    return copy;
}

string User::getEmail() {
    string copy = email;
    return copy;
}

string User::getPassword() {
    string copy = password;
    return copy;
}

User::User() {
    firstName = "";
    lastName = "";
    email = "";
    password = "";
}

User::User(string FN, string LN, string E, string P) {
    firstName = FN;
    lastName = LN;
    email = E;
    password = P;
}

void User::setFirstName(string FN) { firstName = FN; }

void User::setLastName(string LN) { lastName = LN; }

void User::setEmail(string E) { email = E; }

void User::setPassword(string P) { password = P; }
