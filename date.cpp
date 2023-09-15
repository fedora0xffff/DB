#include "date.h"
#include <cctype>

//#define DEBUG
Date ParseDate(std::istringstream& is) { 
	std::vector<std::string> dates(3);
	char c;
	c = is.peek();
	//if (c == ' ' || c == '-' || !std::isdigit(c)) { return {};}
	std::getline(is, dates[0], '-');
	std::getline(is, dates[1], '-'); 
	std::getline(is, dates[2], ' ');
	Date date{std::stoi(dates[0]), std::stoi(dates[1]), std::stoi(dates[2])};
    return date;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.yyyy_ << date.delimiter_ << date.mm_ << date.delimiter_ << date.dd_;
    return os;
}

bool operator==(const Date& lhs, const Date& rhs) { 
	if (lhs.yyyy_ == rhs.yyyy_ && lhs.mm_ == rhs.mm_ && lhs.dd_ == rhs.dd_) return true;
	else return false;
}
bool operator!=(const Date& lhs, const Date& rhs) { 
	return !(lhs == rhs);
}

 bool operator<(const Date& lhs, const Date& rhs) {
	 if (lhs.yyyy_ == rhs.yyyy_) {
		if (lhs.mm_ == rhs.mm_) return lhs.dd_ < rhs.dd_;
		else return lhs.mm_ < rhs.mm_;
	 }
	 else return lhs.yyyy_ < rhs.yyyy_;
 }

 bool operator>(const Date& lhs, const Date& rhs) {
 	if (!(lhs<rhs) && lhs!=rhs) return true;
 	else return false;
 }

void TestDateOps() {
	{
		Date d1{1997, 5, 27};
		Date d2{1111,1,1};
		Date d3{1997,5,27};
		Date d4{1111, 5,5};
		Date d5{2012,12,12};
		std::Assert(d1 == d3, "same date comparison");
		std::Assert(!(d1 == d2), "d1!=d2");
		std::Assert(!(d4 == d3), "d4!=d3");
		std::Assert(!(d2 == d3), "d2!=d3");
		std::Assert(d1 > d2, "1997 > 1111");
		std::Assert(d2 < d3, "1111 < 1997");
	}
{
	Date d1{1111,1,1};
	Date d2{2012,12,12};
	Date d3{3034,10,5};
	Date d4{1111, 5,5};
	Date d5{1997, 5,27};
	std::map<Date, std::string> m;
	m[d1] = "1st event";
	m[d2] = "2nd";
	m[d3] = "3rd";
	std::Assert(m.count(d1) == 1, "d1");
	std::Assert(m.count(d4) == 0, "found d4, though is not there");
	std::Assert(m.count(d5) == 0, "found d5, though no d5");
}

}