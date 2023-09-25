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

//#define DEBUG

class Date {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend bool operator==(const Date& lhs, const Date& rhs);
    friend bool operator!=(const Date& lhs, const Date& rhs);
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator>(const Date& lhs, const Date& rhs);

    Date() { empty = true;}
    Date(int yyyy, short mm, short dd, char delim = '-');
    Date(const Date& d);
    std::string PrintDate() const;

    private:
    int yyyy_ = 0;
    int mm_ = 1;
    int dd_ = 1;
    char delimiter_ = '-';
    bool empty = false;
};

Date ParseDate(std::istringstream& is); 
void TestDateOps();
//std::ostream& operator<<(std::ostream& os, const Date& date);