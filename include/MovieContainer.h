#ifndef MOVIECONTAINER_H
#define MOVIECONTAINER_H

#include <string>
#include <cstddef>
#include "Movie.h"

class MovieContainer {

    private:
        Movie item;
        MovieContainer* lChild;
        MovieContainer* rChild;

    public:
        MovieContainer(Movie item);
        ~MovieContainer();
        Movie getItem() const;
        Movie* getItemAddress();
        MovieContainer* getLChild() const;
        MovieContainer* getRChild() const;
        void setItem(const Movie& item);
        void setLChild(MovieContainer* child);
        void setRChild(MovieContainer* child);
};

#endif // MOVIECONTAINER_H
