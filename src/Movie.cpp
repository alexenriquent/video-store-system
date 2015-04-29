/// \file Movie.cpp
/// \brief Implementation for Movie ADT to model a movie.

#include "Movie.h"

using namespace std;

/// \brief Initialises all the data members of this Movie object with default values.
Movie::Movie() {
    title = "";
    starring = "";
    director = "";
    genre = "";
    classification = "";
    releaseDate = "";
    duration = 0;
    numRentals = 0;
    numDVDs = 0;
}

/// \brief Initialises all the data members of this Movie object with the specified values.
/// \param title std::string - Title of the movie.
/// \param starring std::string - People who starred in the movie.
/// \param director std::string - Director of the movie.
/// \param genre std::string - Genre of the movie.
/// \param classification std::string - Classification of the movie.
/// \param releaseDate std::string - Releasing date of the movie.
/// \param duration int - Duration of the movie.
/// \param numDVDs int - Number of DVDs.
Movie::Movie(std::string title, std::string starring,
             std::string director, std::string genre,
             std::string classification, std::string releaseDate,
             int duration, int numDVDs) {
    this->title = lowerCase(title);
    this->starring = lowerCase(starring);
    this->director = lowerCase(director);
    this->genre = lowerCase(genre);
    this->classification = upperCase(classification);
    this->releaseDate = releaseDate;
    this->duration = duration;
    this->numDVDs = numDVDs;
    numRentals = 0;
}

/// \brief Destroys this Movie object.
Movie::~Movie() {

}

/// \brief Gets the title field.
/// \return std::string - Title of the movie.
std::string Movie::getTitle() const {
    return title;
}

/// \brief Gets the starring field.
/// \return std::string - People who stared in the movie.
std::string Movie::getStarring() const {
    return starring;
}

/// \brief Gets the director field.
/// \return std::string - Director of the movie.
std::string Movie::getDirector() const {
    return director;
}

/// \brief Gets the genre field.
/// \return std::string - Genre of the movie.
std::string Movie::getGenre() const {
    return genre;
}

/// \brief Gets the classification field.
/// \return std::string - Classification of the movie.
std::string Movie::getClassification() const {
    return classification;
}

/// \brief Gets the releaseDate field.
/// \return std::string - Releasing date of the movie.
std::string Movie::getReleaseDate() const {
    return releaseDate;
}

/// \brief Gets the duration field.
/// \return int - Duration of the movie.
int Movie::getDuration() const {
    return duration;
}

/// \brief Gets the numRentals field.
/// \return int - Number of rentals of the movie.
int Movie::getNumRentals() const {
    return numRentals;
}

/// \brief Gets the numDVDs field.
/// \return int - Number of DVDs of the movie.
int Movie::getNumDVDs() const {
    return numDVDs;
}

/// \brief Gets the record field.
/// \return std::vector<std::string> - Rental record of the movie.
std::vector<std::string> Movie::getRecord() const {
    return record;
}

/// \brief Sets the title field with the specified value.
/// \param title std::string - Title of the movie.
void Movie::setTitle(const std::string title) {
    this->title = lowerCase(title);
}

/// \brief Sets the starring field with the specified value.
/// \param starring std::string - People who starred in the movie.
void Movie::setStarring(const std::string starring) {
    this->starring = lowerCase(starring);
}

/// \brief Sets the director field with the specified value.
/// \param director std::string - Director of the movie.
void Movie::setDirector(const std::string director) {
    this->director = lowerCase(director);
}

/// \brief Sets the genre field with the specified value.
/// \param genre std::string - Genre of the movie.
void Movie::setGenre(const std::string genre) {
    this->genre = lowerCase(genre);
}

/// \brief Sets the classification field with the specified value.
/// \param classification std::string - Classification of the movie.
void Movie::setClassification(const std::string classification) {
    this->classification = classification;
}

/// \brief Sets the releaseDate field with the specified value.
/// \param releaseDate std::string - releasing of the movie.
void Movie::setReleaseDate(const std::string releaseDate) {
    this->releaseDate = releaseDate;
}

/// \brief Sets the duration field with the specified value.
/// \param duration int - Duration of the movie.
void Movie::setDuration(const int duration) {
    this->duration = duration;
}

/// \brief Sets the numDVDs field with the specified value.
/// \param numDVDs int - Number of DVDs.
void Movie::setNumDVDs(const int numDVDs) {
    this->numDVDs = numDVDs;
}

/// \brief Increases a number of rentals by 1 when the movie is rented.
void Movie::increaseNumRentals() {
    numRentals++;
}

/// \brief Adds the specified customer's name into the rental record.
/// \param name std::string - Customer's name.
void Movie::addRecord(const std::string name) {
    record.push_back(lowerCase(name));
}

/// \brief Finds an index of the specified customer's name in the rental record.
/// \param name std::string - Customer's name.
/// \return int - Index of the specified customer.
/// \return -1 - Index not found.
int Movie::findRecord(const std::string name) {
    for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
        if (compareCaseInsensitive(record[i], name)) {
            return i;
        }
    }
    return -1;
}

/// \brief Removes the specified customer's name from the rental record.
/// \param name std::string - Customer's name.
void Movie::removeRecord(const std::string name) {
    int index = findRecord(name);
    if (index != -1) {
        record.erase(record.begin() + index);
    }
}

/// \brief Adds the specified number of DVDs.
/// \param numDVDs int - Number of DVDs.
void Movie::addDVDs(const int numDVDs) {
    this->numDVDs = this->numDVDs + numDVDs;
}

/// \brief Removes the specified number of DVDs.
/// \param numDVDs int - Number of DVDs.
void Movie::removeDVDs(const int numDVDs) {
    this->numDVDs = this->numDVDs - numDVDs;
}

/// \brief Displays information of the movie.
void Movie::displayInfo() {
    cout << "\n\n\t\tMOVIE INFORMATION" << endl << endl;
    cout << "\t\tTitle:          " << formatString(title) << endl;
    cout << "\t\tStarring:       " << formatString(starring) << endl;
    cout << "\t\tDirector:       " << formatString(director) << endl;
    cout << "\t\tGenre:          " << formatString(genre) << endl;
    cout << "\t\tClassification: " << classification << endl;
    cout << "\t\tRelease Date:   " << releaseDate << endl;
    cout << "\t\tDuration:       " << duration << " minutes" << endl << endl;
}

/// \brief Helper method to convert a string to uppercase.
/// \param str std::string - A string.
/// \return std::string - String with all uppercase characters.
std::string Movie::upperCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

/// \brief Helper method to convert a string to lowercase.
/// \param str std::string - A string.
/// \return std::string - String with all lowercase characters.
std::string Movie::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/// \brief Helper method to format a string for printing.
/// \param str std::string - A string.
/// \return std::string - formatted string.
std::string Movie::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

/// \brief Helper method to compares two strings regardless the case.
/// \param str1 std::string - Compared string.
/// \param str2 std::string - Comparing string.
/// \return bool - TRUE if the string comparison result is equal.
/// \return bool - FALSE if the string comparison result is not equal.
bool Movie::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
