/// \file MovieContainer.cpp
/// \brief Implementation of MovieContainer ADT

#include "MovieContainer.h"

/// \brief Initialises this MovieContainer.
/// \param item Movie& - Movie Object.
MovieContainer::MovieContainer(Movie item) {
    this->item = item;
    this->lChild = NULL;
    this->rChild = NULL;
}

/// \brief Destroys this MovieContainer.
MovieContainer::~MovieContainer() {

}

/// \brief Gets the item field of this MovieContainer.
/// \return Movie - Movie item contained in this MovieContainer.
Movie MovieContainer::getItem() const {
    return item;
}

/// \brief Gets the item's memory address of this MovieContainer.
/// \return Movie* - Pointer to Memory address of the item contained in this MovieContainer.
Movie* MovieContainer::getItemAddress() {
    return &item;
}

/// \brief Gets the pointer the left child of this MovieContainer.
/// \return Movie* - Pointer to the left child of this MovieContainer.
MovieContainer* MovieContainer::getLChild() const {
    return lChild;
}

/// \brief Gets the right child of this MovieContainer.
/// \return Movie* - Pointer to the right child of this MovieContainer.
MovieContainer* MovieContainer::getRChild() const {
    return rChild;
}

/// \brief Sets the item field with the specified Movie object.
/// \param item Movie& - Movie Object.
void MovieContainer::setItem(const Movie& item) {
    this->item = item;
}

/// \brief Sets the pointer to the left child with the specified MovieContainer pointer.
/// \param child MovieContainer* - Left child pointer.
void MovieContainer::setLChild(MovieContainer* child) {
    lChild = child;
}

/// \brief Sets the pointer to the right child with the specified MovieContainer pointer.
/// \param child MovieContainer* - Right child pointer.
void MovieContainer::setRChild(MovieContainer* child) {
    rChild = child;
}
