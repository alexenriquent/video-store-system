#include "MovieContainer.h"

MovieContainer::MovieContainer(Movie item) {
    this->item = item;
    this->lChild = NULL;
    this->rChild = NULL;
}

MovieContainer::~MovieContainer() {

}

Movie MovieContainer::getItem() const {
    return item;
}

Movie* MovieContainer::getItemAddress() {
    return &item;
}

MovieContainer* MovieContainer::getLChild() const {
    return lChild;
}

MovieContainer* MovieContainer::getRChild() const {
    return rChild;
}

void MovieContainer::setItem(const Movie& item) {
    this->item = item;
}

void MovieContainer::setLChild(MovieContainer* child) {
    lChild = child;
}

void MovieContainer::setRChild(MovieContainer* child) {
    rChild = child;
}
