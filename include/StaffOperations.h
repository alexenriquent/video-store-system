/// \file StaffOperations.h
/// \brief Specification for Sub-menu for the staff operations.

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
        /// Display a list of genres.
        void displayGenres();

        /// Display  a list of classifications.
        void displayClassifications();

        /// Checks if the input genre is on the genre list.
        bool isGenre(std::string genre);

        /// Checks if the input classification is on the classification list.
        bool isClassification(std::string classification);

        /// Converts the specified string to uppercase.
        std::string upperCase(std::string str);

        /// Converts the specified string to lowercase.
        std::string lowerCase(std::string str);

        /// Formats the specified string for printing.
        std::string formatString(std::string str);

        /// Display an error message.
        void displayErrorMessage();

    public:
        /// Constructor of the StaffOperation class.
        StaffOperations();

        /// Destructor of the StaffOperation class.
        ~StaffOperations();

        /// Adds a new movie.
        void addDVDsOfNewMovie(MovieCollection& movies);

        /// Adds DVDs to an existing movie.
        void addDVDsOfExistingMovie(MovieCollection& movies);

        /// Removes DVDs of a movie.
        void removeDVDs(MovieCollection& movies);

        /// Removes a movie.
        void removeMovie(MovieCollection& movies);

        /// Register a new customer.
        void registerCustomer(CustomerCollection& customers);

        /// Removes an exiting customer.
        void removeCustomer(CustomerCollection& customers);

        /// Finds a customer's phone number.
        void findCustomerPhoneNumber(CustomerCollection& customers);

        /// Finds a movie's rental record.
        void findRentalRecord(MovieCollection& movies);

};

#endif // STAFFOPERATIONS_H
