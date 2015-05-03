/// \file StaffOperations.h
/// \brief Specification for Sub-menu for the staff operations.
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

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
        /// Gets a movie's title from user.
        std::string promptTitle();

        /// Gets name(s) of people who starred in the movie.
        std::string promptStarring();

        /// Gets the movie's director from user.
        std::string promptDirector();

        /// Gets the movie's genre from user.
        std::string promptGenre();

        /// Gets the movie's classification from user.
        std::string promptClassification();

        /// Gets the movie's release date from user.
        std::string promptReleaseDate();

        /// Gets the movie's duration from user.
        int promptDuration();

        /// Gets a number of DVDs from user.
        int promptNumDVDs();

        /// Gets a customer's name from user.
        std::string promptName();

        /// Gets the customer's address from user.
        std::string promptAddress();

        /// Gets the customer's phone number from user.
        std::string promptPhoneNumber();

        /// Gets the customer's password from user.
        std::string promptPassword();

        /// Displays a list of genres.
        void displayGenres();

        /// Displays a list of classifications.
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

        /// Display an error message for any invalid input.
        void displayErrorMessage();

        /// Display the movie not found message.
        void displayMovieNotFoundMessage();

        /// Display the customer not found message.
        void displayCustomerNotFoundMessage();

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
