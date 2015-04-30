/// \file MovieCollection.h
/// \brief Specification for MovieCollection ADT to represent a collection of movie
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "MovieContainer.h"

class MovieCollection {

    private:
        MovieContainer* root; ///< Pointer to the root of the collection (tree).
        int numMovies; ///< Number of movies in the collection.

        /// Inserts a Movie object into the collection.
        void insert(MovieContainer* root, Movie item);

        /// Checks if the collection contains the specified movie.
        bool search(MovieContainer* root, std::string title) const;

        /// Traverses through the collection in pre-order.
        void preOrderTraversal(MovieContainer* root);

        /// Traverses through the collection in in-order.
        void inOrderTraversal(MovieContainer* root);

        /// Traverses through the collection in post-order.
        void postOrderTraversal(MovieContainer* root);

        /// Clears the collection.
        void clear(const MovieContainer* root);

        /// Get the memory address of the specified movie.
        Movie* getItemAddress(MovieContainer* root, const std::string title);

        /// get all the movies in the collection.
        void allMovies(MovieContainer* root, std::vector<Movie>& movies) const;

        /// Formats the specified string for printing.
        std::string formatString(std::string str);

    public:
        /// Constructor of the MovieCollection class.
        MovieCollection();

        /// Destructor of the MovieCollection class.
        ~MovieCollection();

        /// Checks if the collection is empty.
        bool empty() const;

        /// Gets a number of movies in the collection.
        int size() const;

        /// Inserts a Movie object into the collection.
        void insert(const Movie item);

        /// Remove the specified movie from the collection.
        void erase(const std::string title);

        /// Checks if the collection contains the specified movie.
        bool search(std::string title) const;

        /// Traverses through the collection in pre-order.
        void preOrderTraversal();

        /// Traverses through the collection in in-order.
        void inOrderTraversal();

        /// Traverses through the collection in post-order.
        void postOrderTraversal();

        /// Clears the collection.
        void clear();

        /// Get the memory address of the specified movie.
        Movie* getItemAddress(const std::string title);

        /// get all the movies in the collection.
        void allMovies(std::vector<Movie>& movies) const;

};

#endif // MOVIECOLLECTION_H
