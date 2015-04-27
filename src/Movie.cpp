#include "Movie.h"

using namespace std;

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

Movie::~Movie() {

}

std::string Movie::getTitle() const {
    return title;
}

std::string Movie::getStarring() const {
    return starring;
}

std::string Movie::getDirector() const {
    return director;
}

std::string Movie::getGenre() const {
    return genre;
}

std::string Movie::getClassification() const {
    return classification;
}

std::string Movie::getReleaseDate() const {
    return releaseDate;
}

int Movie::getDuration() const {
    return duration;
}

int Movie::getNumRentals() const {
    return numRentals;
}

int Movie::getNumDVDs() const {
    return numDVDs;
}

std::vector<std::string> Movie::getRecord() const {
    return record;
}

void Movie::setTitle(const std::string title) {
    this->title = lowerCase(title);
}

void Movie::setStarring(const std::string starring) {
    this->starring = lowerCase(starring);
}

void Movie::setDirector(const std::string director) {
    this->director = lowerCase(director);
}

void Movie::setGenre(const std::string genre) {
    this->genre = lowerCase(genre);
}

void Movie::setClassification(const std::string classification) {
    this->classification = classification;
}

void Movie::setReleaseDate(const std::string releaseDate) {
    this->releaseDate = releaseDate;
}

void Movie::setDuration(const int duration) {
    this->duration = duration;
}

void Movie::setNumDVDs(const int numDVDs) {
    this->numDVDs = numDVDs;
}

void Movie::increaseNumRentals() {
    numRentals++;
}

void Movie::addRecord(const std::string name) {
    record.push_back(lowerCase(name));
}

int Movie::findRecord(const std::string name) {
    for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
        if (compareCaseInsensitive(record[i], name)) {
            return i;
        }
    }
    return -1;
}

void Movie::removeRecord(const std::string name) {
    int index = findRecord(name);
    if (index != -1) {
        record.erase(record.begin() + index);
    }
}

void Movie::addDVDs(const int numDVDs) {
    this->numDVDs = this->numDVDs + numDVDs;
}

void Movie::removeDVDs(const int numDVDs) {
    this->numDVDs = this->numDVDs - numDVDs;
}

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

std::string Movie::upperCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string Movie::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string Movie::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

bool Movie::compareCaseInsensitive(std::string str1, std::string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}
