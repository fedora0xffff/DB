#include "database.h"

void Database::Add(const Date& date, const std::string& event){
	std::cout << "DBG: " << date << std::endl;
	std::cout << "if the entered date exists " << db_.count(date) << std::endl;
	std::cout << "DB: " << db_ << std::endl;
	if (db_.count(date) > 0){
		std::cout << "Such a date already exists. Overwrite (o) or ignore (i)?\n" << std::endl;
		char action;
		std::cin >> action;
		if (action == 'o'){
			db_[date] = event;
		}
	}
	else {
		db_[date] = event;
	}
}

void Database::Print(std::ostream& os) const {
	for (const auto& elem: db_) {
		std::cout << elem.first << " " << elem.second << "\n";
		//std::cout << std::endl;
	}
}

std::string Database::Last(const Date& date) {
	auto last_date = std::upper_bound(db_.begin(), db_.end(), date, 
			[](const Date& val, const std::pair<Date, std::string>& date_in_db) {
			return  date_in_db.first > val;
			});
	if (last_date == db_.begin()) {
		return "No entries";
	}
	else {
		auto target = std::prev(last_date);
		std::string res = (*target).first.PrintDate() + " " + (*target).second;
		return res;
	}
} 
