#include "date.h"

Date ParseDate(std::istringstream& is) { //check for correct values
    std::string yyyy, mm, dd;
    std::getline(is, yyyy, '-');
    std::getline(is, mm, '-');
    std::getline(is, dd);
    #ifdef DEBUG
    std::cout << yyyy <<" " << mm << " " << dd << std::endl;
    #endif
    return Date{std::stoi(yyyy), std::stoi(mm), std::stoi(dd)};
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.yyyy_ << date.delimiter_ << date.mm_ << date.delimiter_ << date.dd_;
    return os;
}