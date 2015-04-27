#include "MovieCollection.h"

using namespace std;

MovieCollection::MovieCollection() {
    root = NULL;
    numMovies = 0;
}

MovieCollection::~MovieCollection() {

}

bool MovieCollection::empty() const {
    return root == NULL;
}

int MovieCollection::size() const {
    return numMovies;
}

void MovieCollection::insert(const Movie item) {
    if (root == NULL) {
        root = new MovieContainer(item);
        numMovies = 1;
    } else {
        insert(root, item);
    }
}

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

bool MovieCollection::search(std::string title) const {
    return search(root, title);
}

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

void MovieCollection::preOrderTraversal() {
    preOrderTraversal(root);
}

void MovieCollection::preOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
        preOrderTraversal(root->getLChild());
        preOrderTraversal(root->getRChild());
    }
}

void MovieCollection::inOrderTraversal() {
    inOrderTraversal(root);
}

void MovieCollection::inOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        preOrderTraversal(root->getLChild());
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
        preOrderTraversal(root->getRChild());
    }
}

void MovieCollection::postOrderTraversal() {
    postOrderTraversal(root);
}

void MovieCollection::postOrderTraversal(MovieContainer* root) {
    if (root != NULL) {
        preOrderTraversal(root->getLChild());
        preOrderTraversal(root->getRChild());
        cout << "\t\t" << setw(15) << left << formatString(root->getItem().getTitle()) << setw(20) << right
             << root->getItem().getNumDVDs() - root->getItem().getRecord().size() << endl;
    }
}

void MovieCollection::clear() {
    clear(root);
    root = NULL;
    numMovies = 0;
}

void MovieCollection::clear(const MovieContainer* root) {
    if (root != NULL) {
        clear(root->getLChild());
        clear(root->getRChild());
        delete root;
    }
}

Movie* MovieCollection::getItemAddress(const std::string title) {
    return getItemAddress(root, title);
}

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

std::vector<Movie> MovieCollection::findTopTenMovies() const {
    return findTopTenMovies(root);
}

std::vector<Movie> MovieCollection::findTopTenMovies(MovieContainer* root) const {
    std::vector<Movie> movies;
    std::vector<Movie> topTenMovies;
    allMovies(root, movies);
    if (movies.size() > 1) {
        for (std::vector<std::string>::size_type i = 0; i < movies.size(); i++) {
            for (std::vector<std::string>::size_type j = 1; j < movies.size(); j++) {
                if (movies[j].getNumRentals() > movies[j-1].getNumRentals()) {
                    Movie temp = movies[j];
                    movies[j] = movies[j-1];
                    movies[j-1] = temp;
                }
            }
        }
    }
    if (movies.size() < 10) {
        for (std::vector<std::string>::size_type i = 0; i < movies.size(); i++) {
            topTenMovies.push_back(movies[i]);
        }
    } else {
        for (std::vector<std::string>::size_type i = 0; i < 10; i++) {
            topTenMovies.push_back(movies[i]);
        }
    }
    return topTenMovies;
}

std::string MovieCollection::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

