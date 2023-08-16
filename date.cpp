#include "date.h"


//#define DEBUG
Date ParseDate(std::istringstream& is) { 
	std::vector<std::string> dates(3);
	std::string str = "";
	int i = 0;
	
	for (std::string line; std::getline(is, line, '-'); ){
	dates[i] = line;
	++i;
	}
    #ifdef DEBUG
    std::cout << dates[0] << " " << dates[1] << " " << dates[2]  << std::endl;
    #endif
	Date date{std::stoi(dates[0]), std::stoi(dates[1]), std::stoi(dates[2])};
 
    return date;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.yyyy_ << date.delimiter_ << date.mm_ << date.delimiter_ << date.dd_;
    return os;
}


bool operator==(const Date& lhs, const Date& rhs) { 
	return (lhs.yyyy_ == rhs.yyyy_ && lhs.mm_ == rhs.mm_ && lhs.dd_ == rhs.dd_);
}
bool operator!=(const Date& lhs, const Date& rhs) { 
	return !(lhs == rhs);
}

 bool operator<(const Date& lhs, const Date& rhs) {
	 if (lhs.yyyy_ < rhs.yyyy_ && lhs.mm_ < rhs.mm_ && lhs.dd_ < rhs.dd_ ) return true;
	 else return false; 
 }

 bool operator>(const Date& lhs, const Date& rhs) {
 	if (!(lhs<rhs) && lhs!=rhs) return true;
 	else return false;
 }

