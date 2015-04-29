/// \file Movie.h
/// \brief Specification for Movie ADT to model a movie.

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>

class Movie {

    private:
        std::string title; ///< Title of the movie.
        std::string starring; ///< People who starred in the movie.
        std::string director; ///< Director of the movie.
        std::string genre; ///< Genre of the movie.
        std::string classification; ///< Classification of the movie.
        std::string releaseDate; ///< Releasing date of the movie.
        int duration; ///< Duration of the movie.
        int numDVDs; ///< Number of DVDs of the movie.
        int numRentals; ///< Number of times the movie has been rented.
        std::vector<std::string> record; ///< Rental record of the movie.

        /// Converts the specified string to uppercase.
        std::string upperCase(std::string str);

        /// Converts the specified string to lowercase.
        std::string lowerCase(std::string str);

        /// Formats the specified string for printing.
        std::string formatString(std::string str);

        /// Compares two strings regardless the case.
        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        /// Default constructor of the Movie class.
        Movie();

        /// Constructor for of the Movie class.
        Movie(std::string title, std::string starring,
              std::string director, std::string genre,
              std::string classification, std::string releaseDate,
              int duration, int numDVDs);

        /// Destructor of the Movie class.
        ~Movie();

        /// Getter method for the title field.
        std::string getTitle() const;

        /// Getter method for the starring field.
        std::string getStarring() const;

        /// Getter method for the director field.
        std::string getDirector() const;

        /// Getter method for the genre field.
        std::string getGenre() const;

        /// Getter method for the classification field.
        std::string getClassification() const;

        /// Getter method for the releaseDate field.
        std::string getReleaseDate() const;

        /// Getter method for the duration field.
        int getDuration() const;

        ///Getter method for the numDVDs field.
        int getNumDVDs() const;

        /// Getter method for the numRentals field.
        int getNumRentals() const;

        /// Getter method for the record field.
        std::vector<std::string> getRecord() const;

        /// Setter for the title field.
        void setTitle(const std::string title);

        /// Setter for the starring field.
        void setStarring(const std::string starring);

        /// Setter for the director field.
        void setDirector(const std::string director);

        /// Setter for the genre field.
        void setGenre(const std::string genre);

        /// Setter for the classification field.
        void setClassification(const std::string classification);

        /// Setter for the releaseDate field.
        void setReleaseDate(const std::string releaseDate);

        /// Setter for the duration field.
        void setDuration(const int duration);

        /// Setter for the numDVDs field.
        void setNumDVDs(const int numDVDs);

        /// Increases the number of rentals.
        void increaseNumRentals();

        /// Adds the specified customer's name into the rental record.
        void addRecord(const std::string name);

        /// Finds the specified customer in the rental record.
        int findRecord(const std::string name);

        /// Removes the specified customer's name from the rental record.
        void removeRecord(const std::string name);

        /// Add DVDs to this movie.
        void addDVDs(const int numDVDs);

        /// Removes DVDs from this movie.
        void removeDVDs(const int numDVDs);

        /// Display information of this movie.
        void displayInfo();
};

#endif // MOVIE_H
