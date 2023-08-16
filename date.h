#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Date {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend bool operator==(const Date& lhs, const Date& rhs);
    friend bool operator!=(const Date& lhs, const Date& rhs);
    friend bool operator<(const Date& lhs, const Date& rhs);
    std::string PrintDate() const{
	    std::string date{std::to_string(yyyy_) + delimiter_ + std::to_string(mm_) + delimiter_ + std::to_string(dd_)};
	    return date;
    }
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
#ifdef DEBUG
        if (yyyy_ == 0 && mm_ == 1 && dd_ == 1) {
            std::cout << "probably sth went wrong with init\n";
	    std::cout << "args fro cstr were " << yyyy << delim << mm << delim << dd << '\n'
		   << "and got " << yyyy_ << delim << mm_ << delim << dd_ << std::endl; 
        }
#endif

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
