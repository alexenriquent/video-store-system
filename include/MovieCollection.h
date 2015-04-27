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
        MovieContainer* root;
        int numMovies;

        void insert(MovieContainer* root, Movie item);
        bool search(MovieContainer* root, std::string title) const;
        void preOrderTraversal(MovieContainer* root);
        void inOrderTraversal(MovieContainer* root);
        void postOrderTraversal(MovieContainer* root);
        void clear(const MovieContainer* root);

        Movie* getItemAddress(MovieContainer* root, const std::string title);
        void allMovies(MovieContainer* root, std::vector<Movie>& movies) const;
        std::string formatString(std::string str);

    public:
        MovieCollection();
        ~MovieCollection();
        bool empty() const;
        int size() const;
        void insert(const Movie item);
        void erase(const std::string title);
        bool search(std::string title) const;
        void preOrderTraversal();
        void inOrderTraversal();
        void postOrderTraversal();
        void clear();

        void allMovies(std::vector<Movie>& movies) const;
        Movie* getItemAddress(const std::string title);

};

#endif // MOVIECOLLECTION_H
