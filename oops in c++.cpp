#include <iostream>
#include <string>
using namespace std;

// 1. Interface LibraryUser
class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
    virtual ~LibraryUser() {}
};


class KidUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() override {
        if (age < 12)
            cout << "You have successfully registered under a Kids Account" << endl;
        else
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
    }

    void requestBook() override {
        if (bookType == "Kids")
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        else
            cout << "Oops, you are allowed to take only kids books" << endl;
    }
};

// 2. AdultUser class
class AdultUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() override {
        if (age > 12)
            cout << "You have successfully registered under an Adult Account" << endl;
        else
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
    }

    void requestBook() override {
        if (bookType == "Fiction")
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        else
            cout << "Oops, you are allowed to take only adult Fiction books" << endl;
    }
};

// LibraryInterfaceDemo
int main() {

    //  Test Case 1: KidUser 
    cout << "=== Test Case #1: KidUser ===" << endl;

    KidUser kid;

    // Age = 10
    kid.age = 10;
    kid.registerAccount();

    // Age = 18
    kid.age = 18;
    kid.registerAccount();

    // BookType = "Kids"
    kid.bookType = "Kids";
    kid.requestBook();

    // BookType = "Fiction"
    kid.bookType = "Fiction";
    kid.requestBook();

    // Test Case #2: AdultUser
    cout << "\n Test Case #2: AdultUser << endl;

    AdultUser adult;

    // Age = 5
    adult.age = 5;
    adult.registerAccount();

    // Age = 23
    adult.age = 23;
    adult.registerAccount();

    // BookType = "Kids"
    adult.bookType = "Kids";
    adult.requestBook();

    // BookType = "Fiction"
    adult.bookType = "Fiction";
    adult.requestBook();

    return 0;
}
