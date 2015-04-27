#include "CustomerCollection.h"

CustomerCollection::CustomerCollection() {

}

CustomerCollection::~CustomerCollection() {

}

void CustomerCollection::addCustomer(const Customer customer) {
    customers.push_back(customer);
}

int CustomerCollection::numberOfCustomers() const {
    return customers.size();
}

bool CustomerCollection::collectionIsEmpty() const {
    return customers.empty();
}

int CustomerCollection::findCustomerIndexByName(const std::string name) {
    for (std::vector<Customer>::size_type i = 0; i != customers.size(); i++) {
        if (compareCaseInsensitive(customers[i].getName(), name)) {
            return i;
        }
    }
    return -1;
}

int CustomerCollection::findCustomerIndexByUsername(const std::string username) {
    for (std::vector<Customer>::size_type i = 0; i != customers.size(); i++) {
        if (customers[i].getUsername() == username) {
            return i;
        }
    }
    return -1;
}

Customer CustomerCollection::customerAt(const int index) {
    return customers[index];
}

Customer* CustomerCollection::getCustomer(const int index) {
    return &customers[index];
}

void CustomerCollection::deleteCustomer(const std::string name) {
    int index = findCustomerIndexByName(name);
    if (index != -1) {
        customers.erase(customers.begin() + index);
    }
}

void CustomerCollection::clearCollection() {
    customers.clear();
}

bool CustomerCollection::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
