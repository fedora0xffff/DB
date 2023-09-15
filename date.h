#pragma once
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include "UnitTestFramework.h"

#define DEBUG

class Date {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend bool operator==(const Date& lhs, const Date& rhs);
    friend bool operator!=(const Date& lhs, const Date& rhs);
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator>(const Date& lhs, const Date& rhs);
    Date() {}
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
    std::string PrintDate() const{
	    std::string date{std::to_string(yyyy_) + delimiter_ + std::to_string(mm_) + delimiter_ + std::to_string(dd_)};
	    return date;
    }

    Date(const Date& d) {
        if (!d.empty) {
            yyyy_ = d.yyyy_;
            mm_ = d.mm_;
            dd_ = d.dd_;
        }
    }
    
    //copy cstr?
    private:
    int yyyy_ = 0;
    int mm_ = 1;
    int dd_ = 1;
    char delimiter_ = '-';
    bool empty = false;
};

Date ParseDate(std::istringstream& is); //move on return?

void TestDateOps();
//std::ostream& operator<<(std::ostream& os, const Date& date);