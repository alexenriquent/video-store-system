/// \file Customer.cpp
/// \brief Implementation for Customer ADT to model a customer.
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

#include "Customer.h"

using namespace std;

/// \brief Initialises all the data members of this Customer object with default values.
Customer::Customer() {
    name = "";
    address = "";
    phoneNumber = "";
    username = "";
    password = "";
}

/// \brief Initialises all the data members of this Customer object with the specified values.
/// \param name std::string - Customer's name.
/// \param address std::string - Customer's address.
/// \param phoneNumber std::string - Customer's phone number.
Customer::Customer(std::string name, std::string address, std::string phoneNumber) {
    this->name = lowerCase(name);
    this->address = lowerCase(address);
    this->phoneNumber = phoneNumber;
    setUserName();
}

/// \brief Destroys this Customer object.
Customer::~Customer() {

}

/// \brief Gets the name field.
/// \return std::string - name of the customer.
std::string Customer::getName() const {
    return name;
}

/// \brief Gets the address field.
/// \return std::string - address of the customer.
std::string Customer::getAddress() const {
    return address;
}

/// \brief Gets the phoneNumber field.
/// \return std::string - phone number of the customer.
std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

/// \brief Gets the username field.
/// \return std::string - username of the customer.
std::string Customer::getUsername() const {
    return username;
}

/// \brief Gets the password field.
/// \return std::string - password of the customer.
std::string Customer::getPassword() const {
    return password;
}

/// \brief Gets the record field.
/// \return std::vector<std::string> - record of the customer.
std::vector<std::string> Customer::getRecord() const {
    return record;
}

/// \brief Sets the name field with the specified value.
/// \param name std::string - Customer's name.
void Customer::setName(const std::string name) {
    this->name = lowerCase(name);
}

/// \brief Sets the address field with the specified value.
/// \param address std::string - Customer's address.
void Customer::setAddress(const std::string address) {
    this->address = address;
}

/// \brief Sets the phoneNumber field with the specified value.
/// \param phoneNumber std::string - Customer's phone number.
void Customer::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

/// \brief Automatically sets the username field of the customer.
void Customer::setUserName() {
    std::istringstream buf(formatString(name));
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> splitedName(beg, end);
    for (int i = splitedName.size()-1; i >= 0; i--) {
        username += splitedName[i];
    }
}

/// \brief Sets the password field with the specified value.
/// \param password std::string - Customer's password.
void Customer::setPassword(const std::string password) {
    this->password = password;
}

/// \brief Sets the record field with the specified value.
/// \param title std::string - Movie's title.
void Customer::addRecord(const std::string title) {
    record.push_back(lowerCase(title));
}

/// \brief Finds an index of the specified movie's title in the rental record.
/// \param title std::string - Movie's title.
/// \return int - Index of the specified customer.
/// \return -1 - Index not found.
int Customer::findRecord(const std::string title) {
    for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
        if (compareCaseInsensitive(record[i], title)) {
            return i;
        }
    }
    return -1;
}

/// \brief Removes the specified movie's title from the rental record.
/// \param title std::string - Movie's title.
void Customer::removeRecord(const std::string title) {
    int index = findRecord(title);
    if (index != -1) {
        record.erase(record.begin() + index);
    }
}

/// \brief Displays the rental record with customer details.
void Customer::displayRecord() {
    cout << "\n\n\t\tCUSTOMER RECORD" << endl << endl;
    cout << "\t\tName:         " << formatString(name) << endl;
    cout << "\t\tAddress:      " << formatString(address) << endl;
    cout << "\t\tPhone Number: " << phoneNumber << endl;
    cout << "\t\tUsername:     " << username << endl;
    cout << "\t\tNumber of movies rented: " << record.size() << endl << endl;

    for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
        cout << "\t\t" << i+1 << ") " << formatString(record[i]) << endl;
    }
    cout << endl;
}

/// \brief Helper method to convert a string to lowercase.
/// \param str std::string - A string.
/// \return std::string - String with all lowercase characters.
std::string Customer::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/// \brief Helper method to format a string for printing.
/// \param str std::string - A string.
/// \return std::string - formatted string.
std::string Customer::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

/// \brief Helper method to compares two strings regardless the case.
/// \param str1 std::string - Compared string.
/// \param str2 std::string - Comparing string.
/// \return bool - TRUE if the string comparison result is equal.
/// \return bool - FALSE if the string comparison result is not equal.
bool Customer::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
