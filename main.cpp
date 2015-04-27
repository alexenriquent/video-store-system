#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <limits>
#include <cctype>
#include "MovieCollection.h"
#include "CustomerCollection.h"
#include "StaffOperations.h"
#include "CustomerOperations.h"

#define STAFF_MODE 1
#define CUSTOMER_MODE 2

using namespace std;

static string STAFF_USERNAME = "staff";
static string STAFF_PASSWORD = "today123";

void displayProgramName();
void displayLoginMenu();
int getLoginOption();
void displayLoginScreen(int loginOption);
bool staffLogin(int loginOption);
bool customerLogin(CustomerCollection& customers,
                   int& customerIndex, int loginOption);
string getUsername();
string getStaffPassword();
string getCustomerPassword();
void displayStaffMenu();
void displayCustomerMenu();
int getStaffOption();
int getCustomerOption();
int confirmLogout();
void displayContinueMessage();
void displayErrorMessage();

int main() {

    Customer c;
    c.setName("Jim Chapman");
    c.setUserName();
    c.setAddress("London, England");
    c.setPhoneNumber("0411234567");
    c.setPassword("8888");

    Customer a;
    a.setName("Alice Wonderland");
    a.setUserName();
    a.setAddress("Wonderland, Another Dimension");
    a.setPhoneNumber("0455123567");
    a.setPassword("8888");

    Movie h;
    h.setTitle("Home");
    h.setStarring("Jim Parsons");
    h.setDirector("Tim Johnson");
    h.setGenre("Animated");
    h.setClassification("PG");
    h.setReleaseDate("27/03/2015");
    h.setDuration(94);
    h.setNumDVDs(10);
    Movie r;
    r.setTitle("The Riot Club");
    r.setStarring("Sam Claflin");
    r.setDirector("Lone Scherfig");
    r.setGenre("Drama");
    r.setClassification("R");
    r.setReleaseDate("27/03/2015");
    r.setDuration(107);
    r.setNumDVDs(10);

    MovieCollection movieCollection;
    movieCollection.insert(h);
    movieCollection.insert(r);
    CustomerCollection customerCollection;
    customerCollection.addCustomer(c);
    customerCollection.addCustomer(a);
    StaffOperations staff;
    CustomerOperations customer;
    int login;
    int staffOperation;
    int customerOperation;
    int authenticated = false;

    displayProgramName();

    do {
        displayLoginMenu();
        login = getLoginOption();
        switch(login) {
            case 1:
                authenticated = staffLogin(login);
                if (authenticated) {
                    cout << "\n\n\t\tLogin successfully" << endl;
                    displayContinueMessage();
                    do {
                        displayStaffMenu();
                        staffOperation = getStaffOption();
                    switch (staffOperation) {
                        case 1:
                            staff.addDVDsOfNewMovie(movieCollection);
                            displayContinueMessage();
                            break;
                        case 2:
                            staff.addDVDsOfExistingMovie(movieCollection);
                            displayContinueMessage();
                            break;
                        case 3:
                            staff.removeDVDs(movieCollection);
                            displayContinueMessage();
                            break;
                        case 4:
                            staff.removeMovie(movieCollection);
                            displayContinueMessage();
                            break;
                        case 5:
                            staff.registerCustomer(customerCollection);
                            displayContinueMessage();
                            break;
                        case 6:
                            staff.removeCustomer(customerCollection);
                            displayContinueMessage();
                            break;
                        case 7:
                            staff.findCustomerPhoneNumber(customerCollection);
                            displayContinueMessage();
                            break;
                        case 8:
                            staff.findRentalRecord(movieCollection);
                            displayContinueMessage();
                            break;
                        case 0:
                            int logoutOption = confirmLogout();
                            if (logoutOption == 1) {
                                staffOperation = -1;
                            }
                            system("CLS");
                            break;
                        }
                    } while (staffOperation != -1);
                    system("CLS");
                } else {
                    cout << "\n\n\t\tIncorrect username or password, please login again" << endl;
                    displayContinueMessage();
                    break;
                }
                break;
            case 2:
                Customer* currentCustomer;
                int index;
                authenticated = customerLogin(customerCollection, index, login);
                currentCustomer = customerCollection.getCustomer(index);
                if (authenticated) {
                        cout << "\n\n\t\tLogin successfully" << endl;
                        displayContinueMessage();
                    do {
                        displayCustomerMenu();
                        customerOperation = getCustomerOption();
                        switch (customerOperation) {
                        case 1:
                            customer.browseAllMovies(movieCollection);
                            displayContinueMessage();
                            break;
                        case 2:
                            customer.displayMovieInfo(movieCollection);
                            displayContinueMessage();
                            break;
                        case 3:
                            customer.rentDVD(movieCollection, currentCustomer);
                            displayContinueMessage();
                            break;
                        case 4:
                            customer.returnDVD(movieCollection, currentCustomer);
                            displayContinueMessage();
                            break;
                        case 5:
                            customer.listCurrentlyRentedMovies(currentCustomer);
                            displayContinueMessage();
                            break;
                        case 6:
                            customer.displayTopTenMovies(movieCollection);
                            displayContinueMessage();
                            break;
                        case 0:
                            int logoutOption = confirmLogout();
                            if (logoutOption == 1) {
                                customerOperation = -1;
                            }
                            system("CLS");
                            break;
                        }
                    } while (customerOperation != -1);
                    currentCustomer == NULL;
                    system("CLS");
                } else {
                    cout << "\n\n\t\tIncorrect username or password, please login again" << endl;
                    displayContinueMessage();
                    break;
                }
                break;
        }
    } while (login != 0);

    return 0;
}

void displayProgramName() {
    cout << "\n\n\n\t      ___________________________________________________" << endl << endl;
    cout << "\t\t   VIDEO STORE MANAGEMENT INFORMATION SYSTEM" << endl;
    cout << "\t      ___________________________________________________" << endl << endl;
    cout << "\t\t     INB371 Data Structures and Algorithms" << endl << endl;
    cout << "\t\t\t\t Assignment 2" << endl << endl;
    displayContinueMessage();
}

void displayLoginMenu(){
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\tLOGIN SCREEN" << endl;
    cout << "\t      ___________________________________________________" << endl << endl;
    cout << "\t\t\t       1) Staff Login" << endl;
    cout << "\t\t\t       2) Customer Login" << endl << endl;
    cout << "\t\t        Press 0 to Exit the Program" << endl << endl;
}

int getLoginOption() {
    int loginOption;
     do {
        cout << "\t\t\tSelect a menu (options 1-2): ";
        cin >> loginOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\t\tSelect a menu (options 1-2): ";
            cin >> loginOption;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (loginOption < 0 || loginOption > 2) {
            displayErrorMessage();
        }
    } while (loginOption < 0 || loginOption > 2);
    system("CLS");
    return loginOption;
}

void displayLoginScreen(int loginOption) {
    if (loginOption == 1) {
        cout << "\n\n\n\n\n\n\t\t\t     STAFF LOGIN SCREEN" << endl;
        cout << "\t     ___________________________________________________" << endl << endl;
    } else if (loginOption == 2) {
        cout << "\n\n\n\n\n\n\t\t\t     CUSTOMER LOGIN SCREEN" << endl;
        cout << "\t     ___________________________________________________" << endl << endl;
    }
}

bool staffLogin(int loginOption) {
    displayLoginScreen(loginOption);
    string username = getUsername();
    string password = getStaffPassword();
    if (username == STAFF_USERNAME && password == STAFF_PASSWORD) {
        return true;
    }
    return false;
}

bool customerLogin(CustomerCollection& customers,
                   int& customerIndex, int loginOption) {
    displayLoginScreen(loginOption);
    string username = getUsername();
    string password = getCustomerPassword();
    int index = customers.findCustomerIndexByUsername(username);
    int notFound = -1;
    if (index == notFound) {
        cout << "\n\n\t\t\tCustomer not found" << endl;
    } else if (index != notFound && password == customers.customerAt(index).getPassword()){
        customerIndex = index;
        return true;
    }
    return false;
}

string getUsername() {
    string username;
    do {
        cout << "\t\t\t     Username: ";
        getline(cin, username);
        if (username == "") {
            cout << "\t\t\tPlease enter your username" << endl;
        }
    } while (username == "");
    return username;
}

string getStaffPassword() {
    string password;
    cout << "\t\t\t     Password: ";
    getline(cin, password);
    return password;
}

string getCustomerPassword() {
    string password;
    bool allDigits;
    do {
        allDigits = true;
        cout << "\t\t\t     Password: ";
        getline(cin, password);
        for (unsigned int i = 0; i < password.length(); i++) {
            if (!isdigit(password[i])) {
                allDigits = false;
            }
        }
        if (password.length() != 4 || allDigits == false)  {
            displayErrorMessage();
            cout << "\t\t\tPlease enter 4-digit password" << endl;
        }
    } while (password.length() != 4 || allDigits == false);
    return password;
}

void displayStaffMenu() {
    cout << "\n\n\t\t\t     STAFF MENU" << endl;
    cout << "\t     ___________________________________________________" << endl << endl;
    cout << "\t\t       1) Add DVDs of a new movie" << endl;
    cout << "\t\t       2) Add DVDs of an existing movie" << endl;
    cout << "\t\t       3) Remove DVDs" << endl;
    cout << "\t\t       4) Remove movie" << endl;
    cout << "\t\t       5) Register a customer" << endl;
    cout << "\t\t       6) Remove a registered customer" << endl;
    cout << "\t\t       7) Find a customer's phone number" << endl;
    cout << "\t\t       8) Find a rental record of a movie" << endl << endl;
    cout << "\t\t       Press 0 to logout" << endl << endl;
}

void displayCustomerMenu() {
    cout << "\n\n\t\t\t     CUSTOMER MENU" << endl;
    cout << "\t     ___________________________________________________" << endl << endl;
    cout << "\t\t       1) Browse all movies" << endl;
    cout << "\t\t       2) Display movie information" << endl;
    cout << "\t\t       3) Rent a DVD" << endl;
    cout << "\t\t       4) Return a DVD" << endl;
    cout << "\t\t       5) List currently rented movies" << endl;
    cout << "\t\t       6) Display top 10 movies" << endl << endl;
    cout << "\t\t       Press 0 to Logout" << endl << endl;
}

int getStaffOption() {
    int staffOption;
    do {
        cout << "\t\tSelect a menu (options 1-8): ";
        cin >> staffOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tSelect a menu (options 1-8): ";
            cin >> staffOption;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (staffOption < 0 || staffOption > 8) {
            displayErrorMessage();
        }
    } while (staffOption < 0 || staffOption > 8);
    system("CLS");
    return staffOption;
}

int getCustomerOption() {
    int customerOption;
    do {
        cout << "\t\tSelect a menu (options 1-6): ";
        cin >> customerOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tSelect a menu (options 1-6): ";
            cin >> customerOption;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (customerOption < 0 || customerOption > 6) {
            displayErrorMessage();
        }
    } while (customerOption < 0 || customerOption > 6);
    system("CLS");
    return customerOption;
}

int confirmLogout() {
    int confirm;
    cout << "\n\n\t\t\tWould you like to log out?" << endl << endl;
    cout << "\t\t\t1) Yes" << endl;
    cout << "\t\t\t2) No" << endl << endl;
    do {
        cout << "\t\t\tEnter an option: ";
        cin >> confirm;
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\t\tEnter an option: ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);
    return confirm;
}

void displayContinueMessage() {
    cout << endl << "\t\tPress ENTER to continue..." << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("CLS");
}

void displayErrorMessage() {
    cout << "\t\t\tERROR: Invalid Input" << endl;
}
