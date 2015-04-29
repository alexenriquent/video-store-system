/// \file CustomerCollection.cpp
/// \brief Implementation for CustomerCollection ADT to represent a collection of customers.
/// \author Thanat Chokwijitkul n9234900
/// \author Xui Koh
/// \date April, 2015

#include "CustomerCollection.h"

/// \brief Initialises this CustomerCollection.
CustomerCollection::CustomerCollection() {
    // Empty constructor
}

/// \brief Destroys this CustomerCollection.
CustomerCollection::~CustomerCollection() {
    // Empty destructor
}

/// \brief Adds a customer object into this CustomerCollection.
/// \param customer Customer - Customer object to be added.
void CustomerCollection::addCustomer(const Customer customer) {
    customers.push_back(customer);
}

/// \brief Returns a number of customers in the collection.
/// \return int - Number of customers.
int CustomerCollection::numberOfCustomers() const {
    return customers.size();
}

/// \brief Checks if the collection is empty or contains at lease 1 customer.
/// \return bool - TRUE if the collection is empty.
/// \return bool - FALSE if the collection is not empty.
bool CustomerCollection::collectionIsEmpty() const {
    return customers.empty();
}

/// \brief Finds a customer's index in the collection by the specified name.
/// \param name std::string - Customer's name.
/// \return int - Customer's index.
/// \return -1 - Customer not found.
int CustomerCollection::findCustomerIndexByName(const std::string name) {
    for (std::vector<Customer>::size_type i = 0; i != customers.size(); i++) {
        if (compareCaseInsensitive(customers[i].getName(), name)) {
            return i;
        }
    }
    return -1;
}

/// \brief Finds a customer's index in the collection by the specified username.
/// \param username std::string - Customer's username.
/// \return int - Customer's index.
/// \return -1 - Customer not found.
int CustomerCollection::findCustomerIndexByUsername(const std::string username) {
    for (std::vector<Customer>::size_type i = 0; i != customers.size(); i++) {
        if (customers[i].getUsername() == username) {
            return i;
        }
    }
    return -1;
}

/// \brief Returns the specific customer object at the specified index.
/// \return Customer - Customer at the index.
Customer CustomerCollection::customerAt(const int index) {
    return customers[index];
}

/// \brief Returns the specific customer's memory address at the specified index.
/// \return Customer* - Pointer to the address of the customer at the index.
Customer* CustomerCollection::getCustomer(const int index) {
    return &customers[index];
}

/// \brief Removes a customer from the collection using the specified name.
/// \param name std::string - Customer's name.
void CustomerCollection::deleteCustomer(const std::string name) {
    int index = findCustomerIndexByName(name);
    if (index != -1) {
        customers.erase(customers.begin() + index);
    }
}

/// \brief Remove all the customers from the collection.
void CustomerCollection::clearCollection() {
    customers.clear();
}

/// \brief Helper method to compares two strings regardless the case.
/// \param str1 std::string - Compared string.
/// \param str2 std::string - Comparing string.
/// \return bool - TRUE if the string comparison result is equal.
/// \return bool - FALSE if the string comparison result is not equal.
bool CustomerCollection::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
