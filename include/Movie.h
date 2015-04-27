#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>

class Movie {

    private:
        std::string title;
        std::string starring;
        std::string director;
        std::string genre;
        std::string classification;
        std::string releaseDate;
        int duration;
        int numDVDs;
        int numRentals;
        std::vector<std::string> record;

        std::string upperCase(std::string str);
        std::string lowerCase(std::string str);
        std::string formatString(std::string str);
        bool compareCaseInsensitive(std::string str1, std::string str2);

    public:
        Movie();
        Movie(std::string title, std::string starring,
              std::string director, std::string genre,
              std::string classification, std::string releaseDate,
              int duration, int numDVDs);
        ~Movie();
        std::string getTitle() const;
        std::string getStarring() const;
        std::string getDirector() const;
        std::string getGenre() const;
        std::string getClassification() const;
        std::string getReleaseDate() const;
        int getDuration() const;
        int getNumDVDs() const;
        int getNumRentals() const;
        std::vector<std::string> getRecord() const;
        void setTitle(const std::string title);
        void setStarring(const std::string starring);
        void setDirector(const std::string director);
        void setGenre(const std::string genre);
        void setClassification(const std::string classification);
        void setReleaseDate(const std::string releaseDate);
        void setDuration(const int duration);
        void setNumDVDs(const int numDVDs);
        void increaseNumRentals();
        void addRecord(const std::string name);
        int findRecord(const std::string name);
        void removeRecord(const std::string name);
        void addDVDs(const int numDVDs);
        void removeDVDs(const int numDVDs);
        void displayInfo();
};

#endif // MOVIE_H
