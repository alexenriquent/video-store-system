#include "Customer.h"

using namespace std;

Customer::Customer() {
    name = "";
    address = "";
    phoneNumber = "";
    username = "";
    password = "";
}

Customer::Customer(std::string name, std::string address, std::string phoneNumber) {
    this->name = lowerCase(name);
    this->address = lowerCase(address);
    this->phoneNumber = phoneNumber;
    setUserName();
}

Customer::~Customer() {

}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

std::string Customer::getUsername() const {
    return username;
}

std::string Customer::getPassword() const {
    return password;
}

std::vector<std::string> Customer::getRecord() const {
    return record;
}

void Customer::setName(const std::string name) {
    this->name = lowerCase(name);
}

void Customer::setAddress(const std::string address) {
    this->address = address;
}

void Customer::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::setUserName() {
    std::istringstream buf(formatString(name));
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> splitedName(beg, end);
    for (int i = splitedName.size()-1; i >= 0; i--) {
        username += splitedName[i];
    }
}

void Customer::setPassword(const std::string password) {
    this->password = password;
}

void Customer::addRecord(const std::string title) {
    record.push_back(lowerCase(title));
}

int Customer::findRecord(const std::string title) {
    for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
        if (compareCaseInsensitive(record[i], title)) {
            return i;
        }
    }
    return -1;
}

void Customer::removeRecord(const std::string title) {
    int index = findRecord(title);
    if (index != -1) {
        record.erase(record.begin() + index);
    }
}

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

std::string Customer::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string Customer::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

bool Customer::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
