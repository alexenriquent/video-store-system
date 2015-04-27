#ifndef STAFFOPERATIONS_H
#define STAFFOPERATIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "MovieCollection.h"
#include "CustomerCollection.h"

#define NUMBER_OF_GENRES 9
#define NUMBER_OF_CLASSIFICATIONS 4

class StaffOperations {

    private:
        void displayGenres();
        void displayClassifications();
        bool isGenre(std::string genre);
        bool isClassification(std::string classification);
        std::string upperCase(std::string str);
        std::string lowerCase(std::string str);
        std::string formatString(std::string str);
        void displayErrorMessage();

    public:
        StaffOperations();
        ~StaffOperations();
        void addDVDsOfNewMovie(MovieCollection& movies);
        void addDVDsOfExistingMovie(MovieCollection& movies);
        void removeDVDs(MovieCollection& movies);
        void removeMovie(MovieCollection& movies);
        void registerCustomer(CustomerCollection& customers);
        void removeCustomer(CustomerCollection& customers);
        void findCustomerPhoneNumber(CustomerCollection& customers);
        void findRentalRecord(MovieCollection& movies);

};

#endif // STAFFOPERATIONS_H
