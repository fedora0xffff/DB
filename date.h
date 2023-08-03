#pragma once
#include <string>
#include <iostream>


class Date {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    Date(int yyyy, short mm, short dd, char delim = '-') {
        if (yyyy >= 0 && yyyy < 10000) {
            yyyy_ = yyyy;
        }
        if (mm > 1 && mm < 13) {
            mm_ = mm;
        }
        if (dd > 0 && dd < 32) {
            dd_ = dd;
        }
        if (yyyy_ == 0 && mm_ == 1 && dd_ == 1) {
            std::cout << "probably sth went wrong with init\n";
        }
    }
    //copy cstr?
    private:
    int yyyy_ = 0;
    int mm_ = 1;
    int dd_ = 1;
    char delimiter_ = '-';
};

Date ParseDate(std::istringstream& is); //move on return?

//std::ostream& operator<<(std::ostream& os, const Date& date);