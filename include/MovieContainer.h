/// \file MovieContainer.h
/// \brief Specification for MovieContainer ADT used as a container (node) in MovieCollection ADT.
/// \author Thanat Chokwijitkul n9234900
/// \author Xui Koh
/// \date April, 2015

#ifndef MOVIECONTAINER_H
#define MOVIECONTAINER_H

#include <string>
#include <cstddef>
#include "Movie.h"

class MovieContainer {

    private:
        Movie item; ///< Movie object stored in the container.
        MovieContainer* lChild; ///< Pointer to the left child node.
        MovieContainer* rChild; ///< Pointer to the right child node.

    public:
        /// Constructor of the MovieContainer class.
        MovieContainer(Movie item);

        /// Destructor of the MovieContainer class.
        ~MovieContainer();

        /// Getter method for the item field.
        Movie getItem() const;

        /// Getter method for the pointer to the item's memory address.
        Movie* getItemAddress();

        /// Getter method for the pointer to the left child node.
        MovieContainer* getLChild() const;

        /// Getter method for the pointer to the right child node.
        MovieContainer* getRChild() const;

        /// Setter method for the item field.
        void setItem(const Movie& item);

        /// Setter method for the pointer to the left child node.
        void setLChild(MovieContainer* child);

        /// Setter method for the pointer to the right child node.
        void setRChild(MovieContainer* child);
};

#endif // MOVIECONTAINER_H
