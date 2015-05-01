/// \file StaffOperations.cpp
/// \brief Implementation for Sub-menu for the staff operations.
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

#include "StaffOperations.h"

using namespace std;

const std::string genres[NUMBER_OF_GENRES] = {"drama", "adventure", "family", "action", "sci-fi",
                                              "comedy", "animated", "thriller", "other"};
const std::string classifications[NUMBER_OF_CLASSIFICATIONS] = {"G", "PG", "M15+", "MA15+"};

/// \brief Initialises this StaffOperation object.
StaffOperations::StaffOperations() {
    // Empty constructor
}

/// \brief Destroys this StaffOperation object.
StaffOperations::~StaffOperations() {
    // Empty destructor
}

/// \brief Adds a new movie to the movie collection.
/// \param movies MovieCollection& - Reference of the movie collection.
void StaffOperations::addDVDsOfNewMovie(MovieCollection& movies) {
    std::string title;
    std::string starring;
    std::string director;
    std::string genre;
    std::string classification;
    std::string releaseDate;
    int duration;
    int numDVDs;

    cout << "\n\n\t\tNEW MOVIE INFORMATION" << endl << endl;
    cout << "\t\tTitle:          ";
    getline(cin, title);
    title = lowerCase(title);

    bool duplicate = movies.search(title);
    if (duplicate) {
        cout << "\n\t\t\"" << formatString(title) << "\" has already existed in the collection" << endl;
        cout << "\n\t\tPlease add a new movie" << endl << endl;
        return;
    }

    cout << "\t\tStarring:       ";
    getline(cin, starring);
    cout << "\t\tDirector:       ";
    getline(cin, director);

    bool correctGenre = false;
    do {
        displayGenres();
        cout << "\t\tGenre:          ";
        getline(cin, genre);
        correctGenre = isGenre(genre);
        if (!correctGenre) {
            displayErrorMessage();
        }
    } while (!correctGenre);

    bool correctClassification = false;
    do {
        displayClassifications();
        cout << "\t\tClassification: ";
        getline(cin, classification);
        correctClassification = isClassification(classification);
        if (!correctClassification) {
            displayErrorMessage();
        }
    } while (!correctClassification);

    cout << "\t\tRelease Date:   ";
    getline(cin, releaseDate);

    do {
        cout << "\t\tDuration:       ";
        cin >> duration;
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tPlease enter only integer" << endl << endl;
            cout << "\t\tDuration:       ";
            cin >> duration;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(duration <= 0) {
            displayErrorMessage();
            cout << "\t\tDuration of the movie must be greater than 0" << endl << endl;
        }
    } while (duration <= 0);

    do {
        cout << "\t\tNumber of DVDs: ";
        cin >> numDVDs;
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tPlease enter only integer" << endl << endl;
            cout << "\t\tNumber of DVDs: ";
            cin >> numDVDs;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(numDVDs <= 0) {
            displayErrorMessage();
            cout << "\t\tA number of DVDs must be greater than 0" << endl << endl;
        }
    } while (numDVDs <= 0);

    if (!duplicate) {
        Movie newMovie(title, starring, director, genre, classification,
        releaseDate, duration, numDVDs);
        movies.insert(newMovie);
        cout << "\n\t\t\"" << formatString(title) << "\" has been added to the collection" << endl << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/// \brief Adds DVDs of an existing movie in the movie collection.
/// \param movies MovieCollection& - Reference of the movie collection.
void StaffOperations::addDVDsOfExistingMovie(MovieCollection& movies) {
    std::string title;
    int numDVDs;
    cout << "\n\n\t\tADD DVDS" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

    bool exist = movies.search(title);
    if (!exist) {
        cout << "\n\t\tMovie not found" << endl << endl;
        return;
    }

    cout << "\t\tEnter number of DVDs: ";
    cin >> numDVDs;
    cout << endl;

    if (exist) {
        Movie* movieAddress = movies.getItemAddress(title);
        movieAddress->addDVDs(numDVDs);
        cout << "\n\t\t" << numDVDs << " DVDs have been added to \"" << formatString(title) << "\"" << endl << endl;
        cout << "\t\t" << setw(15) << left << "Title" << setw(20) << right << "Number of DVDs" << endl << endl;
        cout << "\t\t" << setw(15) << left << formatString(title) << setw(20) << right << movieAddress->getNumDVDs() << endl << endl;
        movieAddress = NULL;
        delete movieAddress;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/// \brief remove DVDs of an movie from the movie collection while the movie is not being rented.
/// \param movies MovieCollection& - Reference of the movie collection.
void StaffOperations::removeDVDs(MovieCollection& movies) {
    std::string title;
    int numDVDs;

    cout << "\n\n\t\tREMOVE DVDS" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

    bool exist = movies.search(title);
    if (!exist) {
        cout << "\n\t\tMovie not found" << endl << endl;
        return;
    }

    cout << "\t\tEnter number of DVDs: ";
    cin >> numDVDs;
    cout << endl;

    if (exist) {
        Movie* movieAddress = movies.getItemAddress(title);
        if (movieAddress->getRecord().empty() && movieAddress->getNumDVDs() == 0) {
            cout << "\n\t\tNumber of DVD is 0" << endl;
        } else if (movieAddress->getRecord().empty() && movieAddress->getNumDVDs() != 0) {
            if (movieAddress->getNumDVDs() - numDVDs < 0) {
                cout << "\n\t\tThe number entered is greater the number of existing DVDs" << endl << endl;
            } else {
                movieAddress->removeDVDs(numDVDs);
                cout << "\n\t\t" << numDVDs << " DVDs have been removed from \"" << formatString(title) << "\"" << endl << endl;
                cout << "\t\t" << setw(15) << left << "Title" << setw(20) << right << "Number of DVDs" << endl << endl;
                cout << "\t\t" << setw(15) << left << formatString(title) << setw(20) << right << movieAddress->getNumDVDs() << endl << endl;
            }
        } else {
        cout << "\n\t\tERROR: One or more DVDs are being rented." << endl << endl;
        }
        movieAddress = NULL;
        delete movieAddress;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/// \brief Removes a movie from the movie collection while the movie is not being rented.
/// \param movies MovieCollection& - Reference of the movie collection.
void StaffOperations::removeMovie(MovieCollection& movies) {
    std::string title;
    cout << "\n\n\t\tREMOVE A MOVIE" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

    bool exist = movies.search(title);
    if (!exist) {
        cout << "\n\t\tMovie not found" << endl << endl;
        return;
    } else {
        Movie* movieAddress = movies.getItemAddress(title);
        if (movieAddress->getRecord().empty()) {
            movies.erase(title);
            cout << "\n\t\t\"" << formatString(title) << "\" has been remove from the collection" << endl << endl;
        } else {
            cout << "\n\t\tERROR: One or more DVDs are being rented." << endl << endl;
        }
        movieAddress = NULL;
        delete movieAddress;
    }
}

/// \brief Adds a new customer to the customer collection.
/// \param customers CustomerCollection& - Reference of the customer collection.
void StaffOperations::registerCustomer(CustomerCollection& customers) {
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string password;

    cout << "\n\n\t\tNEW CUSTOMER DETAILS" << endl << endl;
    cout << "\t\tFull Name:     ";
    getline(cin, name);
    bool duplicate = customers.findCustomerIndexByName(name) >= 0;
    if (duplicate) {
        cout << "\n\t\t\"" << formatString(name) << "\" has already existed in the collection" << endl;
        cout << "\n\t\tPlease add a new customer" << endl << endl;
        return;
    }
    cout << "\t\tAddress:       ";
    getline(cin, address);
    bool allDigitsPhoneNumber;
    do {
        allDigitsPhoneNumber = true;
        cout << "\t\tPhone Number:  ";
        getline(cin, phoneNumber);
        for (int i = 0; i < phoneNumber.length(); i++) {
            if (!isdigit(phoneNumber[i])) {
                allDigitsPhoneNumber = false;
            }
        }
        if (phoneNumber.length() != 10 || allDigitsPhoneNumber == false)  {
            displayErrorMessage();
            cout << "\t\tPlease enter [10 Digits] phone number" << endl;
        }
    } while (phoneNumber.length() != 10 || allDigitsPhoneNumber == false);

    Customer newCustomer(name, address, phoneNumber);

    cout << "\n\t\tCustomer's username: " << newCustomer.getUsername() << endl;
    bool allDigits;
    do {
        allDigits = true;
        cout << "\t\tEnter Password: ";
        getline(cin, password);
        for (int i = 0; i < password.length(); i++) {
            if (!isdigit(password[i])) {
                allDigits = false;
            }
        }
        if (password.length() != 4 || allDigits == false)  {
            displayErrorMessage();
            cout << "\t\tPlease enter 4-digit password" << endl << endl;
        }
    } while (password.length() != 4 || allDigits == false);

    newCustomer.setPassword(password);
    customers.addCustomer(newCustomer);
    cout << "\n\t\t\"" << formatString(name) << "\" has been registered." << endl << endl;
}

/// \brief Removes an existing customer from the customer collection while the customer is not renting any movie.
/// \param customers CustomerCollection& - Reference of the customer collection.
void StaffOperations::removeCustomer(CustomerCollection& customers) {
    std::string name;
    cout << "\n\n\t\tREMOVE A CUSTOMER" << endl << endl;
    cout << "\t\tEnter customer's name: ";
    getline(cin, name);

    bool exist = customers.findCustomerIndexByName(name) >= 0;
    if (!exist) {
        cout << "\n\t\tCustomer not found" << endl << endl;
        return;
    }

    int index = customers.findCustomerIndexByName(name);
    int notFound = -1;

    if (index == notFound) {
        cout << "\n\t\tCustomer not found." << endl;
    } else {
        if (customers.customerAt(index).getRecord().size() > 0) {
            cout << "\n\t\tERROR: The customer is currently renting "
                 << customers.customerAt(index).getRecord().size() << " DVDs" << endl << endl;
        } else {
            customers.deleteCustomer(name);
            cout << "\n\t\t\"" << formatString(name) << "\" has been deleted" << endl << endl;
        }
    }
}

/// \brief Find a customer's phone number given the customer's name.
/// \param customers CustomerCollection& - Reference of the customer collection.
void StaffOperations::findCustomerPhoneNumber(CustomerCollection& customers) {
    std::string name;
    cout << "\n\n\t\tFIND A CUSTOMER'S PHONE NUMBER" << endl << endl;
    cout << "\t\tEnter customer's name: ";
    getline(cin, name);

    bool exist = customers.findCustomerIndexByName(name) >= 0;
    if (!exist) {
        cout << "\n\t\tCustomer not found" << endl << endl;
        return;
    }

    int index = customers.findCustomerIndexByName(name);
    int notFound = -1;

    if (index == notFound) {
        cout << "\n\t\tCustomer not found." << endl;
    } else {
        cout << "\n\t\tCustomer's phone number: ";
        cout << customers.customerAt(index).getPhoneNumber() << endl << endl;
    }
}

/// \brief Finds a movie's rental record given the movie's title.
/// \param movies MovieCollection& - Reference of the movie collection.
void StaffOperations::findRentalRecord(MovieCollection& movies) {
    std::string title;
    cout << "\n\n\t\tDISPLAY A MOVIE'S RECORD" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

    bool exist = movies.search(title);
    if (!exist) {
        cout << "\n\t\tMovie not found" << endl << endl;
        return;
    } else {
        Movie* movieAddress = movies.getItemAddress(title);
        std::vector<std::string> record = movieAddress->getRecord();
        if (record.size() == 0) {
            cout << "\n\t\t\"" << formatString(title) << "\" has not been rented" << endl << endl;
        } else {
            for (std::vector<std::string>::size_type i = 0; i != record.size(); i++) {
            cout << "\n\t\t" << i+1 << ") " << formatString(record[i]) << endl;
            }
        }
        cout << endl;
        movieAddress = NULL;
        delete movieAddress;
    }
}

/// \brief Display all the available genres the system can use to categorise a movie.
void StaffOperations::displayGenres() {
    cout << "\n\t\tGenres may be [Drama, Adventure, Family, Action," << endl;
    cout << "\t\tSci-Fi, Comedy, Animated, Thriller or Other]" << endl << endl;
}

/// \brief Display all the available classification the system can use to classify a movie.
void StaffOperations::displayClassifications() {
    cout << "\n\t\tGenres may be General (G), Parental Guidance (PG)," << endl;
    cout << "\t\tMature (M15+) or Mature Accompanied (MA15+)" << endl << endl;
    cout << "\t\tEnter only its abbreviation i.e. [G, PG, M15+ or MA15+]" << endl << endl;
}

/// \brief Checks if the input genre is valid.
/// \param genre std::string - Input genre.
/// \return bool - TRUE if the input genre is valid.
/// \return bool - FALSE if the input genre is not valid.
bool StaffOperations::isGenre(std::string genre) {
    for (int i = 0; i < NUMBER_OF_GENRES; i++) {
        if (lowerCase(genre) == genres[i]) {
            return true;
        }
    }
    return false;
}

/// \brief Checks if the input classification is valid.
/// \param classification std::string - Input classification.
/// \return bool - TRUE if the input classification is valid.
/// \return bool - FALSE if the input classification is not valid.
bool StaffOperations::isClassification(std::string classification) {
    for (int i = 0; i < NUMBER_OF_CLASSIFICATIONS; i++) {
        if (upperCase(classification) == classifications[i]) {
            return true;
        }
    }
    return false;
}

/// \brief Helper method to convert a string to uppercase.
/// \param str std::string - A string.
/// \return std::string - String with all uppercase characters.
std::string StaffOperations::upperCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

/// \brief Helper method to convert a string to lowercase.
/// \param str std::string - A string.
/// \return std::string - String with all lowercase characters.
std::string StaffOperations::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/// \brief Helper method to format a string for printing.
/// \param str std::string - A string.
/// \return std::string - formatted string.
std::string StaffOperations::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

/// \brief Displays an error message for any invalid input.
void StaffOperations::displayErrorMessage() {
    cout << "\n\t\tERROR: Invalid Input" << endl;
}
