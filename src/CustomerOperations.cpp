/// \file CustomerOperations.cpp
/// \brief Implementation for Sub-menu for the customer operations.
/// \author Thanat Chokwijitkul n9234900
/// \author Month Yean Koh n9070095
/// \date April, 2015

#include "CustomerOperations.h"

using namespace std;

/// \brief Initialises this CustomerOperation object.
CustomerOperations::CustomerOperations() {
    // Empty constructor
}

/// \brief Destroys this CustomerOperation object.
CustomerOperations::~CustomerOperations() {
    // Empty destructor
}

/// \brief Displays all the movies available in the movie collection.
/// \param movies MovieCollection& - Reference of the movie collection.
void CustomerOperations::browseAllMovies(MovieCollection& movies) {
    std::vector<Movie> movieList;
    movies.allMovies(movieList);
    sortMovieList(movieList);

    cout << "\n\t\tALL MOVIES" << endl << endl;
    cout << "\t\t" << setw(15) << left << "Title" << setw(20)
         << right << "Number of DVDs" << endl << endl;

    for (std::vector<std::string>::size_type i = 0; i < movieList.size(); i++) {
        cout << "\t\t" << setw(15) << left
             << formatString(movieList[i].getTitle()) << setw(20) << right
             << movieList[i].getNumDVDs() - movieList[i].getRecord().size() << endl;
    }
}

/// \brief Displays movie information given a movie's title.
/// \param movies MovieCollection& - Reference of the movie collection.
void CustomerOperations::displayMovieInfo(MovieCollection& movies) {
    cout << "\n\n\t\tMOVIE INFORMATION" << endl << endl;
    std::string title = promptTitle();
    bool exist = movies.search(title);
    if (!exist) {
        displayMovieNotFoundMessage();
        return;
    } else {
        Movie* movieAddress = movies.getItemAddress(title);
        movieAddress->displayInfo();
        movieAddress = NULL;
        delete movieAddress;
    }
}

/// \brief Rents a DVD specified by a movie's title.
/// \param movies MovieCollection& - Reference of the movie collection.
/// \param customer Customer* - Pointer to a customer.
void CustomerOperations::rentDVD(MovieCollection& movies, Customer* customer) {
    cout << "\n\n\t\tRENT DVD" << endl << endl;
    std::string title = promptTitle();
    bool exist = movies.search(title);
    if (!exist) {
        displayMovieNotFoundMessage();
        return;
    } else {
        bool duplicate = customer->findRecord(title) >= 0;
        if (duplicate) {
            cout << "\n\t\tERROR: \"" << formatString(title)
                 << "\" has already been rented by the customer" << endl << endl;
        } else if (!duplicate && customer->getRecord().size() < 10) {
            Movie* movieAddress = movies.getItemAddress(title);
            int confirm = confirmRenting(movieAddress);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (confirm == 1) {
                movieAddress->addRecord(customer->getName());
                movieAddress->increaseNumRentals();
                customer->addRecord(title);
                cout << "\n\t\t\"" << formatString(title)
                     << "\" has been rented" << endl << endl;
            } else if (confirm == 2) {
                cout << "\n\t\tRequest has been canceled" << endl << endl;
            }
            movieAddress = NULL;
            delete movieAddress;
        } else {
            cout << "\n\t\tERROR: Cannot rent more than 10 movies" << endl << endl;
        }
    }
}

/// \brief Returns a DVD specified by a movie's title.
/// \param movies MovieCollection& - Reference of the movie collection.
/// \param customer Customer* - Pointer to a customer.
void CustomerOperations::returnDVD(MovieCollection& movies, Customer* customer) {
    cout << "\n\n\t\tRETURN DVD" << endl << endl;
    std::string title = promptTitle();
    bool exist = customer->findRecord(title) >= 0;
    if (!exist) {
        displayMovieNotFoundMessage();
        return;
    } else {
        Movie* movieAddress = movies.getItemAddress(title);
        int confirm = confirmReturning(movieAddress);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (confirm == 1) {
            movieAddress->removeRecord(customer->getName());
            customer->removeRecord(title);
            cout << "\n\t\t\"" << formatString(title)
                 << "\" has been returned" << endl << endl;
        } else if (confirm == 2) {
            cout << "\n\t\tRequest has been canceled" << endl << endl;
        }
        movieAddress = NULL;
        delete movieAddress;
    }
}

/// \brief Displays a list of currently rented movies.
/// \param customer Customer* - Pointer to a customer.
void CustomerOperations::listCurrentlyRentedMovies(Customer* customer) {
    cout << "\n\n\t\tCURRENTLY RENTED MOVIES" << endl;
    customer->displayRecord();
}

/// \brief Displays a list of top ten movies identified by a number of rentals of each movie.
/// \param movies MovieCollection& - Reference of the movie collection.
void CustomerOperations::displayTopTenMovies(MovieCollection& movies) {
    std::vector<Movie> movieList;
    std::vector<Movie> topTenMovies;
    movies.allMovies(movieList);
    sortMovieListByNumRentals(movieList);
    addTopTenMovies(movieList, topTenMovies);

    cout << "\n\n\t\tTOP 10 RENTED MOVIES" << endl << endl;
    cout << "\t\t" << setw(15) << left << "Title" << setw(20)
         << right << "Number of Rentals" << endl << endl;

    for (std::vector<std::string>::size_type i = 0; i < topTenMovies.size(); i++) {
        cout << "\t\t" << setw(15) << left
             << formatString(topTenMovies[i].getTitle()) << setw(20) << right
             << topTenMovies[i].getNumRentals() << endl;
    }
    cout << endl;
}

/// \brief Prompts the user a movie's title.
/// \return string - Title prompted by user.
std::string CustomerOperations::promptTitle() {
    std::string title;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);
    return title;
}

/// \brief Sorts a list of all movies alphabetically.
/// \param movieList std::vector<Movie>& - Reference of a list of movies.
void CustomerOperations::sortMovieList(std::vector<Movie>& movieList) {
    if (movieList.size() > 1) {
        for (std::vector<std::string>::size_type i = 0; i < movieList.size(); i++) {
            for (std::vector<std::string>::size_type j = 1; j < movieList.size(); j++) {
                if (movieList[j].getTitle().compare(movieList[j-1].getTitle()) < 0) {
                    Movie temp = movieList[j];
                    movieList[j] = movieList[j-1];
                    movieList[j-1] = temp;
                }
            }
        }
    }
}

/// \brief Sorts a list of all movies by a number of rentals.
/// \param movieList std::vector<Movie>& - Reference of a list of movies.
void CustomerOperations::sortMovieListByNumRentals(std::vector<Movie>& movieList) {
    if (movieList.size() > 1) {
        for (std::vector<std::string>::size_type i = 0; i < movieList.size(); i++) {
            for (std::vector<std::string>::size_type j = 1; j < movieList.size(); j++) {
                if (movieList[j].getNumRentals() > movieList[j-1].getNumRentals()) {
                    Movie temp = movieList[j];
                    movieList[j] = movieList[j-1];
                    movieList[j-1] = temp;
                }
            }
        }
    }
}

/// \brief Adds top ten movies to the topTenMovie list.
/// \param movieList std::vector<Movie>& - List of all movies.
/// \param topTenMovie std::vector<Movie>& - List of movies.
void CustomerOperations::addTopTenMovies(std::vector<Movie> movieList, std::vector<Movie>& topTenMovies) {
    if (movieList.size() < 10) {
        for (std::vector<std::string>::size_type i = 0; i < movieList.size(); i++) {
            topTenMovies.push_back(movieList[i]);
        }
    } else {
        for (std::vector<std::string>::size_type i = 0; i < 10; i++) {
            topTenMovies.push_back(movieList[i]);
        }
    }
}

/// \brief Confirms DVD rental information.
/// \param movieAddress Movie* - Memory address of a movie.
/// \return int - Customer's confirmation.
int CustomerOperations::confirmRenting(Movie* movieAddress) {
    int confirm;
    cout << "\n\t\tWould you like to rent the following movie?" << endl;
    movieAddress->displayInfo();
    cout << "\t\t1) Yes" << endl;
    cout << "\t\t2) No" << endl << endl;
    do {
        cout << "\t\tEnter an option: ";
        cin >> confirm;
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tEnter an option: ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);
    return confirm;
}

/// \brief Confirms DVD returning information.
/// \param movieAddress Movie* - Pointer to a memory address of a movie.
/// \return int - Customer's confirmation.
int CustomerOperations::confirmReturning(Movie* movieAddress) {
    int confirm;
    cout << "\n\t\tWould you like to return the following movie?" << endl;
    movieAddress->displayInfo();
    cout << "\t\t1) Yes" << endl;
    cout << "\t\t2) No" << endl << endl;
    do {
        cout << "\t\tEnter an option: ";
        cin >> confirm;
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tEnter an option: ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);
    return confirm;
}

/// \brief Helper method to convert a string to lowercase.
/// \param str std::string - A string.
/// \return std::string - String with all lowercase characters.
std::string CustomerOperations::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/// \brief Helper method to format a string for printing.
/// \param str std::string - A string.
/// \return std::string - formatted string.
std::string CustomerOperations::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

/// \brief Displays an error message for any invalid input.
void CustomerOperations::displayErrorMessage() {
    cout << "\n\t\tERROR: Invalid Input" << endl;
}

/// \brief Displays an error message when the movie collection does not contain the specified movie.
void CustomerOperations::displayMovieNotFoundMessage() {
    cout << "\n\t\tMovie not found" << endl << endl;
}
