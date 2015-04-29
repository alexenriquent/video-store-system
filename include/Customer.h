/// \file Customer.h
/// \brief Specification for Customer ADT to model a customer.

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
        std::string name; ///< Name of the customer.
        std::string address; ///< Address of the customer.
        std::string phoneNumber; ///< Contact phone number of the customer.
        std::string username; ///< Username of the customer.
        std::string password; ///< Password of the customer.
        std::vector<std::string> record; ///< Rental record of the customer.

        /// Converts the specified string to lowercase.
        std::string lowerCase(std::string str);

        /// Formats the specified string for printing.
        std::string formatString(std::string str);

        /// Compares two strings regardless the case.
        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        /// Default constructor of the Customer class.
        Customer();

        /// Constructor of the Customer class.
        Customer(std::string name, std::string address, std::string phoneNumber);

        /// Destructor of the Customer class.
        ~Customer();

        /// Getter method for the name field.
        std::string getName() const;

        /// Getter method for the address field.
        std::string getAddress() const;

        /// Getter method for the phoneNumber field.
        std::string getPhoneNumber() const;

        /// Getter method for the username field.
        std::string getUsername() const;

        /// Getter method for the password field.
        std::string getPassword() const;

        /// Getter method for the record field.
        std::vector<std::string> getRecord() const;

        /// Setter method for the name field.
        void setName(const std::string name);

        /// Setter method for the address field.
        void setAddress(const std::string address);

        /// Setter method for the phoneNumber field.
        void setPhoneNumber(const std::string phoneNumber);

        /// Setter method for the username field.
        void setUserName();

        /// Setter method for the password field.
        void setPassword(const std::string password);

        /// Adds the specified title into the rental record.
        void addRecord(const std::string title);

        /// Finds the specified record.
        int findRecord(const std::string title);

        /// Remove the specified record.
        void removeRecord(const std::string title);

        /// Display record details.
        void displayRecord();

};

#endif // CUSTOMER_H
