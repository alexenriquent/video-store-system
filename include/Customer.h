#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include <cctype>
#include <algorithm>
#include "Movie.h"

class Customer {

    private:
        std::string name;
        std::string address;
        std::string phoneNumber;
        std::string username;
        std::string password;
        std::vector<std::string> record;

        std::string lowerCase(std::string str);
        std::string formatString(std::string str);
        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        Customer();
        Customer(std::string name, std::string address, std::string phoneNumber);
        ~Customer();
        std::string getName() const;
        std::string getAddress() const;
        std::string getPhoneNumber() const;
        std::string getUsername() const;
        std::string getPassword() const;
        std::vector<std::string> getRecord() const;
        void setName(const std::string name);
        void setAddress(const std::string address);
        void setPhoneNumber(const std::string phoneNumber);
        void setUserName();
        void setPassword(const std::string password);
        void addRecord(const std::string title);
        int findRecord(const std::string title);
        void removeRecord(const std::string title);
        void displayRecord();

};

#endif // CUSTOMER_H
