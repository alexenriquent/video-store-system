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
        int confirmRenting(Movie* movieAddress);
        int confirmReturning(Movie* movieAddress);
        std::string lowerCase(std::string str);
        std::string formatString(std::string str);
        void displayErrorMessage();
        void displayMovieNotFoundMessage();

    public:
        CustomerOperations();
        ~CustomerOperations();
        void browseAllMovies(MovieCollection& movies);
        void displayMovieInfo(MovieCollection& movies);
        void rentDVD(MovieCollection& movies, Customer* customer);
        void returnDVD(MovieCollection& movies, Customer* customer);
        void listCurrentlyRentedMovies(Customer* customer);
        void displayTopTenMovies(MovieCollection& movies);

};

#endif // CUSTOMEROPERATIONS_H
