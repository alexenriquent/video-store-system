/// \file MovieCollection.cpp
/// \brief Implementation for MovieCollection ADT to represent a collection of movie

#include "MovieCollection.h"

using namespace std;

/// \brief Initialises this MovieCollection.
MovieCollection::MovieCollection() {
    root = NULL;
    numMovies = 0;
}

/// \brief Destroys this MovieCollection.
MovieCollection::~MovieCollection() {

}

/// \brief Checks if the collection does not contain any movie.
/// \return bool - TRUE if the collection is empty.
/// \return bool - FALSE if the collection is not empty.
bool MovieCollection::empty() const {
    return root == NULL;
}

/// \brief Returns a number of movies stored in the collection.
/// \return int - Number of movies stored in the collection.
int MovieCollection::size() const {
    return numMovies;
}

/// \brief Inserts the specified Movie object into the collection.
/// \param item Movie - Movie object to be inserted.
void MovieCollection::insert(const Movie item) {
    if (root == NULL) {
        root = new MovieContainer(item);
        numMovies = 1;
    } else {
        insert(root, item);
    }
}

/// \brief Recursive function that inserts the specified Movie object into the collection.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
/// \param item Movie - Movie object to be inserted.
void MovieCollection::insert(MovieContainer* root, Movie item) {
    if (item.getTitle().compare(root->getItem().getTitle()) < 0) {
        if (root->getLChild() == NULL) {
            root->setLChild(new MovieContainer(item));
            numMovies++;
        } else {
            insert(root->getLChild(), item);
        }
    } else if (item.getTitle().compare(root->getItem().getTitle()) > 0) {
        if (root->getRChild() == NULL) {
            root->setRChild(new MovieContainer(item));
            numMovies++;
        } else {
            insert(root->getRChild(), item);
        }
    }
}

/// \brief Recursive function that erases the specified Movie object from the collection.
/// \param title std::string - Movie's title.
void MovieCollection::erase(const std::string title) {
    MovieContainer* current = root;
    MovieContainer* parent = NULL;
    while (current != NULL && title != current->getItem().getTitle()) {
        parent = current;
        if (title.compare(current->getItem().getTitle()) < 0) {
            current = current->getLChild();
        } else {
            current = current->getRChild();
        }
    }

    if (current != NULL) {
        if (current->getLChild() != NULL && current->getRChild() != NULL) {
            if (current->getLChild()->getRChild() == NULL) {
                MovieContainer* temp = current->getLChild();
                current->setItem(current->getLChild()->getItem());
                current->setLChild(current->getLChild()->getLChild());
                delete temp;
                numMovies--;
            } else {
                MovieContainer* p = current->getLChild()->getRChild();
                MovieContainer* pp = current->getLChild();

                while (p->getRChild() != NULL) {
                    pp = p;
                    p = p->getRChild();
                }

                Movie item = p->getItem();
                current->setItem(item);
                MovieContainer* temp = p->getLChild();
                pp->setRChild(temp);
                delete p;
                numMovies--;
            }
        } else {
            MovieContainer* child;
            if (current->getLChild() != 0) {
                child = current->getLChild();
            } else {
                child = current->getRChild();
            }

            if (current == root) {
                root = child;
            } else if(current == parent->getLChild()) {
                parent->setLChild(child);
            } else {
                parent->setRChild(child);
            }
            delete current;
            numMovies--;
        }
    }
}

/// \brief Searches for the specified Movie object in the collection.
/// \param title std::string - Movie's title.
/// \return bool - TRUE if the specified movie in found.
/// \return bool - FALSE if the specified movie is not found.
bool MovieCollection::search(std::string title) const {
    return search(root, title);
}

/// \brief Recursive function that searches for the specified Movie object in the collection.
/// \param title std::string - Movie's title.
/// \return bool - TRUE if the specified movie in found.
/// \return bool - FALSE if the specified movie is not found.
bool MovieCollection::search(MovieContainer* root, std::string title) const {
    if (root != NULL) {
        if (title.compare(root->getItem().getTitle()) == 0) {
            return true;
        } else if (title.compare(root->getItem().getTitle()) < 0) {
            return search(root->getLChild(), title);
        } else {
            return search(root->getRChild(), title);
        }
    } else {
        return false;
    }
}

/// \brief Traverses and print each movie's title and a number of available DVDs in pre-order.
void MovieCollection::preOrderTraversal() {
    preOrderTraversal(root);
}

/// \brief Recursive function that traverses and print each movie's title and a number of available DVDs in pre-order.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
void MovieCollection::preOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
        preOrderTraversal(root->getLChild());
        preOrderTraversal(root->getRChild());
    }
}

/// \brief Traverses and print each movie's title and a number of available DVDs in in-order.
void MovieCollection::inOrderTraversal() {
    inOrderTraversal(root);
}

/// \brief Traverses and print each movie's title and a number of available DVDs in in-order.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
void MovieCollection::inOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        preOrderTraversal(root->getLChild());
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
        preOrderTraversal(root->getRChild());
    }
}

/// \brief Traverses and print each movie's title and a number of available DVDs in post-order.
void MovieCollection::postOrderTraversal() {
    postOrderTraversal(root);
}

/// \brief Traverses and print each movie's title and a number of available DVDs in post-order.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
void MovieCollection::postOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        preOrderTraversal(root->getLChild());
        preOrderTraversal(root->getRChild());
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
    }
}

/// \brief Removes all the movies from the collection.
void MovieCollection::clear() {
    clear(root);
    root = NULL;
    numMovies = 0;
}

/// \brief Recursive function that removes all the movies from the collection.
void MovieCollection::clear(const MovieContainer* root) {
    if (root != NULL) {
        clear(root->getLChild());
        clear(root->getRChild());
        delete root;
    }
}

/// \brief Gets a pointer to the the address of the specified Movie object.
/// \param title std::string - Movie's title.
/// \return Movie* - Pointer to the address of the specified Movie object.
Movie* MovieCollection::getItemAddress(const std::string title) {
    return getItemAddress(root, title);
}

/// \brief Recursive function that gets a pointer to the the address of the specified Movie object.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
/// \param title std::string - Movie's title.
/// \return Movie* - Pointer to the address of the specified Movie object.
Movie* MovieCollection::getItemAddress(MovieContainer* root, const std::string title) {
    if (root != NULL) {
        if (title.compare(root->getItem().getTitle()) == 0) {
            return root->getItemAddress();
        } else if (title.compare(root->getItem().getTitle()) < 0) {
            return getItemAddress(root->getLChild(), title);
        } else {
            return getItemAddress(root->getRChild(), title);
        }
    } else {
        return NULL;
    }
}

/// \brief Stores all the movies in a vector.
/// \param movies std::vector<Movie>& - Vector of type Movie.
void MovieCollection::allMovies(std::vector<Movie>& movies) const {
    allMovies(root, movies);
}

/// \brief Recursive function that stores all the movies in a vector.
/// \param root MovieContainer* - Pointer to the root of the collection (tree).
/// \param movies std::vector<Movie>& - Vector of type Movie.
void MovieCollection::allMovies(MovieContainer* root, std::vector<Movie>& movies) const {
    if (root == NULL) {
        return;
    }
    if (root->getLChild() != NULL) {
        allMovies(root->getLChild(), movies);
    }
    movies.push_back(root->getItem());
    if (root->getRChild() != NULL) {
        allMovies(root->getRChild(), movies);
    }
}

/// \brief Helper method to compares two strings regardless the case.
/// \param str1 std::string - Compared string.
/// \param str2 std::string - Comparing string.
/// \return bool - TRUE if the string comparison result is equal.
/// \return bool - FALSE if the string comparison result is not equal.
std::string MovieCollection::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

