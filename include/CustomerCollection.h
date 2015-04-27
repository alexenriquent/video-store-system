#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include <string>
#include <vector>
#include "Customer.h"

class CustomerCollection {

    private:
        std::vector<Customer> customers;

        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        CustomerCollection();
        ~CustomerCollection();
        int numberOfCustomers() const;
        bool collectionIsEmpty() const;
        void addCustomer(const Customer customer);
        int findCustomerIndexByName(const std::string name);
        int findCustomerIndexByUsername(const std::string name);
        Customer customerAt(const int index);
        Customer* getCustomer(const int index);
        void deleteCustomer(const std::string name);
        void clearCollection();

};

#endif // CUSTOMERCOLLECTION_H
