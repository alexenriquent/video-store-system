/// \file CustomerCollection.h
/// \brief Specification for CustomerCollection ADT to represent a collection of customers.

#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include <string>
#include <vector>
#include "Customer.h"

class CustomerCollection {

    private:
        std::vector<Customer> customers; ///< A collection of customers.

        /// Compares two strings regardless the case.
        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        /// Constructor of the CustomerCollection class.
        CustomerCollection();

        /// Destructor of the CustomerCollection class.
        ~CustomerCollection();

        /// Gets a number of customers in the collection.
        int numberOfCustomers() const;

        /// Checks if the collection is empty.
        bool collectionIsEmpty() const;

        /// Adds a customer into the collection.
        void addCustomer(const Customer customer);

        /// Finds a customer's index in the collection by name.
        int findCustomerIndexByName(const std::string name);

        /// Finds a customer's index in the collection by username.
        int findCustomerIndexByUsername(const std::string name);

        /// Gets the customer at the specific index.
        Customer customerAt(const int index);

        /// Gets the customer's memory address at the specific index.
        Customer* getCustomer(const int index);

        /// Removes a customer from the collection.
        void deleteCustomer(const std::string name);

        /// Empties the collection.
        void clearCollection();

};

#endif // CUSTOMERCOLLECTION_H
