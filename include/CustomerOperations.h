/// \file CustomerOperations.h
/// \brief Specification for Sub-menu for the customer operations.
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

#ifndef CUSTOMEROPERATIONS_H
#define CUSTOMEROPERATIONS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <MovieCollection.h>
#include <Customer.h>

class CustomerOperations {

     private:
        /// Gets a movie's title from user.
        std::string promptTitle();

        /// Sorts a list of movies by name.
        void sortMovieList(std::vector<Movie>& movieList);

        /// Sorts a list of movies by a number of rentals.
        void sortMovieListByNumRentals(std::vector<Movie>& movieList);

        /// Adds top ten movies to a list.
        void addTopTenMovies(std::vector<Movie> movieList, std::vector<Movie>& topTenMovies);

        /// Confirms DVD renting
        int confirmRenting(Movie* movieAddress);

        /// Confirms DVD returning
        int confirmReturning(Movie* movieAddress);

        /// Converts the specified string to lowercase.
        std::string lowerCase(std::string str);

        /// Formats the specified string for printing.
        std::string formatString(std::string str);

        /// Display an error message for any invalid input.
        void displayErrorMessage();

        /// Display the movie not found message.
        void displayMovieNotFoundMessage();

    public:
        /// Constructor of the CustomerOperation class.
        CustomerOperations();

        /// Destructor of the CustomerOperation class.
        ~CustomerOperations();

        /// Browses all the movies.
        void browseAllMovies(MovieCollection& movies);

        /// Displays movie information.
        void displayMovieInfo(MovieCollection& movies);

        /// Rents a DVD.
        void rentDVD(MovieCollection& movies, Customer* customer);

        /// Returns a DVD.
        void returnDVD(MovieCollection& movies, Customer* customer);

        /// Lists currently rented movies.
        void listCurrentlyRentedMovies(Customer* customer);

        /// Display top ten movies.
        void displayTopTenMovies(MovieCollection& movies);

};

#endif // CUSTOMEROPERATIONS_H
