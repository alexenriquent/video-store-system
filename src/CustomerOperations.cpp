#include "CustomerOperations.h"

using namespace std;

CustomerOperations::CustomerOperations() {

}

CustomerOperations::~CustomerOperations() {

}

void CustomerOperations::browseAllMovies(MovieCollection& movies) {
    cout << "\n\t\tALL MOVIES" << endl << endl;
    cout << "\t\t" << setw(15) << left << "Title" << setw(20) << right << "Number of DVDs" << endl << endl;
    movies.inOrderTraversal();
}

void CustomerOperations::displayMovieInfo(MovieCollection& movies) {
    std::string title;
    cout << "\n\n\t\tMOVIE INFORMATION" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

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

void CustomerOperations::rentDVD(MovieCollection& movies, Customer* customer) {
    std::string title;
    cout << "\n\n\t\tRENT DVD" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);
    title = lowerCase(title);

    bool exist = movies.search(title);
    if (!exist) {
        displayMovieNotFoundMessage();
        return;
    } else {
        bool duplicate = customer->findRecord(title) >= 0;
        if (duplicate) {
            cout << "\n\t\tERROR: \"" << formatString(title) << "\" has already been rented by the customer" << endl << endl;
        } else if (!duplicate && customer->getRecord().size() < 10) {
            Movie* movieAddress = movies.getItemAddress(title);
            int confirm = confirmRenting(movieAddress);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (confirm == 1) {
                movieAddress->addRecord(customer->getName());
                movieAddress->increaseNumRentals();
                customer->addRecord(title);
                cout << "\n\t\t\"" << formatString(title) << "\" has been rented" << endl << endl;
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

void CustomerOperations::returnDVD(MovieCollection& movies, Customer* customer) {
    std::string title;
    cout << "\n\n\t\tRETURN DVD" << endl << endl;
    cout << "\t\tEnter Movie's title:  ";
    getline(cin, title);

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
            cout << "\n\t\t\"" << formatString(title) << "\" has been returned" << endl << endl;
        } else if (confirm == 2) {
            cout << "\n\t\tRequest has been canceled" << endl << endl;
        }
        movieAddress = NULL;
        delete movieAddress;
    }
}

void CustomerOperations::listCurrentlyRentedMovies(Customer* customer) {
    cout << "\n\n\t\tCURRENTLY RENTED MOVIES" << endl;
    customer->displayRecord();
}

void CustomerOperations::displayTopTenMovies(MovieCollection& movies) {
    std::vector<Movie> topTenMovies = movies.findTopTenMovies();
    cout << "\n\n\t\tTOP 10 RENTED MOVIES" << endl << endl;
    cout << "\t\t" << setw(15) << left << "Title" << setw(20) << right << "Number of Rentals" << endl << endl;

    for (std::vector<std::string>::size_type i = 0; i < topTenMovies.size(); i++) {
        cout << "\t\t" << setw(15) << left << formatString(topTenMovies[i].getTitle()) << setw(20) << right
             << topTenMovies[i].getNumRentals() << endl;
    }
    cout << endl;
}

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

std::string CustomerOperations::lowerCase(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string CustomerOperations::formatString(std::string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}

void CustomerOperations::displayErrorMessage() {
    cout << "\n\t\tERROR: Invalid Input" << endl;
}

void CustomerOperations::displayMovieNotFoundMessage() {
    cout << "\n\t\tMovie not found" << endl << endl;
}
